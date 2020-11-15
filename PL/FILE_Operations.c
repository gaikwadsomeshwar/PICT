/*
 ============================================================================
 Name     : Someshwar Gaikwad
 Class    : SE-10 (H-10)
 Roll No  : 23257
 
 Title    : Structure Operations
 
 Problem Statement:
 
 a) Write C program to implement TYPE and COPY commands of DOS using
 command line arguments.
 
 b) Implement sequential file and perform following operations on any database:
 
 i. Display
 ii. Add records
 iii. Search record
 iv. Modify record
 v. Delete record
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EmployeeDatabase
{
    char name[30];
    int emp_id;
    int age;
    long int mb_no;
    float salary;
};

void Add()
{
    struct EmployeeDatabase D,t;
    
    FILE *f1,*f2;
    
    f1=fopen("Data","a");
    f2=fopen("Data","r");
    
    printf("Employee ID: ");
    scanf("%d",&D.emp_id);
    
    int flag=0;
    
    while(!feof(f2))
    {
        fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&t.emp_id,t.name,&t.age,&t.mb_no,&t.salary);
        
        if(t.emp_id==D.emp_id)
        {
            flag=1;
        }
        
        if(flag==1)
        {
            printf("\nEmployee ID already exists\n");
            printf("Enter again\n\n");
            printf("Employee ID: ");
            scanf("%d",&D.emp_id);
            flag=0;
            rewind(f2);
        }
    }
    
    printf("Name: ");
    scanf("%s",D.name);
    
    printf("Age: ");
    scanf("%d",&D.age);
    
    while(D.age<20 || D.age>65)
    {
        printf("\nInvalid Age\nMinimum Age: 20 & Maximum Age: 65\n\n");
        printf("Age: ");
        scanf("%d",&D.age);
    }
    
    printf("Mobile Number: ");
    scanf("%ld",&D.mb_no);
    
    rewind(f2);
    
    while(!feof(f2))
    {
        fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&t.emp_id,t.name,&t.age,&t.mb_no,&t.salary);
        
        if(t.mb_no==D.mb_no)
        {
            flag=1;
        }
        
        if(flag==1)
        {
            printf("\nMobile Number already exists\n");
            printf("Enter again\n\n");
            printf("Mobile Number: ");
            scanf("%ld",&D.mb_no);
            flag=0;
            rewind(f2);
        }
    }
    
    printf("Salary: ");
    scanf("%f",&D.salary);
    
    fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
    
    fclose(f1);
    fclose(f2);
}

int Search(int ch,int eid)
{
    FILE *f;
    
    int flag=0,i;
    
    struct EmployeeDatabase D;
    
    do
    {
        switch(ch)
        {
            case 1:
                
                printf("Enter Employee Name: ");
                char Name[30];
                scanf("%s",Name);
                
                f=fopen("Data","r");
                
                i=1;
                
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f))
                {
                    fscanf(f,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(strcasecmp(D.name,Name)==0)
                    {
                        printf("%d\t %d\t %s\t %d\t %f\t %ld\n",(i++),D.emp_id,D.name,D.age,D.salary,D.mb_no);
                        flag=1;
                    }
                }
                
                if(flag==0)
                {
                    printf("No such Record exist\n\n");
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                fclose(f);
                
                return flag;
                
            case 2:
                
                if(eid==-1)
                {
                    printf("Enter Employee ID: ");
                    scanf("%d",&eid);
                }
                
                f=fopen("Data","r");
                
                i=1;
                
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f))
                {
                    fscanf(f,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(eid==D.emp_id)
                    {
                        printf("%d\t %d\t %s\t %d\t %f\t %ld\n",(i++),D.emp_id,D.name,D.age,D.salary,D.mb_no);
                        flag=1;
                        
                        break;
                    }
                }
                
                if(flag==0)
                {
                    printf("No such Record exist\n\n");
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                fclose(f);
                
                return flag;
                
            case 3:
                
                flag=2;
                break;
                
            default:printf("Enter a value between 1 and 3\n\n");
        }
    }
    
    while(flag!=2);
    
    return flag;
}

void Modify()
{
    int ch,eid,flag;
    
    struct EmployeeDatabase D,t;
    
    printf("Enter Employee ID: ");
    scanf("%d",&eid);
    
    flag=Search(2,eid);
    
    if(flag==1)
    {
        FILE *f1,*f2,*f3;
        f1=fopen("Temp","a");
        f2=fopen("Data","r");
        
        printf("1. Modify Name\n");
        printf("2. Modify Age\n");
        printf("3. Modify Mobile Number\n");
        printf("4. Modify Salary\n");
        printf("5. Modify All of the Abouve\n");
        printf("6. Back\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                
                printf("Name: ");
                scanf("%s",t.name);
                
                printf("\nAfter Modification:");
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f2))
                {
                    fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(D.emp_id==eid)
                    {
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,t.name,D.age,D.mb_no,D.salary);
                        printf("%d\t %s\t %d\t %ld\t %f\n",D.emp_id,t.name,D.age,D.mb_no,D.salary);
                    }
                    else
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                break;
                
            case 2:
                
                printf("Age: ");
                scanf("%d",&t.age);
                
                while(t.age<20 || t.age>65)
                {
                    printf("\nInvalid Age\nMinimum Age: 20 & Maximum Age: 65\n\n");
                    printf("Age: ");
                    scanf("%d",&D.age);
                }
                
                printf("\nAfter Modification:");
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f2))
                {
                    fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(D.emp_id==eid)
                    {
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,t.age,D.mb_no,D.salary);
                        printf("%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,t.age,D.mb_no,D.salary);
                    }
                    else
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                break;
                
            case 3:
                
                printf("Mobile Number: ");
                scanf("%ld",&t.mb_no);
                
                f3=fopen("Data","r");
                
                while(!feof(f3))
                {
                    fscanf(f3,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(t.mb_no==D.mb_no)
                    {
                        flag=1;
                    }
                    
                    if(flag==1)
                    {
                        printf("\nMobile Number already exists\n");
                        printf("Enter again\n\n");
                        printf("Mobile Number: ");
                        scanf("%ld",&t.mb_no);
                        flag=0;
                        rewind(f3);
                    }
                }
                
                fclose(f3);
                
                printf("\nAfter Modification:");
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f2))
                {
                    fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(D.emp_id==eid)
                    {
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,t.mb_no,D.salary);
                        printf("%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,t.mb_no,D.salary);
                    }
                    else
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                break;
                
            case 4:
                
                printf("Salary: ");
                scanf("%f",&t.salary);
                
                printf("\nAfter Modification:");
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f2))
                {
                    fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(D.emp_id==eid)
                    {
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,t.salary);
                        printf("%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,t.salary);
                    }
                    else
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                break;
                
            case 5:
                
                printf("Name: ");
                scanf("%s",t.name);
                
                printf("Age: ");
                scanf("%d",&t.age);
                
                while(t.age<20 || t.age>65)
                {
                    printf("\nInvalid Age\nMinimum Age: 20 & Maximum Age: 65\n\n");
                    printf("Age: ");
                    scanf("%d",&D.age);
                }
                
                printf("Mobile Number: ");
                scanf("%ld",&t.mb_no);
                
                f3=fopen("Data","r");
                
                while(!feof(f3))
                {
                    fscanf(f3,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(t.mb_no==D.mb_no)
                    {
                        flag=1;
                    }
                    
                    if(flag==1)
                    {
                        printf("\nMobile Number already exists\n");
                        printf("Enter again\n\n");
                        printf("Mobile Number: ");
                        scanf("%ld",&t.mb_no);
                        flag=0;
                        rewind(f3);
                    }
                }
                
                fclose(f3);
                
                printf("Salary: ");
                scanf("%f",&t.salary);
                
                printf("\nAfter Modification:");
                printf("\n\n-------------------------------------------------------------------------------\n");
                printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                printf("-------------------------------------------------------------------------------\n");
                
                while(!feof(f2))
                {
                    fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
                    
                    if(D.emp_id==eid)
                    {
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,t.name,t.age,t.mb_no,t.salary);
                        printf("%d\t %s\t %d\t %ld\t %f\n",D.emp_id,t.name,t.age,t.mb_no,t.salary);
                    }
                    else
                        fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
                }
                
                printf("-------------------------------------------------------------------------------\n");
                
                break;
            
            case 6:
                
                break;
                
            default:printf("Enter a value between 1 and 5");
        }
        
        printf("\n\n");
        
        fclose(f1);
        fclose(f2);
        
        remove("Data");
        rename("Temp","Data");
        
    }
}

void Delete()
{
    int eid,flag;
    
    struct EmployeeDatabase D;
    
    printf("Enter Employee ID: ");
    scanf("%d",&eid);
    
    printf("Deleting Record\n");
    
    flag=Search(2,eid);
    
    if(flag==1)
    {
        FILE *f1,*f2;
        f1=fopen("Temp","a");
        f2=fopen("Data","r");
        
        while(!feof(f2))
        {
            fscanf(f2,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
            
            if(eid==D.emp_id)
                continue;
            else
                fprintf(f1,"%d\t %s\t %d\t %ld\t %f\n",D.emp_id,D.name,D.age,D.mb_no,D.salary);
        }
        
        printf("\n\n");
        
        fclose(f1);
        fclose(f2);
        
        remove("Data");
        rename("Temp","Data");
        
    }
    else
    {
        printf("Record not Found");
    }
}

void Display()
{
    
    printf("-------------------------------------------------------------------------------\n");
    printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
    printf("-------------------------------------------------------------------------------\n");
    
    FILE *f;
    f=fopen("Data","r");
    
    struct EmployeeDatabase D;
    
    int i=1;
    
    fscanf(f,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
    
    while(!feof(f))
    {
        
        printf("%d\t %d\t %s\t %d\t %f\t %ld\n",(i++),D.emp_id,D.name,D.age,D.salary,D.mb_no);
        fscanf(f,"%d\t %s\t %d\t %ld\t %f\n",&D.emp_id,D.name,&D.age,&D.mb_no,&D.salary);
    }
    
    printf("%d\t %d\t %s\t %d\t %f\t %ld\n",(i++),D.emp_id,D.name,D.age,D.salary,D.mb_no);
    
    printf("-------------------------------------------------------------------------------\n");
    printf("\n\n");
    
    fclose(f);
}

int main(void)
{
    FILE *f;
    
    f=fopen("Data","w");
    fclose(f);
    
    int ch,flag=0;
    
    do
    {
        printf("1. Add a Record\n");
        printf("2. Search a Record\n");
        printf("3. Modify a Record\n");
        printf("4. Delete a Record\n");
        printf("5. Display all Record\n");
        printf("6. Exit\n");
        printf("\nYour Choice: ");
        
        scanf("%d",&ch);
        
        printf("\n\n");
        
        if(ch==1||flag==1||ch>=6||ch<=0)
        {
            switch(ch)
            {
                case 1:
                
                    Add();
                
                    printf("\n\n");
                
                    flag=1;
                
                    break;
                
                case 2:
                
                    printf("1. Search by Name\n");
                    printf("2. Search by Employee ID\n");
                    printf("3. Back\n");
                
                    int x;
                    scanf("%d",&x);
                
                    x=Search(x,-1);
                
                    break;
            
                case 3:
                
                    Modify();
                    printf("\n\n");
                
                    break;
            
                case 4:
                
                    Delete();
                    printf("\n\n");
                
                    break;
           
                case 5:
                
                    Display();
                
                    break;
            
                case 6:
                
                    printf("End\n\n");
                
                    break;
                
                default:printf("Enter a value between 1 and 6\n\n");
                }
        }
        else
        {
            printf("Record Empty\n\nAdd some values first\n\n");
        }
    }
    while(ch!=6);
    
    return 0;
}

/* Output
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 2
 
 
 Record Empty
 
 Add some values first
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 1
 
 
 Employee ID: 23257
 Name: Someshwar
 Age: 15
 
 Invalid Age
 Minimum Age: 20 & Maximum Age: 65
 
 Age: 21
 Mobile Number: 77234234
 Salary: 23422
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 1
 
 
 Employee ID: 23257
 
 Employee ID already exists
 Enter again
 
 Employee ID: 23256
 Name: Shreyas
 Age: 23
 Mobile Number: 45656453
 Salary: 34324
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 1
 
 
 Employee ID: 23211
 Name: Shelke
 Age: 34
 Mobile Number: 23423435
 Salary: 232434
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 1
 
 
 Employee ID: Muskan
 Name: Age: 23
 Mobile Number: 35453243234
 Salary: 23234
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 5
 
 
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1     23257     Someshwar     21     23422.000000     77234234
 2     23256     Shreyas     23     34324.000000     45656453
 3     23211     Shelke     34     232434.000000     23423435
 4     8     Muskan     23     23234.000000     35453243234
 -------------------------------------------------------------------------------
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 3
 
 
 Enter Employee ID: 8
 
 
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1     8     Muskan     23     23234.000000     35453243234
 -------------------------------------------------------------------------------
 1. Modify Name
 2. Modify Age
 3. Modify Mobile Number
 4. Modify Salary
 5. Modify All of the Abouve
 6. Back
 1
 Name: Muskaan
 
 After Modification:
 
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 8     Muskaan     23     35453243234     23234.000000
 -------------------------------------------------------------------------------
 
 
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 4
 
 
 Enter Employee ID: 23211
 Deleting Record
 
 
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1     23211     Shelke     34     232434.000000     23423435
 -------------------------------------------------------------------------------
 
 
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 5
 
 
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1     23257     Someshwar     21     23422.000000     77234234
 2     23256     Shreyas     23     34324.000000     45656453
 3     8     Muskaan     23     23234.000000     35453243234
 -------------------------------------------------------------------------------
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 
 Your Choice: 6
 
 
 End
 
 */

