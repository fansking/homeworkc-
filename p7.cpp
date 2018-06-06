#include <iostream>
#include "myclass.h"
using namespace std;
Complex operator -(Complex A, Complex B)
{
	return Complex(A.real - B.real, A.image - B.image);
}
Complex operator -(Complex A)
{
	return Complex(-A.real, -A.image);
}
Complex operator ++(Complex &A)
{

	return Complex(++A.real, A.image);
}
Complex operator ++(Complex &A, int)
{
	return Complex(A.real++, A.image);
}
int p7_1()
{
	Complex A(100.0, 200.0), B(-10.0, 20.0), C;
	cout << "A=",A.display();
	cout << "B=", B.display();
	C = B + A;
	cout << "C=A+B=", C.display();
	C = A - B;
	cout << "C=A-B=", C.display();
	C = -A + B;
	cout << "C=-A+B=", C.display();
	C = A++;
	cout << "C=A++", C.display();
	C = ++A;
	cout << "C=++A", C.display();
	C = A + 5;
	C.display();
	return 0;
}
Complex_1 Complex_1::operator+(Complex_1 B)
{
	return Complex_1(real + B.real, image + B.image);
}
Complex_1 Complex_1::operator-(Complex_1 B)
{
	return Complex_1(real - B.real, image - B.image);
}
Complex_1 Complex_1::operator-()
{
	return Complex_1(-real , -image );
}
Complex_1 Complex_1::operator++()
{
	return Complex_1(++real, image);
}
Complex_1 Complex_1::operator++(int)
{
	return Complex_1(real++, image);
}
int p7_2()
{
	Complex_1 A(100.0, 200.0), B(-10.0, 20.0), C;
	cout << "A=", A.display();
	cout << "B=", B.display();
	C = A + B;
	cout << "C=A+B=", C.display();
	C = A - B;
	cout << "C=A-B=", C.display();
	C = -A + B;
	cout << "C=-A+B=", C.display();
	C = A++;
	cout << "C=A++", C.display();
	C = ++A;
	cout << "C=++A", C.display();
	C = A + 5;
	C.display();
	return 0;
}
Complex_2 Complex_2::operator+(Complex_2 B)
{
	return Complex_2(real + B.real, image + B.image);
}
Complex_2 Complex_2::operator=(Complex_2 B)
{
	real = B.real, image = B.image;
	cout << "operator = calling..." << endl;
	return *this;
}
int p7_3()
{
	Complex_2 A(100.0, 200.0), B(-10.0, 20.0), C;
	cout<<"A=", A.display();
	cout << "B=", B.display();
	C = A + B;
	cout << "C=A+B=", C.display();
	C = A;
	cout << "C=A=", C.display();
	return 0;
}
int p7_4()
{
	PComplex P1;
	P1->display();
	Complex_3 C1(100, 200);
	P1 = &C1;
	P1->display();
	return 0;
}
int p7_5()
{
	String1 S1("0123456789abcdef");
	S1.ShowStr();
	S1[10] = 'A';
	cout << "S1[10]=A" << endl;
	S1.ShowStr();
	const String1 S2("ABCDEFGHIJKLMN");
	cout << "S2[10]=" << S2[10] << endl;
	return 0;
}
int p7_6()
{
	Point_4 P1(10, 10);
	cout << "P1.area()=" << P1.area() << endl;
	Circle_4 C1(10, 10, 20);
	cout << "C1.area()=" << C1.area() << endl;
	Point_4 *Pp;
	Pp = &C1;
	cout << "Pp->area()=" << Pp->area() << endl;
	Point_4 &Rp = C1;
	cout << "Rp.area()=" << Rp.area() << endl;
	return 0;
}
int p7_7()
{
	Point_5 P1(10, 10);
	cout << "P1.area()=" << P1.area() << endl;
	Circle_5 C1(10, 10, 20);
	cout << "C1.area()=" << C1.area() << endl;
	Point_5 *Pp;
	Pp = &C1;
	cout << "Pp->area()=" << Pp->area() << endl;
	Point_5 &Rp = C1;
	cout << "Rp.area()=" << Rp.area() << endl;
	return 0;
}
int p7_8()
{
	A*b = new B(10);
	delete b;
	return 0;
}
int p7_9()
{
	Cylinder_6 CY(100, 200, 10, 50);
	Shape *P;
	P = &CY;
	P->show();
	cout << "total area:" << P->area() << endl;
	Circle_6 Cir(5, 10, 100);
	Shape &R = Cir;
	R.show();
	return 0;
}
int p7_10()
{
	Person * PersonArr[5];
	PersonArr[0] = new Student("Joe", "computer");
	PersonArr[1] = new Teacher("Marry", "mathatics");
	PersonArr[2] = new Student("Jasmine", "physics");
	PersonArr[3] = new Teacher("Antony", "chemical");
	PersonArr[4] = new Student("Jayden", "biology");
	for (int i = 0; i < 5; i++)
	{
		PersonArr[i]->who_am_I();
		delete PersonArr[i];
	}
	return 0;
}
int p7()
{
	p7_1();
	p7_2();
	p7_3();
	p7_4();
	p7_5();
	p7_6();
	p7_7();
	p7_8();
	p7_9();
	p7_10();
	return 0;
}