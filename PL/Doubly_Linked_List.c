/*
============================================================================
Name     : Someshwar Gaikwad
Class    : SE-10 (H-10)
Roll No  : 23257

Title: Doubly Linked List

Problem Statement:

Accept input as a string and construct a Doubly Linked List for the input string
with each node contains, as a data one character from the string and perform
1) Insert
2) Delete,
3) Display forward
4) Display backward.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct DoublyLinkedList  {

  int data;
  struct DoublyLinkedList *next;
  struct DoublyLinkedList *prev;
};

typedef struct DoublyLinkedList node;

void display(node *head) {

  node *ptr=head;

  printf("List: ");

  while(ptr!=NULL) {

    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n\n");
}

void displayRev(node *head) {

  node *ptr=head;

  printf("Reverse List: ");

  while(ptr->next!=NULL) {
    ptr=ptr->next;
  }

  while(ptr!=NULL) {

    printf("%d ",ptr->data);
    ptr=ptr->prev;
  }
  printf("\n\n");
}

node* insertNode(node *head,int pos) {

  node *temp=(node*)malloc(sizeof(node));
  node *ptr=head;
  int currentIndex=1;

  printf("Enter Data: ");
  scanf("%d",&temp->data);
  temp->next=NULL;
  temp->prev=NULL;

  if(pos==0) {

    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
  }

  else {

    while(currentIndex<pos && ptr->next!=NULL) {
      ptr=ptr->next;
      currentIndex++;
    }

    if(ptr->next!=NULL) {
      ptr->next->prev=temp;
    }

    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next=temp;

    return head;
  }
}

node* newList(node *head,int *size) {

  int i;
  head=(node*)malloc(sizeof(node));
  node *ptr;

  printf("Enter the number of data elements you want to add: ");
  scanf("%d",size);

  printf("\nEnter elements:\n");

  printf("Enter Data: ");
  scanf("%d",&head->data);
  head->next=NULL;
  head->prev=NULL;

  for(i=1;i<*size;i++) {
    head=insertNode(head,i);
  }
  return head;
}

node* deleteNode(node *head,int pos) {

  node *ptr=head,*prev;
  int currentIndex=1;

  if(ptr==NULL) {
    printf("Empty List\n\n");
  }

  if(pos==0) {

    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
  }

  else {

    while(currentIndex<pos && ptr->next!=NULL) {
      ptr=ptr->next;
      currentIndex++;
    }

    prev=ptr->prev;

    if(ptr->next==NULL) {

      prev->next=NULL;
      free(ptr);
      return head;
    }

    else {

      prev->next=ptr->next;
      ptr=ptr->next;
      free(ptr->prev);
      ptr->prev=prev;
      return head;
    }
  }
}

int main() {

  node *head;
  static int size;
  int ch,Ch,pos,flag=0;

  do {

    printf("Select the Options:\n");
    printf("1. Create a List\n");
    printf("2. Insert an element\n");
    printf("3. Delete an element\n");
    printf("4. Display Reverse\n");
    printf("5. Display the List\n");
    printf("6. Exit\n\n");
    printf("Your Choice: ");
    scanf("%d",&ch);
    printf("\n\n");

    if(ch==1||ch==6||flag==1) {

      switch(ch) {

        case 1: {

          printf("Creating a new List\n\n");
          size=0;
          head=NULL;
          head=newList(head,&size);
          printf("\nNew ");
          display(head);
          printf("\n");
          flag=1;
          break;
        }

        case 2: {

          do {

            printf("Select the Options:\n");
            printf("1. Insert element at beginning\n");
            printf("2. Insert element at a position\n");
            printf("3. Insert element at the end\n");
            printf("4. Back\n\n");
            printf("Your Choice: ");
            scanf("%d",&Ch);
            printf("\n");

            if(Ch==1) {
              head=insertNode(head,0);
              size++;
              printf("New ");
              display(head);
            }

            else if(Ch==3) {
              head=insertNode(head,size);
              size++;
              printf("New ");
              display(head);
            }

            else if(Ch==2) {
              printf("Enter position: ");
              scanf("%d",&pos);

              if(pos>=0 && pos<=size) {
                head=insertNode(head,pos);
                size++;
                printf("New ");
                display(head);
              }
              else {
                printf("Cannot insert");
              }
            }
          }
          while(Ch!=4);
          printf("\n\n");
          break;
        }

        case 3: {

          do {

            printf("Select the Options:\n");
            printf("1. Delete element at beginning\n");
            printf("2. Delete element at a position\n");
            printf("3. Delete element at the end\n");
            printf("4. Back\n\n");
            printf("Your Choice: ");
            scanf("%d",&Ch);
            printf("\n");

            if(Ch==1) {
              head=deleteNode(head,0);
              size--;
              printf("New ");
              display(head);
            }

            else if(Ch==3) {
              head=deleteNode(head,size);
              size--;
              printf("New ");
              display(head);
            }

            else if(Ch==2) {
              printf("Enter position: ");
              scanf("%d",&pos);

              if(pos>0 && pos<size) {
                head=deleteNode(head,pos);
                size--;
                printf("New ");
                display(head);
              }
              else {
                printf("Cannot delete");
              }
            }
          }
          while(Ch!=4);
          printf("\n\n");
          break;
        }

        case 4: {

          displayRev(head);
          printf("\n");
          break;
        }

        case 5: {

          display(head);
          break;
        }

        case 6:

        printf("End\n");
        break;

        default: printf("Select correct Option\n\n");
      }
    }

    else {

      printf("Create a List first\n\n");
    }
  }
  while(ch!=6);
  return 0;
}

/*

Output:

Someshwars-MBP-0ae4:C someshwargaikwad$ ./Doubly_Linked_List
Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Display Reverse
5. Display the List
6. Exit

Your Choice: 1


Creating a new List

Enter the number of data elements you want to add: 5

Enter elements:
Enter Data: 1
Enter Data: 2
Enter Data: 3
Enter Data: 4
Enter Data: 5

New List: 1 2 3 4 5


Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Display Reverse
5. Display the List
6. Exit

Your Choice: 2


Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 1

Enter Data: 0
New List: 0 1 2 3 4 5

Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 2

Enter position: 3
Enter Data: -3
New List: 0 1 2 -3 3 4 5

Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 3

Enter Data: 6
New List: 0 1 2 -3 3 4 5 6

Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 4



Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Display Reverse
5. Display the List
6. Exit

Your Choice: 3


Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 1

New List: 1 2 -3 3 4 5 6

Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 3

New List: 1 2 -3 3 4 5

Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 2

Enter position: 3
New List: 1 2 3 4 5

Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 4



Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Display Reverse
5. Display the List
6. Exit

Your Choice: 4


Reverse List: 5 4 3 2 1


Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Display Reverse
5. Display the List
6. Exit

Your Choice: 5


List: 1 2 3 4 5

Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Display Reverse
5. Display the List
6. Exit

Your Choice: 6


End
Someshwars-MBP-0ae4:C someshwargaikwad$
*/
