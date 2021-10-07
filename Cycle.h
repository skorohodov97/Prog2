#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <math.h>
#include <cmath>                                       
#define PI 3.14159265 
namespace Prog2 {
	
	struct Point {
		double x, y; 
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};
	
	class Cycle {
	private:
		Point p;
		double a;
	public:
		Cycle(double ad = 1);
		Cycle(const Point &p0, double ad = 1);
		Cycle(double x0, double y0, double ad = 1);
		Cycle& setP(const Point &p0) { p = p0; return *this; }
		Cycle& setA(double a0);
		Point getP() const { return p; }
		double getA() const { return a; }
		double ark(double t) const; //длинна дуги
		double rad(double t) const; //радиус кривизны
		Point f(double t) const; //координаты точки
		double square() const { return PI * a*a / 2; }//площадь бесконечной полосы
		double surface() const { return 4 * PI*a*a; }//поверхность тела вращения
		double volume() const { return 2 * PI*a*a*a / 3; }//объем тела вращения
		char *frm() const; 
	};
}
#endif
