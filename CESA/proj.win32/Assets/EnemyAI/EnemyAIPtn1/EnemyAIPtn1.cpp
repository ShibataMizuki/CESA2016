#include "EnemyAIPtn1.h"
#include"GameObjectManager/GameObjectManager.h"
#include"GameObject/EnemyBullet/EnemyBullet.h"
#include"GameObject/PlayerPlane/PlayerPlane.h"
#include"MoveStrategy/MoveLinear/MoveLinear.h"
#include"SoundManager/SoundManager.h"
#include"Effect/EffectCircleSplash.h"
USING_NS_CC;

void EnemyAIPtn1::Move1(float dt)
{
	if (m_duration1 < m_prevShotDeltaTime)
	{
		m_prevShotDeltaTime = 0.f;
		m_state = STATE::ATTACK;
	}
	m_pTargetEnemy->setPosition(m_pTargetEnemy->getPosition() + m_dir1*m_speed1*dt);
}

void EnemyAIPtn1::Attack(float dt)
{
	if (m_duration2 < m_prevShotDeltaTime)
	{
		m_prevShotDeltaTime = 0.f;
		m_state = STATE::MOVE2;
	}
	if (m_flag)return;
	auto player = GameObjectManager::getInstance()->getPlayerPlane();
	if (player)
	{
		Vec2 dir = player->getPosition() - m_pTargetEnemy->getPosition();
		dir.normalize();
		auto bullet = EnemyBullet::create();
		bullet->setPosition(m_pTargetEnemy->getPosition());
		bullet->setMoveStrategy(std::make_shared<MoveLinear>(bullet, 300.f, dir));
	//	bullet->setShape(CircleShape::createSharedPtr(3.0f));
		GameObjectManager::getInstance()->addGameObject(bullet);
		m_flag = true;
	}
}

void EnemyAIPtn1::Move2(float dt)
{
	if (m_duration3 < m_prevShotDeltaTime)
	{
		m_prevShotDeltaTime = 0.f;
		m_state = STATE::END;
	}
	m_pTargetEnemy->setPosition(m_pTargetEnemy->getPosition() + m_dir2*m_speed2*dt);
}

void EnemyAIPtn1::End(float dt)
{
}

EnemyAIPtn1::EnemyAIPtn1(EnemyPlane* pTarget, const cocos2d::Vec2 & startPos, const cocos2d::Vec2 & attackPos, const cocos2d::Vec2 & endPos, float duration1, float duration2, float duration3) :
	EnemyAI(pTarget),
	m_state(STATE::MOVE1), m_prevShotDeltaTime(0), m_flag(false),
	m_startPos(startPos),m_attackPos(attackPos),m_endPos(endPos),
	m_duration1(duration1),m_duration2(duration2),m_duration3(duration3)
{
	m_dir1 = m_attackPos - m_startPos;
	m_dir1.normalize();

	m_dir2 = m_endPos - m_attackPos;
	m_dir2.normalize();

	m_speed1 = (m_attackPos - m_startPos).getLength() / m_duration1;
	m_speed2 = (m_endPos - m_attackPos).getLength() / m_duration3;
}

void EnemyAIPtn1::update(float dt)
{
	switch (m_state)
	{
		//ˆÚ“®ˆ—1
	case EnemyAIPtn1::STATE::MOVE1:
		Move1(dt);
		break;

		//UŒ‚ˆ—
	case EnemyAIPtn1::STATE::ATTACK:
		Attack(dt);
		break;

		//ˆÚ“®ˆ—2
	case EnemyAIPtn1::STATE::MOVE2:
		Move2(dt);
		break;

		//I—¹ˆ—
	case EnemyAIPtn1::STATE::END:
		End(dt);
		break;

	default:
		break;
	}

	if (SoundManager::getInstance()->isBeat(2))
	{
		auto effect = EffectCircleSplash::create();
		m_pTargetEnemy->addChild(effect);
	}

	m_prevShotDeltaTime += dt;
}
