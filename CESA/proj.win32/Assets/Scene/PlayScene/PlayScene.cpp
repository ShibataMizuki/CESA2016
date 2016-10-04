#include "PlayScene.h"

#include"GameObjectManager/GameObjectManager.h"
#include"GameObject/PlayerPlane/PlayerPlane.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"

#include"EnemyAI/EnemyAIFactory.h"

#include"MoveStrategy/MoveWithKeyboard/MoveWithKeyboard.h"

#include"UINode/UINode.h"

#include"SoundManager/SoundManager.h"

#include"EnemyAction/EnemyActionFactory.h"

#include"DebugNode/DebugNode.h"
#include"Utils/Utils.h"
#include"CollisionSystem/CSShape/CSCircle/CSCircle.h"
#include"VirtualPad/ViritualPad.h"
#include"ScoreManager/ScoreManager.h"
#include<memory>

#include"GameObject/GameObjectFactory.h"
#include"GameObject/GameObject.h"

#include"Effect/EffectCircleSplash.h"
#include"Scene/TitleScene/TitleScene.h"
#include"Scene/ResultScene/ResultScene.h"
#include"WorldManager/WorldManager.h"
#include"CollisionSystem/CSHitCallback/CSHitCallback.h"
#include"inc/GameObjects.h"
#include"PopupLabel/PopupLabel.h"

