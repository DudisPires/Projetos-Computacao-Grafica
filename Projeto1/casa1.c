#include <GL/glut.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// Função de desenho (chamada automaticamente)
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa a tela e o buffer de profundidade
    glLoadIdentity();                                   // Reseta a matriz de modelagem

    gluLookAt(0, 0, 5,   // Posição da câmera
              0, 0, 0,   // Para onde a câmera olha
              0, 1, 0);  // Vetor "cima"

            glBegin(GL_LINES);
              
              glColor3ub(255,255,255);

              glVertex3f(-2.55, -0.3 , 0.0); //linha janela entrada (vertical)
              glVertex3f(-2.55, -0.8 , 0.0);
              
              glVertex3f(-2.3, -0.55 , 0.0); //linha janela entrada (horizontal)
              glVertex3f(-2.8, -0.55 , 0.0);
              
              glVertex3f(-0.2, -0.55 , 0.0); //linha janela entrada direita (horizontal)
              glVertex3f(-0.7, -0.55 , 0.0);
              
              glVertex3f(-0.45, -0.3 , 0.0); //linha janela entrada direita (vertical)
              glVertex3f(-0.45, -0.8 , 0.0);

              glColor3f(1,0,0);

              glVertex3f(-1.4, 1.9 , 0.1);
              glVertex3f(3.0, 1.9 , 0.1);
              
              glVertex3f(-1.3, 1.8 , 0.1);
              glVertex3f(3.08, 1.8 , 0.1);
          
              glVertex3f(-1.25, 1.7 , 0.1);
              glVertex3f(3.15, 1.7 , 0.1);
          
              glVertex3f(-1.17, 1.6 , 0.1);
              glVertex3f(3.25, 1.6 , 0.1);
          
              glVertex3f(-1.1, 1.5 , 0.1);
              glVertex3f(3.3, 1.5 , 0.1);
          
              glVertex3f(-1.2, 1.4, 0.0);
              glVertex3f(3.48, 1.4, 0.0);
          
              glVertex3f(-1.1, 1.3, 0.0); 
              glVertex3f(3.55, 1.3, 0.0);
          
              glVertex3f(-1.0, 1.2, 0.0); 
              glVertex3f(3.59, 1.2, 0.0);
          
              glVertex3f(-0.9, 1.1, 0.0); 
              glVertex3f(3.65, 1.1, 0.0);
          
              glVertex3f(-0.8, 1.0, 0.0); 
              glVertex3f(3.75, 1.0, 0.0);
          
              glVertex3f(-0.8, 0.9, 0.0); 
              glVertex3f(3.8, 0.9, 0.0);
          
              glVertex3f(-0.75, 0.8, 0.0); 
              glVertex3f(3.89, 0.8, 0.0);
          
              glVertex3f(-0.7, 0.7, 0.0); 
              glVertex3f(3.98, 0.7, 0.0);
          
              glVertex3f(-0.68, 0.6, 0.0); 
              glVertex3f(4.0, 0.6, 0.0);
          
              glVertex3f(-0.62, 0.5, 0.0); 
              glVertex3f(4.1, 0.5, 0.0);
          
              glVertex3f(-0.58, 0.4, 0.0); 
              glVertex3f(4.22, 0.4, 0.0);
              
              glVertex3f(-0.54, 0.3, 0.0); 
              glVertex3f(4.29, 0.3, 0.0);

              glVertex3f(-0.5, 0.2, 0.0); 
              glVertex3f(4.37, 0.2, 0.0);

              glVertex3f(-0.46, 0.1, 0.0); 
              glVertex3f(4.4, 0.1, 0.0);

              
              
              glEnd();


    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); 
        glVertex3f(-1.5f, 2.0f, 0.0f);  
        glVertex3f( 0.0f, 0.0f, 0.0f);   // tri telhado frente
        glVertex3f( -3.0f,  0.0f, 0.0f);  
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.95f, 0.95f, 0.95f);
        glVertex3f(3.0f, 2.0f, 0.0f);  
        glVertex3f( 4.5f, 0.0f, 0.0f);   // Tri direito telhado
        glVertex3f( 3.0f,  0.0f, 0.0f);  
    glEnd();

    glBegin(GL_QUADS);
         glColor3f(0.95f, 0.95f, 0.95f);
         glVertex3f(0.0f, 2.0f, 0.0f);  
         glVertex3f( 3.0f, 2.0f, 0.0f);  // Quadrado telhado
         glVertex3f( 3.0f,  0.0f, 0.0f);  
         glVertex3f( 0.0f,  0.0f, 0.0f);
         
         
    glEnd();

    glBegin(GL_QUADS);

       glColor3f(0.196f, 0.804f, 0.196f);
       glVertex3f( 0.0f,  -1.0f, -0.5f);
       glVertex3f( -10.8f,  -1.0f, -0.5f);
       glVertex3f( -10.8f,  -10.0f, -0.5f);  // fundo
       glVertex3f( 0.0f,  -10.0f, -0.5f);


        glColor3f(0.196f, 0.804f, 0.196f);
        glVertex3f( 0.0f,  -1.0f, -0.5f);
        glVertex3f( -10.8f,  -1.0f, -0.5f);
        glVertex3f( -10.8f,  -10.0f, -0.5f);  // fundo
        glVertex3f( 0.0f,  -10.0f, -0.5f);

        glColor3f(0.196f, 0.804f, 0.196f);
        glVertex3f( 0.0f,  -1.0f, -0.5f);
        glVertex3f( 10.8f,  -1.0f, -0.5f);  // fundo
        glVertex3f( 10.8f,  -10.0f, -0.5f);
        glVertex3f( 0.0f,  -10.0f, -0.5f);

         glColor3ub(230, 230, 230);
         glVertex3f( 0.6f,  -0.4f, 0.0f);
         glVertex3f( 0.6f,  -1.58f, 0.0f);   
         glVertex3f( 1.4f,  -1.58f, 0.0f);  // janela esquerda lateral detalhe 
         glVertex3f( 1.4f,  -0.4f, 0.0f);
         
         glColor3ub(230, 230, 230);
         glVertex3f( 3.9f,  -0.4f, 0.0f);
         glVertex3f( 3.9f,  -1.58f, 0.0f);   
         glVertex3f( 3.1f,  -1.58f, 0.0f);  // janela direita lateral detalhe
         glVertex3f( 3.1f,  -0.4f, 0.0f);

         glColor3ub(255, 255, 255);
         glVertex3f( 0.5f,  -0.3f, 0.0f);
         glVertex3f( 0.5f,  -1.68f, 0.0f);   
         glVertex3f( 1.5f,  -1.68f, 0.0f);  // janela esquerda lateral 
         glVertex3f( 1.5f,  -0.3f, 0.0f);
          
         glColor3ub(255, 255, 255);
         glVertex3f( 4.0f,  -0.3f, 0.0f);
         glVertex3f( 4.0f,  -1.68f, 0.0f);   
         glVertex3f( 3.0f,  -1.68f, 0.0f);  // janela direita lateral 
         glVertex3f( 3.0f,  -0.3f, 0.0f);

         glColor3ub(230, 0, 0);
         glVertex3f( 0.0f,  0.0f, 0.0f);
         glVertex3f( 4.5f,  0.0f, 0.0f);    // Lateral casa 
         glVertex3f( 4.5f,  -2.0f, 0.0f);
         glVertex3f( 0.0f,  -2.0f, 0.0f);

         glColor3ub(255, 0, 0);
         glVertex3f( -2.8f,  -0.3f, 0.0f);   // Janela esquerda da entrada 
         glVertex3f( -2.3f,  -0.3f, 0.0f);
         glVertex3f( -2.3f,  -0.8f, 0.0f);
         glVertex3f( -2.8f,  -0.8f, 0.0f);

         glColor3ub(255, 0, 0);
         glVertex3f( -0.2f,  -0.3f, 0.0f);
         glVertex3f( -0.7f,  -0.3f, 0.0f);  // Janela direita da entrada 
         glVertex3f( -0.7f,  -0.8f, 0.0f);
         glVertex3f( -0.2f,  -0.8f, 0.0f);

         glColor3f(1.0f, 1.0f, 1.0f);
         glVertex3f( -1.55f,  -1.8f, 0.5f);
         glVertex3f( -1.55f,  -1.0f, 0.5f);  // Porta detalhes 
         glVertex3f( -1.45f,  -1.0f, 0.5f);
         glVertex3f( -1.45f,  -1.8f, 0.5f);



         glColor3ub(255, 255, 255);
         glVertex3f( 0.0f,  0.0f, 0.0f);
         glVertex3f( -3.0f,  0.0f, 0.0f);
         glVertex3f( -3.0f,  -2.0f, 0.0f);
         glVertex3f( 0.0f,  -2.0f, 0.0f);

         glColor3f(1.0f, 0.0f, 0.0f);
         glVertex3f( -1.0f,  -1.8f, 0.5f);
         glVertex3f( -2.0f,  -1.8f, 0.5f);  // Porta
         glVertex3f( -2.0f,  -1.0f, 0.5f);
         glVertex3f( -1.0f,  -1.0f, 0.5f);

         glColor3f(0.545f, 0.271f, 0.075f);
         glVertex3f( -1.8f,  -1.8f, 0.5f);
         glVertex3f( -1.2f,  -1.8f, 0.5f);   // estrada 
         glVertex3f( -2.1f,  -2.9f, 0.5f);
         glVertex3f( -3.0f,  -2.9f, 0.5f);


    glEnd();

    glBegin(GL_TRIANGLES);
         glColor3f(0.94f, 0.94f, 0.94f);
         glVertex3f(-1.5f, 2.0f, 0.0f);  
         glVertex3f( 0.0f, 2.0f, 0.0f);  // Tri esquerdo telhado
         glVertex3f( 0.0f,  0.0f, 0.0f);  
    glEnd();


    float cx = -1.5f;  
    float cy = 0.7f;  
    float raio = 0.3f;  
    int numLados = 200;  

    glColor3f(1.0f, 1.0f, 1.0f); 

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(cx, cy, 0.5f); 
        for (int i = 0; i <= numLados; i++) {
            float angulo = 2.0f * M_PI * i / numLados;
            float x = cx + raio * cos(angulo);
            float y = cy + raio * sin(angulo);
            glVertex3f(x, y, 0.3f);
        }
    glEnd();
    
    cx= -3.5f;
    cy= 1.5f;
    raio= 0.2f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(cx, cy, 0.5f); 
       for (int j=0 ; j<=5 ; j++){ 
        for (int i = 0; i <= numLados; i++) {
            float angulo = 2.0f * M_PI * i / numLados;
            float x = cx + raio * cos(angulo);
            float y = cy + raio * sin(angulo);
            glVertex3f(x, y, 0.3f);
        }
        cx= cx -0.2;
        cy= cy + 0.01;
       } 
    glEnd();

     cx= 4.0f;
     cy= 1.5f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(cx, cy, 0.5f); 
       for (int j=0 ; j<=4 ; j++){ 
        for (int i = 0; i <= numLados; i++) {
            float angulo = 2.0f * M_PI * i / numLados;
            float x = cx + raio * cos(angulo);
            float y = cy + raio * sin(angulo);  
            glVertex3f(x, y, 0.3f);
        }
        cx= cx + 0.2;
        cy= cy + 0.01;
        raio= raio - 0.001;
       } 
    glEnd();

    cx= -2.0f;
    cy= 2.3f;
    raio= 0.15f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx, cy, 0.1f); 
   for (int j=0 ; j<=3 ; j++){ 
    for (int i = 0; i <= numLados; i++) {
        float angulo = 2.0f * M_PI * i / numLados;
        float x = cx + raio * cos(angulo);                 // nuvens 
        float y = cy + raio * sin(angulo);  
        glVertex3f(x, y, 0.3f);
    }
    cx= cx + 0.2;
    cy= cy + 0.01;
   } 
   glEnd();
   
   glColor3ub(254, 128, 0); 
   cx= 5.0f;
   cy= 2.5f;
   raio=0.6f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx, cy, 0.1f);  
    for (int i = 0; i <= numLados; i++) {
        float angulo = 2.0f * M_PI * i / numLados;
        float x = cx + raio * cos(angulo);                //sol 
        float y = cy + raio * sin(angulo);  
        glVertex3f(x, y, 0.1f);
    }
    glEnd();


    glutSwapBuffers(); 
}


void init() {
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);         
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);                 
    glMatrixMode(GL_PROJECTION);           
    glLoadIdentity();                      
    gluPerspective(60.0, (float)w/h, 1.0, 100.0); 
    glMatrixMode(GL_MODELVIEW);            
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);                                
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 600);                          
    glutCreateWindow("Casinha");                     

    init();                        
    glutDisplayFunc(display);     
    glutReshapeFunc(reshape);    
    glutMainLoop();               
    return 0;
}