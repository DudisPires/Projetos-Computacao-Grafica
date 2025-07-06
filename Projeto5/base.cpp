#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

int win_id;

std::vector<float> vertices;
std::vector<float> normals;
std::vector<std::vector<int>> faces_v;
std::vector<std::vector<int>> faces_n;
float scaleFactor = 1.0f;
float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;

void loadOBJ(const char* filename) {
    std::ifstream file(filename);
    std::string line;
    float minX=1e6, minY=1e6, minZ=1e6, maxX=-1e6, maxY=-1e6, maxZ=-1e6;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            minX = std::min(minX, x); maxX = std::max(maxX, x);
            minY = std::min(minY, y); maxY = std::max(maxY, y);
            minZ = std::min(minZ, z); maxZ = std::max(maxZ, z);
        } else if (prefix == "vn") {
            float x, y, z;
            iss >> x >> y >> z;
            normals.push_back(x);
            normals.push_back(y);
            normals.push_back(z);
        } else if (prefix == "f") {
            std::vector<int> v_indices, n_indices;
            std::string token;
            while (iss >> token) {
                int v_idx = 0, n_idx = 0;
                size_t firstSlash = token.find('/');
                size_t lastSlash = token.rfind('/');
                if (firstSlash != std::string::npos && lastSlash != std::string::npos && lastSlash > firstSlash) {
                    v_idx = std::stoi(token.substr(0, firstSlash)) - 1;
                    n_idx = std::stoi(token.substr(lastSlash + 1)) - 1;
                }
                v_indices.push_back(v_idx);
                n_indices.push_back(n_idx);
            }
            faces_v.push_back(v_indices);
            faces_n.push_back(n_indices);
        }
    }

    centerX = (minX + maxX) / 2.0f;
    centerY = (minY + maxY) / 2.0f;
    centerZ = (minZ + maxZ) / 2.0f;

    float maxDim = std::max({maxX - minX, maxY - minY, maxZ - minZ});
    if (maxDim != 0.0f) scaleFactor = 40.0f / maxDim;

    std::cout << "Modelo carregado: vértices = " << vertices.size() / 3
              << ", normais = " << normals.size() / 3
              << ", faces = " << faces_v.size() << std::endl;
}

void drawModel() {
    for (size_t i = 0; i < faces_v.size(); i++) {
        const std::vector<int>& v_idx = faces_v[i];
        const std::vector<int>& n_idx = faces_n[i];

        glBegin(v_idx.size() == 3 ? GL_TRIANGLES : GL_POLYGON);
        for (size_t j = 0; j < v_idx.size(); j++) {
            int ni = n_idx[j] * 3;
            int vi = v_idx[j] * 3;

            if (ni >= 0 && ni + 2 < normals.size())
                glNormal3f(normals[ni], normals[ni + 1], normals[ni + 2]);

            glVertex3f(
                (vertices[vi] - centerX) * scaleFactor,
                (vertices[vi + 1] - centerY) * scaleFactor,
                (vertices[vi + 2] - centerZ) * scaleFactor
            );
        }
        glEnd();
    }
}

void myKeyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 'R': 
    case 'r':
      glColor3f(1.0f, 0.0f, 0.0f);
      break;
    case 'G':
    case 'g':
      glColor3f(0.0f, 1.0f, 0.0f);
      break;
    case 'B':
    case 'b':
      glColor3f(0.0f, 0.0f, 1.0f);
      break;
  }
  glutPostRedisplay();
}

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


void myMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      float r = (float)rand() / (float)RAND_MAX;
      float g = (float)rand() / (float)RAND_MAX;
      float b = (float)rand() / (float)RAND_MAX;
      glColor3f(r, g, b);
      printf("Cor aleatória: %.2f, %.2f, %.2f na posição %d, %d\n", r, g, b, x, y);
  }
  glutPostRedisplay();
}

void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_NORMALIZE);

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

  drawModel(); 

  glFlush();
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho(-50, 50, -50*(GLfloat)h/(GLfloat)w, 50*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
  else
    glOrtho(-50*(GLfloat)w/(GLfloat)h, 50*(GLfloat)w/(GLfloat)h, -50, 50, -100.0, 100.0);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  glutInitWindowSize(500, 500); 
  glutInitWindowPosition(100, 100);
  win_id = glutCreateWindow(argv[0]);

  init();
  loadOBJ("cubo.obj"); 

  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(myKeyboard);
  glutSpecialFunc(myKeyboardSpecial);
  glutMouseFunc(myMouse);

  glutMainLoop();
  return 0;
}
