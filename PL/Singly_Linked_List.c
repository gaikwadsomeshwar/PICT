/*
 ============================================================================
 Name     : Someshwar Gaikwad
 Class    : SE-10 (H-10)
 Roll No  : 23257

 Title: Singly Linked List

 Problem Statement:

 Create a singly linked list with options:
 a) Insert (at front, at end, in the middle),
 b) Delete (at front, at end, in the middle),
 c) Display,
 d) Display Reverse,
 e) Revert the SLL
 ============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct SinglyLinkedList  {

 int data;
 struct SinglyLinkedList *next;
};

typedef struct SinglyLinkedList node;

node* newList(node *head,int *size) {

  head=(node*)malloc(sizeof(node));
  head->next=NULL;

  int i;
  node *ptr;

  printf("Enter the number of data elements you want to add: ");
  scanf("%d",size);

  printf("\nEnter elements:\n");

  scanf("%d",&head->data);

  ptr=head;

  for(i=1;i<*size;i++) {

    ptr->next=(node*)malloc(sizeof(node));
    ptr=ptr->next;
    scanf("%d",&ptr->data);
  }
  ptr->next=NULL;

  return head;
}

node* insertNode(node *head,int pos) {

  int currentIndex=2;
  node *currentNode=head;
  node *newNode=(node*)malloc(sizeof(node));

  printf("Enter data: ");
  scanf("%d",&newNode->data);

  if(pos==1) {

    newNode->next=head;
    head=newNode;
    return head;
  }

  while(currentIndex<=pos && currentNode!=NULL) {

     currentNode=currentNode->next;
     currentIndex++;
   }

   newNode->next=currentNode->next;
   currentNode->next=newNode;

   return head;
}

node* deleteNode(node *head,int pos) {

  int currentIndex=2;
  node *currentNode=head;
  node *previousNode=NULL;

  if(pos==1) {

    currentNode=currentNode->next;
    free(head);
    head=currentNode;
    return head;
  }

  while(currentIndex<=pos && currentNode!=NULL) {

	 previousNode=currentNode;
	 currentNode=currentNode->next;
	 currentIndex++;
  }
  previousNode->next=currentNode->next;
  free(currentNode);

  return head;
}

node* revertList(node *head) {

  node *temp,*currentNode,*reverse;
  currentNode=head;
  temp=NULL;
  reverse=NULL;

  if(head->next==NULL)
	  return head;

  while(currentNode!=NULL) {

	  temp=currentNode->next;
	  currentNode->next=reverse;
	  reverse=currentNode;
	  currentNode=temp;
  }
  head=reverse;
  return head;
}

void display(node *head) {

  node *ptr=head;

  printf("List: ");

   while(ptr!=NULL) {

    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
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
			printf("4. Revert the List\n");
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
						printf("\n\n");

						if(Ch==1) {
							head=insertNode(head,1);
							size++;
							printf("New ");
							display(head);
							printf("\n");
						}

						else if(Ch==3) {
							head=insertNode(head,size);
							size++;
							printf("New ");
							display(head);
							printf("\n");
						}

						else if(Ch==2) {
							printf("Enter position: ");
							scanf("%d",&pos);

							if(pos>0 && pos<size) {
								head=insertNode(head,pos);
								size++;
								printf("New ");
								display(head);
								printf("\n");
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
						printf("\n\n");

						if(Ch==1) {
							head=deleteNode(head,1);
							size--;
							printf("New ");
							display(head);
							printf("\n");
						}

						else if(Ch==3) {
							head=deleteNode(head,size);
							size--;
							printf("New ");
							display(head);
							printf("\n");
						}

						else if(Ch==2) {
							printf("Enter position: ");
							scanf("%d",&pos);

							if(pos>0 && pos<size) {
								head=deleteNode(head,pos);
								size--;
								printf("New ");
								display(head);
								printf("\n");
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

					printf("Before Reverting, ");
					display(head);
					printf("\n");

					head=revertList(head);
					printf("After Reverting, ");
					display(head);
					printf("\n");
					break;
				}

				case 5: {

					display(head);
					printf("\n");
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

Someshwars-MBP-0ae4:C someshwargaikwad$ ./Singly_Linked_List
Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Revert the List
5. Display the List
6. Exit

Your Choice: 1


Creating a new List

Enter the number of data elements you want to add: 5

Enter elements:
1
2
3
4
5

New List: 1 2 3 4 5

Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Revert the List
5. Display the List
6. Exit

Your Choice: 2


Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 1


Enter data: 0
New List: 0 1 2 3 4 5

Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 2


Enter position: 3
Enter data: -3
New List: 0 1 -3 2 3 4 5

Select the Options:
1. Insert element at beginning
2. Insert element at a position
3. Insert element at the end
4. Back

Your Choice: 3


Enter data: 6
New List: 0 1 -3 2 3 4 6 5

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
4. Revert the List
5. Display the List
6. Exit

Your Choice: 3


Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 1


New List: 1 -3 2 3 4 6 5

Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 2


Enter position: 2
New List: 1 2 3 4 6 5

Select the Options:
1. Delete element at beginning
2. Delete element at a position
3. Delete element at the end
4. Back

Your Choice: 3


New List: 1 2 3 4 6

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
4. Revert the List
5. Display the List
6. Exit

Your Choice: 4


Before Reverting, List: 1 2 3 4 6

After Reverting, List: 6 4 3 2 1

Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Revert the List
5. Display the List
6. Exit

Your Choice: 5


List: 6 4 3 2 1

Select the Options:
1. Create a List
2. Insert an element
3. Delete an element
4. Revert the List
5. Display the List
6. Exit

Your Choice: 6


End
Someshwars-MBP-0ae4:C someshwargaikwad$ 
*/
