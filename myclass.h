#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Point_1
{
private:
	int X, Y;
public:
	Point_1(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	void move(int OffX, int OffY)
	{
		X += OffX, Y += OffY;
	}
	void ShowXY()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
};

const double PI = 3.14159;

class Circle_1 :public Point_1
{
public:
	Circle_1(double R, int X, int Y) :Point_1(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius * radius;
	}
	void ShowCircle()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
private:
	double radius;
};

class Point_2
{
public:
	Point_2(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	void move(int OffX, int OffY)
	{
		X += OffX, Y += OffY;
	}
	void ShowXY()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
protected:
	int X, Y;
};

class Circle_2 :protected Point_2
{
public:
	Circle_2(double R, int X, int Y) :Point_2(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius * radius;
	}
	void ShowCircle()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
protected:
	double radius;
};

class Cylinder :protected Circle_2
{
public:
	Cylinder(int X, int Y, double R, double H) :Circle_2(R, X, Y)
	{
		height = H;
	}
	double area()
	{
		return PI * radius * radius;
	}
	double volume()
	{
		return Circle_2::area() * height;
	}
	void ShowCylinder()
	{
		ShowCircle();
		cout << "height of cylinder:" << height << endl;
	}
private:
	double height;
};

class Point_3
{
public:
	Point_3(int X, int Y)
	{
		this->X = X, this->Y = Y;
		cout << "point(" << X << "," << Y << ") constructing..." << endl;
	}
	~Point_3()
	{
		cout << "point(" << X << "," << Y << ") destructing..." << endl;
	}
private:
	int X, Y;
};

class Circle_3 :protected Point_3
{
public:
	Circle_3(double R = 0, int X = 0, int Y = 0) :Point_3(X, Y)
	{
		radius = R;
		cout << "circle constructing, radius: " << radius << endl;
	}
protected:
	double radius;
};

class tube :protected Circle_3
{
public:
	tube(double H, double R1, double R2 = 0, int X = 0, int Y = 0) :InCircle(R2, X, Y), Circle_3(R1, X, Y)
	{
		height = H;
		cout << "tube constructing, height: " << H << endl;
	}
	~tube()
	{
		cout << "tube destructing, height: " << height << endl;
	}
private:
	double height;
	Circle_3 InCircle;
};

class Cylinder_2 :public Circle_1
{
public:
	Cylinder_2(int X, int Y, double R, double H) :Circle_1(X, Y, R)
	{
		height = H;
	}
	void ShowCylinder_2()
	{
		ShowCircle();
		cout << "height of cylinder: " << height << endl;
	}
private:
	double height;
};

class Car
{
public:
	Car(int power, int seat)
	{
		this->power = power, this->seat = seat;
	}
	void show()
	{
		cout << "car power: " << power << "  seat:" << seat << endl;
	}
private:
	int power;
	int seat;
};

class Wagon
{
public:
	Wagon(int power, int load)
	{
		this->power = power, this->load = load;
	}
	void show()
	{
		cout << "wagon power:" << power << "  load:" << load << endl;
	}
private:
	int power;
	int load;
};

class StationWagon :public Car, public Wagon
{
public:
	StationWagon(int power, int seat, int load) :Wagon(power, load), Car(power, seat)
	{}
	void ShowSW()
	{
		cout << "StationWagon:" << endl;
		Car::show();
		Wagon::show();
	}
};

class Automobile
{
public:
	Automobile(int power)
	{
		this->power = power;
	}
	void show()
	{
		cout << "  power:" << power;
	}
private:
	int power;
};

class Car_2 :public Automobile
{
public:
	Car_2(int power, int seat) :Automobile(power)
	{
		this->seat = seat;
	}
	void show()
	{
		cout << "car: ";
		Automobile::show();
		cout << "  seat:" << seat << endl;
	}
private:
	int seat;
};

class Wagon_2 :public Automobile
{
public:
	Wagon_2(int power, int load) :Automobile(power)
	{
		this->load = load;
	}
	void show()
	{
		cout << "wagon:";
		Automobile::show();
		cout << "  load:" << load << endl;
	}
private:
	int load;
};

class StationWagon_2 :public Car_2, public Wagon_2
{
public:
	StationWagon_2(int CPower, int WPower, int seat, int load) :Wagon_2(WPower, load), Car_2(CPower, seat)
	{
	}
	void show()
	{
		cout << "StationWagon: " << endl;
		Car_2::show();
		Wagon_2::show();
	}
};

class Automobile_2
{
public:
	Automobile_2(int power)
	{
		this->power = power;
		cout << "Automobile constructing..." << endl;
	}
	void show()
	{
		cout << "  power" << power;
	}
private:
	int power;
};

class Car_3 :virtual public Automobile_2
{
public:
	Car_3(int power, int seat) :Automobile_2(power)
	{
		this->seat = seat;
		cout << "Car constructing..." << endl;
	}
	void show()
	{
		cout << "car:";
		Automobile_2::show();
		cout << "  seat:" << seat << endl;

	}
private:
	int seat;
};

class Wagon_3 :virtual public Automobile_2
{
public:
	Wagon_3(int power, int load) :Automobile_2(power)
	{
		this->load = load;
		cout << "Wagon constructing..." << endl;
	}
	void show()
	{
		cout << "wagon:";
		Automobile_2::show();
		cout << "  load: " << load << endl;
	}
private:
	int load;
};

class StationWagon_3 :public Car_3, public Wagon_3
{
public:
	StationWagon_3(int CPower, int WPower, int seat, int load) :Automobile_2(CPower), Wagon_3(WPower, load), Car_3(CPower, seat)
	{
		cout << "StationWagon constructing..." << endl;
	}
	void show()
	{
		cout << "StationWagon:" << endl;
		Car_3::show();
		Wagon_3::show();
	}

};
class Complex {
private:
	double real;
	double image;
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		this->real = real, this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	friend Complex operator +(Complex A, Complex B)
	{
		return Complex(A.real + B.real, A.image + B.image);
	}
	friend Complex operator -(Complex A, Complex B);
	friend Complex operator -(Complex A);
	friend Complex operator ++(Complex &A);
	friend Complex operator ++(Complex &A, int);
};
class Complex_1 {
private:
	double real;
	double image;
public:
	Complex_1(double real = 0.0, double image = 0.0)
	{
		this->real = real, this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	Complex_1 operator +(Complex_1 B);
	Complex_1  operator -(Complex_1 B);
	Complex_1 operator -();
	Complex_1 operator ++();
	Complex_1 operator ++(int);
};
class Complex_2 {
private:
	double real;
	double image;
public:
	Complex_2(double real = 0.0, double image = 0.0)
	{
		this->real = real, this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	Complex_2 operator +(Complex_2 B);
	Complex_2 operator =(Complex_2 B);
};
class Complex_3 {
private:
	double real;
	double image;
public:
	Complex_3(double real = 0.0, double image = 0.0)
	{
		this->real = real, this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
};
class PComplex
{
private:
	Complex_3 * PC;
public:
	PComplex(Complex_3 *PC = NULL)
	{
		this->PC = PC;
	}
	Complex_3 *operator->()
	{
		static Complex_3 NullComplex(0, 0);
		if (PC == NULL)
		{
			return &NullComplex;
		}
		return PC;
	}
};
class String1 {
private:
	char *Str;
	int len;
public:
	void ShowStr()
	{
		cout << "string:" << Str << ",length:" << len << endl;
	}
	String1(const char*p = NULL)
	{
		if (p)
		{
			len = strlen(p);
			Str = new char[len + 1];
			strcpy_s(Str,len+1,(char *) p);
		}
		else
		{
			len = 0;
			Str = NULL;
		}
	}
	~String1()
	{
		if (Str != NULL)
			delete[]Str;
	}
	char &operator[](int n)
	{
		return *(Str + n);
	}
	const char &operator[](int n)const
	{
		return *(Str + n);
	}

};
class Point_4 {
private:
	int X, Y;
public:
	Point_4(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	double area()
	{
		return 0.0;
	}

};
class Circle_4:public Point_4 {
private:
	double radius;
public:
	Circle_4(int X, int Y, double R) :Point_4(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius*radius;
	}

};
class Point_5 {
private:
	int X, Y;
public:
	Point_5(int X = 0, int Y = 0)
	{
		this->X = X, this-> Y = Y;
	}
	virtual double area()
	{
		return 0.0;
	}

};
class Circle_5 :public Point_5
{
private:
	double radius;
public:
	Circle_5(int X, int Y, double R) :Point_5(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius*radius;
	}
};
class A
{
public:
	virtual~A()
	{
		cout << "A::~A() is called." << endl;
	}
	A()
	{
		cout << "A::A() is called." << endl;
	}

};
class B :public A
{
private:
	int *ip;
public:
	B(int size = 0)
	{
		ip = new int[size];
		cout << "B::B() is called." << endl;
	}
	~B()
	{
		cout << "B::~B() is called." << endl;
		delete[] ip;
	}
};
class Shape
{
public:
	virtual double area()const = 0;
	virtual void show() = 0;
};
class Point_6 :public Shape{
protected:
	int X, Y;
public:
	Point_6(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	void show()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
	double area()const
	{
		return 0.0;
	}
};
class Circle_6 :public Point_6 {
protected:
	double radius;
public:
	Circle_6(int X, int Y, double R) :Point_6(X, Y)
	{
		radius = R;
	}
	double area() const
	{
		return PI * radius*radius;
	}
	void show()
	{
		cout << "Centre:" << "(" << X << "," << Y << ")" << endl;
		cout << "radius:" << radius << endl;
	}
};
class Cylinder_6 :public Circle_6 {
private:
	double height;
public:
	Cylinder_6(int X, int Y, double R, double H) :Circle_6(X, Y, R)
	{
		height = H;
	}
	double area()const
	{
		return 2 * Circle_6::area() + 2 * PI*radius*height;
	}
	void show()
	{
		Circle_6::show();
		cout << "height of cylinder:" << height << endl;
	}

};
class Person {
protected:
	char name[20];
public:
	Person(const char *iname) { strcpy_s(name, iname); }
	virtual void who_am_I() = 0;
	virtual ~Person() { cout << "~Person() called." << endl; }
};
class Student :public Person {
private:
	char major[20];
public:
	Student(const char * iname, const char *imajor) :Person(iname) {
		strcpy_s(major, imajor);
	}
	void who_am_I()
	{
		cout << "My name is" << name << ", I major in" << major << endl;
	}
	~Student() { cout << "~Student() called" << endl; }
};
class Teacher :public Person
{
private:
	char teach[20];
public:
	Teacher(const char * iname,const char*iteach) :Person(iname) {
		strcpy_s(teach, iteach);
	}
	void who_am_I()
	{
		cout << "My name is" << name << ", I teach" << teach << endl;
	}
	~Teacher() { cout << "~Teacher() called" << endl; }

};