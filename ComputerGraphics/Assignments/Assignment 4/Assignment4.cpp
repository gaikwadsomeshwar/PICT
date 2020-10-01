/*================================================================================
Assignment No: 4
Batch        : H10
Roll No      : 23257
Date         :
Aim          : To implement line drawing and rotation algorithms

Problem Statement:

Draw a 4X4 chessboard rotated 45 ̊ with the horizontal axis. Use Bresenham algorithm
to draw all the lines. Use seed fill algorithm to fill black squares of the
rotated chessboard.

==================================================================================*/

#include <GL/glut.h>
#include <GL/gl.h>
#include<iostream>
#include <cmath>
using namespace std;


#define sin45 (1/sqrt(2))

int X,Y,Side;

typedef struct pixel {

	GLubyte r;
	GLubyte g;
	GLubyte b;
}pixel;

void setPixel (GLint xCoord, GLint yCoord) {

  glBegin(GL_POINTS);
  glVertex2i(xCoord, yCoord);
  glEnd() ;
}

void bresenham_line(int x1, int y1, int x2, int y2) {

  int dx, dy, i, p;
  int incx, incy, inc1, inc2;
  int x,y;
  dx = x2-x1;
  dy = y2-y1;

  if (dx < 0)
  dx = -dx;

  if (dy < 0)
  dy = -dy;

  incx = 1;

  if (x2 < x1)
  incx = -1;

  incy = 1;

  if (y2 < y1)
  incy = -1;

  x = x1; y = y1;

  if (dx > dy) {

    setPixel(x, y);

    p = 2 * dy-dx;
    inc1 = 2*(dy-dx);
    inc2 = 2*dy;

    for (i=0; i<dx; i++) {

      if (p > 0) {

        y += incy;
        p += inc1;
      }

      else
      p += inc2;

      x += incx;
      setPixel(x, y);
    }
  }

  else {

    setPixel(x, y);

    p = 2*dx-dy;
    inc1 = 2*(dx-dy);
    inc2 = 2*dx;

    for (i=0; i<dy; i++) {

      if (p > 0) {

        x += incx;
        p += inc1;
      }

      else
      p += inc2;

      y += incy;
      setPixel(x, y);
    }
  }
}

void bfill(float x,float y,pixel f_clr,pixel b_clr)
{
	pixel c;
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);

	if((c.r!=b_clr.r || c.g!=b_clr.g ||  c.b!=b_clr.b) && (c.r!=f_clr.r || c.g!=f_clr.g || c.b!=f_clr.b)) {

		  glBegin(GL_POINTS);
     	  glVertex2d(x,y);
     		glColor3ub(f_clr.r,f_clr.g,f_clr.b);
      glEnd();
      glFlush();

      bfill(x,y+1,f_clr,b_clr);
      bfill(x-1,y,f_clr,b_clr);
      bfill(x,y-1,f_clr,b_clr);
      bfill(x+1,y,f_clr,b_clr);
    }
}

void Display() {

  int j,i,X1,Y1,X2,Y2,x,y,side;

  pixel bCol;
  pixel color;

  bCol.r=0;
	bCol.g=0;
	bCol.b=0;

	color.r=150;
	color.g=150;
	color.b=150;

  side=Side/4;

  x=side;
  y=0;

  glLineWidth(3);
  glPointSize(2);

  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f (bCol.r,bCol.g,bCol.g);

  for(j=0;j<=4;j++) {

    for(i=0;i<=3;i++) {

      X1=(X+i*x)*sin45-(Y+y)*sin45;
      Y1=(X+i*x)*sin45+(Y+y)*sin45;

      X2=(X+i*x+side)*sin45-(Y+y)*sin45;
      Y2=(X+i*x+side)*sin45+(Y+y)*sin45;

      bresenham_line(X1,Y1,X2,Y2);
    }
    y+=side;
  }

  x=0;
  y=side;

  for(j=0;j<=4;j++) {

    for(i=0;i<=3;i++) {

      X1=(X+x)*sin45-(Y+i*y)*sin45;
      Y1=(X+x)*sin45+(Y+i*y)*sin45;

      X2=(X+x)*sin45-(Y+i*y+side)*sin45;
      Y2=(X+x)*sin45+(Y+i*y+side)*sin45;

      bresenham_line(X1,Y1,X2,Y2);

    }
    x=x+side;

  }

  X1=(X+side)*sin45-Y*sin45;
  Y1=(X+side)*sin45+Y*sin45;

  X2=X*sin45-(Y+side)*sin45;
  Y2=X*sin45+(Y+side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X1=(X+2*side)*sin45-Y*sin45;
  Y1=(X+2*side)*sin45+Y*sin45;

  X2=(X+2*side)*sin45-(Y+side)*sin45;
  Y2=(X+2*side)*sin45+(Y+side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X1=(X+side)*sin45-(Y+side)*sin45;
  Y1=(X+side)*sin45+(Y+side)*sin45;

  X2=(X+2*side)*sin45-(Y+2*side)*sin45;
  Y2=(X+2*side)*sin45+(Y+2*side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X2=(X+3*side)*sin45-(Y+side)*sin45;
  Y2=(X+3*side)*sin45+(Y+side)*sin45;

  X2=(X+4*side)*sin45-(Y+2*side)*sin45;
  Y2=(X+4*side)*sin45+(Y+2*side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X1=(X)*sin45-(Y+2*side)*sin45;
  Y1=(X)*sin45+(Y+2*side)*sin45;

  X2=(X+side)*sin45-(Y+3*side)*sin45;
  Y2=(X+side)*sin45+(Y+3*side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X1=(X+2*side)*sin45-(Y+2*side)*sin45;
  Y1=(X+2*side)*sin45+(Y+2*side)*sin45;

  X2=(X+3*side)*sin45-(Y+3*side)*sin45;
  Y2=(X+3*side)*sin45+(Y+3*side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X1=(X+side)*sin45-(Y+3*side)*sin45;
  Y1=(X+side)*sin45+(Y+3*side)*sin45;

  X2=(X+2*side)*sin45-(Y+4*side)*sin45;
  Y2=(X+2*side)*sin45+(Y+4*side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  X1=(X+3*side)*sin45-(Y+3*side)*sin45;
  Y1=(X+3*side)*sin45+(Y+3*side)*sin45;

  X2=(X+4*side)*sin45-(Y+4*side)*sin45;
  Y2=(X+4*side)*sin45+(Y+4*side)*sin45;

  X1=(X1+X2)/2;
  Y1=(Y1+Y2)/2;

  bfill(X1,Y1,color,bCol);

  glFlush();
  // Clear display window.
  // Set line segment color to green.
  // Specify line-segment geometry.
  // Process all OpenGL routines as quickly as possible.
}

void init (void) {

  glClearColor(1.0,1.0,1.0,0.0);		// Set display-window color to white.
  glMatrixMode(GL_PROJECTION);		// Set projection parameters.
  gluOrtho2D(-1024,1024,-768,768);
}

int main(int argc,char **argv) {

  float temp;

  cout<<"Coordinates:\n";
  cout<<"X: ";
  cin>>X;

  cout<<"Y: ";
  cin>>Y;

  cout<<"Enter side: ";
  cin>>Side;

  glutInit (&argc, argv);									// Initialize GLUT.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);	// Set display mode.
  glutInitWindowPosition(0,0);						// Set top-left display-window position.
  glutInitWindowSize(1024,768);						// Set display-window width and height.
  glutCreateWindow ("Chess Board"); // Create display window.
  init ( );
  glutDisplayFunc (Display);
  glutMainLoop ( );

  return 0;
}
