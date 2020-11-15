#include <GL/glut.h>
#include <GL/gl.h>
#include<iostream>
using namespace std;

int X1,Y1,X2,Y2;

int abs(int x) {
	
	if(x<0)
		return (x*(-1));
	else
		return x;
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
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
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
    steps++;
  }
}	

void GeneratePolygon() {

  int x1,y1,x2,y2,x3,y3,x4,y4,temp1,temp2;
  
	x1=X1;
  y1=Y1;
	
	x2=X1;
	y2=Y2;
	
	x3=X2;
	y3=Y2;
	
	x4=X2;
	y4=Y1;
	
	glColor3f(0.0f, 0.5f, 0.5f);

  Bresenham(x1,y1,x2,y2);
	Bresenham(x2,y2,x3,y3);
	Bresenham(x3,y3,x4,y4);
	Bresenham(x4,y4,x1,y1);
	
	temp1=x1;
	temp2=y1;
	
	x1=(x1+x2)/2;
	y1=(y1+y2)/2;
	
	x2=(x2+x3)/2;
	y2=(y2+y3)/2;

	x3=(x3+x4)/2;
	y3=(y3+y4)/2;

	x4=(temp1+x4)/2;
	y4=(temp2+y4)/2;
	
	glColor3f(1.0f, 0.0f, 1.0f);

  Bresenham(x1,y1,x2,y2);
	Bresenham(x2,y2,x3,y3);
	Bresenham(x3,y3,x4,y4);
	Bresenham(x4,y4,x1,y1);
	
	temp1=x1;
	temp2=y1;

	x1=(x1+x2)/2;
	y1=(y1+y2)/2;
	
	x2=(x2+x3)/2;
	y2=(y2+y3)/2;

	x3=(x3+x4)/2;
	y3=(y3+y4)/2;

	x4=(temp1+x4)/2;
	y4=(temp2+y4)/2;
	
	glColor3f(2.0f, 0.5f, 1.0f);
	
  Bresenham(x1,y1,x2,y2);
	Bresenham(x2,y2,x3,y3);
	Bresenham(x3,y3,x4,y4);
	Bresenham(x4,y4,x1,y1);

  glFlush();
}

void init() {
	
	glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
    
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(-320,320,-240,240);  
}

int main(int argc, char** argv) {
    
	cout<<"Starting Coordinates:\n";
	cout<<"X1: ";
	cin>>X1;
	cout<<"Y1: ";
	cin>>Y1;
	cout<<"End Coordinates:\n";
	cout<<"X2: ";
	cin>>X2;
	cout<<"Y2: ";
	cin>>Y2;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1600,900);
  glutInitWindowPosition(320,240);
  glutCreateWindow("Bresenham");
  init();
  glutDisplayFunc(GeneratePolygon);
  glutMainLoop();     
    
  return 0;
}
