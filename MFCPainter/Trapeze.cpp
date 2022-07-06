#include "pch.h"
#include "Trapeze.h"
IMPLEMENT_SERIAL(Trapeze, CObject, 1)

Trapeze::Trapeze() {}

Trapeze::Trapeze(CPoint p1, CPoint p2, BOOL b)
	:Figure(p1, p2, b) {}

Trapeze::~Trapeze() {}

void Trapeze::Draw(CDC* dc)const
{
	CPen pen(PS_SOLID, Bold ? 7 : 2, FbgColor);
	CPen* oldPen = dc->SelectObject(&pen);
	CBrush brush(bgColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	CPoint TrapezePoints[4];
	TrapezePoints[0].SetPoint(P1.x, P2.y);
	TrapezePoints[1].SetPoint(P2.x, P2.y);
	TrapezePoints[2].SetPoint((P2.x - P1.x) * 3 / 4 + P1.x, P1.y);
	TrapezePoints[3].SetPoint((P2.x - P1.x) * 1 / 4 + P1.x, P1.y);
	InnerDraw(TrapezePoints, dc);
}

void Trapeze::InnerDraw(CPoint* TrapezePoints, CDC* dc)const
{
	CBrush brush;
	CBrush* oldBrush = dc->SelectObject(&brush);
	dc->Polygon(TrapezePoints, 4);
}
