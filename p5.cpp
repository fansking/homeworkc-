#include <iostream>
using namespace std;
void MyStrCpy(char *const p1,const char * p2)
{
	int i = 0;
	while ('\0' != *p2)
	{
		*(p1 + i) = *p2;
		++p2;
		i++;
	}
	while ('\0' != *(p1 + i))
	{
		*(p1 + i) = '\0';
		i++;
	}
}
struct Clock {
	int H, M, S;
};
Clock MyClock;
void SetTime(int H, int M, int S)
{
	MyClock.H = (H >= 0 && H < 24) ? H : 0;
	MyClock.M = (M >= 0 && M < 60) ? S : 0;
	MyClock.M = (M >= 0 && M < 60) ? S : 0;
}
void ShowTime()
{
	cout << MyClock.H << ":";
	cout << MyClock.M << ":";
	cout << MyClock.S << ":";
}
int p5_1_a()
{
	ShowTime();
	SetTime(8, 30, 30);
	ShowTime();
	return 0;
}
class Clock0 {
private:
	int H, M, S;
public:
	void SetTime(int h, int m, int s)
	{
		H = (h >= 0 && h < 24) ? h : 0;
		M = (m >= 0 && m < 24) ? m : 0;
		S = (s >= 0 && s < 24) ? s : 0;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
};
int p5_1_b()
{
	Clock0 MyClock;
	MyClock.ShowTime();
	MyClock.SetTime(8, 30, 30);
	MyClock.ShowTime();
	return 0;
}
class Clock1 {
private:
	int H, M, S;
public:
	Clock1(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
	}
	~Clock1()
	{
		cout << "destructor:" << H << ":" << M << ":" << S << endl;
	}
	Clock1(Clock1 &p)
	{
		cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
		H = p.H;
		M = p.M;
		S = p.S;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
};
int p5_2()
{
	Clock1 C3(10, 0, 0);
	Clock1 C4(11, 0, 0);
	return 0;
}
class String {
private:
	char *Str;
	int len;
public:
	void ShowStr()
	{
		cout << "string:" << Str << ",length:" << len << endl;
	}
	String(String &r)
	{
		len = r.len;
		if (len != 0)
		{
			Str = new char[len + 1];
			strcpy_s(Str,len+1, r.Str);
		}
	}
	String(const char *p)
	{
		len = strlen(p);
		Str = new char[len + 1];
		strcpy_s(Str,len+1, p);
	}
	~String()
	{
		if (Str != NULL)
		{
			delete []Str;
			Str = NULL;
		}
	}

};
int p5_3()
{
	char s[] = "ABCDE";
	String s1(s);
	String s2("123456");
	s1.ShowStr();
	s2.ShowStr();
	return 0;
}
Clock1 fun(Clock1 C)
{
	return C;
}
int p5_4()
{
	Clock1 C1(8, 0, 0);
	Clock1 C2(9, 0, 0);
	Clock1 C3(C1);
	fun(C2);
	Clock1 C4;
	C4 = C2;
	return 0;
}
int p5_5()
{
	String s1("123456");
	String s2 = s1;
	s1.ShowStr();
	s2.ShowStr();
	return 0;
}
class Clock2 {
private:
	int H, M, S;
public:
	void SetTime(int h, int m, int s)
	{
		H = h, M = m, S = s;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	Clock2(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
	}
	Clock2(Clock2 &p)
	{
		H = p.H, M = p.M, S = p.S;
	}
	void TimeAdd(Clock2 *Cp);
	void TimeAdd(int h, int m, int s);
	void TimeAdd(int s);
};
void Clock2::TimeAdd(Clock2 *Cp)
{
	H = (Cp->H + H + (Cp->M + M + (Cp->S + S) / 60) / 60) % 24;
	M = (Cp->M + M + (Cp->S + S) / 60) % 60;
	S = (Cp->S + S) % 60;
}
void Clock2::TimeAdd(int h, int m, int s)
{
	H = (h + H + (m + M + (s + S) / 60) / 60) % 24;
	M = (m + M + (S + s) / 60) % 60;
	S = (s + S) % 60;
}
void Clock2::TimeAdd(int s)
{
	H = (H + (M + (S + s) / 60) / 60) % 24;
	M = (M + (S + s) / 60) % 60;
	S = (S + s) % 60;
}
int p5_6()
{
	Clock2 C1;
	Clock2 C2(8, 20, 20);
	C1.TimeAdd(4000);
	C1.ShowTime();
	C2.TimeAdd(&C1);
	C2.ShowTime();
	return 0;
}
const int MaxN = 100;
const double Rate = 0.6;
class Score {
private:
	long No;
	const char *Name;
	int Peace;
	int Final;
	int Total;
public:
	Score(long =0, const char *name=NULL, int =0,int=0, int =0);
	void Count();
	void ShowScore();

};
Score::Score(long no, const char *name, int peace, int final, int total)
{
	No = no;
	Name = name;
	Peace = peace;
	Final = final;
	Total = total;
}
void Score::Count()
{
	Total = Peace * Rate + Final * (1 - Rate) + 0.5;
}
void Score::ShowScore()
{
	cout << No << "\t" << Name << "\t" << Peace << "\t" << Final << "\t" << Total << endl;
}
int p5_7()
{
	Score ClassScore1[3];
	Score ClassScore2[3] = { Score(200607001,"LiuNa",80,79),
							Score(200607002,"CuiPeng",90,85),
							Score(200607003,"ZhouJun",70,55) };
	for (int i = 0; i < 3; i++)
		ClassScore2[i].Count();
	for (int i = 0; i < 3; i++)
		ClassScore2[i].ShowScore();
	return 0;
}
class Clock3 {
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	Clock3(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	int GetH()
	{
		return H;
	}
	int GetM()
	{
		return M;
	}
	int GetS()
	{
		return S;
	}
};
class TrainTrip {
private:
	const char *TrainNo;
	Clock3 StartTime;
	Clock3 EndTime;
public:
	TrainTrip(const char *TrainNo, Clock3 S, Clock3 E)
	{
		this->TrainNo = TrainNo;
		StartTime = S;
		EndTime = E;
	}
	Clock3 TripTime()
	{
		int tH, tM, tS;
		int carry = 0;
		Clock3 tTime;
		(tS = EndTime.GetS() - StartTime.GetS()) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.GetM() - StartTime.GetM()-carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.GetH() - StartTime.GetH()-carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int p5_8()
{
	Clock3 C1(8, 10, 10), C2(6, 1, 2);
	Clock3 C3;
	TrainTrip T1("K16", C1, C2);
	C3 = T1.TripTime();
	C3.ShowTime();
	return 0;
}
class Student {
private:
	char Name[30];
	int No;
	static int countS;
public:
	static int GetCount()
	{
		return countS;
	}
	Student(const char* = "", int = 0);
	Student(Student &);
	~Student();
};
Student::Student(const char *Name, int No)
{
	this->Name[30] = {};
	MyStrCpy(this->Name, Name);
	this->No = No;
	++countS;
	cout << "constructing:" << Name << endl;
}
Student::Student(Student&r)
{
	Name[30] = {};
	MyStrCpy(Name,r.Name);
	No = r.No;
	++countS;
	cout << "copy constructing:" << r.Name << endl;
}
Student::~Student()
{
	cout << "destructing:" << Name << endl;
	--countS;
}
int Student::countS = 0;
int p5_9()
{
	cout << Student::GetCount() << endl;
	Student s1("Antony");
	cout << s1.GetCount() << endl;
	Student s2(s1);
	cout << s1.GetCount() << endl;
	Student S3[2];
	cout << Student::GetCount() << endl;
	Student *s4 = new Student[3];
	cout << Student::GetCount() << endl;
	delete []s4;
	s4 = NULL;
	cout << Student::GetCount() << endl;
	return 0;
}
class Clock4 {
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M; this->S = S;
	}
	Clock4(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M; this->S = S;
	}
	friend Clock4 TripTime(Clock4 &StartTime, Clock4 & EndTime);
};
Clock4 TripTime(Clock4  &StartTime, Clock4 & EndTime)
{
	int tH, tM, tS;
	int carry = 0;
	Clock4 tTime;
	(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
	(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
	(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
	tTime.SetTime(tH, tM, tS);
	return tTime;
}
int p5_10()
{
	Clock4 C1(8, 10, 10), C2(6, 1, 2);
	Clock4 C3;
	C3 = TripTime(C1, C2);
	C3.ShowTime();
	return 0;
}
class TrainTrip1;
class Clock5 {
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M; this->S = S;
	}
	Clock5(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M; this->S = S;
	}
	friend class TrainTrip1;
};
class TrainTrip1 {
private:
	const char *TrainNo;
	Clock5 StartTime;
	Clock5 EndTime;
public:
	TrainTrip1(const char *TrainNo, Clock5 S, Clock5 E)
	{
		this->TrainNo = TrainNo;
		StartTime = S;
		EndTime = E;
	}
	Clock5 TripTime()
	{
		int tH, tM, tS;
		int carry = 0;
		Clock5 tTime;
		(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}

};
int p5_11()
{
	Clock5 C1(8, 10, 10), C2(6, 1, 2);
	Clock5 C3;
	TrainTrip1 T1("K16", C1, C2);
	C3 = T1.TripTime();
	C3.ShowTime();
	return 0;
}
class A {
private:
	const int& r;
	const int a;
	static const int b;
public:
	A(int i) :a(i), r(a)
	{
		cout << "constructor!" << endl;
	}
	void display()
	{
		cout << a << "," << b << "," << r << endl;
	}

};
const int A::b = 3;
int p5_12()
{
	A a1(1);
	a1.display();
	A a2(2);
	a2.display();
	return 0;
}
int p5()
{
	p5_1_a();
	p5_1_b();
	p5_2();
	p5_3();
	p5_4();
	p5_5();
	p5_6();
	p5_7();
	p5_8();
	p5_9();
	p5_10();
	p5_11();
	p5_12();
	return 0;
}