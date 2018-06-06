#include <iostream>
#include <iomanip>
using namespace std;
int GetNextMonthFirstDayIsWhatDay(int nWhatDay, int nDaysOfMonth)
{
	//�ж���һ���µ�һ�����ڼ������ظ�ֵ
	int j = nWhatDay;
	for (int i = 1; i <= nDaysOfMonth; i++)
	{
		if (j == 6)
			j = 0;
		else
			j++;
	}
	return j;
}
int DaysOfFberuary(int year)
{
	//�ж���������м��죨�Ƿ�Ϊ���꣩
	int daysoffberuary;
		if (year % 100 == 0)
			if (year % 400 == 0)
				daysoffberuary = 29;
			else
				daysoffberuary = 28;
		else if (year % 4 == 0)
			daysoffberuary = 29;
		else
			daysoffberuary = 28;
		return daysoffberuary;
}
int TheDaysOfMonth(int youryear ,int yourmonth)
{	int days;//�ж�һ�����м���
	switch (yourmonth)
	{
		
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		days = 31;  break;
	case 2:
		days = DaysOfFberuary(youryear);  break;
	case 4:case 6:case 9:case 11:
		days = 30;  break;
	}
	return days;
}
void printcalendar(int Theyear,int Themonth,int TheFirstDay, int TheDaysOfThisMonth)
{
	//��ӡĳ��ĳ�µ�����
	int j;
	cout << Theyear << "��" << Themonth << "��" << endl;
	cout << setw(4) << "��" << setw(4) << "һ" << setw(4) << "��" << setw(4) << "��" << setw(4) << "��" << setw(4) << "��" << setw(4) << "��" << endl;
	switch (TheFirstDay)
	{
	case 0:
		cout << setw(4) << "1" << setw(4) << "2" << setw(4) << "3" << setw(4) << "4" << setw(4) << "5" << setw(4) << "6" << setw(4) << "7";
		j = 8; break;
	case 1:
		cout << setw(8) << "1" << setw(4) << "2" << setw(4) << "3" << setw(4) << "4" << setw(4) << "5" << setw(4) << "6";
		j = 7; break;
	case 2:
		cout << setw(12) << "1" << setw(4) << "2" << setw(4) << "3" << setw(4) << "4" << setw(4) << "5";
		j = 6; break;
	case 3:
		cout << setw(16) << "1" << setw(4) << "2" << setw(4) << "3" << setw(4) << "4";
		j = 5; break;
	case 4:
		cout << setw(20) << "1" << setw(4) << "2" << setw(4) << "3";
		j = 4; break;
	case 5:
		cout << setw(24) << "1" << setw(4) << "2";
		j = 3; break;
	case 6:
		cout << setw(28) << "1";
		j = 2; break;
	default:
		cout << "The first day is wrong" << endl;
	}
	cout << endl;
	for (int n = 1; j <= TheDaysOfThisMonth; j++, n++)
	{
		cout << setw(4) << j;
		if (n % 7 == 0)
			cout << endl;
	}
}
void PrintYourCalendar_month(int youryear,int yourmonth)
{
	//��ӡָ����ĳ��ĳ�µ�����
	int  numbers, TheFirstDay, days;
	numbers = (youryear - 1) * 12 + yourmonth - 1;
	if (numbers == 0)//��ӡԪ��1�µ�����
		printcalendar(1, 1, 1, 31);
	else if (numbers == 1)//��ӡԪ��2�µ�����
		printcalendar(1, 2, 4, 28);
	else
	{
		TheFirstDay = GetNextMonthFirstDayIsWhatDay(1, 31);
		int year = 1, month = 2;
		for (int i = 2; i <= numbers; i++)//��Ԫ����¿�ʼһ����һ���µ��ۻ��������Ҫ��ĳ��һ�����ڼ�
		{
			switch (month)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:
				days = 31; TheFirstDay = GetNextMonthFirstDayIsWhatDay(TheFirstDay, days); month++; break;
			case 2:
				days = DaysOfFberuary(year); TheFirstDay = GetNextMonthFirstDayIsWhatDay(TheFirstDay, days); month++; break;
			case 4:case 6:case 9:case 11:
				days = 30; TheFirstDay = GetNextMonthFirstDayIsWhatDay(TheFirstDay, days); month++; break;
			case 12:
				days = 31; TheFirstDay = GetNextMonthFirstDayIsWhatDay(TheFirstDay, days); year++; month = 1; break;
			}
		}
		days = TheDaysOfMonth(youryear, yourmonth);
		printcalendar(youryear, yourmonth, TheFirstDay, days);

	}
	cout << endl;
}
void PrintYourCalendar_yourmonth()
{
	//��ӡ�������ĳ��ĳ�µ�����
	int youryear, yourmonth,numbers,TheFirstDay,days;
	cout << "����������Ҫ����ݣ�";
	cin >> youryear;
	cout << endl << "����������Ҫ���·ݣ�";
	cin >> yourmonth;
	PrintYourCalendar_month(youryear, yourmonth);
}

void PrintYourCalendar_year()
{
	//��ӡĳһ����������������ţ�
	int youryear, yourmonth, numbers, TheFirstDay, days;
	cout << "����������Ҫ����ݣ�";
	cin >> youryear;
	for (yourmonth = 1; yourmonth <= 12; yourmonth++)
	{
		PrintYourCalendar_month(youryear, yourmonth);
	}
}
