/*============================================================================
Name     : Someshwar Gaikwad
Class    : SE-10 (H-10)
Roll No  : 23257

Title: Generalized Linked List

Problem Statement:

Implement Generalized Linked List to create and display the book index.
============================================================================*/

#include <stdio.h>
#include <stdlib.h>

struct Node {

	struct Node *next;
	int flag;

	union {

		char data[51];
		struct Node *dlink;

	}u;
};

typedef struct Node Node;

Node* getnode() {

	Node* New=(Node*)malloc(sizeof(Node));
	New->next = NULL;
	New->u.dlink = NULL;
	return New;
}

Node* Create_GLL(Node* head,char str[]) {

	int i,j;
	Node *temp;

	for(i=0;str[i]!='\0';) {

		if(str[i]=='(' && i==0) {
			head=getnode();
			temp=head;
		}
		else {
			temp->next=getnode();
			temp=temp->next;
		}

		i++;
		j=0;

		while(str[i]!=',' && str[i]!='(' && str[i]!=')') {

			temp->u.data[j]=str[i];
			i++;
			j++;
		}

		temp->u.data[j] = '\0';
		temp->flag = 0;

		if(str[i] == '(') {

			temp->next = getnode();
			temp = temp->next;
			temp->flag = 1;
			temp->u.dlink = Create_GLL(NULL,&str[i]);

			while(str[i] != ')')
				i++;
			i++;
		}

		if(str[i] == ')')
			return head;
	}
	return head;
}

void Display(Node* temp) {

	static int depth;
	int i;
	depth++;

	if(temp == NULL) {

		if(depth == 1)
			printf("List is Empty");
		else
			printf("Sublist is Empty");
	}

	else {

		while(temp != NULL) {

			if(temp->flag == 0) {

				printf("\n");
				for(i = 1; i <= depth; i++)
				printf(" ");
				printf("%s", temp->u.data);
			}
			else Display(temp->u.dlink);

			temp = temp->next;
		}
	}
	depth--;
}

int main() {

	Node *head = NULL;
	int x=0;

	do {

		char str[100];

		printf("\nEnter the book index, string to be converted to GLL: ");
		scanf("%s",str);

		printf("The book index is: ");
		head = Create_GLL(head, str);
		Display(head);

		printf("\n\nTo exit press 0: ");
		scanf("%d",&x);
	}
	while(x!=0);
	printf("End\n");
	return 0;
}

/*

Output:

Someshwars-MBP-0ae4:C someshwargaikwad$ gcc Generalized_Linked_List.c -o Generalized_Linked_List
Someshwars-MBP-0ae4:C someshwargaikwad$ ./Generalized_Linked_List

Enter the book index, string to be converted to GLL: (1.Introduction(1.1_GettingStarted,1.2_History),2.Basics,3.Advanced(3.1_Inheritance,3.2_DataHiding))
The book index is:
 1.Introduction
  1.1_GettingStarted
  1.2_History
 2.Basics
 3.Advanced
  3.1_Inheritance
  3.2_DataHiding

To exit press 0: 0
End
Someshwars-MBP-0ae4:C someshwargaikwad$
*/
