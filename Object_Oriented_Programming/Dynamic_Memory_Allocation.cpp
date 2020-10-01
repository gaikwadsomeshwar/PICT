/*
================================================================
Title     : Dynamic Memory Allocation
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

A Book shop maintains the inventory of books that are being sold at the shop. The list includes details such as title, author, publisher, price and available stock.Write a program in C++ which will have a class called books with suitable member functions for
1. Add
2. Update
3. Search a book
4. Purchase a book (update the stock and display the total cost)
5. Record number of successful/unsuccessful transactions (use static datamembers to keep count of transactions)

Use new operator in constructors to allocate memory space required.
================================================================*/

#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

struct books                  //Structure for Searching Purpose
{
	char t[50];          //Stores the Title of the book user wants to search
	char a[50];         //Stores the Name of Author of the book user wants to search
	long int isbn;          //Stores the ISBN Number of the book user wants to search
}Bk;

class Books
{
    private:

    char *title;
    char *author;
    char *publisher;                  //Data Members
    float *price;
    int *available_stock;
    long int *ISBN;

    public:

    void add();                               //Adds Books in the inventory
    int update(books b,int ch,int i);		 //Updates the stock for a Book
    int search(books b,int ch,int i);      //Searches for a Book
    int purchase(books b,int ch,int i);    //Purchases a Book and Displays total cost
    void display(int i);			      //Displays entire inventory

    static int countU;
    static int countS;

    Books()   //Default Contructor to Dynamically Allocate the Memory
    {
        title=new char[50];
        author=new char[50];
        publisher=new char[50];
        price=new float;
        available_stock=new int;
        ISBN=new long int;
    }
};

int Books::countU;
int Books::countS;

void Books::add()
{
    char dummy[1];
    cin.getline(dummy,1);                       //Dummy used for Accepting Strings (with spaces)

    cout<<"Enter the name of book: ";              //Accepting title of the book
    cin.getline(title,49);

    cout<<"Enter the name of author: ";
    cin.getline(author,49);			//Accepting author's name of the book

    cout<<"Enter the name of publisher: ";
    cin.getline(publisher,49); 			//Accepting publisher's name of the book

    cout<<"Enter the price of book: ";
    cin>>*price;                                //Accepting price of each book

    cout<<"Enter the ISBN number: ";
    cin>>*ISBN;					//Accepting the ISBN Number of the book

    cout<<"Enter the stocks: ";
    cin>>*available_stock;			//Accepting the Stock of each Book

    cout<<"\n";
}

int Books::search(books b,int ch,int i)
{
	int flag=0;

	switch(ch)                    //Searching for the book according to user's choice
    {
    	case 1:if(*ISBN==b.isbn)
    		   {
    				cout<<(i+1)<<setw(25)<<title<<setw(18)<<author<<setw(5)<<publisher<<setw(13)<<*ISBN<<setw(7)<<*price<<setw(5)<<*available_stock<<"\n";
    				flag=1;
    		   }

    		   if(flag==1)
    		   {
    			   return 1;
    		   }

    		   break;

    	case 2:if(strcmp(title,b.t)==0)
    		   {
    				cout<<(i+1)<<setw(25)<<title<<setw(18)<<author<<setw(5)<<publisher<<setw(13)<<*ISBN<<setw(7)<<*price<<setw(5)<<*available_stock<<"\n";
    				flag=1;
    		   }

    		   break;

    	case 3:if(strcmp(author,b.a)==0)
    		   {
    				cout<<(i+1)<<setw(25)<<title<<setw(18)<<author<<setw(5)<<publisher<<setw(13)<<*ISBN<<setw(7)<<*price<<setw(5)<<*available_stock<<"\n";
    				flag=1;
    		   }

    		   break;

    }

	if(flag==1)
	{
		return 1;
	}

	return 0;
}

int Books::update(books b,int ch,int i)
{
    int updateStock;

    cout<<"Sr.No.\t\t Title \t\t Author     Publisher   ISBN \t Price \t Available\n";

    int flag=search(b,ch,i);

    cout<<endl<<endl;

    if(flag==1)
    {

        cout<<"Enter the number of stock you want to add: ";
        cin>>updateStock;

        *available_stock=*available_stock+updateStock;          //Updating the stock

        return 1;   //success
     }

     return 0;    //Failure
}

int Books::purchase(books b,int ch,int i)
{
	int q;

	int flag=search(b,ch,i);

	if(flag==1)
	{
		cout<<"Enter the Quantity: ";
		cin>>q;

		if(q<=*available_stock)
		{
			cout<<"Total Price: Rs. "<<(*price*q);  //If stock is available displaying the total price and updating the stock
			*available_stock=*available_stock-q;
			countS++;           //Successful Transaction incremented
		}

		else if(q>*available_stock)
		{
			cout<<"Out of Stock";    //If the quantity of books is not available, unsuccessful
			countU++;          //Unsuccessful Transaction incremented
		}

		return 1;     //Success in finding the book
	}
	return 0;     //Failure in finding the book
}

void Books::display(int i)
{
	cout<<(i+1)<<setw(25)<<title<<setw(18)<<author<<setw(5)<<publisher<<setw(13)<<*ISBN<<setw(7)<<*price<<setw(5)<<*available_stock<<"\n";
				//Displaying the Inventory
}

