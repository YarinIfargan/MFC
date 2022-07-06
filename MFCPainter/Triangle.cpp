#include "pch.h"
#include "Triangle.h"

IMPLEMENT_SERIAL(Triangle, CObject, 1)

void Triangle::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << P3;
		ar << bgColor;
		ar << FbgColor;
		ar << Bold;
	}
	else
	{
		ar >> P1;
		ar >> P2;
		ar >> P3;
		ar >> bgColor;
		ar >> FbgColor;
		ar >> Bold;
	}
}

Triangle::Triangle(CPoint p1, CPoint p2, BOOL b) :Figure(p1, p2, b) {
	P3.x = p1.x;
	P3.y = p1.y;
}

void Triangle::Shape_Draw(CDC* dc) const {
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPoint p3 = getP3();

	CPoint TPoints[3] = { p1,p2,p3 };

	dc->Polygon(TPoints, 3);
}

void Triangle::Redefine(CPoint start, CPoint end) {
	Figure::Redefine(start, end);

	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPoint p3;

	p3.x = abs(p2.x + p1.x) / 2;
	p3.y = p2.y;

	setP2(p2.x, p1.y);
	setP3(p3.x, p3.y);
}

bool Triangle::isInside(const CPoint &P) const { 
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPoint p3 = getP3();
	int d1, d2, d3;
	bool neg, pos;

	d1 = (P.x - p2.x) * (p1.y - p2.y) - (p1.x - p2.x) * (P.y - p2.y);
	d2 = (P.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (P.y - p3.y);
	d3 = (P.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (P.y - p1.y);

	neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(neg && pos);
}

void Triangle::Shift(CPoint c1, CPoint c2)
{
	CPoint p3 = getP3();
	p3.x += (c1.x - c2.x);
	p3.y += (c1.y - c2.y);
	setP3(p3.x, p3.y);

	Figure::Shift(c1, c2);
}