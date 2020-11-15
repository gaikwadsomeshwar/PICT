/*
============================================================================
Name        : Someshwar Gaikwad
Class       : SE-10 (H-10)
Roll No.    : 23257

Title       : String Operations (Without Pointers)

Problem Statement:

Implement following operations on string with / without pointers
(without using library functions)

1. Length
2. Palindrome
3. String comparison
4. Copy
5. Reverse
6. Substring
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int length(char s[])
{
	int len=0;
	int i=0;

	while(s[i]!='\0')
	{
		len=len+1;
		i++;
	}

	return len;
}

void copy(char s1[],char s2[])
{
	int len=length(s2);
	int i;

	for(i=0;i<len;i++)
	{
		s1[i]=s2[i];
	}

	s1[i]='\0';
}

void reverse(char s1[])
{
	int len=length(s1);
	char s2[len];

	copy(s2,s1);

	int i,j=len-1;

	for(i=0;i<len;i++)
	{
		s1[i]=s2[j--];
	}
}

void palin(char s1[])
{
	int len=length(s1);
	char s2[len];

	copy(s2,s1);

	reverse(s2);

	int i,flag=0;

	for(i=0;i<len;i++)
	{
		if(s2[i]!=s1[i])
		{
			flag=1;
			break;
		}
	}

	if(flag==1)
	{
		printf("%s is not a palindrome string\n",s1);
	}

	else if(flag==0)
	{
		printf("%s is a palindrome string\n",s1);
	}

}

int compare(char s1[],char s2[])
{
	int i,flag=1;

	int len1=length(s1);
	int len2=length(s2);
	int len;

	if(len1>=len2)
	{
		len=len2;
	}

	else
	{
		len=len1;
	}

	for(i=0;i<len;i++)
	{
		if(s1[i]!=s2[i])
		{
			flag=0;
			return ((int)s1[i]-(int)s2[i]);
		}
	}

	if(flag==1)
	{
		return 0;
	}
}

void subString(char s1[],char s2[])
{
	int len1=length(s1);
	int len2=length(s2);
	int i,j=0,c=0;

	for(i=0;i<len1;i++)
	{
		if(j==len2)
		{
			break;
		}
		if(s1[i]==s2[j])
		{
			j++;
		}
		else 
		{
			j=0;
			i=c;
			c++;
		}
	}
			
		
	if(j==len2)
	{
		printf("%s is a part of %s\n\n",s2,s1);
	}
	else
	{
		printf("%s is not a part of %s\n\n",s2,s1);
	}
}

int main(void)
{
	char s1[50],s2[50];
	int len,l;

	printf("Enter a string\n");
	scanf("%s",s1);

	printf("\n\n");

	int ch;
	do
	{
		printf("Select the Options:\n");
		printf("1. Length\n");
		printf("2. Palindrome\n");
		printf("3. String Compare\n");
		printf("4. Copy\n");
		printf("5. Reverse\n");
		printf("6. Substring\n");
		printf("7. Exit\n\n");
		scanf("%d",&ch);

		switch(ch)
		{

			case 1:printf("String : %s\n",s1);

				   len=length(s1);

				   printf("Length of String : %d\n",len);
				   printf("\n\n");

				   break;

			case 2:printf("String : %s\n",s1);
				   palin(s1);
				   printf("\n\n");

				   break;

			case 3:printf("Enter a string to compare it with %s: ",s1);
				   scanf("%s",s2);

				   printf("String 1: %s\n",s1);
				   printf("String 2: %s\n",s2);

				   l=compare(s1,s2);

				   printf("Returned Value: %d\n\n",l);

				   break;

			case 4:printf("Enter a string to copy it in %s: ",s1);
			   	   scanf("%s",s2);

			   	   printf("Before Copying:\n");
			   	   printf("String 1: %s\n",s1);
			   	   printf("String 2: %s\n\n",s2);

			   	   copy(s1,s2);

			   	   printf("After Copying:\n");
			   	   printf("String 1: %s\n",s1);
			   	   printf("String 2: %s\n\n",s2);

			   	   break;

			case 5:printf("Before Reversing:\n");
		   	       printf("String : %s\n\n",s1);

		   	       reverse(s1);

		   	       printf("After Reversing:\n");
		   	       printf("String : %s\n\n",s1);

				   break;

			case 6:printf("Enter a string to check if it is a part of %s: ",s1);
			   	   scanf("%s",s2);

			   	   printf("String 1: %s\n",s1);
			   	   printf("String 2: %s\n",s2);

			   	   subString(s1,s2);

			   	   printf("\n\n");

				   break;

			case 7:printf("END\n\n");
				   break;
			default:printf("Enter Again/n");
		}
	}
	while(ch!=7);

	return EXIT_SUCCESS;
}

