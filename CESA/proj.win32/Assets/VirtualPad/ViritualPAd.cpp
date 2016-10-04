#include"VirtualPad/ViritualPad.h"
#include"GameObjectManager/GameObjectManager.h"
#include"inc/GameObjects.h"
#include"DebugNode/DebugNode.h"

USING_NS_CC;

bool VirtualPad::init()
{
	if (!Node::init())return false;
	auto spr = Sprite::create("note.png");
	addChild(spr);
	spr->setOpacity(64);
	m_pSprite = Sprite::create("note.png");
	addChild(m_pSprite);
	m_pSprite->setScale(0.5f);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = std::bind(&VirtualPad::onTouchBegin,this, std::placeholders::_1, std::placeholders::_2);
	listener->onTouchMoved = std::bind(&VirtualPad::onTouchMoved,this, std::placeholders::_1, std::placeholders::_2);
	listener->onTouchEnded = std::bind(&VirtualPad::onTouchEnded,this, std::placeholders::_1, std::placeholders::_2);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();
	m_isMove = false;

	return true;
}

void VirtualPad::update(float dt)
{
	if (m_isMove)
	{
		this->onTouchMoving(dt);
	}
	String str;
	str.initWithFormat("distance:%.2f", m_distance);
	DebugStringNode::getInstance()->printDebugString(str._string);
}

void VirtualPad::setSprite(cocos2d::Sprite * pSprite)
{
	m_pSprite = pSprite;
}

cocos2d::Sprite * VirtualPad::getSprite() const
{
	return m_pSprite;
}

bool VirtualPad::onTouchBegin(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Vec2 localPos = this->convertToNodeSpace(touch->getLocation());
	if (m_pSprite->getBoundingBox().containsPoint(localPos))return true;
	return false;
}

void VirtualPad::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Vec2 localPos = this->convertToNodeSpace(touch->getLocation());
	Vec2 dir = localPos;
	dir.normalize();
	m_distance = localPos.getLength();

	if (m_distance < 99.f)
	{
		m_pSprite->setPosition(localPos);
	}
	else
	{
		m_pSprite->setPosition(100.f*dir);
		m_distance = 100.f;
	}

	m_moveDir = m_pSprite->getPosition();
	m_moveDir.normalize();

	m_isMove = true;
}

void VirtualPad::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	m_pSprite->setPosition(0.f, 0.f);
	m_isMove = false;
}

void VirtualPad::onTouchMoving(float dt)
{
	auto player = GameObjectManager::getInstance()->getPlayerPlane();
	player->setPosition(player->getPosition() + m_distance*m_moveDir*dt*5.f);
}
