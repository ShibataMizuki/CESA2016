#include "CSCircle.h"

using namespace std;

CSCircle::CSCircle() :
	m_radius(0.f)
{
}

CSCircle::CSCircle(float radius) :
	m_radius(radius)
{
}

CSCircle::CSCircle(const CSVec2 & pos, float radius) :
	CSShape(pos), m_radius(radius)
{
}

void CSCircle::setRadius(float radius)
{
	m_radius = radius;
}

float CSCircle::getRadius() const
{
	return m_radius;
}

std::shared_ptr<CSCircle> CSCircle::createShared()
{
	return make_shared<CSCircle>();
}

std::shared_ptr<CSCircle> CSCircle::createShared(float radius)
{
	return make_shared<CSCircle>(radius);
}

std::shared_ptr<CSCircle> CSCircle::createShared(const CSVec2 & pos, float radius)
{
	return make_shared<CSCircle>(pos, radius);
}
