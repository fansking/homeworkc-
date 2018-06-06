#include <iostream>
#include <fstream>
using namespace std;
void BinaryTxtFile_1(const char *BinaryFileName, const char *TxtFileName)
{
	ifstream in;
	in.open(BinaryFileName, ios::binary | ios::in);
	if (!in.is_open())return;
	ofstream out;
	out.open(TxtFileName);
	if (!out.is_open())return;
	int ncount = 0;
	in.read((char *)&ncount, 4);
	out << ncount << endl;
	double a = 0;
	in.read((char*)&a, 8);
	out << a << endl;
	for (int i = 0; i < ncount; i++)
	{
		double jingwei[2] = {};
		for (int j = 0; j < 2; j++)
		{
			in.read((char*)(jingwei + j), 8);
			out << jingwei[j] << endl;
		}
		long ID=0;
		in.read((char*)&ID, 4);
		out << ID<<endl;
		unsigned char len=0;
		in.read((char*)&len, 1);
		out << (int)len << endl;
		
		char cName[32] = {};
		in.read(cName, len);
		out << cName << endl;
		in.read((char*)&len, 1);
		out << (int)len << endl;
		char cID[32] = {};
		in.read(cID, len);
		out << cID << endl;
		
	}
	out.close();
	in.close();

}
int main()
{
	BinaryTxtFile_1("E:\\0527\\placename.dat", "E:\\test.txt");
}