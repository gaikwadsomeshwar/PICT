#include "Queue.h"

Patient::Patient() {

	name=new char[25];
	city=new char[20];
	age=0;
	data=NULL;
}

void Patient::Admit() {

	data=new node();
	data->data=new Patient();

	cout<<"============================\n";
	cout<<"Name    : ";
	cin>>name;
	cout<<"Age     : ";
	cin>>age;
	cout<<"City    : ";
	cin>>city;

	cout<<"Disease Level\n";
	cout<<"1. General\n";
	cout<<"2. Emergency\n";
	cout<<"3. High Alert\n";
	cout<<"Your Choice: ";
	cin>>data->priority;

	while(data->priority>3 || data->priority<1) {

		cout<<"-------------------------\n";
		cout<<"Invalid Priority\n";
		cout<<"Disease Level\n";
		cout<<"1. General\n";
		cout<<"2. Emergency\n";
		cout<<"3. High Alert\n";
		cout<<"Your Choice: ";
		cin>>data->priority;
		cout<<"-------------------------\n";
	}

	strcpy(data->data->name,this->name);
	strcpy(data->data->city,this->city);
	data->data->age=this->age;

	Q.EnQueue(data);
}

void Patient::Display() { Q.Display(); }

void Patient::Attend() {

	data=Q.DeQueue();

	if(data==NULL)
		cout<<"Record Empty\n";

	else {

		cout<<"Attending Patient:\n";
		data->Display();
	}

	delete data;
}

int main() {

	Patient *P=new Patient();

	int ch,flag;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Accept Details\n";
		cout<<"2. Display Details\n";
		cout<<"3. Add a Patient\n";
		cout<<"4. Attend a Patient\n";
		cout<<"5. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || flag==1 || ch==5) {

			switch(ch) {

				case 1: {

					int Flag;

					do {

						cout<<"----------------------------\n";
						cout<<"0. Exit\n";
						cout<<"1. Add a Patient\n";
						cout<<"Your Choice: ";
						cin>>Flag;
						cout<<"----------------------------\n\n";

						if(Flag==0) break;

						else if(Flag==1) {

							P->Admit();
						}

						else cout<<"Select Correct Option\n";

					} while(true);

					flag=1;
					break;
				}

				case 2: {

					P->Display();
					break;
				}

				case 3: {

					P->Admit();
					break;
				}

				case 4: {

					P->Attend();
					break;
				}

				case 5: {

					cout<<"End\n";
					break;
				}

				default: cout<<"Select Correct Option\n\n";
			}
		}
		else {

			cout<<"Record Empty\n\n";
		}
	}
	while(ch!=5);

	return 0;
}
