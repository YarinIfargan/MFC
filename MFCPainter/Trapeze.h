#pragma once
#include "Figure.h"
class Trapeze : public Figure
{
public:
	DECLARE_SERIAL(Trapeze)
	Trapeze();
	Trapeze(CPoint p1, CPoint p2, BOOL b);
	~Trapeze();
	void Draw(CDC* dc) const;
	void InnerDraw(CPoint* TrapezePoints, CDC* dc) const;

};
