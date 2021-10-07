#include<tchar.h> 
#include <iostream>
#include "../StaticLib1/Cycle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Prog2::Cycle c(2, 1, 2);
	Prog2::Point p;
	int fl1 = 1;
	double a;
	char *s = NULL;
	while (fl1) {
		std::cout << "Your traktris is:" << std::endl;
		s = c.frm();
		std::cout << s << std::endl;
		delete[] s;
		std::cout << "square: " << c.square() << std::endl;
		std::cout << "surface: " << c.surface() << std::endl;
		std::cout << "volume: " << c.volume() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter the angle t in degrees to calculate the values of y(t) and x(t) or press ctrl + Z to exit:" <<
				std::endl;
			double t;
			Prog2::Point y;
			
			std::cin >> t;
			fl2 = std::cin.good();
			if (!fl2) {
				continue;
			}
			try {
				y = c.f(t);
				std::cout << "x = " << y.x << ", y = " << y.y << std::endl;
				std::cout << "ark: " << c.ark(t) << std::endl;
				std::cout << "rad: " << c.rad(t) << std::endl;
			}


				catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Enter new x, y and a to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> p.x >> p.y >> a;
		if (std::cin.good()) {
			c.setP(p);
			try {
				c.setA(a);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		else
			fl1 = 0;
	}
	return 0;
}
