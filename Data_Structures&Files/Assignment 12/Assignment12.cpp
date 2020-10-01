/*============================================================================
 	Title   : Direct Access File
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Implement direct access file using hashing ( chaining without replacement)
	perform following operations on it
	a. Create Database
	b. Display Database
	c. Add a record
	d. Search a record
	e. Modify a record
============================================================================*/

#include<iostream>
#include<fstream>
using namespace std;

typedef struct {

	int empid;
	float salary;
	string name;
	int chain;
}
emp;

class File {

	fstream F;
	int size;

public:

	void create();
	void insert();
	int search(int empid);
	int update(int empid);
	int dlete(int empid);
	void display();
};

void File::create() {

	int i;
	emp E;
	E.empid=-1;
	E.salary=-1;
	E.name="";
	E.chain=-1;

	F.open("Employee.txt",ios::out);

	cout<<"Enter Size: ";
	cin>>size;

	if(F) {

		for(i=0;i<size;i++)
			F.write((char*)&E,sizeof(E));
		F.close();
	}
}

void File::insert() {

	int i,j,LOC,offset;
	char dummy[1];
	emp E,temp;

	cout<<"Employee ID : ";
	cin>>E.empid;

	while(search(E.empid)!=-1) {

		cout<<"\n----------------------------\n\n";
		cout<<"Employee already exits. Enter Another\n\n";
		cout<<"----------------------------\n\n";
		cout<<"Employee ID : ";
		cin>>E.empid;
	}

	cin.getline(dummy,1);
	cout<<"Name        : ";
	getline(cin,E.name);

	cout<<"Salary      : ";
	cin>>E.salary;
	E.chain=-1;

	F.open("Employee.txt");
	LOC=E.empid%size;
	i=0;
	j=LOC;
	offset=j*sizeof(temp);
	F.seekg(offset,ios::beg);
	F.read((char*)&temp,sizeof(temp));

	while(i<size && temp.empid!=-1) {

		if(temp.empid%size==LOC)
			break;
		j=(j+1)%size;
		i++;
		offset=j*sizeof(temp);
		F.seekg(offset,ios::beg);
		F.read((char*)&temp,sizeof(temp));
	}

	if(i==size) {

		F.close();
		cout<<"File is Full"<<endl;
		return;
	}

	while(temp.chain!=-1) {

		j=temp.chain;
		offset=j*sizeof(temp);
		F.seekg(offset,ios::beg);
		F.read((char*)&temp,sizeof(temp));
	}

	LOC=j;

	while(temp.empid!=-1 && i<size) {

		LOC=(LOC+1)%size;
		i++;
		offset=LOC*sizeof(temp);
		F.seekg(offset,ios::beg);
		F.read((char*)&temp,sizeof(temp));
	}

	if(i==size) {

		F.close();
		cout<<"File is Full"<<endl;
		return;
	}

	offset=LOC*sizeof(temp);
	F.seekp(offset,ios::beg);
	F.write((char*)&E,sizeof(E));

	if(j!=LOC) {

		offset=j*sizeof(temp);

		F.seekg(offset,ios::beg);
		F.read((char*)&temp,sizeof(temp));
		temp.chain=LOC;

		F.seekp(offset,ios::beg);
		F.write((char*)&temp,sizeof(temp));
	}
	F.close();
}

int File::search(int empid) {

	emp E;
	int i,j,LOC,offset;
	F.open("Employee.txt");

	i=0;
	LOC=empid%size;
	j=LOC;
	offset=j*sizeof(E);
	F.seekg(offset,ios::beg);
	F.read((char*)&E,sizeof(E));

	while(i<size) {

		if(E.empid%size==LOC)
			break;
		j=(j+1)%size;
		i++;
		offset=j*sizeof(E);
		F.seekg(offset,ios::beg);
		F.read((char*)&E,sizeof(E));
	}

	if(i==size) {

		F.close();
		return -1;
	}

	while(E.chain!=-1) {

		if(E.empid==empid) {

			cout<<"----------------------------\n\n";
			cout<<"Record Found:\n\n";
			cout<<"Employee ID : "<<E.empid<<endl<<"Name        : "<<E.name<<endl<<"Salary      : "<<E.salary<<endl;
			F.close();
			return j;
		}
		j=E.chain;
		offset=j*sizeof(E);
		F.seekg(offset,ios::beg);
		F.read((char*)&E,sizeof(E));
	}

	if(E.empid==empid) {

		cout<<"----------------------------\n\n";
		cout<<"Record Found:\n\n";
		cout<<"Employee ID : "<<E.empid<<endl<<"Name        : "<<E.name<<endl<<"Salary      : "<<E.salary<<endl;
		F.close();
		return j;
	}

	F.close();
	return -1;
}

