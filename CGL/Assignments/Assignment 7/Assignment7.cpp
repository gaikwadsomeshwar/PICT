/*================================================================================
Assignment No: 7
Batch        : H10
Roll No      : 23257
Date         :
Aim          : To implement cube rotation

Problem Statement:

Implement Cube rotation about vertical axis passing through its centroid
==================================================================================*/
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <iostream>
#include <cmath>
using namespace std;

void rotate(float);
void display();
void init();
void reshape(int,int);
void timer(int);

void init() {

	glClearColor(0.0,0.0,0.0,1.0);
	glEnable(GL_DEPTH_TEST);
}

int main(int argc,char **argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(500,500);
	glutCreateWindow("Cube Rotation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	init();
	glutMainLoop();
}

float angle=0;

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0,0,-5);
	rotate(angle);
	glutSwapBuffers();
}

void reshape(int w,int h) {

	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1,2,50);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int) {

	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);

	angle+=1;
	if(angle>360)
		angle=angle-360;
}

void rotate(float deg) {

	deg=(deg*3.14)/180;
	int i,j,k;
	float x,y,z;
	float rmatrix[3][3]= { cos(deg)*cos(deg),sin(deg)*cos(deg),-1*sin(deg),
											 cos(deg)*sin(deg)*sin(deg)-sin(deg)*cos(deg),sin(deg)*sin(deg)*sin(deg)+cos(deg)*cos(deg),cos(deg)*sin(deg),
 										 	 cos(deg)*sin(deg)*cos(deg)+sin(deg)*sin(deg),sin(deg)*sin(deg)*cos(deg)-cos(deg)*sin(deg),cos(deg)*cos(deg) };
	float points[24][3]= { -1.0,1.0,1.0,
											-1.0,-1.0,1.0,
											1.0,-1.0,1.0,
											1.0,1.0,1.0,
											1.0,1.0,-1.0,
											1.0,-1.0,-1.0,
											-1.0,-1.0,-1.0,
											-1.0,1.0,-1.0,
											1.0,1.0,1.0,
											1.0,-1.0,1.0,
											1.0,-1.0,-1.0,
											1.0,1.0,-1.0,
											-1.0,1.0,-1.0,
											-1.0,-1.0,-1.0,
											-1.0,-1.0,1.0,
											-1.0,1.0,1.0,
											-1.0,1.0,-1.0,
											-1.0,1.0,1.0,
											1.0,1.0,1.0,
											1.0,1.0,-1.0,
											-1.0,-1.0,-1.0,
											-1.0,-1.0,1.0,
											1.0,-1.0,1.0,
											1.0,-1.0,-1.0 };
	float res[24][3];

	for(i=0;i<24;i++) {
		for(j=0;j<3;j++) {
			res[i][j]=0;
		}
	}

	for(i=0;i<24;i++) {
		for(j=0;j<3;j++) {
			for(k=0;k<3;k++) {
				res[i][j]+=points[i][k]*rmatrix[k][j];
			}
		}
	}

	glColor3f(1.0,1.0,0.0);
	glBegin(GL_QUADS);

	for(i=0;i<24;i++) {
		for(j=0;j<3;j++) {

			if(j==0) x=res[i][j];
			else if(j==1) y=res[i][j];
			else if(j==2) z=res[i][j];
		}
		glVertex3f(x,y,z);
	}
	glEnd();

}
