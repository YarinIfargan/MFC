#pragma once  
#include "Trapeze.h"
class RTrapeze :public Trapeze {
public:
	DECLARE_SERIAL(RTrapeze)

	RTrapeze();
	RTrapeze(CPoint p1, CPoint p2, BOOL b);
	~RTrapeze();

	void Draw(CDC* dc)const;
	void InnerDraw(CPoint* TrapezePoints, CDC* dc)const;
};