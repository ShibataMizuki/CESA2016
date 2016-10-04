#include "EnemyPlane.h"
#include"GameObjectManager/GameObjectManager.h"
#include"MoveStrategy/MoveStrategy.h"
#include"EnemyAI/EnemyAI.h"
#include"Utils/Utils.h"
#include"ScoreManager/ScoreManager.h"
#include"EnemyAction/EnemyAction.h"
#include"GameObject/ScoreItem/ScoreItem.h"
#include"CollisionSystem/CSShape/CSCircle/CSCircle.h"

USING_NS_CC;

void EnemyPlane::executeAction(float dt)
{
	if (!m_actionQueue.empty())
	{
		auto action = m_actionQueue.front();
		if (action->update(dt))
		{
			m_actionQueue.pop();
			if (!m_actionQueue.empty())
			{
				m_actionQueue.front()->init();
			}
		}
	}
}

void EnemyPlane::pushAction(const std::shared_ptr<EnemyAction>& action)
{
	m_actionQueue.push(action);
}

void EnemyPlane::setScoreToHave(int value)
{
	m_scoreToHave = value;
}

int EnemyPlane::getScoreToHave() const
{
	return m_scoreToHave;
}

EnemyPlane::~EnemyPlane()
{
}

bool EnemyPlane::init()
{
	if (!GameObject::init())return false;

//	m_pSprite = Sprite::create("enemy-small-green.png");
//	m_pSprite->getTexture()->setAliasTexParameters();
//	m_pSprite->setScale(7.0f);
//	addChild(m_pSprite);

	class Dummy :public EnemyAction
	{
	public:
		Dummy(EnemyPlane* pTarget, float duration) :EnemyAction(pTarget, duration) {}
		void init()override {}
		bool update(float dt)override { return isFinished(dt); }
	};

	auto dummy = std::make_shared<Dummy>(this, 0.f);
	this->pushAction(dummy);

	return true;
}

void EnemyPlane::update(float dt)
{
	//装甲が0以下になったら爆発四散
	if (m_life <= 0)
	{
		//アイテム放出
		for (int f1 = 0; f1 < 5; f1++)
		{
			auto item = ScoreItem::create();
			item->setPosition(this->getPosition());
			//item->setShape(CircleShape::createSharedPtr(10.f));
			auto body = CSBody::createShared();
			body->addShape(CSCircle::createShared(10.f));
			body->setCollisionGroup((int)ObjectType::Item);
			item->setBody(body);

			item->setSprite(Sprite::create("point_item.png"));
			item->setScoreToHave(m_scoreToHave / 5.f);
			GameObjectManager::getInstance()->addGameObject(item);
		}

		auto move1 = MoveBy::create(0.05f, Vec2(10.f, 0.f));
		auto move2 = MoveBy::create(0.05f, Vec2(-20.f, 0.f));
		auto move3 = MoveBy::create(0.05f, Vec2(10.f, 0.f));
		auto sequence = Sequence::create(move1, move2, move3, nullptr);
		this->getParent()->runAction(sequence);
		ScoreManager::getInstance()->addScore(this->getScoreToHave());

		auto manager = GameObjectManager::getInstance();
		manager->removeObject(this);
		auto particle = ParticleSystemQuad::create("particle_expl.plist");
		particle->resetSystem();
		particle->setAutoRemoveOnFinish(true);
		particle->setPosition(this->getPosition());
		particle->setStartColor(Color4F::GREEN);
		this->getParent()->addChild(particle);
		//this->removeFromParent();
		return;
	}
	executeAction(dt);

	GameObject::update(dt);
}

void EnemyPlane::setLife(float value)
{
	m_life = value;
}

float EnemyPlane::getLife() const
{
	return m_life;
}

void EnemyPlane::setSprite(cocos2d::Sprite * sprite)
{
	m_pSprite = sprite;
	addChild(sprite);
}

cocos2d::Sprite * EnemyPlane::getSprite() const
{
	return m_pSprite;
}