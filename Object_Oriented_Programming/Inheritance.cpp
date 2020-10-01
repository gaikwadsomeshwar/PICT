/*
================================================================
Title     : Inheritance
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Design a base class with name, date of birth, blood group and another base
class consisting of the data members such as height and weight. Design one more
base class consisting of the insurance policy number and contact address.
The derived class contains the data members’ telephone numbers and driving
license number. Write a menu driven program to carry out the following things:

1. Build a master table
2. Display Record
3. Insert  a record
4. Delete record
5. Edit  record
6. Search  for a record
================================================================*/

#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
using namespace std;

struct Temp {       //For temporary storage

    char Name[50],Blood_grp[3],Add[50];
    int Dob[3];
    float Weight,Height;
    long int Phone_no,Dl_no;
};

class PersonalDetails {      //Contains Personal Details

protected:

    char name[50];
    int dob[3];
    char blood_grp[3];
};

class PhysicalDetails {    //Contains Physical Details

protected:

    float height;
    float weight;
};

class EmergencyDetails {   //Contains Emergency Details

protected:

    long int policy_no;
    char add[50];
};

class Record:public PersonalDetails,public PhysicalDetails,public EmergencyDetails {
            //Inherits 3 base classes
private:

    long int phone_no;
    long int dl_no;

public:

    void Set_Data(Record R[],int n);         //Accepts values for data members
    void Get_Data();                        //Displays data members
    void Edit_Data(int ch);                //Edits data members
    int Search(struct Temp t,int ch);     //Searches for a data member
};

void Record::Set_Data(Record R[],int n) {   //Accepting data members of all classes

    struct Temp t;
    int i,flag=1;
    char dummy[1];

    cin.getline(dummy,1);
    cout<<"Name: ";
    cin.getline(name,49);

    cout<<"Date of Birth:\n";
    cout<<"Year: ";
    cin>>dob[2];

    while(dob[2]>2019 || dob[2]<1) {        //Validation for date of birth
      cout<<"\nInvalid Year\n";
      cout<<"Enter again:\n\n";
      cout<<"Year: ";
      cin>>dob[2];
    }

    cout<<"Month: ";
    cin>>dob[1];

    while(dob[1]>12 || dob[1]<1) {         //Validation for date of birth
      cout<<"\nInvalid Month\n";
      cout<<"Enter again:\n\n";
      cout<<"Month: ";
      cin>>dob[1];
    }

    cout<<"Day: ";
    cin>>dob[0];

    while(dob[0]>30 || dob[0]<0) {        //Validation for date of birth
      cout<<"\nInvalid Day\n";
      cout<<"Enter again:\n\n";
      cout<<"Day: ";
      cin>>dob[1];
    }

    cout<<"Blood Group: ";
    cin>>blood_grp;

    for(int i=0;i<strlen(blood_grp);i++) {
      if(isalpha(blood_grp[i])!=0)
        blood_grp[i]=toupper(blood_grp[i]);
    }

    do {                //Validation for blood group

      if(strcmp(blood_grp,"A+")==0)
        break;

      else if(strcmp(blood_grp,"B+")==0)
        break;

      else if(strcmp(blood_grp,"AB+")==0)
        break;

      else if(strcmp(blood_grp,"O+")==0)
        break;

      else if(strcmp(blood_grp,"A-")==0)
        break;

      else if(strcmp(blood_grp,"B-")==0)
        break;

      else if(strcmp(blood_grp,"AB-")==0)
        break;

      else if(strcmp(blood_grp,"O-")==0)
        break;

      else {

        cout<<"\nInvalid Blood Group\n";
        cout<<"Enter Again:\n\n";
        cout<<"Blood Group: ";
        cin>>blood_grp;

        for(int i=0;i<strlen(blood_grp);i++) {
          if(isalpha(blood_grp[i])!=0)
            blood_grp[i]=toupper(blood_grp[i]);
        }
      }
    }
    while(1);

    cout<<"Height: ";
    cin>>height;

    cout<<"Weight: ";
    cin>>weight;

    cout<<"Insurance Policy Number: ";
    cin>>policy_no;

    cin.getline(dummy,1);
    cout<<"Address: ";
    cin.getline(add,49);

    cout<<"Phone no: ";
    cin>>t.Phone_no;

    for(i=0;i<n;)             //Validation for phone number
    {
        int flag=R[i].Search(t,8);     //Checking for duplicates

        if(flag==1)
        {
            cout<<"\nPhone Number already exists\n";
            cout<<"Enter a different phone number: ";
            cin>>t.Phone_no;
            cout<<"\n\n";
            i=0;
        }

        else
        {
            i++;
        }
    }

    phone_no=t.Phone_no;

    cout<<"Driver's License Number: ";
    cin>>t.Dl_no;

    for(i=0;i<n;) {                   //Validation for driver's license

        int flag=R[i].Search(t,7);

        if(flag==1)
        {
            cout<<"\nDriver's License Number already exists\n";   //Checking for duplicates
            cout<<"Enter a different phone number: ";
            cin>>t.Dl_no;
            cout<<"\n\n";
            i=0;
        }

        else
        {
            i++;
        }
    }

    dl_no=t.Dl_no;

    cout<<"\n\n";
}

