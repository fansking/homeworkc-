#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct WHU {
	char cName[32];
	char cID[32];
	float nSocres[5];
	struct WHU *next;
}; typedef struct WHU Stu;
//从文件中读取链表
Stu *CreatLinkerFromFile_1(const char *pFilename)
{
	ifstream in;
	in.open(pFilename, ios::in);
	if (!in.is_open()) { cout << "没有找到文件" << endl; return NULL; }
	int ncount = 0;
	in >> ncount;
	Stu *pHeader = new Stu();
	pHeader->next = NULL;
	Stu *pT = pHeader;
	for (int i = 0; i < ncount; i++)
	{
		char temp[32];
		Stu *pX = new Stu();
		in >> pX->cID >> pX->cName>>temp>>temp;
		for (int j = 0; j < sizeof(pX->nSocres) / sizeof(float); j++)
			in >> pX->nSocres[j];
		pT->next = pX;
		pT = pT->next;
		pT->next = NULL;
	}
	in.close();
	return pHeader;
}
//删除链表
void DeleteLinkers(Stu *pHeader)
{
	while (NULL != pHeader)
	{
		Stu *pT = pHeader;
		pHeader = pHeader->next;
		delete pT;
	}
}
//交换pB与pC
void SwapLinkers(Stu *pA,Stu *pB, Stu *pC)
{
	pA->next = pB->next;
	pB->next = pC->next;
	pC->next = pB;
}
//学生个数
int NumOfStu(Stu *pH)
{
	int num = 1;
	Stu *pT = pH->next;
	while (NULL != pT->next)
	{
		++num;
		pT = pT->next;
	}
	return num;
}
//翻转链表
void ReverseLinkers(Stu *pH)
{
	Stu *pA = pH;
	Stu *pB = pA->next;
	Stu *pC = pB->next;
	int n = NumOfStu(pH);
	for (int i = 0; i <n - 1; i++)
	{
		pA = pH;
		pB = pH->next;
		pC = pB->next;
		for (int j = 0; j < n - i - 1; j++)
		{
			SwapLinkers(pA, pB, pC);
			pA = pA->next;
			pB = pA->next;
			pC = pB->next;
		}
	}
}
//1 升序 0降序
void SortByTotalSocres(Stu *pH,bool ascend)
{
	Stu *pA = pH;
	Stu *pB = pA->next;
	Stu *pC = pB->next;
	int n = NumOfStu(pH);
	for (int i = 0; i <n - 1; i++)
	{
		pA = pH;
		pB = pH->next;
		pC = pB->next;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (pB->nSocres[4]> pC->nSocres[4])
				SwapLinkers(pA, pB, pC);
			pA = pA->next;
			pB = pA->next;
			pC = pB->next;
		}
	}
	if (ascend)
	{
		ReverseLinkers(pH);
	}
}
//根据链表写出文本文件
void WriteTxtFile(Stu *pH,const char *pFileName)
{
	Stu *pT = pH->next;
	ofstream out;
	out.open(pFileName);
	if (!out.is_open())return;
	for (int i = 0; i < NumOfStu(pH)-1; i++)
	{
		out << pT->cID << "\t" << pT->cName << "\t";
		for (int j = 0; j < sizeof(pT->nSocres) / sizeof(float); j++)
		{
			out <<  pT->nSocres[j] << "\t";
		}
		out << endl;
		pT = pT->next;
	}

	out.close();
}
//二进制文件转换为文本文件
void BinaryTxtFile(const char *BinaryFileName, const char *TxtFileName)
{
	ifstream in;
	in.open(BinaryFileName,ios::binary|ios::in);
	if (!in.is_open())return ;
	ofstream out;
	out.open(TxtFileName);
	if (!out.is_open())return;
	int ncount=0;
	in.read((char *)&ncount, 4);
	out << ncount<<endl;
	for (int i = 0; i < ncount; i++)
	{
		char cNum[32] = {};
		char cName[32] = {};
		float nscore[5] = {};
		int nLen = 0;
		in.read((char *)&nLen, 4);
		in.read(cNum, nLen);
		out<< cNum <<'\t';
		in.read((char*)&nLen, 4);
		in.read(cName, nLen);
		out << cName <<"\t";
		for (int j = 0; j < 5; j++)
		{
			in.read((char*)(nscore + j), 4);
			out <<nscore[j]<< "\t";
		}
		out << endl;
	}
	out.close();
	in.close();

}
//直接从二进制文件创建链表
Stu* CreatLinkerFromBinary(const char *BinaryFileName)
{
	ifstream in;
	in.open(BinaryFileName, ios::binary | ios::in);
	if (!in.is_open())return NULL;
	int nCount = 0;
	in.read((char*)&nCount, sizeof(int));
	Stu *pH = new Stu();
	pH->next = NULL;
	Stu *pT = pH;
	for (int i = 0; i < nCount; i++)
	{
		pT->next = new Stu();
		pT = pT->next;
		pT->next = NULL;
		int Len = 0;
		in.read((char*)&Len, sizeof(Len));
		in.read(pT->cID, Len);
		pT->cID[Len] = '\0';

		in.read((char *)&Len, sizeof(Len));
		in.read(pT->cName, Len);
		pT->cName[Len] = '\0';

		float scores;
		for (int j = 0; j < 5; j++)
		{
			in.read((char *)&scores, sizeof(float));
			pT->nSocres[j] = (int)scores;
		}
	}
	return pH;
}
int homework10()
{
	Stu *pY = CreatLinkerFromBinary("F:\\Documents\\Tencent Files\\935802216\\FileRecv\\abc.bin");
	BinaryTxtFile("F:\\Documents\\Tencent Files\\935802216\\FileRecv\\abc.bin", "E:\\abc.txt");
	Stu *pH=CreatLinkerFromFile_1("E:\\学生成绩链表测试1.txt");
	SortByTotalSocres(pH,true);
	WriteTxtFile(pH, "E://排序后.txt");
	DeleteLinkers(pH);
	return 0;

}