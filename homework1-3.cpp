#include <iostream>
#include <iomanip>
using namespace std;
void paixu()
{
	//��������������
	int a, b, c;
	cout << "Please input three numbers:";
	cin >> a >> b >> c;
	if (a > b)//�ȱȽ��������ٽ���һ�������Ƚ�
	{
		if (b > c)
			cout <<a<< ">"<<b<<">"<<c << endl;
		else if (a > c)
			cout <<a<<">"<<c<<">"<<b << endl;
		else
			cout << c<<">"<<a<<">"<<b << endl;
	}
	else
	{
		if (a > c)
			cout << b<<">"<<a<<">"<<c << endl;
		else if (b > c)
			cout <<b<<">"<<c<<">"<<a << endl;
		else
			cout << c<<">"<<b<<">"<<a << endl;
	}
}
void add_n()//1+1/2+1/3+.....+1/n
{
	int n,sum;
	sum = 0;
	cout << "Please input a number:";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum = sum + 1 / i;
	}
	cout << "1+1/2+...+1/n = " << sum << endl;
}
void jinzita()
{
	//ע�⵽*��λ�ù��ɣ�����ѭ�����캯��
	int n;
	cout << "Please input a number: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << setw(n - i+1)<<"*";
		for (int j = 2; j <= i; j++)
		{
			cout << setw(2) << "*";
		}
		cout << endl;
	}
}
void daojinzi()
{
	int n;
	cout << "Please input a number: ";
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		cout << setw(n - i + 1) << "*";
		for (int j = 1; j < i; j++)
		{
			cout << setw(2) << "*";
		}
		cout << endl;
	}
}
void zhijiao()
{
	//ÿ�пո�ݼ�
	int n;
	cout << "Please input a number: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << setw(i) << "*";
		for (int j = n; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	
}
int maopao()
{
	int n,a[5],i,j;
	cout << "������������֣�";
	for (n = 0; n <5; n++)
	{
		cin >> a[n];
		if (a[n] < 0)
			break;
	}
	for (i=0;i<n-1;i++)//�����Ƚϣ�ֱ����������Ԫ��
		for(j=i+1;j<n;j++)
			if (a[i] < a[j])
			{
				int t;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	cout << "��С��������Ϊ��";
	for (i = 0; i <n; i++)
		cout << a[i] << "\t";
	cout << endl;
	return 0;
}
