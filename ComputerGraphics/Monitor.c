#include <GL/freeglut.h>
#include <GL/gl.h>

void OuterSquare() {

	glBegin(GL_LINES);
	
		glVertex2i(30,30);        
		glVertex2i(30,450);
        
    glVertex2i(30,450);
    glVertex2i(610,450);
        
    glVertex2i(610,30);
    glVertex2i(610,450); 
    
    glVertex2i(370,30);
    glVertex2i(610,30); 
    
    glVertex2i(30,30);
    glVertex2i(270,30);
    
	glEnd();
}

void InnerSquare() {

	glBegin(GL_LINES);
	
		glVertex2i(40,40);				
		glVertex2i(40,440);
        
    glVertex2i(40,440);
    glVertex2i(600,440);
        
    glVertex2i(600,40);
    glVertex2i(600,440);
        
    glVertex2i(40,40);
    glVertex2i(600,40);	
	
	glEnd();
}

void Mountains() {

	glBegin(GL_LINES);
	
    glVertex2i(40,40);
		glVertex2i(160,160);
        
    glVertex2i(320,40);
    glVertex2i(160,160);
        
    glVertex2i(320,40);
    glVertex2i(480,350);
        
    glVertex2i(600,40);
    glVertex2i(480,350);
	
	glEnd();
}

void Stand() {

	glBegin(GL_LINES);
	
		glVertex2i(60,0);
    glVertex2i(270,30); 	
	
		glVertex2i(370,30);
    glVertex2i(580,0);

	glEnd();
}

void renderFunction() {
    
  OuterSquare();
	InnerSquare();
	Stand();
	Mountains();
  glFlush();
}

void init() {
	
	glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
    
  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);  
}

int main(int argc, char** argv) {
    
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
  glutInitWindowPosition(320,240);
  glutCreateWindow("Sample");
  init();
  glutDisplayFunc(renderFunction);
  glutMainLoop();     
    
    return 0;
}
