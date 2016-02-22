//============================================================================
// Name        : pgm2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;
class student{
	string usn,name,sem;
public:
	void read();

void pack(char *fname);
//void write();
};
int i,n;
void student::read()
{

	cout<<"enter number of records\n";
	cin>>n;

	cout<<"enter name";
	cin>>name;
	cout<<"enter usn";
	cin>>usn;
	cout<<"enter sem";
	cin>>sem;

}

void student::pack(char *fname)
{
	fstream fp;
	string buffer;
	buffer=usn+'|'+name+'|'+sem;
	buffer.resize(100,'$');
fp.open(fname,ios::out);
		fp<<buffer;
fp.close();
}
int main()
{
	student s;
	char *fname;
	int ch;
	cout<<"1.insert\t 2.search\t 3.delete\t 4.modification\n";
	cout<<"enter your choice\n";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"insert\n";
		cout<<"enter the filename\n";
	cin>>fname;
	s.read();
	s.pack(fname);
	}


return 0;
}


