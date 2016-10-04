#include "CollisionDetection.h"
#include"CSCircle/CSCircle.h"
#include"CSPolygon/CSPolygon.h"

bool CircleToCircle(CSCircle* shapeA,CSCircle* shapeB, const CSVec2& posA, const CSVec2& posB)
{
	float x = posA.x - posB.x;
	float y = posA.y - posB.y;
	float r = shapeA->getRadius() + shapeB->getRadius();
	return x*x + y*y <= r*r;
}
bool CircleToPolygon(CSCircle* circle, CSPolygon* polygon, const CSVec2& posA, const CSVec2& posB)
{
	return false;
}

bool PolygonToPolygon(CSPolygon* polygonA, CSPolygon* polygonB, const CSVec2& posA, const CSVec2& posB)
{
	return false;
}

bool CollisionDetection(CSShape* shapeA,CSShape* shapeB, const CSVec2 & posA, const CSVec2 & posB)
{
	//‰~‘Î‰~‚Ì”»’è
	if (typeid(*shapeA) == typeid(CSCircle) && typeid(*shapeB) == typeid(CSCircle))
		return CircleToCircle(dynamic_cast<CSCircle*>(shapeA), dynamic_cast<CSCircle*>(shapeB), posA, posB);
	
	//‰~‘Î‘½ŠpŒ`‚Ì”»’è1
	if (typeid(*shapeA) == typeid(CSCircle) && typeid(*shapeB) == typeid(CSPolygon))
		return CircleToPolygon(dynamic_cast<CSCircle*>(shapeA), dynamic_cast<CSPolygon*>(shapeB), posA, posB);
	
	//‰~‘Î‘½ŠpŒ`‚Ì”»’è2
	if (typeid(*shapeA) == typeid(CSPolygon) && typeid(*shapeB) == typeid(CSCircle))
		return CircleToPolygon(dynamic_cast<CSCircle*>(shapeB), dynamic_cast<CSPolygon*>(shapeA), posB, posA);

	//‘½ŠpŒ`‘Î‘½ŠpŒ`‚Ì”»’è
	if (typeid(*shapeA) == typeid(CSPolygon) && typeid(*shapeB) == typeid(CSPolygon))
		return PolygonToPolygon(dynamic_cast<CSPolygon*>(shapeA), dynamic_cast<CSPolygon*>(shapeB), posA, posB);

	return false;
}