void Record::Get_Data() {     //Printing all data members

    cout<<setw(20)<<name<<setw(11)<<dob[0]<<"/"<<dob[1]<<"/"<<dob[2]<<setw(8)<<blood_grp;
    cout<<setw(7)<<height<<setw(7)<<weight;
    cout<<setw(15)<<policy_no<<setw(12)<<phone_no<<setw(15)<<dl_no<<"\t"<<add<<"\n";
}

void Record::Edit_Data(int ch) {   //Editing a particular data member according to the choice

    char dummy[1];

    switch(ch) {

        case 1: {

            cout<<"New Height: ";
            cin>>height;
            break;
        }

        case 2: {

            cout<<"New Weight: ";
            cin>>weight;
            break;
        }

        case 3: {

            cin.getline(dummy,1);
            cout<<"New Address: ";
            cin.getline(add,49);
            break;
        }

        case 4: {

            cout<<"New Phone Number: ";
            cin>>phone_no;
            break;
        }
    }
}

int Record::Search(struct Temp t,int ch) {     //Searching a data member according to a choice

    switch(ch) {

        case 1: {

            if(strcmp(t.Name,name)==0)
                return 1;

            break;
        }

        case 2: {

            if(t.Dob[0]==dob[0] && t.Dob[1]==dob[0] && t.Dob[2]==dob[0])
                return 1;

            break;
        }

        case 3: {

            if(strcmp(t.Blood_grp,blood_grp)==0)
                return 1;

            break;
        }

        case 4:{

            if(t.Weight==weight)
                return 1;

            break;
        }

        case 5: {

            if(t.Height==height)
                return 1;

            break;
        }

        case 6: {

            if(strcmp(t.Add,add)==0)
                return 1;

            break;
        }

        case 7: {

            if(t.Dl_no==dl_no)
                return 1;

            break;
        }

        case 8: {

            if(t.Phone_no==phone_no)
                return 1;

            break;
        }
    }

    return -1;
}

