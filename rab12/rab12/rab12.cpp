// rab12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


struct Point
{
	double x;
	double y;

};
struct Side
{
	Point p1;
	Point p2;
};
class Quadr // имя класса
{
protected: // спецификатор доступа protected
	Side s1;
	Side s2;
private:
	Side s3;
	Side s4;
public: // спецификатор доступа public
	Quadr()
	{
		Side s11, s21, s31, s41;
		Point p1,p2,p3,p4;
		p1.x = 0; p1.y = 0;
		p2.x = 0; p2.y = 100;
		p3.x = 100; p3.y = 100;
		p4.x = 100; p4.y = 0;
		s11.p1 = p1; s11.p2 = p2;
		s21.p1 = p1; s21.p2 = p4;
		s31.p1 = p3; s31.p2 = p4;
		s41.p1 = p2; s41.p2 = p3;
	}
	Quadr(Side s11, Side s21, Side s31, Side s41) // конструктор класса
	{
		s1 = s11;
		s2 = s21;
		s3 = s31;
		s4 = s41;
	}
	virtual double Size_s(Side s11)
	{
		return sqrt((s11.p1.x - s11.p2.x)*(s11.p1.x - s11.p2.x) + (s11.p1.y - s11.p2.y)*(s11.p1.y - s11.p2.y));
	}
	
	virtual double perimeter()
	{
		return Size_s(s1) + Size_s(s2) + Size_s(s3) + Size_s(s4);
	}

};
class Rect :public Quadr
{
public:
	Rect()
	{
		Side s11, s21;
		Point p1, p2, p3;
		p1.x = 0; p1.y = 0;
		p2.x = 0; p2.y = 100;
		p3.x = 100; p3.y = 100;
		s11.p1 = p1; s11.p2 = p2;
		s21.p1 = p1; s21.p2 = p3;
	}
	Rect(Side s11, Side s21)
	{
		s1 = s11;
		s2 = s21;
	}
	double perimeter()
	{ 
		return Size_s(s1) * 2 + Size_s(s2) * 2;
	}
	
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Quadr *p;
	
	Side s1, s2, s3, s4;
	Point p1, p2, p3, p4;
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 100;
	p3.x = 200; p3.y = 200;
	p4.x = 100; p4.y = 0;
	s1.p1 = p1; s1.p2 = p2;
	s2.p1 = p1; s2.p2 = p4;
	s3.p1 = p3; s3.p2 = p4;
	s4.p1 = p2; s4.p2 = p3;
	Quadr q1(s1,s2,s3,s4);
	Rect r(s1,s2);
	p = &q1;
	cout << "Периметр четырехугольника - " << (p->perimeter());
	p = &r;
	cout << "\nПериметр прямоугольника - " << (p->perimeter())<<"\n";
	system("pause");
    return 0;
}

