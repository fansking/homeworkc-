#include <iostream>
#include <fstream>
using namespace std;
int getNext(int i, int m, int n)//�õ����
{
	return (i%n)*m + i / n;
}
int getPre(int i, int m, int n)//�õ�ǰ��
{
	return (i%m)*n + i / m;
}
void movedata(int *p, int i, int m, int n)//�������±�Ϊi�����Ļ�
{
	int temp = p[i];
	int cur = i;
	int pre = getPre(cur, m, n);
	while (pre != i)
	{
		p[cur] = p[pre];
		cur = pre;
		pre = getPre(cur,m,n);
	}
	p[cur] = temp;
}
void transpose(int *p, int m, int n)//ת��
{
	for (int i = 0; i < m*n; i++)
	{
		int next = getNext(i, m, n);
		while (next > i)
		{
			next = getNext(next, m, n);
		}
		if (next == i)
			movedata(p, i, m, n);
	}
}
int homework8()//��E����in�ļ�����ȡ���е���ֵ������ת�������out�ļ���
{
	ifstream in;
	in.open("E:\\in.txt");
	if (!in.is_open())
	{
		cout << "�Ҳ���in�ļ�";
		return 1;
	}
	int nCol, nRow;
	in >> nRow >> nCol;
	int *p = new int[nCol*nRow];
	for (int i = 0; i < nCol*nRow; i++)
		in >> *(p + i);
	in.close();
	transpose(p, nRow, nCol);
	ofstream out;
	out.open("E:\\out.txt");
	out << nCol << " " << nRow << endl;
	for (int i = 0; i <nCol; i++)
	{
		for (int j = 0; j < nRow; j++)
			out << *(p + i * nRow + j) << " ";
		out<< endl;
	}
	out.close();
	delete[] p;//ɾ���ͷſռ�
	p = NULL;
	return 0;
}