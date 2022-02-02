#include <windows.h>
#include <gl/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include <string>
#include<math.h>
using namespace std;

int homeTeam = 0,awayTeam = 0;
char txt[30];
float xmove[]{ 0, 0 };
float ymove[]{ 0, 0 };
float zmove[]{ 0, 0 };


void gameScore(char *String)
{
    sprintf(txt,"FLA %d X %d VAS 1T 00:00",homeTeam,awayTeam);

  	glPushMatrix();
        glRasterPos3f(0,9.3,2);
        while(*String)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*String++);
	glPopMatrix();
}


void goalpost()
{
    glColor3f(255,255,255);
    //First goalpost
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
     glVertex3f(-1.5,0.0,-15);
     glVertex3f(1.5,0.0,-15);
     glVertex3f(1.5,2.0,-13);
     glVertex3f(-1.5,2.0,-13);
    glEnd();

   glLineWidth(1);
   glBegin(GL_LINE_LOOP);
      glVertex3f(1.6,0,-17);
      glVertex3f(-1.6,0,-17);
      glVertex3f(-1.5,2.0,-13);
      glVertex3f(1.5,2.0,-13);
    glEnd();
    glBegin(GL_LINES);
      glVertex3f(1.6,0,-17);
      glVertex3f(1.6,0.0,-15);
      glVertex3f(-1.6,0,-17);
      glVertex3f(-1.6,0.0,-15);
    glEnd();


    //Second goalpost
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
     glVertex3f(-1.5,0.0,15);
     glVertex3f(1.5,0.0,15);
     glVertex3f(1.5,2.0,13);
     glVertex3f(-1.5,2.0,13);
    glEnd();

    glLineWidth(1);
   glBegin(GL_LINE_LOOP);
      glVertex3f(1.6,0,17);
      glVertex3f(-1.6,0,17);
      glVertex3f(-1.5,2.0,13);
      glVertex3f(1.5,2.0,13);
    glEnd();
    glBegin(GL_LINES);
      glVertex3f(1.6,0,17);
      glVertex3f(1.6,0.0,15);
      glVertex3f(-1.6,0,17);
      glVertex3f(-1.6,0.0,15);
    glEnd();
}

