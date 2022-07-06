#include "pch.h"
#include "Hexagonal.h"

IMPLEMENT_SERIAL(Hexagonal, CObject, 1)

Hexagonal::Hexagonal() {}
Hexagonal::Hexagonal(CPoint p1, CPoint p2, BOOL b) : Figure(p1, p2, b){}
Hexagonal::~Hexagonal() {}

void Hexagonal::Draw(CDC* dc) const
{
	CPen pen(PS_SOLID, Bold ? 7 : 2, FbgColor);
	CPen* oldPen = dc->SelectObject(&pen);
	CBrush brush(bgColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	CPoint hexagonalPoints[6];
	hexagonalPoints[0].SetPoint(P1.x, P2.y);
	hexagonalPoints[1].SetPoint(P2.x, P2.y);
	hexagonalPoints[2].SetPoint(P2.x + (P2.x - P1.x), (P2.y + P1.y) * 0.5);
	hexagonalPoints[3].SetPoint(P2.x, P1.y);
	hexagonalPoints[4].SetPoint(P1.x, P1.y);
	hexagonalPoints[5].SetPoint(P1.x - (P2.x - P1.x), (P2.y + P1.y) * 0.5);
	dc->Polygon(hexagonalPoints, 6);
}