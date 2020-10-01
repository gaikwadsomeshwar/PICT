/*
============================================================================
 Name     : Someshwar Gaikwad
 Class    : SE-10 (H-10)
 Roll No  : 23257
 
 Title    : Structure Operations
 
 Problem Statement:
 
 Create a Database using array of structures and perform
 following operations on it:
 a) Create Database  
 b) Display Database  
 c) Add record  
 d) Search a record  
 e) Modify a record.  
 f) Delete a record.  
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

void Add(struct EmployeeDatabase D[],struct EmployeeDatabase temp,int index)
{
	int i;

	char dummy;
	scanf("%c",&dummy);

	printf("Name: ");
	scanf("%[^\n]s",temp.name);

	printf("Employee ID: ");
	scanf("%d",&temp.emp_id);

	while(index>0)
	{
		for(i=0;i<index;i++)
		{
			if(D[i].emp_id==temp.emp_id)
			{
				printf("Employee ID already Exists\n");
				printf("Enter Again\n\n");
				printf("Employee ID: ");
				scanf("%d",&temp.emp_id);
				i=0;
			}
		}
		break;
	}


	printf("Age: ");
	scanf("%d",&temp.age);
    
    while(temp.age<18 || temp.age>65)
    {
        printf("Invalid Age\nAge should be between 18 to 65\nEnter Again\n\n");
        printf("Age: ");
        scanf("%d",&temp.age);
    }

	printf("Mobile Number: ");
	scanf("%ld",&temp.mb_no);

	while(index>0)
	{
		for(i=0;i<index;i++)
		{
			if(D[i].mb_no==temp.mb_no)
			{
				printf("Mobile Number already Exists\n");
				printf("Enter Again\n\n");
				printf("Employee ID: ");
				scanf("%d",&temp.emp_id);
				i=0;
			}
		}
		break;
	}


	printf("Salary: ");
	scanf("%f",&temp.salary);

	D[index].emp_id=temp.emp_id;
	strcpy(D[index].name,temp.name);
	D[index].age=temp.age;
	D[index].mb_no=temp.mb_no;
	D[index].salary=temp.salary;
}

int Search(struct EmployeeDatabase D[],int in,int ch,int Dummy)
{
	int i,flag=-1;
	char dummy;
    
    switch(ch)
	{
		case 1:printf("Enter Employee Name: ");

			   scanf("%c",&dummy);
			   char name[30];
			   scanf("%[^\n]s",name);

               if(Dummy==1)
               {
                   printf("-------------------------------------------------------------------------------\n");
                   printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                   printf("-------------------------------------------------------------------------------\n");
               }
            
		       for(i=0;i<in;i++)
			   {
			   	   if(strcmp(name,D[i].name)==0)
			   	   {
                       flag=i;
                       if(Dummy==1)
                       {
                           printf("%d\t%d\t%s\t%d\t%f\t%ld\n",(i+1),D[i].emp_id,D[i].name,D[i].age,D[i].salary,D[i].mb_no);
                       }
                   }
			   }

		       break;

		case 2:printf("Enter Employee ID: ");

			   int eid;
			   scanf("%d",&eid);
            
               if(Dummy==1)
               {
                   printf("-------------------------------------------------------------------------------\n");
                   printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
                   printf("-------------------------------------------------------------------------------\n");
               }

		       for(i=0;i<in;i++)
			   {
			   	   if(eid==D[i].emp_id)
			   	   {
                       flag=i;
			   		   return flag;
			   	   }
			   }

		       break;

		case 3:break;

		default:printf("Enter a value between 1 and 3\n\n");
	}

	return flag;
}

void Modify(struct EmployeeDatabase D[],int in)
{
    int ch,flag;

	flag=Search(D,in,2,0);

	if(flag!=-1)
	{
		printf("1. Modify Name\n");
		printf("2. Modify Age\n");
		printf("3. Modify Mobile Number\n");
		printf("4. Modify Salary\n");
		printf("5. Back\n");
		scanf("%d",&ch);

		char dummy;

		switch(ch)
		{
			case 1:scanf("%c",&dummy);

			       printf("Name: ");
				   scanf("%[^\n]s",D[flag].name);

				   break;

			case 2:printf("Age: ");
				   scanf("%d",&D[flag].age);

				   break;

			case 3:printf("Mobile Number: ");
				   scanf("%ld",&D[flag].mb_no);

				   break;

			case 4:printf("Salary: ");
				   scanf("%f",&D[flag].salary);

				   break;

			case 5:break;

			default:printf("Enter a value between 1 and 5");
		}

		printf("\n\n");
	}
	else
	{
		printf("Record not Found");
	}
}

int Delete(struct EmployeeDatabase D[],int in)
{
    int i,j,flag;

	flag=Search(D,in,2,0);

	if(flag!=-1)
	{
		printf("Deleting Record of %s with ID: %d",D[flag].name,D[flag].emp_id);

		for(i=flag,j=flag+1;j<in;j++,i++)
		{
			strcpy(D[i].name,D[j].name);
			D[i].emp_id=D[j].emp_id;
			D[i].salary=D[j].salary;
			D[i].age=D[j].age;
			D[i].mb_no=D[j].mb_no;
		}
		return (in-1);
	}
	else
	{
		printf("Record not Found");
	}

	return in;
}

void Display(struct EmployeeDatabase D[],int in)
{
	int i;

	printf("-------------------------------------------------------------------------------\n");
	printf("Sr_No \t Emp. ID \t Emp. Name \t Age \t Salary \t Mobile Number\n");
	printf("-------------------------------------------------------------------------------\n");

	for(i=0;i<in;i++)
	{
		printf("%d\t%d\t%s\t%d\t%f\t%ld\n",(i+1),D[i].emp_id,D[i].name,D[i].age,D[i].salary,D[i].mb_no);
	}

	printf("-------------------------------------------------------------------------------\n");
	printf("\n\n");
}

int main(void)
{
	struct EmployeeDatabase D[50],temp;

	static int index;

	int ch,i,flag=0;

	do
	{
		printf("1. Add a Record\n");
		printf("2. Search a Record\n");
		printf("3. Modify a Record\n");
		printf("4. Delete a Record\n");
		printf("5. Display all Record\n");
		printf("6. Exit\n");

		scanf("%d",&ch);

		if(ch==1||ch==6||flag==1)
		{
			switch(ch)
			{
				case 1:if(index==-1)
					   {
							index=0;
					   }

					   Add(D,temp,index);
					   index++;

					   printf("\n\n");
					   flag=1;

					   break;

				case 2:printf("1. Search by Name\n");
				       printf("2. Search by Employee ID\n");
				       printf("3. Back\n");

				       int ch;
				       scanf("%d",&ch);

				       i=Search(D,index,ch,1);

                       if(i==-1)
				       {
				    	   printf("Record not Found");
				       }

				       printf("\n\n");

				       break;

				case 3:Modify(D,index);
					   printf("\n\n");

					   break;

				case 4:i=Delete(D,index);
					   index=i;
					   printf("\n\n");

					   break;

				case 5:if(index==0)
					   {
							printf("Record Empty\n\n");
					   }
					   else
					   {
						   Display(D,index);
					   }

					   break;

				case 6:printf("End");
					   break;

				default:printf("Enter a value between 1 and 6\n\n");
			}
		}
		else
		{
			printf("Record is Empty\n");
			printf("Add a Record\n\n");
			continue;
		}
	}
	while(ch!=6);
}

/* Output:
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 1
 Name: someshwar
 Employee ID: 23257
 Age: 13
 Invalid Age
 Age should be between 18 to 65
 Enter Again
 
 Age: 19
 Mobile Number: 34234654
 Salary: 23423
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 1
 Name: Muskan
 Employee ID: 23257
 Employee ID already Exists
 Enter Again
 
 Employee ID: 23255
 Age: 19
 Mobile Number: 245235234
 Salary: 234322
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 1
 Name: Shelke
 Employee ID: 23243
 Age: 34
 Mobile Number: 23445445
 Salary: 234234
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 1
 Name: shreyas
 Employee ID: 23256
 Age: 45
 Mobile Number: 12354353
 Salary: 34343
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 5
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1    23257    someshwar    19    23423.000000    34234654
 2    23255    Muskan    19    234322.000000    245235234
 3    23243    Shelke    34    234234.000000    23445445
 4    23256    shreyas    45    34343.000000    12354353
 -------------------------------------------------------------------------------
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 3
 Enter Employee ID: 23255
 1. Modify Name
 2. Modify Age
 3. Modify Mobile Number
 4. Modify Salary
 5. Back
 1
 Name: Muskaan
 
 
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 5
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1    23257    someshwar    19    23423.000000    34234654
 2    23255    Muskaan    19    234322.000000    245235234
 3    23243    Shelke    34    234234.000000    23445445
 4    23256    shreyas    45    34343.000000    12354353
 -------------------------------------------------------------------------------
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 2
 1. Search by Name
 2. Search by Employee ID
 3. Back
 1
 Enter Employee Name: Skelke
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 Record not Found
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 2
 1. Search by Name
 2. Search by Employee ID
 3. Back
 1
 Enter Employee Name: Shelke
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 3    23243    Shelke    34    234234.000000    23445445
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 4
 Enter Employee ID: 23243
 Deleting Record of Shelke with ID: 23243
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 5
 -------------------------------------------------------------------------------
 Sr_No      Emp. ID      Emp. Name      Age      Salary      Mobile Number
 -------------------------------------------------------------------------------
 1    23257    someshwar    19    23423.000000    34234654
 2    23255    Muskaan    19    234322.000000    245235234
 3    23256    shreyas    45    34343.000000    12354353
 -------------------------------------------------------------------------------
 
 
 1. Add a Record
 2. Search a Record
 3. Modify a Record
 4. Delete a Record
 5. Display all Record
 6. Exit
 6
 End
 */
