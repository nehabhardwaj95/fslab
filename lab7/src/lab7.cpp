#include<stdio.h>
#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;
class match
{
int c1,c2;
public:
void load();
void coseq();
void sort();
string l1[100],l2[100];
};
void match::load()
{
c1=0;
c2=0;
fstream f1,f2;
string buf;
f1.open("data1.txt",ios::in);
while(!f1.eof())
{
getline(f1,buf);
l1[c1++]=buf;
}
f1.close();
f2.open("data2.txt",ios::in);
while(!f2.eof())
{
getline(f2,buf);
l2[c2++]=buf;
}
f2.close();
}
void match::coseq()
{
int i=0,j=0;
while(i<=c1 && j<=c2)
{
if(l1[i]<l2[j])
{
i++;
}
else if(l1[i]==l2[j])
{
cout<<l1[i]<<"\n";
i++;
j++;
}
else
{
j++;
}
}
}
void match::sort()
{
int i,j;
string temp;
for(i=0;i<c1-1;i++)
{
for(j=i+1;j<c1;j++)
{
if(l1[i]>l1[j])
{
temp=l1[i];
l1[i]=l1[j];
l1[j]=temp;
}
}
}
cout<<"sorted array1 is \n";
for(i=0;i<c1;i++)
{
cout<<l1[i]<<"\n";
}
for(i=0;i<c2-1;i++)
{
for(j=i+1;j<c2;j++)
{
if(l2[i]>l2[j])
{
temp=l2[i];
l2[i]=l2[j];
l2[j]=temp;
}
}
}
cout<<"sorted array2 is \n";
for(j=0;j<c2;j++)
{
cout<<l2[j]<<"\n";
}
}
int main()
{
match m;
m.load();
cout<<"before sort \n";
m.sort();
cout<<"after sorting \n";
cout<<"matching names are \n";
m.coseq();
}

