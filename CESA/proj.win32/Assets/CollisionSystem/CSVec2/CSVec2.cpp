#include "CSVec2.h"
#include<cmath>
#include<iostream>

CSVec2::CSVec2() :
	x(0.f), y(0.f)
{
}

CSVec2::CSVec2(float x, float y) :
	x(x), y(y)
{
}

const CSVec2 & CSVec2::operator+(const CSVec2 & rv)
{
	return CSVec2(x + rv.x, y + rv.y);
}

const CSVec2 & CSVec2::operator-(const CSVec2 & rv)
{
	return CSVec2(x - rv.x, y - rv.y);
}

const CSVec2 & CSVec2::operator*(float rv)
{
	return CSVec2(x*rv, y*rv);
}

const CSVec2 & CSVec2::operator/(float rv)
{
	return CSVec2(x / rv, y / rv);
}

float CSVec2::getLength() const
{
	return sqrtf(x*x + y*y);
}

void CSVec2::normalize()
{
	float length = getLength();
	x /= length;
	y /= length;
}

CSVec2 CSVec2::getNormalized() const
{
	float length = getLength();
	return std::move(CSVec2(x / length, y / length));
}

float CSVec2::dot(const CSVec2 & rv) const
{
	return x*rv.x + y*rv.y;
}

float CSVec2::cross(const CSVec2 & rv) const
{
	return x*rv.y - y*rv.x;
}

constexpr float CSVec2::calcDot(const CSVec2 & lv, const CSVec2 & rv)
{
	return lv.x*rv.x + lv.y*rv.x;
}

constexpr float CSVec2::calcCross(const CSVec2 & lv, const CSVec2 & rv)
{
	return lv.x*rv.y - lv.y*rv.x;
}