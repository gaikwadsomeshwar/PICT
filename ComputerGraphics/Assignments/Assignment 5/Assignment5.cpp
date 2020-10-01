/*================================================================================
Assignment No: 5
Batch        : H10
Roll No      : 23257
Date         :
Aim          : To implement Polygon/Line Clipping

Problem Statement:

Implement Cohen Sutherland algorithm to clip any given Line/polygon. Provide
the vertices of the Line/polygon to be clipped and pattern of clipping interactively.
==================================================================================*/
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <iostream>
using namespace std;

int N;
float X1,Y1,X2,Y2;
float xmin,ymin,xmax,ymax;

int Abs(int);
void DDA(float,float,float,float);
int code(int,int);
void display();
void init();

void init() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(-1000,1000,-1000,1000);
}

int main(int argc,char **argv) {

	cout<<"Enter Coordinates for Clipping Window\n";
	cout<<"Xmin: ";
	cin>>xmin;
	cout<<"Ymin: ";
	cin>>ymin;
	cout<<"Xmax: ";
	cin>>xmax;
	cout<<"Ymax: ";
	cin>>ymax;

	cout<<"X1: ";
	cin>>X1;
	cout<<"Y1: ";
	cin>>Y1;
	cout<<"X2: ";
	cin>>X2;
	cout<<"Y2: ";
	cin>>Y2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(800,900);
	glutInitWindowPosition(320,240);
	glutCreateWindow("Polygon Clipping");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

int code(float x,float y) {

	if(x>=xmin && x<=xmax) {

		if(y<ymin)
			return 4;

		if(y>=ymin && y<=ymax)
			return 0;

		if(y>ymax)
			return 8;
	}

	if(x<xmin) {

		if(y<ymin)
			return 5;

		if(y>=ymin && y<=ymax)
			return 1;

		if(y>ymax)
			return 9;
	}

	if(x>xmax) {

		if(y<ymin)
			return 6;

		if(y>=ymin && y<=ymax)
			return 2;

		if(y>ymax)
			return 10;
	}
}

void display() {

	int f1,f2,f3;
	float x,y,m;
	m=(Y2-Y1)/(X2-X1);

	glColor3f(1.0, 1.0, 0.0);
	DDA(xmin,ymin,xmax,ymin);
	DDA(xmax,ymax,xmax,ymin);
	DDA(xmin,ymax,xmax,ymax);
	DDA(xmin,ymin,xmin,ymax);

	f1=code(X1,Y1);
	f2=code(X2,Y2);
	glColor3f(1.0, 1.0, 1.0);

	if(f1==0 && f2==0)
		DDA(X1,Y1,X2,Y2);

	else if((f1&f2)==0) {

		x=X1;
		y=Y1;

		switch(f1) {

			case 1: {

				X1=xmin;
				Y1=m*(X1-x)+y;
				break;
			}
			case 2: {

				X1=xmax;
				Y1=m*(X1-x)+y;
				break;
			}
			case 4: {

				Y1=ymin;
				X1=((Y1-y)/m)+x;
				break;
			}
			case 5: {

				X1=xmin;
				Y1=m*(X1-x)+y;
				f3=code(X1,Y1);
				if(f3!=0) {
					Y1=ymin;
					X1=((Y1-y)/m)+x;
				}
				break;
			}
			case 6: {

				X1=xmax;
				Y1=m*(X1-x)+y;
				f3=code(X1,Y1);
				if(f3!=0) {
					Y1=ymin;
					X1=((Y1-y)/m)+x;
				}
				break;
			}
			case 8: {

				Y1=ymax;
				X1=((Y1-y)/m)+x;
				break;
			}
			case 9: {

				X1=xmin;
				Y1=m*(X1-x)+y;
				f3=code(X1,Y1);
				if(f3!=0) {
					Y1=ymax;
					X1=((Y1-y)/m)+x;
				}
				break;
			}
			case 10: {

				X1=xmax;
				Y1=m*(X1-x)+y;
				f3=code(X1,Y1);
				if(f3!=0) {
					Y1=ymax;
					X1=((Y1-y)/m)+x;
				}
				break;
			}
		}

		x=X2;
		y=Y2;

		switch(f2) {

			case 1: {

				X2=xmin;
				Y2=m*(X2-x)+y;
				break;
			}
			case 2: {

				X2=xmax;
				Y2=m*(X2-x)+y;
				break;
			}
			case 4: {

				Y2=ymin;
				X2=((Y2-y)/m)+x;
				break;
			}
			case 5: {

				X2=xmin;
				Y2=m*(X2-x)+y;
				f3=code(X2,Y2);
				if(f3!=0) {
					Y2=ymin;
					X2=((Y2-y)/m)+x;
				}
				break;
			}
			case 6: {

				X2=xmax;
				Y2=m*(X2-x)+y;
				f3=code(X2,Y2);
				if(f3!=0) {
					Y2=ymin;
					X2=((Y2-y)/m)+x;
				}
				break;
			}
			case 8: {

				Y2=ymax;
				X2=((Y2-y)/m)+x;
				break;
			}
			case 9: {

				X2=xmin;
				Y2=m*(X2-x)+y;
				f3=code(X2,Y2);
				if(f3!=0) {
					Y2=ymax;
					X2=((Y2-y)/m)+x;
				}
				break;
			}
			case 10: {

				X2=xmax;
				Y2=m*(X2-x)+y;
				f3=code(X2,Y2);
				if(f3!=0) {
					Y2=ymax;
					X2=((Y2-y)/m)+x;
				}
				break;
			}
		}
		DDA(X1,Y1,X2,Y2);
	}
	glFlush();
}

int Abs(int x) {

	if(x<0)
		return (x*(-1));
	else
		return x;
}

void DDA(float x1,float y1,float x2,float y2) {

	float dx,dy,steps,x,y,i,Xinc,Yinc;

	dx=x2-x1;
	dy=y2-y1;

	if(Abs(dx)>=Abs(dy))
		steps=Abs(dx);
	else
		steps=Abs(dy);

	Xinc=dx/steps;
	Yinc=dy/steps;

	x=x1;
	y=y1;

	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();

	for(i=0;i<=steps;i++) {

		x=x+Xinc;
		y=y+Yinc;

    glBegin(GL_POINTS);
    	glVertex2i(x,y);
    glEnd();
  }
}