int File::update(int empid) {

	emp E;
	char dummy[1];
	int j=search(empid),offset;

	if(j!=-1) {

		cout<<"----------------------------\n\n";
		cout<<"Updating the Record\n\n";

		F.open("Employee.txt");
		offset=j*sizeof(E);
		F.seekg(offset,ios::beg);
		F.read((char*)&E,sizeof(E));

		cin.getline(dummy,1);
		cout<<"New Name    : ";
		getline(cin,E.name);

		cout<<"New Salary  : ";
		cin>>E.salary;

		F.seekp(offset,ios::beg);
		F.write((char*)&E,sizeof(E));
		F.close();
		return 1;
	}
	F.close();
	return 0;
}

int File::dlete(int empid) {

	emp E,temp;
	int i,j,LOC,offset,flag=0;
	F.open("Employee.txt");

	i=0;
	LOC=empid%size;
	j=LOC;
	offset=j*sizeof(E);
	F.seekg(offset,ios::beg);
	F.read((char*)&E,sizeof(E));

	while(i<size) {

		if(E.empid%size==LOC)
			break;
		j=(j+1)%size;
		i++;
		offset=j*sizeof(E);
		F.seekg(offset,ios::beg);
		F.read((char*)&E,sizeof(E));
	}

	if(i==size) {

		F.close();
		return 0;
	}

	LOC=j;
	while(E.chain!=-1) {

		if(E.empid==empid) {

			cout<<"----------------------------\n\n";
			cout<<"Record Found:\n\n";
			cout<<"Employee ID : "<<E.empid<<endl<<"Name        : "<<E.name<<endl<<"Salary      : "<<E.salary<<endl;
			cout<<"----------------------------\n\n";
			cout<<"Deleting the Record\n";
			flag=1;
			break;
		}
		LOC=j;
		j=E.chain;
		offset=j*sizeof(E);
		F.seekg(offset,ios::beg);
		F.read((char*)&E,sizeof(E));
	}

	if(E.empid==empid && !flag) {

		cout<<"----------------------------\n\n";
		cout<<"Record Found:\n\n";
		cout<<"Employee ID : "<<E.empid<<endl<<"Name        : "<<E.name<<endl<<"Salary      : "<<E.salary<<endl;
		cout<<"----------------------------\n\n";
		cout<<"Deleting the Record\n";
		flag=1;
	}

	if(flag==1) {

		offset=LOC*sizeof(E);
		F.seekg(offset,ios::beg);
		F.read((char*)&E,sizeof(E));

		offset=j*sizeof(temp);
		F.seekg(offset,ios::beg);
		F.read((char*)&temp,sizeof(temp));

		E.chain=temp.chain;
		temp.name="";
		temp.empid=-1;
		temp.salary=-1;
		temp.chain=-1;

		offset=LOC*sizeof(E);
		F.seekp(offset,ios::beg);
		F.write((char*)&E,sizeof(E));

		offset=j*sizeof(temp);
		F.seekp(offset,ios::beg);
		F.write((char*)&temp,sizeof(temp));
		F.close();
		return 1;
	}

	F.close();
	return 0;
}

void File::display() {

	emp E;
	F.open("Employee.txt");
  cout<<"----------------------------\n";
	cout<<"Emp ID \t Name \t Salary \t Chain\n";
	cout<<"----------------------------\n";

	while(F.read((char*)&E,sizeof(E)))
		cout<<E.empid<<"\t"<<E.name<<"\t"<<E.salary<<"\t"<<E.chain<<endl;
	F.close();
}

int main() {

	File F;
	int ch,flag,empid;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Create File\n";
		cout<<"2. Add a Record\n";
		cout<<"3. Search a Record\n";
		cout<<"4. Update a Record\n";
		cout<<"5. Delete a Record\n";
		cout<<"6. Display Records\n";
		cout<<"7. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		switch(ch) {

			case 1: {

				F.create();
				cout<<endl;
				break;
			}

			case 2: {

				F.insert();
				cout<<endl;
				break;
			}

			case 3: {

				cout<<"Employee ID: ";
				cin>>empid;
				cout<<endl;
				flag=F.search(empid);
				if(flag==-1) {
					cout<<"----------------------------\n\n";
					cout<<"Record not Found\n";
				}
				cout<<endl;
				break;
			}

			case 4: {

				cout<<"Employee ID: ";
				cin>>empid;
				cout<<endl;
				flag=F.update(empid);
				if(!flag) {
					cout<<"----------------------------\n\n";
					cout<<"Record not Found\n";
				}
				cout<<endl;
				break;
			}

			case 5: {

				cout<<"Employee ID: ";
				cin>>empid;
				cout<<endl;
				flag=F.dlete(empid);
				if(!flag) {
					cout<<"----------------------------\n\n";
					cout<<"Record not Found\n";
				}
				cout<<endl;
				break;
			}

			case 6: {

				F.display();
				cout<<endl;
				break;
			}

			case 7: {

				cout<<"End\n";
				break;
			}

			default: cout<<"Select Correct Option\n\n";
		}
	}
	while(ch!=7);

	return 0;
}
