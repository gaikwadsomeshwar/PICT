#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

union REGS inreg,outreg;
struct SREGS segreg;

void CRDIR() {
	
	char dirname[50];

	printf("\nEnter the directory name: ");
	scanf("%s",dirname);

	inreg.h.ah=0x39;//Create Directory
	inreg.x.dx=FP_OFF(dirname);
	segreg.ds=FP_SEG(dirname);

	int86x(0X21,&inreg,&outreg,&segreg);//INT 21h
	
	if(outreg.x.cflag)
		printf("\nERROR IN CREATING DIRECTORY\n");
		else
		printf("\nDIRECTORY IS CREATED\n");
}

void DELDIR() {
	
	char dirname[50];

	printf("\nEnter the directory name: ");
	scanf("%s",dirname);

	inreg.h.ah=0x3A;//Delete Directory
	inreg.x.dx=FP_OFF(dirname);
	segreg.ds=FP_SEG(dirname);

	int86x(0X21,&inreg,&outreg,&segreg);//INT 21h
	
	if(outreg.x.cflag)
		printf("\nERROR IN DELETING DIRECTORY\n");
		else
		printf("\nDIRECTORY IS DELETED\n");
}

void DELFILE() {
	
	char filename[20];
	
	printf("\nEnter the filename to delete: ");
	scanf("%s",filename);

	inreg.h.ah=0x41;//Delete File
	inreg.x.dx=FP_OFF(filename);

	int86(0x21,&inreg,&outreg);
	
	if(outreg.x.cflag)
		printf("\nERROR!!!\n");
	else
		printf("\n\FILE IS DELETED!!!");
}

void COPY() {
	
	char far(f1[128]);
	char far(f2[128]);
	char far(buffer[256]);
	int bytes;
	int h1,h2;	
	
	printf("\nEnter the Filename to be copied: ");
	scanf("%s",f1);

	inreg.h.ah=0X3D;//Opening File
	inreg.x.dx=FP_OFF(f1);
	segreg.ds=FP_SEG(f1);
	inreg.h.al=0X00;//Read Mode
	intdosx(&inreg,&outreg,&segreg);

	h1=outreg.x.ax;

	printf("\n---------------------------------------------\n");
	if(outreg.x.cflag==0)
		printf("%s File 1 is opened in reading mode!!!\n",f1);
	else
		printf("Cannot Open File 1!!!\n");
	printf("---------------------------------------------\n");

	printf("\nEnter Filename: ");
	scanf("%s",f2);

	inreg.h.ah=0X3C;//Create File
	inreg.x.dx=FP_OFF(f2);
	inreg.x.cx=0X00;
	intdosx(&inreg,&outreg,&segreg);

	if(outreg.x.cflag==0)
		printf("\n%s File 2 created!!!\n",f2);

	inreg.h.ah=0X3D;//Opening File
	inreg.x.dx=FP_OFF(f2);
	segreg.ds=FP_SEG(f2);
	inreg.h.al=0X01;//Write Mode
	intdosx(&inreg,&outreg,&segreg);

	h2=outreg.x.ax;
	
	printf("\n---------------------------------------------\n");
	if(outreg.x.cflag==0)
		printf("%s File 2 has opened in write mode\n",f2);
	printf("---------------------------------------------\n");	

	inreg.h.ah=0X3F;//Read File
	inreg.x.bx=h1;
	inreg.x.cx=255;//Size to Read in bytes
	inreg.x.dx=FP_OFF(buffer);
	segreg.ds=FP_SEG(buffer);
	intdosx(&inreg,&outreg,&segreg);;
	bytes=outreg.x.ax;

	if(outreg.x.cflag==0) {
		
		printf("\n---------------------------------------------\n");
		printf("File 1 is being read\n");
		printf("No of bytes being read: %u\n",outreg.x.ax);
	}

	inreg.h.ah=0X40;//Writing File
	inreg.x.bx=h2;
	inreg.x.cx=bytes;//Size to Write
	inreg.x.dx=FP_OFF(buffer);
	segreg.ds=FP_SEG(buffer);
	intdosx(&inreg,&outreg,&segreg);
	
	if(outreg.x.cflag==0) {

		printf("\nFile 2 is being written\n");
		printf("No of bytes being written: %u\n",outreg.x.ax);
		printf("---------------------------------------------\n");
	}

	inreg.h.ah=0X3E;//Closing File
	inreg.x.bx=h1;
	intdos(&inreg,&outreg);

	inreg.h.ah=0X3E;//Closing File
	inreg.x.bx=h2;
	intdos(&inreg,&outreg);		
}

int main() {

	int ch;
	clrscr();
	
	do {
		
		printf("\n==============================================================================\n");
		printf("File Operations\n1. Create a directory\n2. Delete Directory\n3. Copy a File\n4. Delete a file\n5. Exit\nYour choice: ");
		scanf("%d",&ch);
		printf("==============================================================================\n");
		
		switch(ch) {
			
			case 1:CRDIR();
				break;
			
			case 2:DELDIR();
				break;
			
			case 3:COPY();
				break;
				
			case 4:DELFILE();
				break;				
			
			case 5:printf("END\n\n"); 
				break;

			default:printf("\nInvalid choice\n");
		}
	}while(ch!=5);

	getch();
	return 0;
}