void players()
{
  //Home team
  //player 1
  glColor3ub(255,0,0);
  glPushMatrix();
      glTranslatef(0.0, 0.0, 13);
      glScalef(0.7,1.0,0.5);
      glutSolidCube(1.0);
  glPopMatrix();
  //header
  glPushMatrix();
      glColor3ub(255, 205, 153);
      glTranslatef(0.0, 1.0, 13);
      glutSolidSphere(0.40,100,100);
  glPopMatrix();
  //end

  //player 2
  glColor3ub(255,0,0);
  glPushMatrix();
     glTranslatef(-1.6, 0.0, 9.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

  //header
   glPushMatrix();
      glColor3ub(255, 205, 153);
     glTranslatef(-1.6, 1.0, 9.0);
     glutSolidSphere(0.40,100,100);
  glPopMatrix();
  //end

  //player 3
  glColor3ub(255,0,0);
  glPushMatrix();
     glTranslatef(2.4, 0.0, 9.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(2.4, 1.0, 9.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

   //player 4
  glColor3ub(255,0,0);
  glPushMatrix();
     glTranslatef(4.3, 0.0, 4.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(4.3, 1.0, 4.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

   //player 5
   glColor3ub(255,0,0);
   glPushMatrix();
     glTranslatef(-4.3, 0.0, 4.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(-4.3, 1.0, 4.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

  //player 6
   glColor3ub(255,0,0);
   glPushMatrix();
     glTranslatef(0.0, 0.0, 3.5);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
   glPopMatrix();

    //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(0.0, 1.0, 3.5);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

  //Manager
   glColor3ub(255,0,0);
   glPushMatrix();
     glTranslatef(8.0, 0.0, 4.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
   glPopMatrix();

    //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(8.0, 1.0, 4.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end


  //Away team
  //player 1
   glColor3ub(255,255,255);
   glPushMatrix();
      glTranslatef(0.0, 0.0, -13);
      glScalef(0.7,1.0,0.5);
      glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(0.0, 1.0, -13);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

  //player 2
  glColor3ub(255,255,255);
  glPushMatrix();
     glTranslatef(-1.6, 0.0, -9.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(-1.6, 1.0, -9.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

  //player 3
  glColor3ub(255,255,255);
  glPushMatrix();
     glTranslatef(2.4, 0.0, -9.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(2.4, 1.0, -9.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end


   //player 4
  glColor3ub(255,255,255);
  glPushMatrix();
     glTranslatef(4.3, 0.0, -4.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
  glPopMatrix();

   //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(4.3, 1.0, -4.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

   //player 5
   glColor3ub(255,255,255);
   glPushMatrix();
     glTranslatef(-4.3, 0.0, -4.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
   glPopMatrix();

    //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(-4.3, 1.0, -4.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

  //player 6
   glColor3ub(255,255,255);
   glPushMatrix();
     glTranslatef(0.0, 0.0, -1);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
   glPopMatrix();

    //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(0.0, 1.0, -1);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end

   //Manager
   glColor3ub(255,255,255);
   glPushMatrix();
     glTranslatef(8.0, 0.0, -4.0);
     glScalef(0.7,1.0,0.5);
     glutSolidCube(1.0);
   glPopMatrix();

    //header
   glPushMatrix();
     glColor3ub(255, 205, 153);
     glTranslatef(8.0, 1.0, -4.0);
     glutSolidSphere(0.40,100,100);
   glPopMatrix();
  //end
}

void circle()
{
    int i;
	float theta;
    ////Adding a big circle at middle
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
       for(int i=0;i < 360;i++)
       {
           theta=i*(3.1416/180);
           glVertex3f(0.3,2.6*sin(theta),2.6*cos(theta));
       }
    glEnd();
    //Adding central mark
    glPointSize(5);
    glBegin(GL_POINTS);
      glVertex3f(0,0,0);
    glEnd();
    //end

}


void ball()
{
    //Adding ball
    glPushMatrix();
      glColor3ub(255,255,255);
      glTranslatef(xmove[0], ymove[0], zmove[0]);
      glutSolidSphere(0.40, 100, 100);
    glPopMatrix();

     //Updating game score
     //Home Team
     if ( (xmove[0] <= 1.5 && xmove[0] >= -1.5) && zmove[0] > 15)
     {
            xmove[0] = 0;
            ymove[0] = 0;
            zmove[0] = 0;
            awayTeam+=1;
     }
     //Away Team
      else if ( (xmove[0] <= 1.5 && xmove[0] >= -1.5) && zmove[0] < -15)
     {
            xmove[0] = 0;
            ymove[0] = 0;
            zmove[0] = 0;
            homeTeam+=1;
     }

}


void pitch()
{
   gluLookAt(5,12, 0, 1, 0, 0, 0, 1, 0);
   glEnable(GL_POLYGON_OFFSET_FILL);
   glPolygonOffset(1.0,1.0);

   //Adding pitch of soccer
   glLineWidth(2.4);
   glColor3ub(0,129,0);
   glBegin(GL_QUADS);
      glVertex3f(-7,0,15);
      glVertex3f(7,0,15);
      glVertex3f(7,0,-15);
      glVertex3f(-7,0,-15);
   glEnd();

  //Hollow square
  glBegin(GL_LINE_LOOP);
      glColor3ub(255,255,255);
      glVertex3f(-7,0,15);
      glVertex3f(7,0,15);
      glVertex3f(7,0,-15);
      glVertex3f(-7,0,-15);
   glEnd();
   //end

   //Line at middle
   glColor3ub(255,255,255);
   glBegin(GL_LINES);
     glVertex3f(-7,0,0);
     glVertex3f(7,0,0);
     glVertex3f(0,0,-15);
   glEnd();

    //left corner| left size
     glBegin(GL_LINES);
      glVertex3f(-7,0,14);
      glVertex3f(-6,0,15);
     glEnd();

     //right corner| left size
     glBegin(GL_LINES);
      glVertex3f(7,0,14);
      glVertex3f(6,0,15);
     glEnd();

     //left corner| right size
      glBegin(GL_LINES);
        glVertex3f(7,0,-14);
        glVertex3f(6,0,-15);
      glEnd();

      //right corner| right size
      glBegin(GL_LINES);
        glVertex3f(-7,0,-14);
        glVertex3f(-6,0,-15);
      glEnd();

   //Lines within the area
   //larger square
   glBegin(GL_LINE_LOOP);
     glVertex3f(-2.3,0,12.5);
     glVertex3f(2.3,0,12.5);
     glVertex3f(2.3,0,15);
     glVertex3f(-3.5,0,15);
     glVertex3f(-3.5,0,10.5);
     glVertex3f(3.5,0,10.5);
     glVertex3f(3.5,0,15);
     glVertex3f(-2.3,0,15);
   glEnd();

    //smaller square
    glBegin(GL_LINE_LOOP);
     glVertex3f(-2.3,0,-12.5);
     glVertex3f(2.3,0,-12.5);
     glVertex3f(2.3,0,-15);
     glVertex3f(-3.5,0,-15);
     glVertex3f(-3.5,0,-10.5);
     glVertex3f(3.5,0,-10.5);
     glVertex3f(3.5,0,-15);
     glVertex3f(-2.3,0,-15);
   glEnd();


   //Add penalty mark
   glPointSize(3);
   glBegin(GL_POINTS);
    glVertex3f(0,0,11.5);
    glVertex3f(0,0,-11.5);
   glEnd();
   //end

 // stands
   glColor3ub(176,196,222);
  glPushMatrix();
      glTranslatef(0.0, 0.0, 25.0);
      glScalef(7.0, 2.0, 0.0);
      glutSolidCube(2.0);
  glPopMatrix();

  glPushMatrix();
      glTranslatef(0.0, 0.0, -25.0);
      glScalef(7.0, 2.0, 0.0);
      glutSolidCube(2.0);
  glPopMatrix();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
     pitch();
     ball();
     circle();
     goalpost();
     gameScore(txt);
     players();
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


void keyboard(int button, int x, int y)
{
    switch (button)
    {
        case GLUT_KEY_UP: xmove[0] -= 0.3; break;
        case GLUT_KEY_LEFT: zmove[0] += 0.3; break;
        case GLUT_KEY_RIGHT: zmove[0] -= 0.3; break;
        case GLUT_KEY_DOWN: xmove[0] += 0.3; break;
    }
    glutPostRedisplay();
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
  glutSpecialFunc(keyboard);
  glutMainLoop();
  return(0);
}
