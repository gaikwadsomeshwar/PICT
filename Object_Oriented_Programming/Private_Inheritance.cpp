#include<iostream>
#include<cstring>
using namespace std;

struct Temp {
    
    char Name[50],Blood_grp[2],Add[50];
    int Dob[3];
    float Weight,Height;
    long int Phone_no,Dl_no;
};

class PersonalDetails {
    
private:
    
    char *name;
    int *dob;
    char *blood_grp;
    
public:
    
    PersonalDetails() {
        
        name=new char[50];
        dob=new int[3];
        blood_grp=new char[2];
    }
    
    void Set_name();
    void Set_dob();
    void Set_blood();
    char* Get_name();
    int* Get_dob();
    char* Get_blood();
};

class PhysicalDetails {
    
private:
    
    float height;
    float weight;
    
public:
    
    PhysicalDetails() {
        height=0.0;
        weight=0.0;
    }
    
    void Set_height();
    void Set_weight();
    float Get_height();
    float Get_weight();
};

class EmergencyDetails {
    
private:
    
    long int policy_no;
    char *add;
    
public:
    
    EmergencyDetails() {
        policy_no=0;
        add=new char[50];
    }
    
    void Set_policy();
    void Set_add();
    long int Get_policy();
    char* Get_add();
};

class Record:PersonalDetails,PhysicalDetails,EmergencyDetails {
    
private:
    
    long int phone_no;
    long int dl_no;
    
public:
    
    Record() {
        phone_no=0;
        dl_no=0;
    }
    
    void Set_Data(int n);
    void Get_Data();
    void Edit_Data(int ch);
    int Search(struct Temp t,int ch);
};

void PersonalDetails::Set_name() {
    
    char dummy[1];
    cin.getline(dummy,1);
    cout<<"Name: ";
    cin.getline(name,49);
}

void PersonalDetails::Set_dob() {
    
    cout<<"Date of Birth:\n";
    cout<<"Year: ";
    cin>>*(dob+2);
    cout<<"Month: ";
    cin>>*(dob+1);
    cout<<"Day: ";
    cin>>*(dob+0);
}

void PersonalDetails::Set_blood() {
    
    cout<<"Blood Group: ";
    cin>>blood_grp;
}

void PhysicalDetails::Set_height() {
    
    cout<<"Height: ";
    cin>>height;
}

void PhysicalDetails::Set_weight() {
    
    cout<<"Weight: ";
    cin>>weight;
}

void EmergencyDetails::Set_policy() {
    
    cout<<"Insurance Policy Number: ";
    cin>>policy_no;
}

void EmergencyDetails::Set_add() {
    
    char dummy[1];
    cin.getline(dummy,1);
    cout<<"Address: ";
    cin.getline(add,49);
}

