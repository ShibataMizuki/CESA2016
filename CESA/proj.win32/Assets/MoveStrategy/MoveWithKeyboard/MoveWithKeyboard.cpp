#include "MoveWithKeyboard.h"
#include"GameObject/GameObject.h"

USING_NS_CC;

MoveWithKeyboard::MoveWithKeyboard(GameObject * pTargetObject, float moveSpeed) :
	MoveStrategy(pTargetObject),
	m_moveSpeed(moveSpeed),
	m_pressAFlag(false),
	m_pressDFlag(false),
	m_pressSFlag(false),
	m_pressWFlag(false)
{
	m_pListenerKeyboard = EventListenerKeyboard::create();
	m_pListenerKeyboard->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_W:
			m_pressWFlag = true;
			break;
		case EventKeyboard::KeyCode::KEY_A:
			m_pressAFlag = true;
			break;
		case EventKeyboard::KeyCode::KEY_S:
			m_pressSFlag = true;
			break;
		case EventKeyboard::KeyCode::KEY_D:
			m_pressDFlag = true;
			break;
		}
	};

	m_pListenerKeyboard->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_W:
			m_pressWFlag = false;
			break;
		case EventKeyboard::KeyCode::KEY_A:
			m_pressAFlag = false;
			break;
		case EventKeyboard::KeyCode::KEY_S:
			m_pressSFlag = false;
			break;
		case EventKeyboard::KeyCode::KEY_D:
			m_pressDFlag = false;
			break;
		}
	};

	m_pTargetObject->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_pListenerKeyboard, m_pTargetObject);
}

MoveWithKeyboard::~MoveWithKeyboard()
{
	m_pTargetObject->getEventDispatcher()->removeEventListener(m_pListenerKeyboard);
}

void MoveWithKeyboard::update(float delta)
{
	//ŽÎ‚ßˆÚ“®‚ÉŠ|‚¯‚éŒW”
	static const float coef = 1.f / sqrtf(2.f);

	//¶ãŽÎ‚ßˆÚ“®
	if (this->m_pressWFlag&&this->m_pressAFlag)
	{
		Vec2 vel = Vec2(-m_moveSpeed*coef, m_moveSpeed*coef);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//‰EãŽÎ‚ßˆÚ“®
	else if (this->m_pressWFlag&&this->m_pressDFlag)
	{
		Vec2 vel = Vec2(m_moveSpeed*coef, m_moveSpeed*coef);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//¶‰ºŽÎ‚ßˆÚ“®
	else if (this->m_pressSFlag&&this->m_pressAFlag)
	{
		Vec2 vel = Vec2(-m_moveSpeed*coef, -m_moveSpeed*coef);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//‰E‰ºŽÎ‚ßˆÚ“®
	else if (this->m_pressSFlag&&this->m_pressDFlag)
	{
		Vec2 vel = Vec2(m_moveSpeed*coef, -m_moveSpeed*coef);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//ãˆÚ“®
	else if (this->m_pressWFlag)
	{
		Vec2 vel = Vec2(0.f, m_moveSpeed);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//‰ºˆÚ“®
	else if (this->m_pressSFlag)
	{
		Vec2 vel = Vec2(0.f, -m_moveSpeed);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//¶ˆÚ“®
	else if (this->m_pressAFlag)
	{
		Vec2 vel = Vec2(-m_moveSpeed, 0.f);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	//‰EˆÚ“®
	else if (this->m_pressDFlag)
	{
		Vec2 vel = Vec2(m_moveSpeed, 0.f);
		m_pTargetObject->setPosition(m_pTargetObject->getPosition() + vel);
	}

	Size winSize = Director::getInstance()->getVisibleSize();
	Rect bb = m_pTargetObject->getBoundingBox();

	if (bb.getMinX() < 0)
	{
		m_pTargetObject->setPosition((bb.getMaxX() - bb.getMinX()) / 2.f, m_pTargetObject->getPosition().y);
	}

	if (bb.getMaxX() > winSize.width)
	{
		m_pTargetObject->setPosition(winSize.width - (bb.getMaxX() - bb.getMinX()) / 2.f,
			m_pTargetObject->getPosition().y);
	}

	if (bb.getMinY() < 0)
	{
		m_pTargetObject->setPosition(m_pTargetObject->getPosition().x,
			(bb.getMaxY() - bb.getMinY()) / 2.f);
	}
	
	if (bb.getMaxY() > winSize.height)
	{
		m_pTargetObject->setPosition(m_pTargetObject->getPosition().x,
			winSize.height - (bb.getMaxY() - bb.getMinY()) / 2.f);
	}
}
