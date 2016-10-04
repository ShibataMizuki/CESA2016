#include "EnemyActionSplashShot.h"
#include"GameObject/PlayerPlane/PlayerPlane.h"
#include"GameObject/EnemyPlane/EnemyPlane.h"
#include"GameObject/EnemyBullet/EnemyBullet.h"
#include"MoveStrategy/MoveStrategyFactory.h"
#include"GameObjectManager/GameObjectManager.h"
#include"SoundManager/SoundManager.h"
#include"Utils/Utils.h"
#include"CollisionSystem/CSShape/CSCircle/CSCircle.h"

EnemyActionSplashShot::EnemyActionSplashShot(EnemyPlane * pTarget, float duration, float shotIntervel,
	float wide, float bulletSpeed) :
	EnemyAction(pTarget, duration),
	m_shotInterval(shotIntervel), m_wide(wide), m_bulletSpeed(bulletSpeed),
	m_timer(0.f)
{
}

void EnemyActionSplashShot::init()
{
}

bool EnemyActionSplashShot::update(float dt)
{
	if (SoundManager::getInstance()->isBeat(m_beatIndex))
	{
		m_timer = 0.f;
		auto bullet = EnemyBullet::create();
		bullet->setPosition(m_pTargetEnemy->getPosition());
		auto player = GameObjectManager::getInstance()->getPlayerPlane();

		if (!GameObjectManager::getInstance()->isArrive(player))return isFinished(dt);

		float angle = cocos2d::random(-(m_wide / 2.f), m_wide / 2.f) + (player->getPosition() - bullet->getPosition()).getAngle();
		auto move = MoveStrategyFactory::createMoveLinear(bullet, m_bulletSpeed, Util::convertToDirection(angle));
		bullet->setMoveStrategy(move);
		GameObjectManager::getInstance()->addGameObject(bullet);
		//bullet->setShape(CircleShape::createSharedPtr(10.f));
		auto body = CSBody::createShared();
		body->addShape(CSCircle::createShared(10.f));
		body->setCollisionGroup((int)ObjectType::EnemyBullet);
		bullet->setBody(body);

	}
	m_timer += dt;
	return isFinished(dt);
}

void EnemyActionSplashShot::setBeatIndex(int index)
{
	m_beatIndex = index;
}
