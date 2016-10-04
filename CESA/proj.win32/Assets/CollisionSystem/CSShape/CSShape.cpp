#include "CSShape.h"

CSShape::CSShape(const CSVec2 & pos) :
	m_position(pos)
{
}

void CSShape::setPosition(const CSVec2 & pos)
{
	m_position = pos;
}

const CSVec2 & CSShape::getPosition() const
{
	return m_position;
}
