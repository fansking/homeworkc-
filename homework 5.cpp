#include <iostream>
using namespace std;

void exchange_1(int &a, int&b)
{
	//ʹ������ʵ���������α����Ľ���
	int t;
	t = a;
	a = b;
	b = t;
}
void exchange_2(int* a, int *b)
{
	//ʹ��ָ��ʵ���������α����Ľ���
	//��ʹ��ǰӦ��ָ�����ȡ�����α����ĵ�ַ
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void exchange_3(int* &i, int *&j)
{
	//ʹ������ʵ����������ָ������Ľ���
	int *p;
	p = i;
	i = j;
	j = p;
}
void exchange_4(int**a, int **b)
{
	//ʹ��ָ����ʵ����������ָ������Ľ���
	//ʹ��ǰӦ��ָ��ָ����������ָ�����
	int *p;
	p = *a;
	*a = *b;
	*b = p;
}
void print_negative_number()
{
	//ͨ��ǿ��ת���������ͣ�����ֵ�����һ������
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
	cout << "�������ý�a(1)��b(2)������" << a << "\t" << b <<endl;
	exchange_2(pa, pb);
	cout <<"����ָ�뽫a(2)��b(1)������" << a << "\t" << b << endl;
	cout << "�������ý�pa" << pa << "��pb" << pb << "������";
	exchange_3(pa, pb);
	cout << pa<< "\t" << pb << endl;
	exchange_4(ppa, ppb);
	cout << "����ָ�뽫pa��pb������" << pa << "\t" << pb << endl;
	cout << "����ǿ��ת�����һ��������";
	print_negative_number();
	cout << endl;
}