int main()
{
    int size,ch,i,flag=0,SrNo=0;
    static int index;       //Stores the last index of book in the inventory

    cout<<"Enter inventory size: ";
    cin>>size;          //Stores the size of inventory
    cout<<"\n";

    Books b[size];       //Object Declaration and Constructor Call

    do
    {
        cout<<"1.Add books to Inventory\n";
        cout<<"2.Search a book in the Inventory\n";
        cout<<"3.Update Inventory\n";                    //Menu for the User
        cout<<"4.Purchase a book\n";
        cout<<"5.Display entire Inventory\n";
        cout<<"6.Exit\n\n";
        cin>>ch;

        switch(ch)
        {
            case 1:int n;
                   cout<<"Enter the number of books you want to add: ";
                   cin>>n;

                   cout<<"\n";

                   n=n+index;

                   if(n<=size)
                   {
                        for(;index<n;index++)
                        {
                            b[index].add();     //Only adds the book if space in inventory in available
                        }
                        cout<<"\n\n";
                   }
                   else if(n>size)
                   {
                   		cout<<"Inventory Full\n";
                   		cout<<"You cannot add books\n\n";
                   }

                   break;

            case 2:cout<<"Search by:\n";
            	   cout<<"1. ISBN Number\n";
            	   cout<<"2. Title\n";           //Menu for User
            	   cout<<"3. Author\n";

            	   char dummy[1];        //Dummy variable required for accepting strings (with spaces)

            	   int c,count;

            	   count=0;

            	   cin>>c;

            	   switch(c)
            	   {
            	   	   case 1:cout<<"Enter the ISBN number: ";
            	   	   	   	  cin>>Bk.isbn;

            	   	   	   	  cout<<"Sr.No.\t\t Title \t\t Author     Publisher   ISBN \t Price \t Available\n";

            		      	  for(i=0;i<index;i++)
            		      	  {
            		      		  flag=b[i].search(Bk,c,SrNo);    //Searching by ISBN No. Using structure variable

            		      		  if(flag==1)
            		      		  {
            		      			  count=1;
            		      		  }
            	   	    	  }

            		    	  if(count==0)
            		      	  {
            		   		  cout<<"\nBook not Found\n\n";
            		     	  }

            		      	  flag=0;

            		     	  break;

            	   	   case 2:cin.getline(dummy,1);

            	   	   	   	  cout<<"Enter the Title of Book: ";
            	   	   	   	  cin.getline(Bk.t,49);

            	   	   	   	  cout<<"Sr.No.\t\t Title \t\t Author     Publisher   ISBN \t Price \t Available\n";

            	   	   	   	  for(i=0;i<index;i++)
            	   	   	   	  {
            	   	   	   		  flag=b[i].search(Bk,c,SrNo);    //Searching by Title Using structure variable

            	   	   	   		  if(flag==1)
            	   	   	   		  {
            	   	   	   			  count=1;
            	   	   	   		  }
            	   	   	   	  }

            	   	   	   	  if(count==0)
            	   	   	   	  {
            	   	   	   		  cout<<"\nBook not Found\n\n";
            	   	   	   	  }

            	   	   	   	  flag=0;

            	   	   	   	  break;

            	   	   case 3:cin.getline(dummy,1);

            	   	   	   	  cout<<"Enter the Author's name: ";
            	   	   	   	  cin.getline(Bk.a,49);

            		     	  cout<<"Sr.No.\t\t Title \t\t Author     Publisher   ISBN \t Price \t Available\n";

            		     	  for(i=0;i<index;i++)
            	   	     	  {
            		     		  flag=b[i].search(Bk,c,SrNo);   //Searching by Author Using structure variable

            		     		  if(flag==1)
            		     		  {
            		     			  count=1;
            		     		  }
            	   	      	  }

            		     	  if(count==0)
            		     	  {
            		     		  cout<<"\nBook not Found\n\n";
            		     	  }

            		      	  flag=0;

            		      	  break;

            	   	   default:cout<<"Incorrect Choice";

            	   }
            	   cout<<"\n\n";

                   break;

            case 3:cout<<"Enter ISBN number to update its stock: ";
                   cin>>Bk.isbn;

                   for(i=0;i<index;i++)
                   {
                        flag=b[i].update(Bk,1,index);

                        if(flag==1)
                        {
                            break;        //If success in updating break
                        }
            	   }

            	   if(flag==0)     //Checking if Book was found or not
            	   {
            	        cout<<"Book not Found";
            	   }

            	   flag=0;

            	   cout<<"\n\n";

            	   break;

           case 4:cout<<"Enter the ISBN number of the book to purchase it: ";
           	   	  cin>>Bk.isbn;

           	   	  for(i=0;i<index;i++)
           	   	  {
           	   		 flag=b[i].purchase(Bk,1,index);      //Purchasing by ISBN Number

           	   		 if(flag==1)     //Checking for success
           	   		 {
           	   			 break;
           	   		 }
           	   	  }

                  if(flag==0)     //Checking for unsuccess
                  {
                        cout<<"Book not available";
                  }

                  flag=0;

                  cout<<"\n\n";

    	   	   	  break;


            case 5:cout<<"Sr.No.\t\t Title \t\t Author     Publisher   ISBN \t Price \t Available\n";

            	   for(i=0;i<index;i++)
                   {
                        b[i].display(i);        //Displaying the inventory
                   }
                   cout<<"\n\n";

                   break;

            case 6:cout<<"Thank You Visit Again\n\n";

                   break;

            default:cout<<"Enter a number between 1 to 6\n\n";
       }
       if(ch==6)
       {
            break;
       }
    }
    while(true);

    cout<<"Number of Successful Transactions: "<<Books::countS<<"\n";       //Displaying number of successful and unsuccessful transactions
    cout<<"Number of Unsuccessful Transactions: "<<Books::countU<<"\n";

    return 0;
}
