/*================================================================================
Assignment No: 6
Batch        : H10
Roll No      : 23257
Date         :
Aim          : To implement transformation algorithms

Problem Statement:

Implement translation, sheer, rotation and scaling transformations on equilateral
triangle and rhombus.
==================================================================================*/
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <iostream>
#include <cmath>
using namespace std;

int side,choice;
int tx,ty,xsh,ysh,sx,sy;
float theta;

int Abs(int x) {

	if(x>0)
		return x;
	else
		return (-1*x);
}

int sign(int x) {

	if(x==0)
		return 0;

	else if(x<0)
		return -1;

	else return 1;
}

void SWAP(int *x,int *y) {

	int temp=*x;
	*x=*y;
	*y=temp;
}

void Bresenham(int x1,int y1,int x2,int y2) {

	int dx,dy,steps=1,x,y,i,P,sw=0,s1,s2;

	x=x1;
	y=y1;

	dx=Abs(x2-x1);
	dy=Abs(y2-y1);

	s1=sign(x2-x1);
	s2=sign(y2-y1);

	if(dy>dx) {

		SWAP(&dx,&dy);
		sw=1;
	}

	P=(2*dy)-dx;

	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();

	while(steps<=dx) {

		if(P>=0) {

			x=x+s1;
			y=y+s2;
			P=P+2*(dy-dx);
		}

		else {

			if(sw==1) y=y+s2;
			else      x=x+s1;

		 	P=P+2*dy;
		}
		glBegin(GL_POINTS);
    	glVertex2i(x,y);
    glEnd();
		glFlush();
    steps++;
  }
}

void Translate(int x1,int y1,int x2,int y2) {

	x1=x1+tx;
	y1=y1+ty;

	x2=x2+tx;
	y2=y2+ty;

	Bresenham(x1,y1,x2,y2);
}

void Rotate(int x1,int y1,int x2,int y2) {

	int temp1,temp2;

	temp1=x1;
	temp2=y1;

	x1=temp1*cos(theta)-temp2*sin(theta);
	y1=temp1*sin(theta)+temp2*cos(theta);

	temp1=x2;
	temp2=y2;

	x2=temp1*cos(theta)-temp2*sin(theta);
	y2=temp1*sin(theta)+temp2*cos(theta);

	Bresenham(x1,y1,x2,y2);
}

void Scale(int x1,int y1,int x2,int y2) {

	x1=x1*sx;
	y1=y1*sy;
	x2=x2*sx;
	y2=y2*sy;

	Bresenham(x1,y1,x2,y2);
}

void XShear(int x1,int y1,int x2,int y2) {

	y1=y1+x1*xsh;
	y2=y2+x2*xsh;

	Bresenham(x1,y1,x2,y2);
}

void YShear(int x1,int y1,int x2,int y2) {

	x1=x1+y1*ysh;
	x2=x2+y2*ysh;

	Bresenham(x1,y1,x2,y2);
}

void GenerateTriangle() {

	glColor3f(0.0, 0.0, 0.0);

	int h=(1.732/2)*side;

	Bresenham(-1000,0,1000,0);
	Bresenham(0,1000,0,-1000);
	Bresenham(0,0,side,0);
	Bresenham(0,0,side/2,h);
	Bresenham(side,0,side/2,h);

	if(choice==1) {

		glColor3f(1.0, 0.0, 0.0);

		Translate(0,0,side,0);
		Translate(0,0,side/2,h);
		Translate(side,0,side/2,h);
	}

	else if(choice==2) {

		glColor3f(0.0, 1.0, 0.0);

		Rotate(0,0,side,0);
		Rotate(0,0,side/2,h);
		Rotate(side,0,side/2,h);
	}

	else if(choice==3) {

		glColor3f(0.0, 0.0, 1.0);

		Scale(0,0,side,0);
		Scale(0,0,side/2,h);
		Scale(side,0,side/2,h);
	}

	else if(choice==4) {

		glColor3f(1.0, 1.0, 0.0);

		XShear(0,0,side,0);
		XShear(0,0,side/2,h);
		XShear(side,0,side/2,h);
	}

	else if(choice==5) {

		glColor3f(0.0, 1.0, 1.0);

		YShear(0,0,side,0);
		YShear(0,0,side/2,h);
		YShear(side,0,side/2,h);
	}
}

