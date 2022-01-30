#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include<math.h>




void pitch()
{
    int i;
	float theta;
   gluLookAt(0,10, -9, 0, 0, 1, 0, 1, 0);
   glEnable(GL_POLYGON_OFFSET_FILL);
   glPolygonOffset( 1.0, 1.0 );
   //Adding pitch of soccer
   glBegin(GL_QUADS);
     glColor3ub(0,129,0);
      glVertex3f(-10,0,10);
      glVertex3f(10,0,10);
      glVertex3f(10,0,-10);
      glVertex3f(-10,0,-10);
   glEnd();

   glBegin(GL_LINES);
     glColor3ub(255,255,255);
     glVertex3f(-10.1,0,0);
     glVertex3f(10.1,0,0);
   glEnd();

   //First goalpost
   glBegin(GL_LINES);
     glColor3ub(255,255,255);
     glVertex3f(-2.5,0,8.6);
     glVertex3f(2.5,0,8.6);

     glVertex3f(-5,0,7.8);
     glVertex3f(5,0,7.8);

   glEnd();

   glBegin(GL_LINES);
     glVertex3f(-2.5,0,10);
     glVertex3f(-2.5,0,8.6);
     glVertex3f(2.5,0,10);
     glVertex3f(2.5,0,8.6);

     glVertex3f(-5,0,10);
     glVertex3f(-5,0,7.8);

      glVertex3f(5,0,10);
      glVertex3f(5,0,7.8);
   glEnd();
   //end

   //Second goalpost
    glBegin(GL_LINES);
     glColor3ub(255,255,255);
     glVertex3f(-2.5,0,-8.6);
     glVertex3f(2.5,0,-8.6);

     glVertex3f(-5,0,-7.8);
     glVertex3f(5,0,-7.8);
    glEnd();

     glBegin(GL_LINES);
     glVertex3f(-2.5,0,-10);
     glVertex3f(-2.5,0,-8.6);
     glVertex3f(2.5,0,-10);
     glVertex3f(2.5,0,-8.6);

     glVertex3f(-5,0,-10);
     glVertex3f(-5,0,-7.8);

      glVertex3f(5,0,-10);
      glVertex3f(5,0,-7.8);
   glEnd();
   //end

   ////Adding a big circle at middle
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
       for(int i=0;i<360;i++)
       {
           theta=i*(3.1416/180);
           glVertex3f(2*cos(theta),2*sin(theta),0.0);
       }
    glEnd();
    //Adding ball
    glPushMatrix();
      glColor3ub(255,255,255);
      glTranslated(0,0.2,0);
      glutSolidSphere(0.40, 100, 100);
    glPopMatrix();


}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
    pitch();
  glPopMatrix();

  glutSwapBuffers();
}

void reshape(int w, int h)
{

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100.0,w/(float)h,0.1,30.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, w, h);
  display();
}



int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1000, 500);
  glutInitWindowPosition(150, 150);
  glutCreateWindow("Soccer project");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return(0);
}
