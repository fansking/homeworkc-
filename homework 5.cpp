#include <iostream>
using namespace std;

void exchange_1(int &a, int&b)
{
	//使用引用实现两个整形变量的交换
	int t;
	t = a;
	a = b;
	b = t;
}
void exchange_2(int* a, int *b)
{
	//使用指针实现两个整形变量的交换
	//在使用前应用指针变量取出整形变量的地址
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void exchange_3(int* &i, int *&j)
{
	//使用引用实现两个整形指针变量的交换
	int *p;
	p = i;
	i = j;
	j = p;
}
void exchange_4(int**a, int **b)
{
	//使用指针来实现两个整形指针变量的交换
	//使用前应用指针指向两个整形指针变量
	int *p;
	p = *a;
	*a = *b;
	*b = p;
}
void print_negative_number()
{
	//通过强制转换数据类型，并赋值来输出一个负数
	int A[10] = { 1,2,3,4,5,6,7,8 };
	short int *p = (short int *)A;
	p[1] = 0xffff;
	cout << A[0] << endl;
}
void homework_5()
{
	int a = 1, b = 2;
	int *pa=&a, *pb=&b;
	int **ppa=&pa, **ppb=&pb;
	exchange_1(a, b);
	cout << "利用引用将a(1)与b(2)交换：" << a << "\t" << b <<endl;
	exchange_2(pa, pb);
	cout <<"利用指针将a(2)与b(1)交换：" << a << "\t" << b << endl;
	cout << "利用引用将pa" << pa << "与pb" << pb << "交换：";
	exchange_3(pa, pb);
	cout << pa<< "\t" << pb << endl;
	exchange_4(ppa, ppb);
	cout << "利用指针将pa与pb交换：" << pa << "\t" << pb << endl;
	cout << "利用强制转换输出一个负数：";
	print_negative_number();
	cout << endl;
}