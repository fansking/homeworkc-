#include <iostream>
#include "myclass.h"

using namespace std;

int P6_1()
{
	Circle_1 Cir1(10, 100, 200);
	Cir1.ShowCircle();
	cout << "area is: " << Cir1.area() << endl;
	Cir1.move(10, 20);
	Cir1.ShowXY();
	return 0;
}

int P6_2()
{
	Cylinder CY(100, 200, 10, 50);
	CY.ShowCylinder();
	cout << "total area:" << CY.area() << endl;
	cout << "volume:" << CY.volume();
	return 0;
}

int P6_3()
{
	tube TU(100, 20, 5);
	return 0;
}

int P6_4()
{
	Point_1 P(1, 1);
	Circle_1 Cir(20, 20, 15.5);
	Cylinder_2 CY(300, 300, 15.5, 50);
	Point_1 * Pp;
	Pp = &P;
	Pp->ShowXY();
	Pp = &Cir;
	Pp->ShowXY();
	Pp = &CY;
	Pp->ShowXY();
	Circle_1 & RC = CY;
	RC.ShowXY();
	P = Cir;
	P.ShowXY();
	return 0;
}

int P6_5()
{
	StationWagon SW(105, 3, 8);
	SW.ShowSW();
	return 0;
}

int P6_6()
{
	StationWagon_2 SW(105, 108, 3, 8);
	SW.show();
	return 0;
}

int P6_7()
{
	StationWagon_3 SW(105, 108, 3, 8);
	SW.show();
	return 0;
}
int p6()
{
	P6_1();
	P6_2();
	P6_3();
	P6_4();
	P6_5();
	P6_6();
	P6_7();
	return 0;
}