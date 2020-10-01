/*
Name        : Someshwar Gaikwad
Class       : SE-10 (H-10)
Roll No.    : 23257

Title       : Operations on single variable polynomial using circular linked lists

Problem Statement:

Implement polynomial using CLL and perform
a) Addition of Polynomials
b) Multiplication of polynomials
c) Evaluation of polynomial
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
  float coef;
  int exp;
  struct node *next;
};

typedef struct node node;

node* insert(node *head,float coef,int exp) {

  node *temp1=(node*)malloc(sizeof(node)),*temp2,*temp3;
  temp1->coef=coef;
  temp1->exp=exp;

  if(head==NULL) {

    head=temp1;
    head->next=head;

    return head;
  }

  else if(exp>head->exp) {

    temp1->next=head;
    temp2=head;

    while(temp2->next!=head) {

      temp2=temp2->next;
    }

    temp2->next=temp1;
    head=temp1;

    return head;
  }

  else if(exp==head->exp) {

      head->coef=head->coef+coef;
      return head;
  }

  else {

    temp2=head;

    do {

      temp3=temp2;
      temp2=temp2->next;
    }
    while(temp2!=head && temp2->exp>exp);

    if(temp2->exp==exp)
      temp2->coef=temp2->coef+coef;

    else {

      temp3->next=temp1;
      temp1->next=temp2;
    }
    return head;
  }
}

node* newList(node *head) {

  head=NULL;

  int i,exp,size;
  float coef;

  printf("Enter the number of terms you want to add: ");
  scanf("%d",&size);
  printf("\nEnter the terms:\n");
  printf("Coefficient: ");
  scanf("%f",&coef);
  printf("Exponent: ");
  scanf("%d",&exp);
  printf("\n");

  head=insert(head,coef,exp);

  for(i=1;i<size;i++) {

    printf("Coefficient: ");
    scanf("%f",&coef);
    printf("Exponent: ");
    scanf("%d",&exp);
    printf("\n");
    head=insert(head,coef,exp);
  }
  return head;
}

node* Addition(node *poly1,node *poly2) {

  node *head=NULL,*p=poly1;

  do {

    head=insert(head,p->coef,p->exp);
    p=p->next;
  }
  while(p!=poly1);

  p=poly2;

  do {

    head=insert(head,p->coef,p->exp);
    p=p->next;
  }
  while(p!=poly2);

  return head;
}

node* Multiplication(node *poly1,node *poly2) {

  node *head=NULL;
  node *p1=poly1;

  do {

    node *p2=poly2;
    do {

      head=insert(head,p1->coef*p2->coef,p1->exp+p2->exp);
      p2=p2->next;
    }
    while(p2!=poly2);
    p1=p1->next;
  }
  while(p1!=poly1);

  return head;
}

double Evaluation(node *head) {

  node* p=head;
  double value=0.0,x;

  printf("Value of x: ");
  scanf("%lf",&x);

  do {

	value=value+(p->coef*pow(x,p->exp));
    p=p->next;
  }
  while(p!=head);

  return value;
}

void display(node* head) {

  node* p=head;
  while(p->next!=head){

    printf("(%.2fx^%d)+",p->coef,p->exp);
    p=p->next;
  }
  printf("(%.2fx^%d)",p->coef,p->exp);
  printf("\n\n");
}

int main() {

  node *poly1,*poly2,*result;
  int ch,flag=0;
  double value=0.0;

  do {

    printf("Select the Options:\n");
    printf("1. Create 2 Polynomials\n");
    printf("2. Addition\n");
    printf("3. Multiplication\n");
    printf("4. Evaluation\n");
    printf("5. Exit\n\n");
    printf("Your Choice: ");
    scanf("%d",&ch);
    printf("\n\n");

    if(ch==1||ch==4||flag==1) {

      switch(ch) {

        case 1: {

          printf("Creating Polynomial 1\n\n");
          poly1=newList(poly1);
          printf("Polynomial 1: ");
          display(poly1);

          printf("Creating Polynomial 2\n\n");
          poly2=newList(poly2);
          printf("Polynomial 2: ");
          display(poly2);
          flag=1;
          break;
        }

        case 2: {

          result=Addition(poly1,poly2);
          printf("Polynomial 1: ");
          display(poly1);
          printf("Polynomial 2: ");
          display(poly2);
          printf("Addition: ");
          display(result);
          break;
        }

        case 3: {

          result=Multiplication(poly1,poly2);
          printf("Polynomial 1: ");
          display(poly1);
          printf("Polynomial 2: ");
          display(poly2);
          printf("Multiplication: ");
          display(result);
          break;
        }

        case 4: {

          printf("Polynomial 1: ");
          display(poly1);
          value=Evaluation(poly1);
          printf("Evaluation of Polynomial 1 is: %.2f\n\n",value);
          printf("Polynomial 2: ");
          display(poly2);
          value=Evaluation(poly2);
          printf("Evaluation of Polynomial 2 is: %.2f\n\n",value);
          break;
        }

        case 5:

        printf("End\n");
        break;

        default: printf("Select correct Option\n\n");
      }
    }

    else {

      printf("Create polynomials first\n\n");
    }
  }
  while(ch!=5);

  return EXIT_SUCCESS;
}

/*

Output:

Someshwars-MBP-0ae4:C someshwargaikwad$ ./Circular_Linked_List
Select the Options:
1. Create 2 Polynomials
2. Addition
3. Multiplication
4. Evaluation
5. Exit

Your Choice: 1


Creating Polynomial 1

Enter the number of terms you want to add: 4

Enter the terms:
Coefficient: 1
Exponent: 3

Coefficient: 2
Exponent: 5

Coefficient: 3
Exponent: 1

Coefficient: 2
Exponent: 5

Polynomial 1: (4.00x^5)+(1.00x^3)+(3.00x^1)

Creating Polynomial 2

Enter the number of terms you want to add: 3

Enter the terms:
Coefficient: 3
Exponent: 3

Coefficient: 3
Exponent: 3

Coefficient: 2
Exponent: 6

Polynomial 2: (2.00x^6)+(6.00x^3)

Select the Options:
1. Create 2 Polynomials
2. Addition
3. Multiplication
4. Evaluation
5. Exit

Your Choice: 2


Polynomial 1: (4.00x^5)+(1.00x^3)+(3.00x^1)

Polynomial 2: (2.00x^6)+(6.00x^3)

Addition: (2.00x^6)+(4.00x^5)+(7.00x^3)+(3.00x^1)

Select the Options:
1. Create 2 Polynomials
2. Addition
3. Multiplication
4. Evaluation
5. Exit

Your Choice: 3


Polynomial 1: (4.00x^5)+(1.00x^3)+(3.00x^1)

Polynomial 2: (2.00x^6)+(6.00x^3)

Multiplication: (8.00x^11)+(2.00x^9)+(24.00x^8)+(6.00x^7)+(6.00x^6)+(18.00x^4)

Select the Options:
1. Create 2 Polynomials
2. Addition
3. Multiplication
4. Evaluation
5. Exit

Your Choice: 4


Polynomial 1: (4.00x^5)+(1.00x^3)+(3.00x^1)

Value of x: 1
Evaluation of Polynomial 1 is: 8.00

Polynomial 2: (2.00x^6)+(6.00x^3)

Value of x: 2
Evaluation of Polynomial 2 is: 176.00

Select the Options:
1. Create 2 Polynomials
2. Addition
3. Multiplication
4. Evaluation
5. Exit

Your Choice: 5


End

Someshwars-MBP-0ae4:C someshwargaikwad$
*/