int main() {

    int ch,Ch,n,i,Pos,flag=0;
    static int pos;

    Record R[50];
    struct Temp t;

    do {

        cout<<"1. Build Master Table\n";
        cout<<"2. Display Records\n";
        cout<<"3. Insert a Record\n";
        cout<<"4. Delete a Record\n";           //Menu for user
        cout<<"5. Edit a Record\n";
        cout<<"6. Search a Record\n";
        cout<<"7. Exit\n\n";
        cout<<"Your Choice: ";
        cin>>ch;

        cout<<"\n\n";

        if(ch==1 || ch==7 || flag==1) {

          switch(ch) {

            case 1: {

                char dummy[1];

                n=0;
                pos=0;

                cout<<"Enter the number of Records you want to add: ";
                cin>>n;

                cout<<"\n\n";

                n=n+pos;

                for(i=pos;i<n && i<50;i++)
                {
                    R[i].Set_Data(R,i);         //function call for Accepting values
                }
                pos=i;

                if(i==50)
                {
                    cout<<"Record Full";     //Maximum 50 records
                }

                cout<<"\n\n";
                flag=1;

                break;
            }

            case 2: {

                cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
                cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                for(i=0;i<pos;i++)
                {
                    R[i].Get_Data();     //function call for Printing records
                }

                cout<<"\n\n";
                break;
            }

            case 3: {

                R[pos].Set_Data(R,pos);
                pos++;

                cout<<"\n\n";
                break;
            }

            case 4: {

                cout<<"To delete a Record, enter Driver's License Number: ";
                cin>>t.Dl_no;

                Pos=-1;

                for(i=0;i<pos;i++)
                {
                    Pos=R[i].Search(t,7);     //Searching for the record to be deleted
                    if(Pos==1)
                    {
                        Pos=i;
                        break;
                    }
                }

                if(Pos!=-1)
                {
                    cout<<"\nDeleting Record:\n";
                    cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
                    cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                    cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                    R[Pos].Get_Data();

                    for(i=Pos;i<pos-1;i++)
                    {
                        R[i]=R[i+1];   //Deleting Record
                    }
                    pos=pos-1;

                    cout<<"\nDelete Successful";
                }

                else
                {
                    cout<<"Record not Found";
                }

                cout<<"\n\n";
                break;
            }

            case 5: {

                cout<<"Edit the following:\n";
                cout<<"1. Height\n";
                cout<<"2. Weight\n";
                cout<<"3. Address\n";
                cout<<"4. Phone Number\n";         //Sub-menu for user
                cout<<"5. Back\n\n";
                cout<<"Your Choice: ";
                cin>>Ch;

                cout<<"\n\n";

                while(Ch>5 || Ch<1) {

                    cout<<"Enter a value between 1 and 4\n";
                    cout<<"Enter Again\n\n";
                    cout<<"Your Choice: ";
                    cin>>Ch;
                }

                if(Ch==5)
                    break;

                cout<<"To edit a Record, enter Driver's License Number: ";
                cin>>t.Dl_no;

                Pos=-1;

                for(i=0;i<pos;i++)
                {
                    Pos=R[i].Search(t,7);  //Searching for a particular field
                    if(Pos==1)
                    {
                        Pos=i;
                        break;
                    }
                }

                if(Pos!=-1)
                {
                    R[Pos].Edit_Data(Ch);      //function call for Editing record
                }

                else
                {
                    cout<<"Record not Found";
                }

                cout<<"\n\n";
                break;
            }

            case 6: {  //Serching for a particular field

                char dummy[1];
                int flag=0,Flag;

                cout<<"Search By:\n";
                cout<<"1. Name\n";
                cout<<"2. Date of Birth\n";
                cout<<"3. Blood Group\n";
                cout<<"4. Weight\n";                        //Sub-menu for user
                cout<<"5. Height\n";
                cout<<"6. Address\n";
                cout<<"7. Driver's License Number\n";
                cout<<"8. Phone Number\n";
                cout<<"9. Back\n\n";
                cout<<"Your Choice: ";
                cin>>Ch;

                cout<<"\n\n";

                while(Ch>9 || Ch<1) {

                    cout<<"Enter a value between 1 and 4\n";
                    cout<<"Enter Again\n\n";

                    cout<<"Your Choice: ";
                    cin>>Ch;
                    cout<<"\n\n";
                }

                if(Ch==9) {
                    break;
                }

                switch(Ch) {

                    case 1: {

                        cin.getline(dummy,1);
                        cout<<"Enter name: ";
                        cin.getline(t.Name,49);

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 2: {

                        cout<<"Enter Date of Birth:\n";
                        cout<<"Year: ";
                        cin>>t.Dob[2];
                        cout<<"Month: ";
                        cin>>t.Dob[1];
                        cout<<"Day: ";
                        cin>>t.Dob[0];

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 3: {

                        cout<<"Enter Blood Group: ";
                        cin>>t.Blood_grp;

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 4: {

                        cout<<"Enter Weight: ";
                        cin>>t.Weight;

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 5: {

                        cout<<"Enter Height: ";
                        cin>>t.Height;

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 6: {

                        cin.getline(dummy,1);
                        cout<<"Enter Address: ";
                        cin.getline(t.Add,49);

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 7: {

                        cout<<"Enter Driver's License Number: ";
                        cin>>t.Dl_no;

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }

                    case 8: {

                        cout<<"Enter Phone Number: ";
                        cin>>t.Phone_no;

                        cout<<"\n\n----------------------------------------------------------------------------------------------------------------------------\n";
                        cout<<setw(15)<<"Name"<<setw(18)<<"DOB"<<setw(12)<<"Bl. Grp."<<setw(8)<<"Ht.(cm)"<<setw(8)<<"Wt.(kg)"<<setw(15)<<"Policy No."<<setw(12)<<"Phone No."<<setw(15)<<"Driver's Lic. No.\t Address\n";
                        cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                        for(i=0;i<pos;i++)
                        {
                            Flag=R[i].Search(t,Ch);

                            if(Flag==1)
                            {
                                R[i].Get_Data();
                                flag=1;
                            }
                        }

                        if(flag==0)
                            cout<<"No Record Found";

                        break;
                    }
                }

                cout<<"\n\n";
                break;
            }

            case 7: {

                cout<<"End\n\n";
                break;
            }

            default:

                cout<<"Enter a value between 1 and 7\n\n";

        }
      }
      else
      {
        cout<<"Create a Master Table 1st\n\n";
      }

    }
    while(ch!=7);

    return 0;
}

/*
Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Inheritance
1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 2


Create a Master Table 1st

1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 1


Enter the number of Records you want to add: 2


Name: Someshwar
Date of Birth:
Year: 1999
Month: 12
Day: 15
Blood Group: n+

Invalid Blood Group
Enter Again:

Blood Group: o+
Height: 173
Weight: 75
Insurance Policy Number: 8345395340535
Address: 234234234
Phone no: 845645969450
Driver's License Number: 5325462748234


Name: Muskaan
Date of Birth:
Year: 2000
Month: 5
Day: 12
Blood Group: o-
Height: 167
Weight: 55
Insurance Policy Number: 234928349823
Address: Akola
Phone no: 8456486540
Driver's License Number: 32432552296




1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 2


----------------------------------------------------------------------------------------------------------------------------
           Name               DOB    Bl. Grp. Ht.(cm) Wt.(kg)     Policy No.   Phone No.Driver's Lic. No.	 Address
----------------------------------------------------------------------------------------------------------------------------
           Someshwar         15/12/1999      O+    173     75  8345395340535845645969450  5325462748234	234234234
             Muskaan         12/5/2000      O-    167     55   234928349823  8456486540    32432552296	Akola


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 5


Edit the following:
1. Height
2. Weight
3. Address
4. Phone Number
5. Back

Your Choice: 3


To edit a Record, enter Driver's License Number: 5325462748234
New Address: Mundhwa


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 2


----------------------------------------------------------------------------------------------------------------------------
           Name               DOB    Bl. Grp. Ht.(cm) Wt.(kg)     Policy No.   Phone No.Driver's Lic. No.	 Address
----------------------------------------------------------------------------------------------------------------------------
           Someshwar         15/12/1999      O+    173     75  8345395340535845645969450  5325462748234	Mundhwa
             Muskaan         12/5/2000      O-    167     55   234928349823  8456486540    32432552296	Akola


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 3


Name: Shreyas
Date of Birth:
Year: 2001
Month: 1
Day: 16
Blood Group: b+
Height: 175
Weight: 61
Insurance Policy Number: 83475837593
Address: Pune
Phone no: 8772398223
Driver's License Number: 903534535345




1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 2


----------------------------------------------------------------------------------------------------------------------------
           Name               DOB    Bl. Grp. Ht.(cm) Wt.(kg)     Policy No.   Phone No.Driver's Lic. No.	 Address
----------------------------------------------------------------------------------------------------------------------------
           Someshwar         15/12/1999      O+    173     75  8345395340535845645969450  5325462748234	Mundhwa
             Muskaan         12/5/2000      O-    167     55   234928349823  8456486540    32432552296	Akola
             Shreyas         16/1/2001      B+    175     61    83475837593  8772398223   903534535345	Pune


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 6


Search By:
1. Name
2. Date of Birth
3. Blood Group
4. Weight
5. Height
6. Address
7. Driver's License Number
8. Phone Number
9. Back

Your Choice: 1


Enter name: Someshwar
           Someshwar         15/12/1999      O+    173     75  8345395340535845645969450  5325462748234	Mundhwa


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 2


----------------------------------------------------------------------------------------------------------------------------
           Name               DOB    Bl. Grp. Ht.(cm) Wt.(kg)     Policy No.   Phone No.Driver's Lic. No.	 Address
----------------------------------------------------------------------------------------------------------------------------
           Someshwar         15/12/1999      O+    173     75  8345395340535845645969450  5325462748234	Mundhwa
             Muskaan         12/5/2000      O-    167     55   234928349823  8456486540    32432552296	Akola
             Shreyas         16/1/2001      B+    175     61    83475837593  8772398223   903534535345	Pune


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 4


To delete a Record, enter Driver's License Number: 8456486540
Record not Found

1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 4


To delete a Record, enter Driver's License Number: 32432552296

Deleting Record:
----------------------------------------------------------------------------------------------------------------------------
           Name               DOB    Bl. Grp. Ht.(cm) Wt.(kg)     Policy No.   Phone No.Driver's Lic. No.	 Address
----------------------------------------------------------------------------------------------------------------------------
             Muskaan         12/5/2000      O-    167     55   234928349823  8456486540    32432552296	Akola

Delete Successful

1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 2


----------------------------------------------------------------------------------------------------------------------------
           Name               DOB    Bl. Grp. Ht.(cm) Wt.(kg)     Policy No.   Phone No.Driver's Lic. No.	 Address
----------------------------------------------------------------------------------------------------------------------------
           Someshwar         15/12/1999      O+    173     75  8345395340535845645969450  5325462748234	Mundhwa
             Shreyas         16/1/2001      B+    175     61    83475837593  8772398223   903534535345	Pune


1. Build Master Table
2. Display Records
3. Insert a Record
4. Delete a Record
5. Edit a Record
6. Search a Record
7. Exit

Your Choice: 7


End

Someshwars-MacBook-Pro:C++ someshwargaikwad$
*/
