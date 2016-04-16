#include<iostream>
 #include<fstream>
 #include<vector>
 using namespace std;
 string merge(vector<string> filenames,int left,int right)
 {
 if(left==right)
 {
 return filenames[left];
 }
 else if((right-left)==1)
 {
 ifstream if1(filenames[left].c_str());
 ifstream if2(filenames[right].c_str());
 string newfile=filenames[left]+"a";
 ofstream of(newfile.c_str());
 string s1,s2;
 getline(if1,s1);
 getline(if2,s2);
 while(!if1.eof() && !if2.eof())
 {
 if(s1<s2)
 {
 of<<s1<<endl;
 getline(if1,s1);
 }
 else if(s1==s2)
 { if ( s1 != "" )
   of<<s2<<endl;
 getline(if1,s1);
 getline(if2,s2);
 }
 else
 {
 if(s2 != "")
    of<<s2<<endl;
 getline(if2,s2);
 }
 }
 while(!if1.eof()){
 if (s1 != "")
     of<<s1<<endl;
 getline(if1,s1);
 }
 while(!if2.eof())
 {
 if(s2 != "")
    of<<s2<<endl;
 getline(if2,s2);
 }
 if1.close();
 if2.close();
 of.close();
 return filenames[left]+"a";
 }

 else{
 int mid=(left+right)/2;
 string f1,f2;
 f1= merge(filenames,left,mid);
 f2=merge(filenames,mid+1,right);
 vector<string> v;
 v.push_back(f1);
 v.push_back(f2);
 return merge(v,0,1);
 }
 }

 int main()
 {
 vector<string> a;
 a.push_back("a1.txt");
 a.push_back("a2.txt");
 a.push_back("a3.txt");
 a.push_back("a4.txt");
 a.push_back("a5.txt");
 a.push_back("a6.txt");
 a.push_back("a7.txt");
 a.push_back("a8.txt");
 cout<<merge(a,0,7);
 return 0;
 }
