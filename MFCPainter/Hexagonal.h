#pragma once
#include "Figure.h"
class Hexagonal : public Figure
{
public:
	DECLARE_SERIAL(Hexagonal)
	Hexagonal();
	Hexagonal(CPoint p1, CPoint p2, BOOL b);
	~Hexagonal(void);
	void Draw(CDC* dc)const;
};