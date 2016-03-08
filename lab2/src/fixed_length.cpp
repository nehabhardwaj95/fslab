
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string usn;
    string  name;
    string branch;
    string sem;
public:
    void read();
    void pack(string filename);
    void search(string,string);
    void modify(string);
    };
int main()
{
    int ch;
    //fstream f;

    Student s;
    string filename,key;
    while(1)
    {
    cout<<"1.insert 2.search 3.modify.4.exit\n";
    cout<<"enter your choice";
    cin>>ch;

         switch(ch)
        {
        case 1:
            s.read();
            cout<<"enter filename ";
            cin >> filename;
            s.pack(filename);
            break;
        case 2:
            cout<<"Enter the USN to be searched\n";
            cin>>key;
            cout<<"enter filename ";
                        cin >> filename;
            s.search(key,filename);
            break;
        case 3:
            s.modify(key);
            break;
        case 4:
          exit(0);
            

            }
        }
}
void Student::read(){
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter usn"<<endl;
    cin>>usn;
    cout<<"enter branch"<<endl;
    cin>>branch;
    cout<<"enter sem"<<endl;
    cin>>sem;
}
void Student::pack(string filename){
    string buffer;
    ofstream myf(filename.c_str(),ios::app);
    buffer= usn+"|"+name+"|"+sem+"|"+branch;
    buffer.resize(100,'$');
    myf<<buffer<<endl;
    myf.close();

}	
int Student::search(string key)
	{
		fstream fp1;
		string rcvusn;
		fp1.open("data2.txt",ios::in);
		while(!fp1.eof())
		{
			getline(fp1,buffer);
			cout<<"record read"<<endl;
			cout<<buffer<<endl;
			int pos=fp1.tellp();
			cout<<"position in file : "<<pos-101<<endl;
			rcvusn=unpack();
		if(usn==key)
		{
			return pos;
			cout<<"success"<<endl;
		}
		else
		{
			cout<<"not found"<<endl;
		}
		}
		return -1;
	}
	void Student::unpack()
	{
		string s;

			int i=0;
			cout<<endl<<endl;
			usn.erase();
			while(buffer[i]!='|')
			{
				usn+=buffer[i];
				i++;
			}
			i++;
			name.erase();
			while(buffer[i]!='|')
			{
				name+=buffer[i];
				i++;
			}
			i++;
			branch.erase();
			while(buffer[i]!='|')
			{
				branch+=buffer[i];
				i++;
			}
			i++;
			sem=0;
			while(buffer[i]!='$')
			{
				s=buffer[i];
				stringstream convert(s);
				convert>>sem;
				i++;
			}
			cout<<"usn is :"<<usn<<endl;
			cout<<"name is :"<<name<<endl;
			cout<<"branch is :"<<branch<<endl;
			cout<<"sem is :"<<sem<<endl;
			return usn;
	}
	void Student::modify(string key)
	{
		fstream fp1;
		cout<<"enter the filename to be modified"<<endl;
		char fln[10];
		cin>>fln;
		int choice;
		int pos1=search(key);
		if (pos1 < 0) {
			return;
		}
		pos1=pos1-101;
		cout<<"record modi pos :"<<pos1<<endl;
		cout<<"enter the field to be modified :\n1.Name\n2.USN\n3.branch\n4.sem"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				cout<<"Enter the new name :";
				cin>>name;
				cout<<endl;
				pack();
			}
			break;
		case 2:
			{
				cout<<"Enter the new USN :";
				cin>>usn;
				cout<<endl;
				pack();

			}
			break;
		case 3:
			{
				cout<<"Enter the new branch :";
				cin>>branch;
				cout<<endl;
				pack();

			}
			break;
		case 4:
			{
				cout<<"Enter the new sem :";
				cin>>sem;
				cout<<endl;
				pack();
			}
			break;
		default: cout<<"Enter a valid choice"<<endl;
		}
		fp1.open(fln);
		fp1.seekp(pos1,ios::beg);
		fp1<<buffer;
		fp1.close();
	}
}
