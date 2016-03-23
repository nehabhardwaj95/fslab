//============================================================================
// Name        : coseq.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class coseq
{
	string list1[100],list2[100];
	int count1,count2;
public:
	void load();
	void sort();
	void match();
	void read();
};
void coseq::load()
{
	fstream file,file1;
	string name;
	count1=-1;count2=-1;
	file.open("name1.txt",ios::out);
	name.erase();
	while(1)
	{
		cout<<"Enter the list1 names  ";
		cin>>name;
		if(name=="0")
			break;
		name=name+'\n';
		file<<name;
	}
	file.close();
	file.open("name1.txt");
	while (!file.eof()){
		name.erase();
		getline(file,name);
		list1[++count1]=name;
		cout<<"list\n"<<list1[count1];
		}
	file.close();

	file1.open("name2.txt",ios::out);
	name.erase();
	while(1)
	{
		cout<<"Enter the names for list2  ";
		cin>>name;
		if(name=="0")
			break;
		name=name+'\n';
		file1<<name;
	}
	file1.close();
	file1.open("name2.txt");
	while (!file1.eof())
	{
		name.erase();
		getline(file1,name);
		list2[++count2]=name;
		cout<<"inside list2\n"<<list2[count2];
	}

	file.close();
}
void coseq::match()
{
	fstream file;
	int i=0,j=0;
	string name;
	file.open("name3.txt",ios::out);
	while (i<=count1 && j<=count2)
	{
		if (list1[i]==list2[j])
		{
			cout<<"\n"<<list1[i];
			name=list1[i]+'\n';
			file<<name;
			i++;
			j++;
		}
		if (list1[i] < list2[j]) i++;
		if (list1[i] > list2[j]) j++;
	}
	file.close();
}

int main()
{
	coseq c;
	c.load();
	c.match();
	return 0;
}

