#include <iostream>
using namespace std;

//�����ĸ�����������ķ�ʽ��ת�������µ���
int Reverse1(int val)
{
	char *p = (char *)&val;
	for (int i = 0; i < sizeof(val) / 2; i++)
	{
		char c = p[i];
		p[i] = p[sizeof(val) - i - 1];
		p[sizeof(val) - i - 1] = c;
	}
	return val;
}
float Reverse1(float val)
{
	char *p = (char *)&val;
	for (int i = 0; i < sizeof(val) / 2; i++)
	{
		char c = p[i];
		p[i] = p[sizeof(val) - i - 1];
		p[sizeof(val) - i - 1] = c;
	}
	return val;
}
double Reverse1(double val)
{
	char *p = (char *)&val;
	for (int i = 0; i < sizeof(val) / 2; i++)
	{
		char c = p[i];
		p[i] = p[sizeof(val) - i - 1];
		p[sizeof(val) - i - 1] = c;
	}
	return val;
}

template<class T>
T Reverse1(T val)
{
	char *p = (char*)&val;
	for (int i = 0; i < sizeof(val) / 2; i++)
	{
		char c = p[i];
		p[i] = p[sizeof(val) - i - 1];
		p[sizeof(val) - i - 1] = c;
	}
	return val;
}
//����λ���㷭ת�������µ���
int Reverse2(int val)
{
	int a,a1, a2, a3, a4;
	a = val << 24;
	a1 = a & 0xff000000;
	a = val << 8;
	a2 = a & 0xff0000;
	a = val >> 8;
	a3 = a & 0xff00;
	a = val >> 24;
	a4 = a & 0xff;
	a = a1 | a2 | a3 | a4;
	return a;
}
//��ӡ�����ݴ洢���ڴ��е�0��1

void Bit(int val, char *pArry)
{
	char *pVal=(char *)&val;
	int m = 0;
	for (int i = 0; i < sizeof(val); i++)
	{
		for (int j =7; j >=0; j--)
		{
			pArry[m] = ((pVal[i])&(1 << j))?'1': '0';
			++m;
		}
	}
	pArry[m] = '\0';
}
void Bit(float val, char *pArry)
{
	char *pVal = (char *)&val;
	int m = 0;
	for (int i = 0; i < sizeof(val); i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			pArry[m] = ((pVal[i])&(1 << j)) ? '1' : '0';
			++m;
		}
	}
	pArry[m] = '\0';

}
void Bit(double val, char *pArry)
{
	char *pVal = (char *)&val;
	int m = 0;
	char iTaker = 0x80;
	for (int i = 0; i < sizeof(val);++ i)
	{
		for (int j = 0; j < 8;++ j)
		{
			pArry[m] = ((pVal[i])&(1 << j)) ? '1' : '0';
			++m;
		}
	}
	pArry[m] = '\0';

}
template<class T>
T Bit(T val, char*pArry)
{
	char *pVal = (char *)&val;
	int m = 0;
	for (int i = 0; i < sizeof(val); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pArry[m] = ((pVal[i])&(1 << j)) ? '1' : '0';
			++m;
		}
	}
	pArry[m] = '\0';
}
void homework_7()
{
	int a=3;
	int b = Reverse1(a);
	cout << "3���η�ת֮��Ϊ��" << Reverse2(b) << endl;
	char p[65];
	Bit(a, p);
	cout << "����3�Ĵ洢��ʽΪ��";
	for (int i = 0; i < sizeof(a); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << p[i * 8 + j];
		}
		cout << "\t";
	}
	cout << endl;
}