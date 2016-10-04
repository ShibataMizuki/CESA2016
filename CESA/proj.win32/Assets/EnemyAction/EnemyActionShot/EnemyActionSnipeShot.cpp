#include "EnemyActionSnipeShot.h"
#include"inc/GameObjects.h"
#include"MoveStrategy/MoveStrategyFactory.h"
#include"Utils/Utils.h"
#include"SoundManager/SoundManager.h"
#include"GameObject/GameObjectFactory.h"
#include"CollisionSystem/CSShape/CSCircle/CSCircle.h"
USING_NS_CC;

EnemyActionSnipeShot::EnemyActionSnipeShot(EnemyPlane * pTarget, float duration, float shotInterVal, float bulletSpeed) :
	EnemyAction(pTarget, duration),
	m_bulletSpeed(bulletSpeed),
	m_shotInterval(shotInterVal)
{
	m_timer = 0.f;
	m_shotInterval = 0.5f;
}

void EnemyActionSnipeShot::init()
{
}

bool EnemyActionSnipeShot::update(float dt)
{
	
	if (SoundManager::getInstance()->isBeat(m_beatIndex))
	{
		m_timer = 0.f;
		auto objMng = GameObjectManager::getInstance();
		auto player = objMng->getPlayerPlane();

		if (!objMng->isArrive(player))return isFinished(dt);

		auto bullet = EnemyBullet::create();
		bullet->setPosition(m_pTargetEnemy->getPosition());

		Vec2 dir = player->getPosition() - bullet->getPosition();
		dir.normalize();

		auto move = MoveStrategyFactory::createMoveLinear(bullet, m_bulletSpeed, dir);
		bullet->setMoveStrategy(move);
		//bullet->setShape(CircleShape::createSharedPtr(10.f));
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(10.f));
		body->setCollisionGroup((int)ObjectType::EnemyBullet);
		bullet->setBody(body);
		objMng->addGameObject(bullet);
	}
	

	m_timer += dt;

	return isFinished(dt);
}

void EnemyActionSnipeShot::setBeatIndex(int index)
{
	m_beatIndex = index;
}
