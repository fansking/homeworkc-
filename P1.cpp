#include <iostream>
#include <iomanip>
using namespace std;
int P1_1()
{
	cout << "Hello C++" << endl;
	return 0;
}

int P1_2()
{
	float num1, num2, num3;
	cout << "Please input three numbers : ";
	cin >> num1 >> num2 >> num3;
	cout << "The average of " << num1 << "," << num2 << "and" << num3;
	cout << "is: "<<(num1+num2+num3)/3 << endl;
	return 0;
}

int P1_3()
{
	float num1, num2, num3;
	cout << "Please input three numbers : ";
	cin >> num1 >> num2 >> num3;
	cout << setw(8) << setprecision(12);
	cout << "The average of " << num1 << "," << num2 << "and" << num3;
	cout << "is:" << setw(20) << (num1 + num2 + num3) / 3 << endl;
	return 0;
}
int p1()
{
	P1_1();
	P1_2();
	P1_3();
	return 0;
}