USING_NS_CC;
void PlayScene::enemyQueueInit()
{
	m_prevShotDeltaTime = 0.f;

	auto createCircleBody = [&](float radius)
	{
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(radius));
		body->setCollisionGroup((int)ObjectType::Enemy);
		return body;
	};

	//1秒~6秒 中心から5機
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy1.png");
		spr->setScale(2.f);
		spr->getTexture()->setAliasTexParameters();

		auto enemy = GameObjectFactory::createEnemy(spr,createCircleBody(50.f),
			Vec2(960.f / 2.f, 1400.f),2.f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveBy(enemy, 5.0f, Vec2(0.f, -1800.f));
		enemy->pushAction(move);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(f1*1.f + 3.f, enemy));
	}

	//10秒~15秒 左端から5機
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy1.png");
		//spr->getTexture()->setAliasTexParameters();
		spr->setScale(2.f);
		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(100.f, 1400.f), 3.f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveTo(enemy, 2.0f, Vec2(960.f / 2.f+f1*100.f, 800.f));
		auto shot = EnemyActionFactory::createEnemyActionSnipeShot(enemy, 3.0f, 2, 500.f);
		auto move2 = EnemyActionFactory::createEnemyActionMoveTo(enemy, 3.0f, Vec2(960.f / 2.f, 1800.f));
		enemy->pushAction(move);
		enemy->pushAction(shot);
		enemy->pushAction(move2);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(f1*1.f + 10, enemy));
	}

	//16~20秒 右端から5機
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy1.png");
		//spr->getTexture()->setAliasTexParameters();
		spr->setScale(2.f);
		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(1080.f, 1400.f), 3.f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveTo(enemy, 2.0f, Vec2(960.f / 2.f - f1*100.f, 800.f));
		auto shot = EnemyActionFactory::createEnemyActionSplashShot(enemy, 3.0, 2, Util::convertToRadian(30), 700.f);
		auto move2 = EnemyActionFactory::createEnemyActionMoveTo(enemy, 3.0f, Vec2(960.f / 2.f, 1800.f));
		enemy->pushAction(move);
		enemy->pushAction(shot);
		enemy->pushAction(move2);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(f1*1.f + 16, enemy));
	}

	//30秒 上から単横陣
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy2.png");
		//spr->getTexture()->setAliasTexParameters();
		spr->setScale(2.f);
		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(300+f1*100.f, 1400.f), 3.f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveTo(enemy, 2.0f, Vec2(960.f / 2.f - f1*100.f, 800.f));
		auto shot = EnemyActionFactory::createEnemyActionSplashShot(enemy, 3.0, 3, Util::convertToRadian(45), 700.f);
		auto move2 = EnemyActionFactory::createEnemyActionMoveTo(enemy, 3.0f, Vec2(960.f / 2.f, 1800.f));
		enemy->pushAction(move);
		enemy->pushAction(shot);
		enemy->pushAction(move2);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(30, enemy));
	}

	//38秒 上から単横陣
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy3.png");
		//spr->getTexture()->setAliasTexParameters();
		spr->setScale(2.f);
		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(900 - f1*100.f, 1400.f), 3.f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveTo(enemy, 2.0f, Vec2(960.f / 2.f - f1*100.f, 800.f));
		auto shot = EnemyActionFactory::createEnemyActionSplashShot(enemy, 3.0, 3, Util::convertToRadian(45), 700.f);
		auto move2 = EnemyActionFactory::createEnemyActionMoveTo(enemy, 3.0f, Vec2(960.f / 2.f, 1800.f));
		enemy->pushAction(move);
		enemy->pushAction(shot);
		enemy->pushAction(move2);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(38, enemy));
	}

	//45秒 上から単横陣
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy2.png");
		//spr->getTexture()->setAliasTexParameters();
		spr->setScale(2.f);
		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(300 + f1*100.f, 1400.f), 3.f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveTo(enemy, 2.0f, Vec2(960.f / 2.f - f1*100.f, 800.f));
		auto shot = EnemyActionFactory::createEnemyActionSplashShot(enemy, 3.0, 3, Util::convertToRadian(45), 700.f);
		auto move2 = EnemyActionFactory::createEnemyActionMoveTo(enemy, 3.0f, Vec2(960.f / 2.f, 1800.f));
		enemy->pushAction(move);
		enemy->pushAction(shot);
		enemy->pushAction(move2);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(45, enemy));
	}

	//52秒 上から複数の単横陣
	for (int f1 = 0; f1 < 3; f1++)
	{
		for (int f2 = 0; f2 < 5; f2++)
		{
			auto spr = Sprite::create("enemy2.png");
			//spr->getTexture()->setAliasTexParameters();
			spr->setScale(2.f);
			auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
				Vec2((f1%2)*(300 + f2*100.f)+(!(f1%2))*(900 - f2*100.f), 1400.f), 3.f, 1000.f);
			auto move = EnemyActionFactory::createEnemyActionMoveTo(enemy, 2.0f, Vec2(960.f / 2.f - f2*100.f, 800.f));
			auto shot = EnemyActionFactory::createEnemyActionSplashShot(enemy, 3.0, 3, Util::convertToRadian(45), 700.f);
			auto move2 = EnemyActionFactory::createEnemyActionMoveTo(enemy, 3.0f, Vec2(960.f / 2.f, 1800.f));
			enemy->pushAction(move);
			enemy->pushAction(shot);
			enemy->pushAction(move2);
			enemy->retain();
			m_enemyQueue.push(std::make_pair(52 + f1 * 2, enemy));
		}
	}

	//65秒 単縦陣*3
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy1.png");
		spr->setScale(2.f);
		spr->getTexture()->setAliasTexParameters();

		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(960.f / 2.f, 1400.f), 0.4f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveBy(enemy, 3.0f, Vec2(0.f, -1800.f));
		enemy->pushAction(move);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(f1*0.5f + 65.f, enemy));
	}
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy2.png");
		spr->setScale(2.f);
		spr->getTexture()->setAliasTexParameters();

		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(960.f / 2.f + 200.f, 1400.f), 0.4f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveBy(enemy, 3.0f, Vec2(0.f, -1800.f));
		enemy->pushAction(move);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(f1*0.5f + 65.f, enemy));
	}
	for (int f1 = 0; f1 < 5; f1++)
	{
		auto spr = Sprite::create("enemy3.png");
		spr->setScale(2.f);
		spr->getTexture()->setAliasTexParameters();

		auto enemy = GameObjectFactory::createEnemy(spr, createCircleBody(50.f),
			Vec2(960.f / 2.f - 200.f, 1400.f), 0.4f, 1000.f);
		auto move = EnemyActionFactory::createEnemyActionMoveBy(enemy, 3.0f, Vec2(0.f, -1800.f));
		enemy->pushAction(move);
		enemy->retain();
		m_enemyQueue.push(std::make_pair(f1*0.5f + 65.f, enemy));
	}
}