void GenerateRhombus() {

	glColor3f(0.0, 0.0, 0.0);

	Bresenham(-1000,0,1000,0);
	Bresenham(0,1000,0,-1000);
	Bresenham(0,0,side/2,side);
	Bresenham(0,0,side/2,-1*side);
	Bresenham(side,0,side/2,side);
	Bresenham(side,0,side/2,-1*side);

	if(choice==1) {

		glColor3f(1.0, 0.0, 0.0);

		Translate(0,0,side/2,side);
		Translate(0,0,side/2,-1*side);
		Translate(side,0,side/2,side);
		Translate(side,0,side/2,-1*side);
	}

	else if(choice==2) {

		glColor3f(0.0, 1.0, 0.0);

		Rotate(0,0,side/2,side);
		Rotate(0,0,side/2,-1*side);
		Rotate(side,0,side/2,side);
		Rotate(side,0,side/2,-1*side);
	}

	else if(choice==3) {

		glColor3f(0.0, 0.0, 1.0);

		Scale(0,0,side/2,side);
		Scale(0,0,side/2,-1*side);
		Scale(side,0,side/2,side);
		Scale(side,0,side/2,-1*side);
	}

	else if(choice==4) {

		glColor3f(1.0, 1.0, 0.0);

		XShear(0,0,side/2,side);
		XShear(0,0,side/2,-1*side);
		XShear(side,0,side/2,side);
		XShear(side,0,side/2,-1*side);
	}

	else if(choice==5) {

		glColor3f(0.0, 1.0, 1.0);

		YShear(0,0,side/2,side);
		YShear(0,0,side/2,-1*side);
		YShear(side,0,side/2,side);
		YShear(side,0,side/2,-1*side);
	}
}

void init (void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(-1000,1000,-1000,1000);
}

int main(int argc, char** argv) {

	int ch,flag=0;

	do {

	  cout<<"==================================\n";
	  cout<<"Select Correct Option\n";
	  cout<<"==================================\n";
	  cout<<"1. Generate Equilateral Triangle\n";
	  cout<<"2. Generate Rhombus\n";
	  cout<<"3. Exit\n";
	  cout<<"Your Chice: ";
	  cin>>ch;
	  cout<<"==================================\n";

		switch(ch) {

			case 1: {

				cout<<"Side: ";
				cin>>side;

				cout<<"==================================\n";
			  cout<<"Select Correct Option\n";
			  cout<<"==================================\n";
			  cout<<"1. Translation\n";
			  cout<<"2. Rotation\n";
				cout<<"3. Scaling\n";
				cout<<"4. X Shear\n";
				cout<<"5. Y Shear\n";
			  cout<<"6. Back\n";
			  cout<<"Your Chice: ";
			  cin>>choice;
			  cout<<"==================================\n";

				if(choice==1) {

					cout<<"Translation Factor X: ";
					cin>>tx;

					cout<<"Translation Factor Y: ";
					cin>>ty;
				}

				else if(choice==2) {

					cout<<"Angle of Rotation   : ";
					cin>>theta;
					theta=(theta*3.14)/180;
				}

				else if(choice==3) {

					cout<<"Scaling Factor X    : ";
					cin>>sx;

					cout<<"Scaling Factor Y    : ";
					cin>>sy;
				}

				else if(choice==4) {

					cout<<"X Shear             : ";
					cin>>xsh;
				}

				else if(choice==5) {

					cout<<"Y Shear             : ";
					cin>>ysh;
				}

				else if(choice==6) break;

				glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_SINGLE);
				glutInitWindowSize(800,900);
				glutInitWindowPosition(320,240);
				glutCreateWindow("Equilateral Triangle");
				init();
				glutDisplayFunc(GenerateTriangle);
				glutMainLoop();
				break;
			}

			case 2: {

				cout<<"Side: ";
				cin>>side;

				cout<<"==================================\n";
			  cout<<"Select Correct Option\n";
			  cout<<"==================================\n";
			  cout<<"1. Translation\n";
			  cout<<"2. Rotation\n";
				cout<<"3. Scaling\n";
				cout<<"4. X Shear\n";
				cout<<"5. Y Shear\n";
			  cout<<"6. Back\n";
			  cout<<"Your Chice: ";
			  cin>>choice;
			  cout<<"==================================\n";

				if(choice==1) {

					cout<<"Translation Factor X: ";
					cin>>tx;

					cout<<"Translation Factor Y: ";
					cin>>ty;
				}

				else if(choice==2) {

					cout<<"Angle of Rotation   : ";
					cin>>theta;
					theta=(theta*3.14)/180;
				}

				else if(choice==3) {

					cout<<"Scaling Factor X    : ";
					cin>>sx;

					cout<<"Scaling Factor Y    : ";
					cin>>sy;
				}

				else if(choice==4) {

					cout<<"X Shear             : ";
					cin>>xsh;
				}

				else if(choice==5) {

					cout<<"Y Shear             : ";
					cin>>ysh;
				}

				else if(choice==6) break;

				glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_SINGLE);
				glutInitWindowSize(800,900);
				glutInitWindowPosition(320,240);
				glutCreateWindow("Rhombus");
				init();
				glutDisplayFunc(GenerateRhombus);
				glutMainLoop();
				break;
			}

			case 3: cout<<"End\n";
			break;

			default: cout<<"Select correct Option\n\n";
		}
	}
	while(ch!=3);
	return 0;
}
