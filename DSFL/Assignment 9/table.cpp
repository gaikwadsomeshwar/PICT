#include "table.h"

void LP_withoutreplacement::init() {

	for(int i=0;i<MAX;i++) {

		Records[i].stud.name="\0";
		Records[i].stud.tel_number=-1;
		Records[i].flag=0;
		Records[i].chain=-1;
	}
}

void LP_withoutreplacement::insert(student key) {

	int i,j,LOC;

	LOC=key.tel_number%MAX;
	i=0;
	j=LOC;

	while(i<MAX && Records[j].flag==1) {

		if(Records[j].stud.tel_number%MAX==LOC)
			break;
		j=(j+1)%MAX;
		i++;
	}

	if(i==MAX) {

		cout<<"Table is Full"<<endl;
		return;
	}

	while(Records[j].chain!=-1)
		j=Records[j].chain;

	LOC=j;

	while(Records[LOC].flag==1 && i<MAX) {

		LOC=(LOC+1)%MAX;
		i++;
	}

	if(i==MAX) {

		cout<<"Table is Full"<<endl;
		return;
	}

	Records[LOC].stud=key;
	Records[LOC].flag=1;

	if(j!=LOC)
		Records[j].chain=LOC;
}

int LP_withoutreplacement::search(long tel_number) {

	int i,LOC;

	LOC=tel_number%MAX;
	i=0;

	while(i<MAX && Records[LOC].flag==1 && Records[LOC].stud.tel_number%MAX!=LOC) {

		i++;
		LOC=(LOC+1)%MAX;
	}

	if(Records[LOC].flag==0 || i==MAX)
		return 0;

	while(LOC!=-1) {

		if(Records[LOC].stud.tel_number==tel_number) {

			cout<<"Data Found: Name: "<<Records[LOC].stud.name<<" Tel No: "<<Records[LOC].stud.tel_number<<endl;
			return 1;
		}
		LOC=Records[LOC].chain;
	}
	return 0;
}

void LP_withoutreplacement::display() {

	cout<<"Index \t Name \t Tel No \t Flag \t Chain"<<endl;

	for(int i=0;i<MAX;i++)
		cout<<i<<"\t"<<Records[i].stud.name<<"\t"<<Records[i].stud.tel_number<<"\t"<<Records[i].flag<<"\t"<<Records[i].chain<<endl;
}

void LP_withreplacement::init() {

	for(int i=0;i<MAX;i++) {

		Records[i].stud.name="\0";
		Records[i].stud.tel_number=-1;
		Records[i].flag=0;
		Records[i].chain=-1;
	}
}

void LP_withreplacement::insert(student key) {

	int i,j,LOC;

	LOC=key.tel_number%MAX;

	if(Records[LOC].flag==0) {

		Records[LOC].stud=key;
		Records[LOC].flag=1;
		return;
	}

	i=0;
	j=LOC;

	while(i<MAX && Records[j].flag==1) {

		i++;
		j=(j+1)%MAX;
	}

	if(i==MAX) {

		cout<<"Table is Full"<<endl;
		return;
	}

	if(Records[LOC].stud.tel_number%MAX!=LOC) {

		i=Records[LOC].stud.tel_number%MAX;

		while(Records[i].chain!=LOC)
			i=Records[i].chain;
		Records[i].chain=Records[LOC].chain;

		while(Records[i].chain!=-1)
			i=Records[i].chain;

		Records[i].chain=j;
		Records[j].stud=Records[LOC].stud;
		Records[j].flag=1;
		Records[j].chain=-1;

		Records[LOC].stud=key;
		Records[LOC].flag=1;
		Records[LOC].chain=-1;
		return;
	}

	if(Records[LOC].stud.tel_number%MAX==LOC) {

		Records[j].stud=key;
		Records[j].flag=1;
		Records[j].chain=-1;
		i=LOC;

		while(Records[i].chain!=-1)
			i=Records[i].chain;
		Records[i].chain=j;
	}
}

int LP_withreplacement::search(long tel_number) {

	int i,LOC;

	LOC=tel_number%MAX;
	i=0;

	while(i<MAX && Records[LOC].flag==1 && Records[LOC].stud.tel_number%MAX!=LOC) {

		i++;
		LOC=(LOC+1)%MAX;
	}

	if(Records[LOC].flag==0 || i==MAX)
		return 0;

	while(LOC!=-1) {

		if(Records[LOC].stud.tel_number==tel_number) {

			cout<<"Data Found: Name: "<<Records[LOC].stud.name<<" Tel No: "<<Records[LOC].stud.tel_number<<endl;
			return 1;
		}
		LOC=Records[LOC].chain;
	}
	return 0;
}

void LP_withreplacement::display() {

	cout<<"Index \t Name \t Tel No \t Flag \t Chain"<<endl;

	for(int i=0;i<MAX;i++)
		cout<<i<<"\t"<<Records[i].stud.name<<"\t"<<Records[i].stud.tel_number<<"\t"<<Records[i].flag<<"\t"<<Records[i].chain<<endl;
}
