#include <GL/freeglut.h>
#include <GL/gl.h>
#include<iostream>
using namespace std;

float X1,Y1,X2,Y2;

void DDA(float x1,float y1,float x2,float y2) {

	float dx,dy,steps,x,y,i,Xinc,Yinc;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>=abs(dy)) 
		steps=abs(dx);
	else
		steps=abs(dy);
		
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

  DDA(x1,y1,x2,y2);
	DDA(x2,y2,x3,y3);
	DDA(x3,y3,x4,y4);
	DDA(x4,y4,x1,y1);
	
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

  DDA(x1,y1,x2,y2);
	DDA(x2,y2,x3,y3);
	DDA(x3,y3,x4,y4);
	DDA(x4,y4,x1,y1);
	
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
	
  DDA(x1,y1,x2,y2);
	DDA(x2,y2,x3,y3);
	DDA(x3,y3,x4,y4);
	DDA(x4,y4,x1,y1);

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
  glutCreateWindow("DDA");
  init();
  glutDisplayFunc(GeneratePolygon);
  glutMainLoop();     
    
  return 0;
}
