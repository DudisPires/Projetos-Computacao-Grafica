#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int win_id;

// ângulos dos membros
float anguloBracoEsq = 0.0f;
float anguloBracoDir = 0.0f;
float anguloPernaEsq = 0.0f;
float anguloPernaDir = 0.0f;

//Aqui se capturam as teclas comuns (letras, números e ESC, por exemplo)
void myKeyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 'r': anguloBracoDir += 5.0f; break;
    case 'R': anguloBracoDir -= 5.0f; break;
    case 'l': anguloBracoEsq += 5.0f; break;
    case 'L': anguloBracoEsq -= 5.0f; break;
    case 'p': anguloPernaDir += 5.0f; break;
    case 'P': anguloPernaDir -= 5.0f; break;
    case 'o': anguloPernaEsq += 5.0f; break;
    case 'O': anguloPernaEsq -= 5.0f; break;
  }
  glutPostRedisplay();
}

//Aqui se capturam as teclas especiais (Alt, Control, Shift, F1, F2, etc.)
void myKeyboardSpecial(int key, int x, int y ) {
  switch ( key ) {
    case GLUT_KEY_UP:
      glutFullScreen();
      break;
    case GLUT_KEY_DOWN:
      glutReshapeWindow(640, 480);
      break;
    default:
      printf("Você apertou a tecla especial código: %d\n", key);
      break;
  }
}

// Função callback chamada para gerenciar eventos do mouse
void myMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {
      float r, g, b;
      r = (double)rand() / (double)RAND_MAX;
      g = (double)rand() / (double)RAND_MAX;
      b = (double)rand() / (double)RAND_MAX;
      glColor3f(r,g,b);
      printf("%.2f, %.2f, %.2f, na posicao %d, %d\n", r, g, b, x, y);
    }
  glutPostRedisplay();
}

