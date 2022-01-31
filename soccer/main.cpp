#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include<math.h>




void goalpost()
{
    glColor3f(255,255,255);
    glBegin(GL_LINE_LOOP);
     glLineWidth(4);
     glVertex3f(-1.5,0.0,-15);
     glVertex3f(1.5,0.0,-15);
     glVertex3f(1.5,2.0,-13);
     glVertex3f(-1.5,2.0,-13);
    glEnd();

    glColor3f(255,255,255);
    glBegin(GL_LINE_LOOP);
     glLineWidth(4);
     glVertex3f(-1.5,0.0,15);
     glVertex3f(1.5,0.0,15);
     glVertex3f(1.5,2.0,13);
     glVertex3f(-1.5,2.0,13);
    glEnd();
}
void circle()
{
    ////Adding a big circle at middle
    int i;
	float theta;
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
       for(int i=0;i<360;i++)
       {
           theta=i*(3.1416/180);
           glVertex3f(2*cos(theta),2*sin(theta),0);
       }
    glEnd();
}

void ball()
{
    //Adding ball
    glPushMatrix();
      glColor3ub(255,255,255);
      glTranslated(0,0.2,0);
      glutSolidSphere(0.40, 100, 100);
    glPopMatrix();
}

void pitch()
{
   gluLookAt(5,10, 0, 1, 0, 0, 0, 1, 0);
   glEnable(GL_POLYGON_OFFSET_FILL);
   glPolygonOffset( 1.0, 1.0 );
   //Adding pitch of soccer
   glLineWidth(3);
   glBegin(GL_QUADS);
     glColor3ub(0,129,0);
      glVertex3f(-7,0,15);
      glVertex3f(7,0,15);
      glVertex3f(7,0,-15);
      glVertex3f(-7,0,-15);
   glEnd();

   //Line at middle
   glBegin(GL_LINES);
     glColor3ub(255,255,255);
     glVertex3f(-7,0,0);
     glVertex3f(7,0,0);
   glEnd();

   glBegin(GL_LINE_LOOP);
     glColor3ub(255,255,255);
     glVertex3f(-2.3,0,12.5);
     glVertex3f(2.3,0,12.5);
     glVertex3f(2.3,0,15);
     glVertex3f(-2.3,0,15);
   glEnd();

   glBegin(GL_LINE_LOOP);
     glColor3ub(255,255,255);
     glVertex3f(-3.5,0,10.5);
     glVertex3f(3.5,0,10.5);
     glVertex3f(3.5,0,15);
     glVertex3f(-3.5,0,15);
   glEnd();

    glBegin(GL_LINE_LOOP);
     glColor3ub(255,255,255);
     glVertex3f(-2.3,0,-12.5);
     glVertex3f(2.3,0,-12.5);
     glVertex3f(2.3,0,-15);
     glVertex3f(-2.3,0,-15);
   glEnd();

   glBegin(GL_LINE_LOOP);
     glColor3ub(255,255,255);
     glVertex3f(-3.5,0,-10.5);
     glVertex3f(3.5,0,-10.5);
     glVertex3f(3.5,0,-15);
     glVertex3f(-3.5,0,-15);
   glEnd();

   glBegin(GL_POINTS);
    glVertex3f(0,0,11.5);
    glVertex3f(0,0,-11.5);
   glEnd();

}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
    pitch();
     ball();
     circle();
     goalpost();
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
