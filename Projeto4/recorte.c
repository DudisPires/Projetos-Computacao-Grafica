#include <GL/glut.h>
#include <stdlib.h>    
#include <time.h>      
#include <stdbool.h>   

int larguraJanela = 800, alturaJanela = 600;
float larguraRetangulo = 400.0f, alturaRetangulo = 300.0f;

const int DENTRO = 0;    //0000
const int ESQUERDA = 1;  // 0001
const int DIREITA = 2;    // 0010
const int ABAIXO = 4;     //0100
const int ACIMA = 8;     // 1000

float x_min, x_max, y_min, y_max;

int calcularCodigoRegiao(double x, double y) {
    int codigo = DENTRO;

    if (x < x_min)
        codigo |= ESQUERDA;
    else if (x > x_max)
        codigo |= DIREITA;

    if (y < y_min)
        codigo |= ABAIXO;
    else if (y > y_max)
        codigo |= ACIMA;

    return codigo;
}

void exibir() {
    glClear(GL_COLOR_BUFFER_BIT);

    float centroX = larguraJanela / 2.0f;
    float centroY = alturaJanela / 2.0f;
    x_min = centroX - larguraRetangulo / 2.0f;
    x_max = centroX + larguraRetangulo / 2.0f;
    y_min = centroY - alturaRetangulo / 2.0f;
    y_max = centroY + alturaRetangulo / 2.0f;

    glLineWidth(3.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x_min, y_min);
        glVertex2f(x_max, y_min);
        glVertex2f(x_max, y_max);
        glVertex2f(x_min, y_max);
    glEnd();

    glLineWidth(1.0f);

    //************************************************
    //* Desenho das linhas recortadas a partir daqui *
    //************************************************

    for (int i = 0; i < 10; i++) {
        double x1 = rand() % larguraJanela;
        double y1 = rand() % alturaJanela;
        double x2 = rand() % larguraJanela;
        double y2 = rand() % alturaJanela;

        double x1_orig = x1, y1_orig = y1;
        double x2_orig = x2, y2_orig = y2;
        
        int codigo1 = calcularCodigoRegiao(x1, y1);
        int codigo2 = calcularCodigoRegiao(x2, y2);
        
        bool aceito = false;

        while (true) {
            if (codigo1 == 0 && codigo2 == 0) {
                aceito = true;
                break;
            } 
            else if (codigo1 & codigo2) {
                break;
            }
            else {
                double x, y;
                int codigoFora = codigo1 ? codigo1 : codigo2;
                
                if (codigoFora & ACIMA) {
                    x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                    y = y_max;
                } else if (codigoFora & ABAIXO) {
                    x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                    y = y_min;
                } else if (codigoFora & DIREITA) {
                    y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                    x = x_max;
                } else { 
                    y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                    x = x_min;
                }

                if (codigoFora == codigo1) {
                    x1 = x;
                    y1 = y;
                    codigo1 = calcularCodigoRegiao(x1, y1);
                } else {
                    x2 = x;
                    y2 = y;
                    codigo2 = calcularCodigoRegiao(x2, y2);
                }
            }
        }
        
        if (aceito) {
            glColor3f(0.0f, 0.0f, 1.0f); 
            glBegin(GL_LINES);
                glVertex2d(x1, y1);
                glVertex2d(x2, y2);
            glEnd();

            glColor3f(1.0f, 0.0f, 0.0f); 
            glBegin(GL_LINES);
                glVertex2d(x1_orig, y1_orig);
                glVertex2d(x1, y1);
                glVertex2d(x2_orig, y2_orig);
                glVertex2d(x2, y2);
            glEnd();
        } else { 
             glColor3f(1.0f, 0.0f, 0.0f); 
             glBegin(GL_LINES);
                glVertex2d(x1_orig, y1_orig);
                glVertex2d(x2_orig, y2_orig);
            glEnd();
        }
    }

    glutSwapBuffers();
}

void redimensionar(int largura, int altura) {
    glViewport(0, 0, largura, altura);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclado(unsigned char tecla, int x, int y) {
    if (tecla == 27) { 
        exit(0);
    } else { 
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(larguraJanela, alturaJanela);
    glutCreateWindow("Retângulo base de recorte - Cohen-Sutherland");
    glutInitWindowPosition(100, 100);
    
    srand(time(NULL));

    glutDisplayFunc(exibir);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(teclado);
    glClearColor(0.75f, 0.75f, 0.75f, 1.0f);
    glutMainLoop();
    return 0;
}