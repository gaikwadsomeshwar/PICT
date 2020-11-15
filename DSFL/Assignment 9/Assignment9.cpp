/*============================================================================
 	Title   : Hashing
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Store data of students with telephone no and name in the structure using
	hashing function for telephone number and implement chaining with and without
	replacement.
============================================================================*/

#include "table.h"

int main() {

	LP_withreplacement TR;
	LP_withoutreplacement TWR;
	int Ch,ch,flag=0,Flag=0,data;
	char dummy[1];
	student key;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Linear Probing with Replacement\n";
		cout<<"2. Linear Probing with Replacement\n";
		cout<<"3. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>Ch;
		cout<<"----------------------------\n\n";

		if(Ch==1) {

			Flag=0;
			flag=0;
			TR.init();
			do {

				cout<<"----------------------------\n";
				cout<<"Select the Options\n";
				cout<<"----------------------------\n";
				cout<<"1. Insert a Value\n";
				cout<<"2. Search for a Value\n";
				cout<<"3. Display Table\n";
				cout<<"4. Back\n\n";
				cout<<"Your Choice: ";
				cin>>ch;
				cout<<"----------------------------\n\n";

				if(ch==1 || flag==1 || ch==4) {

					switch(ch) {

						case 1: {

							do {

								cin.getline(dummy,1);
								cout<<"Name  : ";
								getline(cin,key.name);

								cout<<"Tel No: ";
								cin>>key.tel_number;

								Flag=TR.search(key.tel_number);

								if(Flag==1) {

									cout<<"Already the above record exists with same Telephone Number"<<endl;
									cout<<"Enter Again"<<endl;
								}
								cout<<"----------------------------\n";
							}
							while(Flag==1);

							TR.insert(key);

							flag=1;
							cout<<endl;
							break;
						}

						case 2: {

							cout<<"Tel No: ";
							cin>>key.tel_number;
							Flag=TR.search(key.tel_number);

							if(Flag==0)
								cout<<"Data not Found\n";
							cout<<endl;
							break;
						}

						case 3: {

							TR.display();
							cout<<endl;
							break;
						}

						case 4: {

							break;
						}

						default: cout<<"Select Correct Option\n\n";
					}
				}
				else {

					cout<<"Graph not Created\n\n";
				}
			}
			while(ch!=4);
		}

		else if(Ch==2) {

			Flag=0;
			flag=0;
			TWR.init();
			do {

				cout<<"----------------------------\n";
				cout<<"Select the Options\n";
				cout<<"----------------------------\n";
				cout<<"1. Insert a Value\n";
				cout<<"2. Search for a Value\n";
				cout<<"3. Display Table\n";
				cout<<"4. Back\n\n";
				cout<<"Your Choice: ";
				cin>>ch;
				cout<<"----------------------------\n\n";

				if(ch==1 || flag==1 || ch==4) {

					switch(ch) {

						case 1: {

							do {

								cin.getline(dummy,1);
								cout<<"Name  : ";
								getline(cin,key.name);

								cout<<"Tel No: ";
								cin>>key.tel_number;

								Flag=TWR.search(key.tel_number);

								if(Flag==1) {

									cout<<"Already the above record exists with same Telephone Number"<<endl;
									cout<<"Enter Again"<<endl;
								}
								cout<<"----------------------------\n";
							}
							while(Flag==1);

							TWR.insert(key);

							flag=1;
							cout<<endl;
							break;
						}

						case 2: {

							cout<<"Tel No: ";
							cin>>key.tel_number;
							Flag=TWR.search(key.tel_number);

							if(Flag==0)
								cout<<"Data not Found\n";
							cout<<endl;
							break;
						}

						case 3: {

							TWR.display();
							cout<<endl;
							break;
						}

						case 4: {

							break;
						}

						default: cout<<"Select Correct Option\n\n";
					}
				}
				else {

					cout<<"Graph not Created\n\n";
				}
			}
			while(ch!=4);
		}

		else if(Ch==3) {

			cout<<"End\n";
			break;
		}

		else cout<<"Select Correct Option\n";
	}
	while(Ch!=3);

	return 0;
}
