#include <iostream>
#include <fstream>
using namespace std;
int getNext(int i, int m, int n)//得到后继
{
	return (i%n)*m + i / n;
}
int getPre(int i, int m, int n)//得到前驱
{
	return (i%m)*n + i / m;
}
void movedata(int *p, int i, int m, int n)//处理以下标为i的起点的环
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
void transpose(int *p, int m, int n)//转置
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
int homework8()//打开E盘中in文件，读取其中的数值并进行转置输出到out文件中
{
	ifstream in;
	in.open("E:\\in.txt");
	if (!in.is_open())
	{
		cout << "找不到in文件";
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
	delete[] p;//删除释放空间
	p = NULL;
	return 0;
}