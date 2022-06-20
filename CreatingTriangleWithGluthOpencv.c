#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gl\glu.h>
//most systems include GL/glut.h others just glut.h
#include "gl\glut.h"
//#include <GL/glut.h>

	

void display(void){
	

       glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(2, 3, 1);
        glVertex3f(7, 3, 1);
        glVertex3f(2, 6, 1);
        
	    glRotatef(30, 0.0,0.0,1.0);

        glEnd(); 
   
	      glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(6, 6, 0);
        glVertex3f(10, 6, 0);
        glVertex3f(10, 10, 0);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(2, -3, 1);
        glVertex3f(7, -3, 1);
        glVertex3f(2, -6, 1);
        glEnd();
        
        
      
	glFlush();

}


int main(int argc, char *argv[]){
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("deneme");
    
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,20.0,-10.0,20.0,-2.0,1.0);
    
    
 glutDisplayFunc(display);
     
  
    glutMainLoop();
    
    
	return 0;
}