void PlayScene::enemyQueueExecute(float dt)
{
	while(!m_enemyQueue.empty())
	{
		auto top = m_enemyQueue.top();
		if (top.first <= m_prevShotDeltaTime)
		{
			top.second->autorelease();
			GameObjectManager::getInstance()->addGameObject(top.second);
			m_enemyQueue.pop();
		}
		else
		{
			break;
		}
	}
	m_prevShotDeltaTime += dt;
}

void PlayScene::executeFinish(float dt)
{
	if (!m_isFinished)
	{
		m_isFinished = m_enemyQueue.empty() && (GameObjectManager::getInstance()->getEnemyList().size() == 0);
		if (GameObjectManager::getInstance()->getPlayerPlane()->getLife() == 0)
		{
			m_isFinished = true;
			auto particle = ParticleSystemQuad::create("particle_expl.plist");
			particle->resetSystem();
			particle->setAutoRemoveOnFinish(true);
			particle->setPosition(GameObjectManager::getInstance()->getPlayerPlane()->getPosition());
			particle->setStartColor(Color4F::WHITE);
			particle->setScale(2.0f);
			this->addChild(particle);
			GameObjectManager::getInstance()->getPlayerPlane()->setPosition(-100.f, -100.f);
			GameObjectManager::getInstance()->getPlayerPlane()->setVisible(false);
			//GameObjectManager::getInstance()->removeObject(GameObjectManager::getInstance()->getPlayerPlane());
		}
		m_sceneMoveFlg = false;
	}
	else
	{
		m_finishTimeCnt += dt;
		if (m_finishTimeCnt > 3.f&&!m_sceneMoveFlg)
		{
			auto director = Director::getInstance();
			auto transition = TransitionFadeBL::create(2.0f, ResultScene::createScene());
			director->replaceScene(transition);
			m_sceneMoveFlg = true;
		}
	}
}

cocos2d::Scene * PlayScene::createScene()
{
	auto scene = Scene::create();
	auto playScene = PlayScene::create();
	scene->addChild(playScene);
	return scene;
}

