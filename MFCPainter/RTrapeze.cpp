#include "pch.h"
#include "RTrapeze.h"
IMPLEMENT_SERIAL(RTrapeze, CObject, 1)

RTrapeze::RTrapeze() {}
RTrapeze::RTrapeze(CPoint p1, CPoint p2, BOOL b) : Trapeze(p1, p2, b) {}
RTrapeze::~RTrapeze() {}


void RTrapeze::Draw(CDC* dc)const
{
	CPen pen(PS_SOLID, Bold ? 7 : 2, FbgColor);
	CPen* oldPen = dc->SelectObject(&pen);
	CBrush brush(bgColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	CPoint midlleP((P1.x + P2.x) / 2, (P1.y + P2.y) / 2);
	CPoint point(P1.x - (P2.x - P1.x), P2.y), point2(P1.x + (P2.x - P1.x), P1.y);

	CPoint angle[] = { P1, point , P2 ,point2 };
	Trapeze::InnerDraw(angle, dc);
}