void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); // importante!

  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  glColor3f(0.5, 1.0, 0.5);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0f, 30.0f, 50.0f, 0.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);


  // chapeu 

  glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 33.0f, 0.5f);
    glScalef(1.5f, 0.8f, 4.0f);
    glutSolidSphere(3.0f, 10, 10);
  glPopMatrix();

  glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 30.0f, 0.5f);
    glScalef(3.5f, 0.7f, 4.0f);
    glutSolidSphere(4.3f, 10, 2);
  glPopMatrix();


  // Corpo principal
  glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 15.0f, 0.1f);
    glScalef(1.0f, 1.5f, 0.4f);
    glutSolidCube(20.0f);
  glPopMatrix();

  // nariz 
  glPushMatrix();
    glColor3ub(0, 0, 0); // tom amarelado
    glTranslatef(0.0f, 20.5f, 10.0f); // posição no rosto
    glBegin(GL_TRIANGLES);
      glVertex3f(0.5f, 0.0f, 10.0f);   // ponta do nariz (mais à frente)
      glVertex3f(-0.9f, -1.0f, 0.0f); // base inferior esquerda
      glVertex3f(1.7f, -1.0f, 0.0f);  // base inferior direita
    glEnd();
  glPopMatrix();

  // Calça
  glPushMatrix();
    glColor3f(0.4f, 0.2f, 0.0f);
    glTranslatef(0.0f, 5.0f, 0.0f);
    glScalef(1.0f, 1.6f, 0.4f);
    glutSolidCube(20.0f);
  glPopMatrix();

  // Roupa branca
  glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 1.6f, 0.0f);
    glScalef(1.0f, 0.26f, 0.5f);
    glutSolidCube(20.0f);
  glPopMatrix();

  // Gravata
  glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 2.8f, 0.0f);
    glScalef(0.08f, 0.16f, 0.6f);
    glutSolidCube(20.0f);
  glPopMatrix();

  // Detalhes da calça
  float cx = -9.4f;
  for(int i = 0 ; i < 8 ; i++){
    glPushMatrix();
      glColor3f(0.0f, 0.0f, 0.0f); 
      glTranslatef(cx , -2.4f , 0.0f);
      glScalef(0.12f, 0.01f, 0.6f);
      glutSolidCube(20.0f);
    glPopMatrix();
    cx = cx + 3.1;
  }

  // Boca
  glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); 
    glTranslatef(0.0f, 10.6f, 0.0f);
    glScalef(0.3f, 0.15f, 0.5f);
    glutSolidCube(20.0f);
  glPopMatrix();

  // Dentes
  glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); 
    glTranslatef(-1.0f, 11.8f, 0.0f);
    glScalef(0.05f, 0.08f, 0.6f);
    glutSolidCube(20.0f);
  glPopMatrix();

  glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); 
    glTranslatef(1.0f, 11.8f, 0.0f);
    glScalef(0.05f, 0.08f, 0.6f);
    glutSolidCube(20.0f);
  glPopMatrix();

  // bochechas
  glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.5f);
    glTranslatef(-6.0f, 15.0f, 9.0f);
    glutSolidSphere(0.8f, 10, 10);
  glPopMatrix();

  glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.5f);
    glTranslatef(6.0f, 15.0f, 9.0f);
    glutSolidSphere(0.8f, 10, 10);
  glPopMatrix();

  // Olhos e pupilas
  glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-5.0f, 22.0f, 9.0f);
    glutSolidSphere(1.8f, 20, 20);
  glPopMatrix();

  // somb esq 
  glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); 
    glTranslatef(-5.0f, 26.0f, 9.0f);
    glScalef(0.2f, 0.02f, 0.1f);
    glutSolidCube(20.0f);
  glPopMatrix();

  glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(5.0f, 22.0f, 9.0f);
    glutSolidSphere(1.8f, 20, 20);
  glPopMatrix();

  glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(-5.0f, 22.0f, 11.0f);
    glutSolidSphere(0.7f, 20, 20);
  glPopMatrix();

   // somb Dir  
   glPushMatrix();
     glColor3f(0.0f, 0.0f, 0.0f); 
     glTranslatef(5.0f, 24.7f, 9.0f);
     glScalef(0.2f, 0.02f, 0.1f);
     glutSolidCube(20.0f);
   glPopMatrix();

  glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glTranslatef(5.0f, 22.0f, 11.0f);
    glutSolidSphere(0.7f, 20, 20);
  glPopMatrix();

  // Braço esquerdo
  glPushMatrix();
    glTranslatef(-11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -4.0f, 0.0f);
    glScalef(0.2f, 1.2f, 0.2f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  //mao esquerda 

  // dedao
  glPushMatrix();
    glTranslatef(-11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(-0.5f, -10.5f, -0.5f);
    glScalef(0.05f, 0.1f, 0.05f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  float x = -0.5f;
  for(int j = 0 ; j <= 2 ; j++){
    glPushMatrix();
      glTranslatef(-11.0f, 10.0f, 0.0f);
      glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
      glTranslatef(x , -10.5f, 0.3f);
      glScalef(0.03f, 0.1f, 0.05f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glutSolidCube(10.0f);
    glPopMatrix();
    x = x + 0.4;
  }

    //mao esquerda 

  // dedao
  glPushMatrix();
    glTranslatef(-11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(-0.5f, -10.5f, -0.5f);
    glScalef(0.05f, 0.1f, 0.05f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  float x1 = -0.5f;
  for(int j = 0 ; j <= 2 ; j++){
    glPushMatrix();
      glTranslatef(-11.0f, 10.0f, 0.0f);
      glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
      glTranslatef(x1 , -10.5f, 0.3f);
      glScalef(0.03f, 0.1f, 0.05f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glutSolidCube(10.0f);
    glPopMatrix();
    x1 = x1 + 0.4;
  }

  //mao dir 

  // dedao
  glPushMatrix();
    glTranslatef(11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoDir, 1.0f, 0.0f, 0.0f);
    glTranslatef(-0.5f, -10.5f, -0.5f);
    glScalef(0.05f, 0.1f, 0.05f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  float x2 = -0.5f;
  for(int k = 0 ; k <= 2 ; k++){
    glPushMatrix();
      glTranslatef(11.0f, 10.0f, 0.0f);
      glRotatef(anguloBracoDir, 1.0f, 0.0f, 0.0f);
      glTranslatef(x2 , -10.5f, 0.3f);
      glScalef(0.03f, 0.1f, 0.05f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glutSolidCube(10.0f);
    glPopMatrix();
    x2 = x2 + 0.4;
  }

  // detalhe ombro esq
  glPushMatrix();
    glTranslatef(-11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 2.0f, 0.0f);
    glScalef(0.3f, 0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidCube(10.0f);
  glPopMatrix();
  
  // detalhe preto ombro esq
  glPushMatrix();
    glTranslatef(-11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.3f, 0.1f, 0.3f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  // Braço direito
  glPushMatrix();
    glTranslatef(11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoDir, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -4.0f, 0.0f);
    glScalef(0.2f, 1.2f, 0.2f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

   // detalhe ombro dir
  glPushMatrix();
   glTranslatef(11.0f, 10.0f, 0.0f);
   glRotatef(anguloBracoDir, 1.0f, 0.0f, 0.0f);
   glTranslatef(0.0f, 2.0f, 0.0f);
   glScalef(0.3f, 0.3f, 0.3f);
   glColor3f(1.0f, 1.0f, 1.0f);
   glutSolidCube(10.0f);
 glPopMatrix();

  // detalhe preto ombro dir
  glPushMatrix();
    glTranslatef(11.0f, 10.0f, 0.0f);
    glRotatef(anguloBracoDir, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.3f, 0.1f, 0.3f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();


  // Perna esquerda
  glPushMatrix();
    glTranslatef(-5.0f, -5.0f, 0.0f);
    glRotatef(anguloPernaEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -5.0f, 0.0f);
    glScalef(0.25f, 1.0f, 0.25f);
    glColor3f(0.4f, 0.2f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  // pe esquerdo 

  glPushMatrix();
    glTranslatef(-5.0f, -5.0f, 0.0f);
    glRotatef(anguloPernaEsq, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -10.0f, 0.9f);
    glScalef(0.25f, 0.2f, 0.6f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  // Perna direita
  glPushMatrix();
    glTranslatef(5.0f, -5.0f, 0.0f);
    glRotatef(anguloPernaDir, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -5.0f, 0.0f);
    glScalef(0.25f, 1.0f, 0.25f);
    glColor3f(0.4f, 0.2f, 0.0f);
    glutSolidCube(10.0f);
  glPopMatrix();


  // pe dir 

  glPushMatrix();
    glTranslatef(5.0f, -5.0f, 0.0f);
    glRotatef(anguloPernaDir, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -10.0f, 0.9f);
    glScalef(0.25f, 0.2f, 0.6f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidCube(10.0f);
  glPopMatrix();

  glFlush();
}

void reshape (int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho (-50, 50, -50*(GLfloat)h/(GLfloat)w, 50*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
  else
    glOrtho (-50*(GLfloat)w/(GLfloat)h, 50*(GLfloat)w/(GLfloat)h, -50, 50, -100.0, 100.0);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  win_id = glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(myKeyboard);
  glutSpecialFunc(myKeyboardSpecial);
  glutMouseFunc(myMouse);
  glutMainLoop();
  return 0;
}
