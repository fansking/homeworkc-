#include <iostream>
#include <fstream>

using namespace std;
struct Student
{
	char cName[32];
	char cID[17];
	int nSocres[3];
	struct Student *next ;
}; typedef struct Student CStu;
int cmp(int m,int n)
{
	if (m > n)
		return 1;
	else if (m == n)
		return 0;
	else
		return -1;
}
int cmp(char*pA, char*pB)
{
	return strcmp(pA, pB);
}
void SwapLinkers(CStu *pA, CStu *pB, CStu *pC)
{
	pA->next = pB->next;
	pB->next = pC->next;
	pC->next = pB;
}
//����ѧ������
int NumOfStu(CStu *pH)
{
	int num = 1;
	CStu *pT = pH->next;
	while (NULL != pT->next)
	{
		++num;
		pT = pT->next;
	}
	return num;
}
//����ָ��������ѧ������
int NumOfEligibleStuName(CStu *pH, const char *pName)
{
	CStu *pT = pH;
	int num = 0;
	while (NULL != pT)
	{
		if (0 == strcmp(pT->cName, pName))
			++num;
		pT = pT->next;
	}
	return num;
}
//���ļ��ж�ȡ����
CStu *CreatLinkerFromFile(const char *pFilename)
{
	ifstream in;
	in.open(pFilename, ios::in);
	if (!in.is_open()) { cout << "û���ҵ��ļ�"<<endl; return NULL; }
	int ncount = 0;
	in >> ncount;
	CStu *pHeader = new CStu();
	pHeader->next = NULL;
	CStu *pT = pHeader;
	for (int i = 0; i < ncount; i++)
	{
		CStu *pX = new CStu();
		in >> pX->cName >> pX->cID;
		for (int j = 0; j < sizeof(pX->nSocres) / sizeof(int); j++)
			in >> pX->nSocres[j];
		pT->next = pX;
		pT = pT->next;
		pT->next = NULL;
	}
	in.close();
	return pHeader;
}
//ɾ����������
void DeleteLinkers(CStu *pHeader)
{
	while (NULL != pHeader)
	{
		CStu *pT = pHeader;
		pHeader = pHeader->next;
		delete pT;
	}
}
//��������ɾ�����������Ľṹ��nFlag 0 ɾ����һ����1ɾ�����һ����2ɾ�����з���������
bool DeleteStuByName(CStu *pH,const char*pName,int nFlag)
{
	CStu *pB = pH;
	CStu *pT = pH->next;
	int num = 0;
	int m = NumOfEligibleStuName(pH, pName);
	while (NULL != pT)
	{
		
		if (0 == strcmp(pT->cName, pName))
		{
			++num;
			if (0 == nFlag)
			{
				pB->next = pT->next;
				delete pT;
				return true;
			}
			else if (1 == nFlag)
			{
				if (num == m)
				{
					pB->next = pT->next;
					delete pT;
					return true;
				}
				else
				{
					pB = pB->next;
					pT = pT->next;
				}
			}
			else if (2 == nFlag)
			{
				CStu *pO = pT;
				pB->next = pT->next;
				pT = pB->next;
				delete pO;
				if (num == m)
					return true;
			}
		}
		else
		{
			pB = pB->next;
			pT = pT->next;
		}
	}
	return false;
}
//����һ����ѧ����nFlag��ֵ��������λ��
bool InsertNewStu(CStu *pH, const char *pName, int nFlag)
{
	CStu *pB = pH;
	CStu *pT = pH->next;
	int num = 0;
	int old_num = NumOfStu(pH);
	if (nFlag > old_num + 1)
	{
		cout << "ָ��λ�ó���ѧ������";
		return false;
	}
	while (num <= old_num + 1)
	{
		++num;
		if (num == nFlag)
		{
			CStu *pN = new CStu();
			strcpy_s(pN->cName, pName);
			pB->next = pN;
			pN->next = pT;
			return true;
		}
		else
		{
			pB = pB->next;
			pT = pT->next;
		}
	}
	return false;
}
//����ѧ������
void SortBycID(CStu *pH)
{
	CStu *pA = pH;
	CStu *pB = pA->next;
	CStu *pC = pB->next;
	int n = NumOfStu(pH);
	for (int i = 0; i <n-1; i++)
	{
		pA = pH;
		pB = pH->next;
		pC = pB->next;
		for (int j = 0; j < n-i-1; j++)
		{
			if (cmp(pB->cID, pC->cID) == 1)
				SwapLinkers(pA, pB, pC);
			pA = pA->next;
			pB = pA->next;
			pC = pB->next;
		}
	}
}
//������������
void SortBycName(CStu *pH)
{
	CStu *pA = pH;
	CStu *pB = pA->next;
	CStu *pC = pB->next;
	int n = NumOfStu(pH);
	for (int i = 0; i <n - 1; i++)
	{
		pA = pH;
		pB = pH->next;
		pC = pB->next;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (cmp(pB->cName, pC->cName) == 1)
				SwapLinkers(pA, pB, pC);
			pA = pA->next;
			pB = pA->next;
			pC = pB->next;
		}
	}
}
//���յ�һ���ɼ���С��������
void SortByScore(CStu *pH)
{
	CStu *pA = pH;
	CStu *pB = pA->next;
	CStu *pC = pB->next;
	int n = NumOfStu(pH);
	for (int i = 0; i <n - 1; i++)
	{
		pA = pH;
		pB = pH->next;
		pC = pB->next;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (cmp(pB->nSocres[0] , pC->nSocres[0])==1)
				SwapLinkers(pA, pB, pC);
			pA = pA->next;
			pB = pA->next;
			pC = pB->next;
		}
	}
}
//nFlag 0 �ܳɼ� 1 ��һ���ɼ� 2 3 ��С����
void SortByScore(CStu *pH, int nFlag)
{
	CStu * pA = pH;
	CStu *pB = pA->next;
	CStu *pC = pB->next;
	int n = NumOfStu(pH);
	int x, y;
	for (int i = 0; i <n - 1; i++)
	{
		pA = pH;
		pB = pH->next;
		pC = pB->next;
		for (int j = 0; j < n - i - 1; j++)
		{
			int total_socres1 = pB->nSocres[0] + pB->nSocres[1] + pB->nSocres[2];
			int total_socres2 = pC->nSocres[0] + pC->nSocres[1] + pC->nSocres[2];
			switch (nFlag)
			{
			case 0:x = total_socres1; y = total_socres2; break;
			case 1:x = pB->nSocres[0]; y = pC->nSocres[0]; break;
			case 2:x = pB->nSocres[1]; y = pC->nSocres[1]; break;
			case 3:x = pB->nSocres[2]; y = pC->nSocres[2]; break;
			}
			if (cmp(x,y) == 1)
				SwapLinkers(pA, pB, pC);
			pA = pA->next;
			pB = pA->next;
			pC = pB->next;
		}
	}
}
//��ת����
void ReverseLinkers(CStu *pH)
{
	CStu *pA = pH;
	CStu *pB = pA->next;
	CStu *pC = pB->next;
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
//��������ӵ����
void CopyLinkers(CStu *pH)
{
	CStu *pA = pH->next;
	CStu *pX = pH;
	int num = NumOfStu(pH);
	for (int j = 0; j < num; j++)
	{
		pX = pX->next;
	}
	for (int i = 0; i < num; i++)
	{
		CStu *pN = new CStu();
		strcpy_s(pN->cName, pA->cName);
		strcpy_s(pN->cID, pA->cID);
		for (int j = 0; j < sizeof(pA->nSocres) / sizeof(int); j++)
			pN->nSocres[j]=pA->nSocres[j];
		pX->next = pN;
		pN->next = NULL;
		pX = pX->next;
		pA = pA->next;
	}
}
//����ascend Ϊtrueʱ���򣬷����� nFlag 0 ���������� 1����ѧ���� 2 �����ܷ��� 3���յ�һ�ųɼ� 4���յڶ��� 5 ���յ�����
void Sort(CStu *pH,bool ascend, int nFlag)
{
	switch (nFlag)
	{
	case 0:
		SortBycName(pH); break;
	case 1:
		SortBycID(pH); break;
	case 2:
		SortByScore(pH, 0); break;
	case 3:
		SortByScore(pH,1); break;
	case 4:
		SortByScore(pH, 2); break;
	case 5:
		SortByScore(pH, 3); break;
	}
	if (ascend == false)
		ReverseLinkers(pH);
}
int homework9()
{
	CStu *pH=CreatLinkerFromFile("E:\\student.txt");
	Sort(pH, false, 5);
	DeleteLinkers(pH);
	return 0;
}