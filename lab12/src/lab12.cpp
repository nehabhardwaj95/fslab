//============================================================================
// Name        : lab12.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : programs.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;
class student
	{
	private:
		string name,usn,sem;
	public:
		void read();
		void pack(char * xyz);
		void write();
	};
void student::read()
{
	cout<<"enter name";
	cin>> name;
	cout<<"enter usn";
	cin>>usn;
	cout<<"enter sem";
	cin>>sem;
}

void student::pack(char * fname)
{
	 fstream fp;
	 string buffer;
	 buffer=name+'|'+usn+'|'+sem;
	 buffer.resize(100,'*');
	 fp.open(fname,ios::out);
	 fp<<buffer;
	 fp.close();
}
int main()
{
	student s;
	char * abc;
	int ch;
	while(1)
	{
	cout<<"1.insert\t 2.search\t 3.delete\t 4.modification\t 5.exit\t";
	cout<<"enter your choice";
	cin>>ch;
	switch(ch)
	{
	case 1: cout<< "enter filename";
	cin>> abc;
	s.read();
	s.pack(abc);
	break;
	case 5: cout<<"wrong input";
	break;
}
	}
	return 0;
}
