#include "PlayerPlane.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"
#include"GameObject/PlayerBullet/PlayerBullet.h"
#include"GameObjectManager/GameObjectManager.h"
#include"Effect/EffectCircleSplash.h"
#include"MoveStrategy/MoveHoming/MoveHoming.h"
#include"Utils/Utils.h"
#include"MoveStrategy/MoveWithKeyboard/MoveWithKeyboard.h"
#include"MoveStrategy/MoveLinear/MoveLinear.h"
#include"SoundManager/SoundManager.h"
#include"DebugNode/DebugNode.h"

#include"PopupLabel/PopupLabel.h"
#include"Metronome/Metronome.h"

#include"CollisionSystem/CSShape/CSCircle/CSCircle.h"

USING_NS_CC;

void PlayerPlane::setSprite(cocos2d::Sprite * pSprite)
{
	m_pSprite = pSprite;
}

cocos2d::Sprite * PlayerPlane::getSprite() const
{
	return m_pSprite;
}

void PlayerPlane::updateLifeSprite()
{
	for (int f1 = 0; f1 < m_life; f1++)
	{
		m_sprLife[f1]->setVisible(true);
		m_sprLifeDamaged[f1]->setVisible(false);
	}
	for (int f1 = LifeMax - 1; f1 >= m_life; f1--)
	{
		m_sprLife[f1]->setVisible(false);
		m_sprLifeDamaged[f1]->setVisible(true);
	}

	if (m_life == 3)
	{
		for (int f1 = 0; f1 < LifeMax; f1++)
		{
			m_sprLife[f1]->setColor(Color3B(0, 255, 0));
			m_sprLifeDamaged[f1]->setColor(Color3B(0, 255, 0));
		}
	}
	else if (m_life == 2)
	{
		for (int f1 = 0; f1 < LifeMax; f1++)
		{
			m_sprLife[f1]->setColor(Color3B(255, 255, 0));
			m_sprLifeDamaged[f1]->setColor(Color3B(255, 255, 0));
		}
	}
	else if (m_life == 1)
	{
		for (int f1 = 0; f1 < LifeMax; f1++)
		{
			m_sprLife[f1]->setColor(Color3B(255, 0, 0));
			m_sprLifeDamaged[f1]->setColor(Color3B(255, 0, 0));
		}
	}
}

int PlayerPlane::getLife() const
{
	return m_life;
}

void PlayerPlane::executeShooting(float dt)
{
	m_prevShotDeltaTime += dt;
	//前回の射撃から1.f/shotPerSec秒経ったら射撃
	if (m_prevShotDeltaTime >= 1.f / m_shotPerSec)
	{
		//射撃処理
		auto bullet = PlayerBullet::create();

		bullet->setPosition(this->getPosition());
		
		auto spr = Sprite::create("player-bullet.png");
		spr->setScale(3.0f);
		spr->setOpacity(128);
		spr->getTexture()->setAliasTexParameters();
		bullet->setSprite(spr);
		//bullet->setShape(CircleShape::createSharedPtr(50.f));
		auto body = CSBody::createShared(CSVec2(this->getPosition().x, this->getPosition().y));
		body->addShape(CSCircle::createShared(50.f));
		body->setCollisionGroup((int)ObjectType::PlayerBullet);
		bullet->setBody(body);

		bullet->setPower(0.2f);

		auto move = std::make_shared<MoveLinear>(bullet, 2000.f, Util::convertToDirection(Util::convertToRadian(90.f)));
		bullet->setMoveStrategy(move);

		GameObjectManager::getInstance()->addGameObject(bullet);

		m_prevShotDeltaTime = 0.f;
	}
}

