#pragma once

constexpr float EPS = (float)1e-9;

struct CSVec2
{
	//! X要素,Y要素
	float x, y;

	/*==============================
	コンストラクタ
	===============================*/
	CSVec2();
	CSVec2(float x, float y);

	/*==============================
	オペレータのオーバーロード
	===============================*/
	const CSVec2& operator+(const CSVec2& rv);
	const CSVec2& operator-(const CSVec2& rv);
	const CSVec2& operator*(float rv);
	const CSVec2& operator/(float rv);

	//! ベクトルの長さを算出
	float getLength()const;
	//! ベクトルを正規化
	void normalize();
	//! 正規化したベクトルを取得
	CSVec2 getNormalized()const;
	//! ベクトルの内積
	float dot(const CSVec2& rv)const;
	//! ベクトルの外積
	float cross(const CSVec2& rv)const;

	////////////////////////////////////////
	//! ベクトルの内積
	static constexpr float calcDot(const CSVec2& lv, const CSVec2& rv);
	//! ベクトルの外積
	static constexpr float calcCross(const CSVec2& lv, const CSVec2& rv);
	//! ベクトルの直交判定
	static constexpr bool isOrthogonal(const CSVec2& lv, const CSVec2& rv);
	//! ベクトルの平行判定
	static constexpr bool isParallel(const CSVec2& lv, const CSVec2& rv);
};