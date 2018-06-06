#include <iostream>
using namespace std;


int MyStrLen(char *p)
{
	int i = 0;
	while ('\0' != *p)
	{
		p++;
		i++;
	}
	
	return i;
}
void MyStrCat(char *const p1, char const *p2)
{
	int i=MyStrLen(p1);
	while ('\0' != *p2)
	{
		*(p1 + i) = *p2;
		i++;
		p2++;
	}
	*(p1 + i) = '\0';

}
void MyStrCpy(char *const p1,char * p2)
{
	int i = 0;
	while ('\0' != *p2)
	{
		*(p1 + i) = *p2;
		++p2;
		i++;
	}
	while ('\0' != *(p1 + i ))
	{
		*(p1 + i ) = '\0';
		i++;
	}
}
void MyStrReverse(char * const p)
{
	char A[100] = "123";
	int i = MyStrLen(p);
	for (int j = 0; j <= i; j++)
	{
		*(A+j) = *(p+i-j-1);
	}

	for ( int j = 0; j <= i; j++)
	{
		*(p+j)=*(A+j);
	}
}
int MyStrCompare( char *p1,  char *p2)
{
	int i = MyStrLen(p1);
	int j = MyStrLen(p2);
	int k = i > j ? j : i;
	int x;
	for (int n = 0; n < k; n++)
	{
		if (*(p1 + n) > *(p2 + n))
		{
			x = 1;
			break;
		}
		else if(*(p1 + n)< *(p2 + n))
		{
			x = -1;
			break;
		}
		if (n = k - 1)
		{
			if (i ==j)
				x = 0;
			else if (k == i)
				x = -1;
			else
				x = 1;
		}
	}
	return x;
}
void EraseDigital(char*p)
{
	int i = MyStrLen(p);
	char A[100] = {};
	int k = 0;
	for (int j = 0; j < i; j++)
	{
		if (p[j] < 48 || p[j]>57)
		{
			A[k] = p[j];
			k++;
		}

	}
	MyStrCpy(p, A);
}
void homework_6()
{
	int n;
	char p1[100] = "abc0966dfgh";
	EraseDigital(p1);
	cout << "去除p1中的数字后为："<< p1 << endl;
	char p2[5] = "bc";
	cout << "比较p1与p2为："<< MyStrCompare(p2, p1) << endl;
	MyStrCat(p1, p2);
	cout << "将p2接到p1之后："<< p1 << endl;
	MyStrCpy(p1, p2);
	cout << "将p2的内容复制到p1中："<< p1 << endl;
	MyStrReverse(p1);
	cout << "将p1的内容翻转："<< p1 << endl;
}