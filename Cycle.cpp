#include "pch.h"
#include "framework.h"
#include "Cycle.h"
#include <strstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>                                       
#define PI 3.14159265 
namespace Prog2 {
	
	Cycle::Cycle(double ad) :p(0, 0)
		
	{
		if (ad <= 0)
			throw std::exception("disconnected height");
		a = ad;
	}
	Cycle::Cycle(const Point &p0, double ad) :p(p0) 
	{
		if (ad <= 0)
			throw std::exception("disconnected height");
		a = ad;
	}
	Cycle::Cycle(double x0, double y0, double ad) :p(x0, y0) 
		
	{
		if (ad <= 0)
			throw std::exception("disconnected height");
		a = ad;
	}
	Cycle& Cycle::setA(double a0)
	{
		if (a0 <= 0)
			throw std::exception("disconnected height");
		a = a0;
		return *this;
	}
	Point Cycle::f(double t) const 
	{
		if (t <= 0||t>=180)
			throw std::exception("illegal argument t");
		double cs = cos(t* PI / 180);
		double sn = sin(t* PI / 180);
		double tg = tan(t* PI / 180);
		tg = std::log(tg);
		Point res;
		res.x = p.x + a*cs+a*tg;
		res.y = p.y + a*sn;
		return res;
	}
	double Cycle::ark(double t) const 
	{ 
		if (t <= 0 || t >= 180)
			throw std::exception("illegal argument t");
		return a * std::log(1 / sin(t* PI / 180)); 
	}
	double Cycle::rad(double t) const 
	{ 
		if (t <= 0 || t >= 180)
			throw std::exception("illegal argument t");
		return a / tan(t* PI / 180); 
	}
	char *Cycle::frm() const 
	{

		const char *s1 = "(x - ) = *cos(t)+ *ln(tg(t/2))\n(y- )= *sin(t)\n"; 
		int l = strlen(s1) + 1; 
		size_t Size = 20;
		char num[20];
		sprintf_s(num, 20, "%.2f", p.x); 
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.y); 
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", a); 
		l=l+3*strlen(num);
		
		char *s = new char[l];
		
		if (p.x == 0)
			sprintf_s(s, l, "x");
		else
			sprintf_s(s, l, "(x - %.2f)", p.x);
		int k = strlen(s);
		sprintf_s(s + k, l - k, " = %.2fcos(t)+%.2fln(tg(t/2))\n",a,a);
		k = strlen(s);
		if (p.y == 0)
			sprintf_s(s + k, l - k, "y");
		else
			sprintf_s(s + k, l - k, "(y - %.2f)", p.y);
		k = strlen(s);
		sprintf_s(s + k, l - k, " = %.2f*sin(t)\n", a);
		return s;
	}
}
