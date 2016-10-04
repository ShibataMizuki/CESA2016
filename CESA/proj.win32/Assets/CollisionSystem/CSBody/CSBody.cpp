#include "CSBody.h"

CSBody::CSBody() :
	m_pos(), m_angle(0.f), m_collisionGroup(-1), m_pUserData(nullptr)
{
}

void CSBody::setPosition(const CSVec2 & pos)
{
	m_pos = pos;
}

const CSVec2 & CSBody::getPosition() const
{
	return m_pos;
}

void CSBody::setAngle(float angle)
{
	m_angle = angle;
}

float CSBody::getAngle() const
{
	return m_angle;
}

void CSBody::addShape(const std::shared_ptr<CSShape>& pShape)
{
	m_shapeList.push_back(pShape);
}

const std::list<std::shared_ptr<CSShape>>& CSBody::getShapeList() const
{
	return m_shapeList;
}

std::list<std::shared_ptr<CSShape>>::iterator CSBody::getShapeBegin()
{
	return m_shapeList.begin();
}

std::list<std::shared_ptr<CSShape>>::iterator CSBody::getShapeEnd()
{
	return m_shapeList.end();
}

void CSBody::setCollisionGroup(int group)
{
	m_collisionGroup = group;
}

int CSBody::getCollisionGroup() const
{
	return m_collisionGroup;
}

void CSBody::setTag(const std::string & tag)
{
	m_tag = tag;
}

std::string CSBody::getTag() const
{
	return m_tag;
}

void CSBody::setUserData(void * pUserData)
{
	m_pUserData = pUserData;
}

void * CSBody::getUserData() const
{
	return m_pUserData;
}

std::shared_ptr<CSBody> CSBody::createShared(const CSVec2 & pos)
{
	auto body = std::make_shared<CSBody>();
	body->m_pos = pos;
	return body;
}

std::shared_ptr<CSBody> CSBody::createShared()
{
	return std::make_shared<CSBody>();
}