void PlayerPlane::initHomingShot()
{
	m_homingShotEnable = false;

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		if (m_homingShotEnable)
		{
			auto manager = GameObjectManager::getInstance();
			auto enemyList = manager->getEnemyList();
			auto worldTouchPos = this->getParent()->convertTouchToNodeSpace(touch);

			for (auto& enemy : enemyList)
			{
				auto enemyBB = enemy->getSprite()->getBoundingBox();
				auto rect = RectApplyAffineTransform(enemyBB, enemy->getNodeToWorldAffineTransform());
				if (rect.containsPoint(worldTouchPos))
				{
					this->shotHomingBullet(enemy);
					//	addChild(EffectCircleSplash::create());
					m_homingShotEnable = false;

					auto sndMng = SoundManager::getInstance();
					if (sndMng->getTimeToPrevBeat(2) < 150 || sndMng->getTimeToNextBeat(2) < 150)
					{
						auto label = Label::createWithTTF("GOOD", "font/misaki_gothic.ttf", 64);
						label->setColor(Color3B::GREEN);
						createPopupLabel(label);
						label->setPosition(enemy->getPosition() + Vec2(0.f, 100.f));
						GameObjectManager::getInstance()->getTargetNode()->addChild(label);
					}
					else
					{
						auto label = Label::createWithTTF("BAD", "font/misaki_gothic.ttf", 64);
						label->setColor(Color3B::BLUE);
						createPopupLabel(label);
						label->setPosition(enemy->getPosition() + Vec2(0.f, 100.f));
						GameObjectManager::getInstance()->getTargetNode()->addChild(label);
					}
					break;
				}
			}
		}
		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void PlayerPlane::executeHomingShot(float dt)
{
	auto sndMng = SoundManager::getInstance();

	
	if (m_homingShotEnable)
	{
		if (sndMng->getTimeToPrevBeat(2)<300)
		{
			m_homingShotEnable = false;
		}
	}
	
	if (sndMng->getTimeToNextBeat(2)<300)
	{
		m_homingShotEnable = true;
	}
}

bool PlayerPlane::init()
{
	if (!Node::init())return false;
	
	m_pSprite = Sprite::create("player-plane.png");
	addChild(m_pSprite);
	m_pSprite->getTexture()->setAliasTexParameters();
	
	scheduleUpdate();

	this->setMoveStrategy(std::make_shared<MoveWithKeyboard>(this, 10.f));

	/*==============================
	ライフ関係
	===============================*/
	m_life = this->LifeMax;
	for (int f1 = 0; f1 < LifeMax;f1++)
	{
		m_sprLife[f1] = Sprite::create("life.png");
		m_sprLife[f1]->setVisible(true);
		m_sprLife[f1]->setPosition(Vec2(-(LifeMax*30.f) + (f1+2)*30.f, -80.f));
		m_sprLife[f1]->setScale(3.0f);
		m_sprLife[f1]->getTexture()->setAliasTexParameters();
		m_sprLife[f1]->setColor(Color3B(0, 255, 0));
		addChild(m_sprLife[f1]);
	}
	for (int f1 = 0; f1 < LifeMax;f1++)
	{
		m_sprLifeDamaged[f1] = Sprite::create("life-damaged.png");
		m_sprLifeDamaged[f1]->setVisible(false);
		m_sprLifeDamaged[f1]->setPosition(m_sprLife[f1]->getPosition());
		m_sprLifeDamaged[f1]->setScale(3.0f);
		m_sprLifeDamaged[f1]->getTexture()->setAliasTexParameters();
		m_sprLifeDamaged[f1]->setColor(Color3B(0, 255, 0));
		addChild(m_sprLifeDamaged[f1]);
	}

	/*==============================
	メイン射撃初期化
	===============================*/
	m_prevShotDeltaTime = 0.f;

	initHomingShot();

	/*==============================
	メトロノーム
	===============================*/
	auto metronome = Metronome::create(SoundManager::getInstance()->getBackSound(),
		SoundManager::getInstance()->getBackSoundBPM(), 4);
	metronome->setScale(1.5f);
	addChild(metronome);

	return true;
}

void PlayerPlane::update(float dt)
{
	this->executeShooting(dt);
	this->executeHomingShot(dt);
	GameObject::update(dt);

	char buf[128];
	sprintf(buf, "%.2f,%.2f", this->getPosition().x, this->getPosition().y);
	DebugStringNode::getInstance()->printDebugString(buf);
}


void PlayerPlane::shotHomingBullet(EnemyPlane* enemyPlane)
{
	{
		auto bullet = PlayerBullet::create();
		bullet->setPower(1.f);
		bullet->setPosition(this->getPosition());
		//bullet->setShape(CircleShape::createSharedPtr(2.f));
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(2.f));
		body->setPosition(CSVec2(this->getPosition().x, this->getPosition().y));
		body->setCollisionGroup((int)ObjectType::PlayerBullet);
		bullet->setBody(body);

		auto move = std::make_shared<MoveHoming>(bullet, enemyPlane, 5.f, 1000.f, Util::convertToRadian(45.f));
		bullet->setMoveStrategy(move);

		auto spr = Sprite::create("bullet.png");
		bullet->setSprite(spr);

		auto particle = ParticleSystemQuad::create("particle_shot.plist");
		particle->resetSystem();
		particle->setAutoRemoveOnFinish(true);
		particle->setPosition(Vec2(0.f, 0.f));
		bullet->addChild(particle);

		GameObjectManager::getInstance()->addGameObject(bullet);
	}
	{
		auto bullet = PlayerBullet::create();
		bullet->setPower(1.f);
		bullet->setPosition(this->getPosition());
		//bullet->setShape(CircleShape::createSharedPtr(2.f));
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(2.f));
		body->setPosition(CSVec2(this->getPosition().x, this->getPosition().y));
		body->setCollisionGroup((int)ObjectType::PlayerBullet);
		bullet->setBody(body);

		auto move = std::make_shared<MoveHoming>(bullet, enemyPlane, 5.f, 1000.f, Util::convertToRadian(135.f));
		bullet->setMoveStrategy(move);

		auto spr = Sprite::create("bullet.png");
		bullet->setSprite(spr);

		auto particle = ParticleSystemQuad::create("particle_shot.plist");
		particle->resetSystem();
		particle->setAutoRemoveOnFinish(true);
		particle->setPosition(Vec2(0.f, 0.f));
		bullet->addChild(particle);

		GameObjectManager::getInstance()->addGameObject(bullet);
	}
}

void PlayerPlane::takeDamage(int damage)
{
	m_life -= damage;
	if (m_life > LifeMax)m_life = LifeMax;
	if (m_life < 0)m_life = 0;
	this->updateLifeSprite();
}

void PlayerPlane::repairDamage(int repairValue)
{
	m_life += repairValue;
	if (m_life > LifeMax)m_life = LifeMax;
	if (m_life < 0)m_life = 0;
	this->updateLifeSprite();
}
