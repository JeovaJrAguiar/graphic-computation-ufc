// Desenvolvido por Aguiar
// Universidade Federal do Ceará
// Ciência da Computação - campus Crateús

// Definindo libs
#include <stdio.h>
#include <gl/glut.h>

// Angulos dos discos(braço, antebraço e punho)
float ang0=135, ang1=215 , ang2=115 ,vy=-1, ty=1;

GLUquadricObj *planet;

void Desenha(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,0.0,1.0);
     
     // A definição de hierarquia vai ocorrer baseado em que 
	 // o elemento instanciado dentro e outro será considerado 
	 // filho do mesmo e assim ocorre para os elemento criados aqui
	 // Braço, antebraço e pulso.
     glPushMatrix();
         glRotatef(ang0, 0.0, 0.0, 1.0);
         glColor3f(1.0,0.0,0.0);
         gluDisk(planet, 0, 1.4, 8, 1);
         glBegin(GL_QUADS);
            glVertex2f(0,-0.5);
            glVertex2f(0,0.5);
            glVertex2f(10,0.5);
            glVertex2f(10,-0.5);
         glEnd();
         glPushMatrix();
             glTranslatef(10.0, 0.0, 0.0);
             glRotatef(ang1, 0.0, 0.0, 1.0);
             glColor3f(1.0,1.0,0.0);
             gluDisk(planet, 0, 0.8, 6, 1);
             glBegin(GL_QUADS);
                glVertex2f(0,-0.3);
                glVertex2f(0,0.3);
                glVertex2f(6,0.3);
                glVertex2f(6,-0.3);
             glEnd();
             glPushMatrix();
                 glTranslatef(6.0, 0.0, 0.0);
                 glRotatef(ang2, 0.0, 0.0, 1.0);
                 glColor3f(0.0,0.0,1.0);
                 glBegin(GL_QUADS);
                    glVertex2f(0,-0.3);
                    glVertex2f(0,0.3);
                    glVertex2f(5,0.3);
                    glVertex2f(5,-0.3);
                 glEnd();
                 gluDisk(planet, 0, 0.8, 10, 1);
                 glPushMatrix();
                     glTranslatef(4.0, 0.0, 0.0);
                     glColor3f(0.0,0.0,1.0);
                     glBegin(GL_QUADS);
                         glVertex2f(1,-1);
                         glVertex2f(1,1);
                         glVertex2f(1.5,1);
                         glVertex2f(1.5,-1);
                      glEnd();
                      glBegin(GL_QUADS);
                         glVertex2f(1.5,ty-0.5);
                         glVertex2f(1.5,ty);
                         glVertex2f(3,ty);
                         glVertex2f(3,ty-0.5);
                      glEnd();
                      glBegin(GL_QUADS);
                         glVertex2f(1.5,vy);
                         glVertex2f(1.5,vy+0.5);
                         glVertex2f(3,vy+0.5);
                         glVertex2f(3,vy);
                      glEnd();

                 glPopMatrix();
             glPopMatrix();
         glPopMatrix();
     glPopMatrix();
     glFlush();
}

void TeclasEspeciais(int key, int x, int y)
{
    switch (key)
    {
      case GLUT_KEY_DOWN:
          if (vy>=-0.9 & vy<=-0.4) vy=vy-0.1;
          if (ty>=0.4 & ty<=0.9)ty=ty+0.1;
      break;

      case GLUT_KEY_UP:
          if (vy>=-1.1 & vy<=-0.5) vy=vy+0.1;
          if (ty>=0.5 & ty<=1.1)ty=ty-0.1;
      break;

      case GLUT_KEY_HOME:
          ang0=ang0+5.0;
      break;
      case GLUT_KEY_END:
          ang0=ang0-5.0;
      break;

      case GLUT_KEY_PAGE_UP:
          ang1=ang1+7.0;
      break;
      case GLUT_KEY_PAGE_DOWN:
          ang1=ang1-7.0;
      break;
      case GLUT_KEY_LEFT:
          ang2=ang2+9.0;
      break;
      case GLUT_KEY_RIGHT:
          ang2=ang2-9.0;
      break;

    }
    glutPostRedisplay();
}

void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-13.0,13.0,-13.0,13.0);
}

int main(int argc, char **argv)
{
	printf("\n==== Computacao Grafica 2022.2 ====");
	printf("\nUniversidade Federal do Ceará");
	printf("\nCiencia da Computacao - campus Crateus");
	printf("\nDiscente: Aguiar - 495586");
	printf("\nDoscente: Arnaldo Barreto");
	printf("\nTrabalho: Braco Robotico");
	printf("\n==== Computacao Grafica ====");
	
	  glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutCreateWindow("Braço robótico");
      planet=gluNewQuadric();
      glutDisplayFunc(Desenha);
      glutSpecialFunc(TeclasEspeciais);
      Inicializa();
      glutMainLoop();
      return 0;
}


