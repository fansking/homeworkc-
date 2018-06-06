#include <iostream>
#include "mymath.h"
#include "TsingHua.h"
#define N 5

using namespace std;

extern void p1dispG();
extern void p2dispG();
extern void p2dispg();
int G = 0, g = 0;
int P4_1()
{
	p1dispG();
	p2dispG();
	p2dispg();
	cout << "in p G = " << G << endl;
	cout << "in p g = " << g << endl;
	return 0;
}

void fun()
{
	static int n = 0;
	int m = 0;
	++n;
	++m;
	cout << "m = " << m << ", n = " << n << endl;
}
int P4_2()
{
	for (int i = 0; i < 4; ++i) { fun(); }
	return 0;
}


void fun_2(int i=1, int j=2)
{
	const int k = 3;
	static int l = 0;
	int m;
	const char *p = "abcdef";
	char *q = new char[N + 1];
	for (m = 0; m < N; ++m) { q[m] = 'A' + m; }
	q[m] = '\0';
	cout << "\t" << "&i = " << &i << "\t" << "&j = " << &j << endl;
	cout << "局部变量的地址:" << endl;
	cout << "\t" << "&k = " << &k << "\t" << "&m = " << &m << "\t" << "&p = " << &p << "\t" << "&q = " << &q << endl;
	cout << "静态局部变量的地址:" << endl;
	cout << "\t" << "&l = " << &l << endl;
	cout << "字符串常量的地址:" << endl;
	cout << "\t" << "p串的地址 = " << (void *)p << endl;
	cout << "堆的地址:" << endl;
	cout << "\t(void *)q = " << (void *)q << endl;
	cout << "\tq串 = " << q << endl;
	delete[] q;
	cout << "\tdelete后,(void *)q = " << (void *)q << endl;
	//cout << "\tdelete后,q指向的单元的内容 = " << q << endl;

}
int k = 300;
const int i = 100;
const int j = 200;
int P4_3()
{
L1: fun_2();
L2: cout << "全局变量的地址:" << endl;
	cout << "\t&i = " << &i << "\t" << "&j = " << &j << "\t" << "&k = " << &k << endl;
	cout << "函数的入口地址:" << endl;
	cout << "\t&fun_2() = " << (void *)fun << "\t" << "&P4_3 = " << (void *)P4_3 << endl;
	return 0;
}

void fun_3(int I=2)
{
	cout << "L2: I = " << I << endl;
	{
		int I = 3;
		cout << "L3: I = " << I << endl;
		{
			for (int I = 4; I < 5; cout << "L6: I = " << I << endl, ++I)
			{
				cout << "L4: I = " << I << endl;
				//int I = 5;

				++I;
				cout << "L5: I = " << I << endl;
			}
		}
	}
}
int I = 100, J = 200;
int P4_4()
{
	fun_3();
	return 0;
}



int P4_5()
{
	cout << mymax(5, 6) << endl;
	return 0;
}

int P4_6()
{
	TsingHua::ShowName();
	return 0;
}

int P4_7()
{
	using TsingHua::ShowName;
	ShowName();
	return 0;
}
int p4()
{
	P4_1();
	P4_2();
	P4_3();
	P4_4();
	P4_5();
	P4_6();
	P4_7();
	return 0;
}