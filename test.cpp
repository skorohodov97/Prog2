#include "pch.h"
#include<tchar.h> 
#include "gtest\gtest.h"
#include "../StaticLib1/Cycle.h"
TEST(CircleConstructor, DefaultConstructor)
{
	Prog2::Cycle a1;
	ASSERT_EQ(0, a1.getP().x);
	ASSERT_EQ(0, a1.getP().y);
	ASSERT_EQ(1, a1.getA());
}
TEST(CircleConstructor, InitConstructors)
{
	Prog2::Cycle a2(3);
	Prog2::Point p(2, 3);
	ASSERT_EQ(3, a2.getA());
	ASSERT_EQ(0, a2.getP().x);
	ASSERT_EQ(0, a2.getP().y);
	Prog2::Cycle a3(p, 8);
	ASSERT_EQ(2, a3.getP().x);
	ASSERT_EQ(3, a3.getP().y);
	ASSERT_EQ(8, a3.getA());
	Prog2::Cycle a4(-4, -5, 3);
	ASSERT_EQ(-4, a4.getP().x);
	ASSERT_EQ(-5, a4.getP().y);
	ASSERT_EQ(3, a4.getA());
}
TEST(CircleConstructor, TestException)
{
	Prog2::Point p;
	ASSERT_ANY_THROW(Prog2::Cycle(2, 5, -5));
	ASSERT_ANY_THROW(Prog2::Cycle(p, 0));
}
TEST(CircleMethods, Setters)

{
	Prog2::Cycle a;
	Prog2::Point p1(3, 2);
	a.setP(p1);
	ASSERT_EQ(3, a.getP().x);
	ASSERT_EQ(2, a.getP().y);
	Prog2::Point p2(-3, -2);
	a.setP(p2);
	ASSERT_EQ(-3, a.getP().x);
	ASSERT_EQ(-2, a.getP().y);
	a.setA(2);
	ASSERT_EQ(2, a.getA());
	ASSERT_ANY_THROW(a.setA(0));
}
TEST(CircleMethods, Parameters)
{
	Prog2::Cycle a1;
	const double  err = 0.0000001, err1 = 0.000001;
	ASSERT_NEAR(PI/2, a1.square(), err);
	ASSERT_NEAR(4 * PI, a1.surface(), err);
	ASSERT_NEAR(2 * PI/3, a1.volume(), err);
	ASSERT_NEAR(0.316719, a1.f(30).x,err1);
	ASSERT_NEAR(0.5, a1.f(30).y,0.1);
	ASSERT_NEAR(20.1383, a1.f(90).x, 0.0001);
	ASSERT_EQ(1, a1.f(90).y);
	ASSERT_ANY_THROW(a1.f(180));
	ASSERT_ANY_THROW(a1.f(0));
	ASSERT_EQ(0, a1.ark(90));
	ASSERT_ANY_THROW(a1.ark(180));
	ASSERT_ANY_THROW(a1.ark(0));
	ASSERT_NEAR(1, a1.rad(45),0.1);
	ASSERT_ANY_THROW(a1.rad(180));
	ASSERT_ANY_THROW(a1.rad(0));
	ASSERT_STREQ("x = 1.00cos(t)+1.00ln(tg(t/2))\ny = 1.00*sin(t)\n", a1.frm());
	Prog2::Cycle a2(1, 3, 2);
	ASSERT_NEAR(PI*2, a2.square(), err);
	ASSERT_NEAR(16 * PI, a2.surface(), err);
	ASSERT_NEAR(16.7551608, a2.volume(), err);
	ASSERT_NEAR(1.63344, a2.f(30).x,0.00001);
	ASSERT_NEAR(4, a2.f(30).y,0.1);
	ASSERT_NEAR(41.2766, a2.f(90).x, 0.0001);
	ASSERT_EQ(5, a2.f(90).y);
	ASSERT_ANY_THROW(a2.f(180));
	ASSERT_ANY_THROW(a2.f(0));
	ASSERT_EQ(0, a2.ark(90));
	ASSERT_ANY_THROW(a2.ark(180));
	ASSERT_ANY_THROW(a2.ark(0));
	ASSERT_NEAR(2, a2.rad(45),0.1);
	ASSERT_ANY_THROW(a2.rad(180));
	ASSERT_ANY_THROW(a2.rad(0));
	ASSERT_STREQ("(x - 1.00) = 2.00cos(t)+2.00ln(tg(t/2))\n(y - 3.00) = 2.00*sin(t)\n", a2.frm());
}
int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