bool PlayScene::init()
{
	/*==============================
	cocos2d-x
	===============================*/
	if (!Layer::init())return false;
	scheduleUpdate();

	Size winSize = Director::getInstance()->getVisibleSize();
	
	/*==============================
	ADX2の初期化
	===============================*/
	/*
	auto manager = ADX2Manager::getInstance();
	manager->initialize("../Resources/TutorialProject.acf");
	auto acbHandle = manager->loadCueSheet("../Resources/CueSheet_0.acb");
	auto player = manager->createPlayer(acbHandle, 3);
	GameObjectManager::getInstance()->setItemHitPlayer(manager->createPlayer(acbHandle, 2));
	*/
	/*==============================
	サウンドマネージャ初期化
	===============================*/
	/*
	auto soundManager = SoundManager::getInstance();
	soundManager->setBackSound(player, 180.f);
	soundManager->getBackSound()->stop();
	soundManager->getBackSound()->start();
	*/
	/*==============================
	スコアマネージャ初期化
	===============================*/
	ScoreManager::getInstance()->init();

	/*==============================
	オブジェクトマネージャ初期化
	===============================*/
	auto objectManager = GameObjectManager::getInstance();
	objectManager->reset();
	objectManager->setTargetNode(this);

	/*==============================
	自機の初期化
	===============================*/
	auto playerPlane = PlayerPlane::create();
	playerPlane->setMoveStrategy(std::make_shared<MoveWithKeyboard>(playerPlane, 10.f));
	auto body = CSBody::createShared();
	body->addShape(CSCircle::createShared(10.f));
	body->setCollisionGroup((int)ObjectType::Player);
	playerPlane->setBody(body);
	playerPlane->setPosition(Vec2(960.f / 2.f, 100.f));
	objectManager->addGameObject(playerPlane);

	/*==============================
	UIの初期化
	===============================*/
	auto ui = UINode::create();
	ui->setPosition(Vec2(500.f, 100.f));
	addChild(ui, (int)NODE_DEPTH::UI);

	/*==============================
	背景の初期化
	===============================*/
	auto bg = Sprite::create("background.png");
	bg->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(bg, (int)NODE_DEPTH::BACK_GROUND);

	auto bgParticle = ParticleSystemQuad::create("particle_background.plist");
	bgParticle->setPosition(Vec2(winSize.width / 2.f, winSize.height + 100.f));
	bgParticle->setAutoRemoveOnFinish(true);
	bgParticle->resetSystem();
	addChild(bgParticle);

	/*==============================
	Virtual Padの初期化
	===============================*/
	auto pad = VirtualPad::create();
	pad->setPosition(200.f, 200.f);
	this->addChild(pad);


	/*==============================
	デバッグ文字列表示の初期化
	===============================*/
	DebugStringNode::getInstance()->init(this);

	enemyQueueInit();

	m_pLabel = Label::createWithTTF("THE NEW CHALLENGER :D'elf","font/misaki_gothic.ttf",64);
	m_pLabel->setVisible(false);
	m_pLabel->setPosition(50.f, 600.f);
	m_pLabel->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(m_pLabel,2);
	m_pLabel->setOpacity(0);

	m_appendFlag = false;
	m_finishTimeCnt = 0.f;
	m_isFinished = false;

	/*==============================
	BGMレジューム
	===============================*/
	//ポーズ・レジューム
	auto listener = EventListenerCustom::create("DidEnterBackground", [](EventCustom* event)
	{
		SoundManager::getInstance()->getBackSound()->pause();
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	listener = EventListenerCustom::create("WillEnterBackground", [](EventCustom* event)
	{
		SoundManager::getInstance()->getBackSound()->resume();
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	WorldManager::getInstance()->setDrawNode(this);

	/*==============================
	衝突コールバックの設定
	===============================*/
	WorldManager::getInstance()->getWorld()->removeAllCallback();
	auto callback1 = CSHitCallback::createShared((int)ObjectType::Player, (int)ObjectType::EnemyBullet);
	callback1->HitBegin = [&](const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)
	{
		auto player = bodyA->getCastedUserData<PlayerPlane*>();
		//ライフにダメージを与える
		player->takeDamage(1);

		//画面を揺らす
		auto move1 = MoveBy::create(0.05f, Vec2(40.f, 0.f));
		auto move2 = MoveBy::create(0.05f, Vec2(-80.f, 0.f));
		auto move3 = MoveBy::create(0.05f, Vec2(40.f, 0.f));
		auto sequence = Sequence::create(move1, move2, move3, nullptr);
		this->runAction(sequence);

		auto bullet = static_cast<EnemyBullet*>(bodyB->getUserData());
		GameObjectManager::getInstance()->removeObject(bullet);
	};
	WorldManager::getInstance()->getWorld()->addHitCallback(callback1);

	auto callback2 = CSHitCallback::createShared((int)ObjectType::PlayerBullet, (int)ObjectType::Enemy);
	callback2->HitBegin = [&](const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)
	{
		auto bullet = bodyA->getCastedUserData<PlayerBullet*>();
		auto enemy = bodyB->getCastedUserData<EnemyPlane*>();

		//演出
		auto particle = ParticleSystemQuad::create("particle_hitEffect.plist");
		particle->resetSystem();
		particle->setScale(1.0f);
		particle->setAutoRemoveOnFinish(true);
		particle->setPosition(bullet->getPosition());
		this->addChild(particle);

		//ライフを減らす
		enemy->setLife(enemy->getLife() - bullet->getPower());

		ScoreManager::getInstance()->addEnemyShootingDownCount();

		GameObjectManager::getInstance()->removeObject(bullet);
	};
	WorldManager::getInstance()->getWorld()->addHitCallback(callback2);

	auto callback3 = CSHitCallback::createShared((int)ObjectType::Player, (int)ObjectType::Item);
	callback3->HitBegin = [&](const std::shared_ptr<CSBody>& bodyA, const std::shared_ptr<CSBody>& bodyB)
	{
		auto item = bodyB->getCastedUserData<ScoreItem*>();

		//スコア追加
		ScoreManager::getInstance()->addScore(item->getScoreToHave());
		auto particle = ParticleSystemQuad::create("particle_hitEffect.plist");
		particle->resetSystem();
		particle->setScale(1.0f);
		particle->setAutoRemoveOnFinish(true);
		particle->setPosition(item->getPosition());
		this->addChild(particle);

		char buf[128];
		sprintf(buf, "%d", item->getScoreToHave());

		auto pLabel = Label::createWithTTF(buf, "font/misaki_gothic.ttf", 48);
		createPopupLabel(pLabel);
		pLabel->setOpacity(128);
		pLabel->setPosition(item->getPosition() + Vec2(0.f, 50.f));
		this->addChild(pLabel);

		GameObjectManager::getInstance()->removeObject(item);
		//m_pItemHitPlayer->stop();
		//m_pItemHitPlayer->start();
	};
	WorldManager::getInstance()->getWorld()->addHitCallback(callback3);

	return true;
}

void PlayScene::update(float dt)
{

	ADX2Manager::getInstance()->executeMain();
	auto objectManager = GameObjectManager::getInstance();
	auto sndMng = SoundManager::getInstance();

	sndMng->updateTimeToNextBeat();
	this->enemyQueueExecute(dt);
	objectManager->update(dt);
	ScoreManager::getInstance()->update();

	DebugStringNode::getInstance()->update();

	if (sndMng->isBeat(2))
	{
		auto move1 = MoveBy::create(0.05f, Vec2(0.f, 5.f));
		auto move2 = MoveBy::create(0.05f, Vec2(0.f, -10.f));
		auto move3 = MoveBy::create(0.05f, Vec2(0.f, 5.f));
		auto sequence = Sequence::create(move1, move2, move3, nullptr);
		this->runAction(sequence);

		auto effect = EffectCircleSplash::create();
		effect->setPosition(Vec2(960.f / 2.f, 1280.f / 2.f));
		effect->setScale(2.0f);
		effect->setOpacity(64);
		addChild(effect);
	}

	if (!m_appendFlag&&m_prevShotDeltaTime >= 22.f)
	{
		auto fade = FadeIn::create(2.0f);
		auto fadeOut = FadeOut::create(2.0f);
		auto sequence = Sequence::create(fade, fadeOut, nullptr);
		m_pLabel->runAction(sequence);
		m_pLabel->setVisible(true);

		auto label = Label::createWithTTF("BGM", "font/misaki_gothic.ttf", 64);
		label->setPosition(960.f / 2.f, 700.f);
		label->setOpacity(0);
		label->runAction(Sequence::create(FadeIn::create(2.0f), FadeOut::create(2.0f), nullptr));
		addChild(label);

		m_appendFlag = true;
	}
	WorldManager::getInstance()->getWorld()->executeCollision();
	WorldManager::getInstance()->debugDraw();

	executeFinish(dt);
}

PlayScene::PlayScene():
	m_prevShotDeltaTime(0.f)
{
}
