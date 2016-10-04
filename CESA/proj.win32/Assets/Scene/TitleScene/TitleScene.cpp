#include "TitleScene.h"
#include"Scene/PlayScene/PlayScene.h"
#include"ADX2Rapper/ADX2Manager.h"
USING_NS_CC;

cocos2d::Scene * TitleScene::createScene()
{
	auto scene = Scene::create();
	auto titleScene = TitleScene::create();
	scene->addChild(titleScene);
	return scene;
}

bool TitleScene::init()
{
	if (!Layer::init())return false;

	/*==============================
	背景の設定
	===============================*/
	auto spr = Sprite::create("background-title.png");
	spr->setAnchorPoint(Vec2(0.f, 0.f));
	addChild(spr);

	m_isSceneMoving = false;
	m_procTime = 0.f;

	/*==============================
	タッチリスナー
	===============================*/
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		if (!m_isSceneMoving)
		{
			auto director = Director::getInstance();
			auto transition = TransitionFadeBL::create(2.0f, PlayScene::createScene());
			director->replaceScene(transition);
			m_isSceneMoving = true;
		}
		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	/*==============================
	ラベル
	===============================*/
	auto label = Label::createWithTTF("TAP TO START", "font/misaki_gothic.ttf", 128);
	label->setAnchorPoint(Vec2(0.f, 0.f));
	label->setPosition(100.f, 200.f);
	auto blink = Blink::create(1.0f, 2);
	auto repeat = RepeatForever::create(blink);
	label->runAction(repeat);
	addChild(label);
	
	scheduleUpdate();

	return true;
}

void TitleScene::update(float dt)
{
	ADX2Manager::getInstance()->executeMain();
	m_procTime += dt;
}