void Record::Set_Data(int n) {
    
    struct Temp t;
    int i;
    
    Set_name();
    Set_dob();
    Set_blood();
    Set_height();
    Set_weight();
    Set_policy();
    Set_add();
    
    cout<<"Phone no: ";
    cin>>t.Phone_no;
    
    for(i=0;i<n;)
    {
        int flag=Search(t,8);
        
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
    
    for(i=0;i<n;)
    {
        int flag=Search(t,7);
        
        if(flag==1)
        {
            cout<<"\nDriver's License Number already exists\n";
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

char* PersonalDetails::Get_name() {
    
    return name;
}

int* PersonalDetails::Get_dob() {
    
    return dob;
}

char* PersonalDetails::Get_blood() {
    
    return blood_grp;
}

float PhysicalDetails::Get_height() {
    
    return height;
}

float PhysicalDetails::Get_weight() {
    
    return weight;
}

long int EmergencyDetails::Get_policy() {
    
    return policy_no;
}

char* EmergencyDetails::Get_add() {
    
    return add;
}

void Record::Get_Data() {
    
    int *DOB=Get_dob();
    
    cout<<Get_name()<<"\t"<<*(DOB+0)<<"/"<<*(DOB+1)<<"/"<<*(DOB+2)<<"\t"<<Get_blood();
    cout<<"\t"<<Get_height()<<"\t"<<Get_weight()<<"\t";
    cout<<Get_policy()<<"\t"<<phone_no<<"\t"<<dl_no<<"\t"<<Get_add()<<"\n";
}

void Record::Edit_Data(int ch) {
    
    switch(ch) {
            
        case 1: {
            
            cout<<"New ";
            Get_height();
            break;
        }
            
        case 2: {
            
            cout<<"New ";
            Get_weight();
            break;
        }
            
        case 3: {
            
            cout<<"New ";
            Get_add();
            break;
        }
            
        case 4: {
            
            cout<<"New Phone Number: ";
            cin>>phone_no;
            break;
        }
    }
}

int Record::Search(struct Temp t,int ch) {
    
    switch(ch) {
        
        case 1: {
            
            if(strcmp(t.Name,Get_name())==0)
                return 1;
            
            break;
        }
       
        case 2: {
            
            int *DOB=Get_dob();
            if(t.Dob[0]==*(DOB+0) && t.Dob[1]==*(DOB+1) && t.Dob[2]==*(DOB+2))
                return 1;
            
            break;
        }
            
        case 3: {
            
            if(strcmp(t.Blood_grp,Get_blood())==0)
                return 1;
            
            break;
        }
        
        case 4:{
            
            if(t.Weight==Get_weight())
                return 1;
            
            break;
        }
        
        case 5: {
            
            if(t.Height==Get_height())
                return 1;
            
            break;
        }
        
        case 6: {
            
            if(strcmp(t.Add,Get_add())==0)
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
    
    int ch,Ch,n,i,Pos;
    char title[25];
    static int pos;
    
    Record R[50];
    struct Temp t;
    
    do {
       
        cout<<"1. Build Master Table\n";
        cout<<"2. Display Records\n";
        cout<<"3. Insert a Record\n";
        cout<<"4. Delete a Record\n";
        cout<<"5. Edit a Record\n";
        cout<<"6. Search a Record\n";
        cout<<"7. Exit\n\n";
        cout<<"Your Choice: ";
        cin>>ch;
        
        cout<<"\n\n";
        
        switch(ch) {
            
            case 1: {
                
                n=0;
                pos=0;
                
                cout<<"A new Master Table is Created\nGive it a name: ";
                cin>>title;
                
                cout<<"Enter the number of Records you want to add: ";
                cin>>n;
                
                cout<<"\n\n";
                
                n=n+pos;
                
                for(i=pos;i<n && i<50;i++)
                {
                    R[i].Set_Data(i);
                }
                pos=i;
                
                if(i==50)
                {
                    cout<<"Record Full";
                }
                
                cout<<"\n\n";
                break;
            }
                
            case 2: {
                
                for(i=0;i<pos;i++)
                {
                    R[i].Get_Data();
                }
                
                cout<<"\n\n";
                break;
            }
                
            case 3: {
                
                R[pos].Set_Data(pos);
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
                    Pos=R[i].Search(t,7);
                    if(Pos==1)
                    {
                        Pos=i;
                        break;
                    }
                }
                
                if(Pos!=-1)
                {
                    for(i=Pos;i<pos-1;i++)
                    {
                        R[i]=R[i+1];
                    }
                    pos=pos-1;
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
                cout<<"4. Phone Number\n";
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
                    Pos=R[i].Search(t,7);
                    if(Pos==1)
                    {
                        Pos=i;
                        break;
                    }
                }
                
                if(Pos!=-1)
                {
                    R[Pos].Edit_Data(ch);
                }
                
                else
                {
                    cout<<"Record not Found";
                }
                
                cout<<"\n\n";
                break;
            }
                
            case 6: {
                
                char dummy[1];
                int flag=0,Flag;
                
                cout<<"Search By:\n";
                cout<<"1. Name\n";
                cout<<"2. Date of Birth\n";
                cout<<"3. Blood Group\n";
                cout<<"4. Weight\n";
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
                }
                
                if(Ch==9)
                    break;
                
                switch(Ch) {
                        
                    case 1: {
                        
                        cin.getline(dummy,1);
                        cout<<"Enter name: ";
                        cin.getline(t.Name,49);
                        
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
    while(ch!=7);
    
    return 0;
}
