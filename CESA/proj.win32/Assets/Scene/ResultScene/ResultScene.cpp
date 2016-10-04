#include "ResultScene.h"
#include"ScoreManager/ScoreManager.h"
#include"Scene/TitleScene/TitleScene.h"
#include"ADX2Rapper/ADX2Manager.h"

USING_NS_CC;

cocos2d::Scene * ResultScene::createScene()
{
	auto scene = Scene::create();
	auto playScene = ResultScene::create();
	scene->addChild(playScene);
	return scene;
}

bool ResultScene::init()
{
	if (!Layer::init())return false;

	/*==============================
	背景初期化
	===============================*/
	auto sprite = Sprite::create("background_result.png");
	sprite->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(sprite);

	/*==============================
	スコアラベルの初期化
	===============================*/
	auto scoreMng = ScoreManager::getInstance();
	char buf[128];
	sprintf(buf, "SCORE : %.0f", scoreMng->getScore());
	m_pScoreLabel = Label::createWithTTF(buf, "font/misaki_gothic.ttf", 128);
	m_pScoreLabel->setPosition(10.f, 800.f);
	m_pScoreLabel->setAnchorPoint(Vec2(0.f, 0.f));
	m_pScoreLabel->setVisible(false);

	addChild(m_pScoreLabel);

	/*==============================
	撃墜数ラベルの初期化
	===============================*/
	sprintf(buf, "SHOOT DOWN : %3d", scoreMng->getEnemyShootingDownCount());
	m_pShootDownLabel = Label::createWithTTF(buf, "font/misaki_gothic.ttf", 128);
	m_pShootDownLabel->setVisible(false);
	m_pShootDownLabel->setPosition(10.f, 400.f);
	m_pShootDownLabel->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(m_pShootDownLabel);

	/*==============================
	テキストラベルの初期化
	===============================*/
	m_pTextLabel = Label::createWithTTF("RETURN TO TITLE", "font/misaki_gothic.ttf", 128);
	m_pTextLabel->setPosition(10.f, 200.f);
	m_pTextLabel->setVisible(false);
	m_pTextLabel->setAnchorPoint(Vec2(0.f, 0.f));
	auto blink = Blink::create(1.0f, 2);
	auto repeat = RepeatForever::create(blink);
	m_pTextLabel->runAction(repeat);
	addChild(m_pTextLabel);

	m_procTime = 0.f;
	m_isSceneMoving = false;
	/*==============================
	イベントリスナー
	===============================*/
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		if (!m_isSceneMoving&&m_procTime >= 3.5f)
		{
			auto director = Director::getInstance();
			auto transition = TransitionFadeBL::create(2.0f, TitleScene::createScene());
			director->replaceScene(transition);
			m_isSceneMoving = true;
		}
		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();

	return true;
}

void ResultScene::update(float dt)
{
	ADX2Manager::getInstance()->executeMain();
	static int cnt = 0;
	if (m_procTime >= 2.5f)
	{
		m_pScoreLabel->setVisible(true);
	}

	if (m_procTime >= 3.5f)
	{
		m_pShootDownLabel->setVisible(true);
	}

	m_procTime += dt;
	cnt++;
}
