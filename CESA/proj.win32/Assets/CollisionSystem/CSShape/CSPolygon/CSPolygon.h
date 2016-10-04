#pragma once

#include"../CSShape.h"
#include<vector>

class CSPolygon :public CSShape
{
protected:
	//! 頂点リスト
	std::vector<CSVec2> m_vertexes;

public:
	/*==============================
	コンストラクタ
	===============================*/
	CSPolygon();
	CSPolygon(const std::vector<CSVec2>& vertexes);
};