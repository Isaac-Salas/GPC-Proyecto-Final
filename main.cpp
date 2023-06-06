/*

Nombre programa: Proyecto Final
Programadores: Carmen Judith Guzman Cortez, Isaac Salas Carmona, Paola lizbeth Cabrera Oros,
NUA: 147696,
Fecha: 09-Jun-2023

Objetivo: Mostrar figuras con colores y movimientos diferentes.

*/

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

typedef enum{NEGRO,
            AZUL,
            VERDE,
            CYAN,
            ROJO,
            MAGENTA,
            AMARILLO,
            BLANCO,
            GRIS,
            GRIS_OSCURO,
            GRIS_CLARO,
            NARANJA,
            VERDE_AZUL,
            BABY_BLUE,
            LILA,
            DARK_PURPLE,
            BRONZE,
            DARK_BLUE,
            FOREST_GREEN,
            BROWN,
            DARK_GREY
            }COLOR;

float PALETA_COLORES[21][3]={0, 0, 0, //NEGRO - listo
                             0, 0, 1, //AZUL - list
                             0, 1, 0, //VERDE - listo
                             0, 1, 1, //CYAN - list
                             1, 0, 0, //ROJO -listo
                             1, 0, 1, //MAGENTA
                             1, 1, 0, //AMARILLO - lis
                             1, 1, 1, //BLANCO - listo
                             0.5,0.5,0.5, //GRIS -listo
                             0.25,0.25,0.25, //GRIS_OSC listo
                             0.8,0.8,0.8,// - listo-GRIS_CLARO
                             1.0,0.5,0.0, //NARANJA -NUEVO
                             0.0, 0.5, 0.5, //VERDE_AZUL
                             0.0, 0.5, 1.0,//BABY_BLUE
                             0.784, 0.635, 0.884,//LILA
                             0.5, 0.0, 0.5,//DARK_PURPLE
                             0.5, 0.5, 0.0,//BRONZE
                             0.0, 0.1, 0.5,//DARK_BLUE
                             0.0, 0.5, 0.0,//FOREST_GREEN
                             0.5, 0.1, 0.1,//BROWN
                             0.1, 0.1, 0.1//DARK_GREY - COLOR DEL MENU FONDO
                             };



typedef struct  {   float x;
                    float y;
                }PUNTO;

typedef struct  {   PUNTO ini;
                    PUNTO fin;
                    COLOR color;
                }LINEA;

typedef struct  {   PUNTO piv;
                    float lado;
                    COLOR color;
                }CUADRADO;

typedef struct  {   PUNTO piv;
                    float ancho;
                    float alto;
                    COLOR color;
                }RECTANGULO;

typedef struct  {   PUNTO c;
                    float r;
                    int NumLados;
                    COLOR color;
                }POLIGONO;

typedef struct  {   PUNTO c;
                    float r;
                    COLOR color;
                }CIRCULO;

typedef struct  {   PUNTO c;
                    float eje_mayor;
                    float eje_menor;
                    COLOR color;
                }ELIPSE;

typedef struct  {   PUNTO piv;
                    PUNTO fin;
                    COLOR color;
                }TRIANGULOG;

                typedef struct  {   PUNTO piv;
                    float base;
                    float altura;
                    COLOR color;
                }TRIANGULO_ISO;





//PROTOTIPOS DE FUNCIONES
void DibujarTexto(char *Texto, float x, float y);
PUNTO CVent_a_Cplano(int x, int y,int AnchoV, int AltoV, float xini, float xfin, float yini, float yfin);

//FUNCIONES FIGURAS
void Linea(LINEA L);
void Cuadradold(CUADRADO c);
void Cuadrado(LINEA c);
void Rectangulo(RECTANGULO r);
void Poligono(POLIGONO p);
void Circulo(CIRCULO ci);
void Elipse(ELIPSE e);
void Triangulo(TRIANGULOG t);
void TrianguloLEG(TRIANGULO_ISO t);
void AsignaColor(COLOR c);
void display (void);


void Rectangulo(RECTANGULO r);
void Circulo(CIRCULO ci);
void Poligono(POLIGONO p);
void Elipse(ELIPSE e);

void Raton(int boton, int estado, int x, int y);
void RatonPasivo(int x, int y);
void RatonActivo(int x, int y);
PUNTO PosRaton_Posplano(int x, int y);
void TraslacionLinea(LINEA *L,float tx,float ty);
void RotacionLinea(LINEA *L,float xr, float yr, float Theta);
void EscalamientoLinea(LINEA *L,float xr, float yr, float sx,float sy);
void TeclasEspeciales(int tecla, int x, int y);
void TeclasNormales(unsigned char tecla, int x, int y);

//Funcion del Menu - GUI
void MenuGUI();
void MenuICONS();

//Variables globales
const float pi = 3.14159;
char coordenadas[40] = "(0,0)";
char Traslacion[40] = "Trasladar";
char Rotacion[40] = "Rotacion";
char escalationUP[40] = "Flecha";
char escalationUP2[40] = "Arriba";
char escalationUP3[40] = "Abajo";
char Escalar[40] = "Escalar";
char existeFigura[8] = {1, 1, 1, 1, 1, 1, 1, 1};
PUNTO falso;
TRIANGULOG t1;
LINEA c1; //CUADRADO
//
LINEA p1;
CIRCULO cir1;
ELIPSE e1;
LINEA l1, r1;

int seleccion= 0;
PUNTO PuntoInicial;
PUNTO PuntoReferencia;
PUNTO PuntoFinal;
CUADRADO cent;
float X_ini = 0;
float Y_ini = 0;
float Y_fin = 0;
float X_fin = 0;
float tbase = 1;
float taltura = 1;

//TESTING
COLOR selcolor;
COLOR selop;
COLOR s1=BLANCO, s2=BLANCO, s3=BLANCO, s4=BLANCO, s5=BLANCO, s6=BLANCO, s7=BLANCO, s8=BLANCO, s8B=NEGRO, s9=BLANCO,s9B=NEGRO, s10=BLANCO, s10B=NEGRO;
void Tachita(LINEA l);
int ContadorClick = 0;
PUNTO ptini, ptfin, ptescalado;
LINEA ptcolor;
int tachaex=0;
int modo = 0;
float DistanciaXY(float x1, float y1, float x2, float y2);
float DistanciaX(float x1, float x2);
float DistanciaY(float y1, float y2);
void drawPolygon(float x1, float y1, float x2, float y2);
PUNTO cuad1, cuad2;
int todo = 0;
char titulo[256];

int sides = 3;  // Number of sides in the polygon
float radius = 0;



float DistanciaXY(float x1, float y1, float x2, float y2)
{
    float distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    return distance;
}
float DistanciaX(float x1, float x2)
{
    float distance = std::abs(x2 - x1);
    return distance;
}
float DistanciaY(float y1, float y2)
{
    float distance = std::abs(y2 - y1);
    return distance;
}

void keyboard() {

    switch(todo)
    {
    case 0:
        if (GetAsyncKeyState(VK_SPACE)){
           todo = 1;
     }
        break;
    case 1:
          if (GetAsyncKeyState(VK_SPACE)){
           todo = 0;
     }
        break;
    }

    switch (seleccion)
    {
    case 5:
             if (GetAsyncKeyState(VK_UP)){
           sides+=1;

     }

     if (GetAsyncKeyState(VK_DOWN)){
            sides-=1;

     }

     if (GetAsyncKeyState(VK_RIGHT)){


     }

     if (GetAsyncKeyState(VK_LEFT)){


     }

        break;

        case 6:
             if (GetAsyncKeyState(VK_UP)){

     }

     if (GetAsyncKeyState(VK_DOWN)){

     }

     if (GetAsyncKeyState(VK_RIGHT)){

     }

     if (GetAsyncKeyState(VK_LEFT)){

     }

        break;

    }



}


void drawSquare(float x1, float y1, float x2, float y2)
{
    AsignaColor(c1.color);
    // Calculate the center of the square
    GLfloat centerX = (x1 + x2) / 2.0f;
    GLfloat centerY = (y1 + y2) / 2.0f;

    // Calculate the half side length
    GLfloat halfSide = fabs(x2 - x1) / 2.0f;

    // Calculate the vertices of the square
    GLfloat vertices[] = {
        centerX - halfSide, centerY - halfSide, // Vertex 1 (bottom-left)
        centerX + halfSide, centerY - halfSide, // Vertex 2 (bottom-right)
        centerX + halfSide, centerY + halfSide, // Vertex 3 (top-right)
        centerX - halfSide, centerY + halfSide  // Vertex 4 (top-left)
    };

    // Enable vertex arrays
    glEnableClientState(GL_VERTEX_ARRAY);

    // Specify the vertex data
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    // Draw the square
        switch (modo)
    {
    case 0:
        glDrawArrays(GL_LINE_LOOP, 0, 4);
        break;
    case 1:
        glDrawArrays(GL_QUADS, 0, 4);
        break;
    }



    // Disable vertex arrays
    glDisableClientState(GL_VERTEX_ARRAY);
}


void drawPolygon(float x1, float y1, float x2, float y2)
{
    AsignaColor(p1.color);
    // Calculate the center of the polygon
    GLfloat centerX = (x1 + x2) / 2.0f;
    GLfloat centerY = (y1 + y2) / 2.0f;

    // Calculate the angle between each side
    GLfloat angle = 2.0f * M_PI / sides;

    // Calculate the initial angle offset
    GLfloat initialAngle = atan2(y2 - y1, x2 - x1) + M_PI / 2.0f;

    // Begin drawing the polygon
           switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }



    // Calculate and specify the vertices of the polygon
    for (int i = 0; i < sides; i++)
    {
        GLfloat x = centerX + radius * cos(initialAngle + angle * i);
        GLfloat y = centerY + radius * sin(initialAngle + angle * i);
        glVertex2f(x, y);
    }

    // End drawing the polygon
    glEnd();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("PAINT WAJAKO");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0,10.0,-10.0, 10.0, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(&display);
//    glutMotionFunc(ratonActivo);
  //  glutSpecialFunc(teclasEspeciales);
  glutMouseFunc(Raton);
  glutPassiveMotionFunc(RatonPasivo);
  glutMotionFunc(RatonActivo);




    glutMainLoop();

    return 0;
}
void rectanwajako(float x1,float y1, float x2, float y2)
{
AsignaColor(r1.color);
    switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }
glVertex2f(x1, y1);
glVertex2f(x2, y1);
glVertex2f(x2, y2);
glVertex2f(x1, y2);
glEnd();

}

void display(void){
    glClearColor(1,1,1,1);
    glClearColor(0.96,0.96,0.86,1);
    keyboard();
    glClear(GL_COLOR_BUFFER_BIT);
    //Funcion que manda imprimir lass figuras
   // mostrarFiguras();
    //Muestra el MenuGUI
    switch(seleccion)
    {
        case 1:
        Linea(l1);
        break;
        case 2:
        Triangulo(t1);
        break;
        case 3:
        drawSquare(c1.ini.x,c1.ini.y,c1.fin.x,c1.fin.y);
        break;

        case 4:
        rectanwajako(r1.ini.x,r1.ini.y, r1.fin.x, r1.fin.y);
        break;
        case 5:
        drawPolygon(p1.ini.x, p1.ini.y, p1.fin.x,p1.fin.y);
        snprintf(titulo, sizeof(titulo), "PAINT WAJAKO ---> Lados = %i", sides);
        glutSetWindowTitle(titulo);
        break;
        case 6:
        Circulo(cir1);
        snprintf(titulo, sizeof(titulo), "PAINT WAJAKO ---> Radio = %g", cir1.r);
        glutSetWindowTitle(titulo);
        break;
        case 7:
        Elipse(e1);
        break;
        case 8:
           Linea(l1);
        break;
         case 9:
           Linea(l1);
        break;
         case 10:
           Linea(l1);
        break;
    }

    switch(todo)
    {
    case 0:
        break;
    case 1:
    Linea(l1);
     Triangulo(t1);
     drawSquare(c1.ini.x,c1.ini.y,c1.fin.x,c1.fin.y);
     rectanwajako(r1.ini.x,r1.ini.y, r1.fin.x, r1.fin.y);;
     drawPolygon(p1.ini.x, p1.ini.y, p1.fin.x,p1.fin.y);
     Circulo(cir1);
     Elipse(e1);
        break;

    }


    MenuGUI();
    //Menu del Iconos - Figuras

     MenuICONS();




    switch(tachaex)
    {
        case 0:
        break;

        case 1:
        Tachita(ptcolor);
        break;
    }


     /*
    l1.ini.x = 4;
    l1.ini.y = 7;
    l1.fin.x = -3;
    l1.fin.y = -2;
    l1.color = VERDE;
    Linea(l1);
    */


    glRenderMode(GL_SELECT);
    AsignaColor(AZUL);
    glFlush();
}

//DEFINICION DE FUNCIONES
void DibujarTexto(char *Texto, float x, float y)
{   int k=0;
    glRasterPos2f(x,y);
    while(Texto[k]!='\0')
    {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,Texto[k]);
        k++;
    }
}


void AsignaColor(COLOR c){
    glColor3f(PALETA_COLORES[c][0],
    PALETA_COLORES[c][1],
    PALETA_COLORES[c][2]);

}

//FUNCION DEL MENU DE COLORES
void MenuGUI(void) {

int boton, estado;

falso.x = 1.5;
falso.y = -1.5;

    //FONDO DEL MENU COSTADO
    AsignaColor(BLANCO);
    glRectf(-7,7,-10,-7);
    Raton(boton, estado, -7.7, -10);

    //PALETA DE COLORES

    /*COLOR BLANCO*/
    /*AsignaColor(BLANCO);
    glRectf(-5.5, -7.5,-9.5,-8.5);*/


   /*COLOR NEGRO*/
    glRenderMode(GL_SELECT);
    AsignaColor(AZUL); //LISTO
    glRectf(-9.8,-5.8,-8.8,-4.8);

    /*COLOR NEGRO*/
    switch (seleccion)
    {
    case 2:
          AsignaColor(NEGRO); //0 FALSO
            glRectf(1.45,-1.45,1.55,-1.55);
            break;
    }


    /*COLOR GRIS*/
    AsignaColor(GRIS); //LISTO
    glRectf(-8.5,-5.8,-7.5,-4.8);

    /*COLOR GRIS OSCURO*/
    AsignaColor(DARK_GREY); //LISTO
    glRectf(-9.8,-4.5,-8.8,-3.5);

    /*COLOR GRIS CLARO*/
    AsignaColor(GRIS_CLARO); //LISTO
    glRectf(-8.5,-4.5,-7.5,-3.5);

    /*COLOR GRIS ROJO*/
    AsignaColor(ROJO); //LISTO
    glRectf(-9.8,-3.2,-8.8,-2.2);

    /*COLOR GRIS VERDE*/ //LISTO
    AsignaColor(VERDE);
    glRectf(-8.5,-3.2,-7.5,-2.2);

    /*COLOR GRIS AMARILLO*/ //LISTO
    AsignaColor(AMARILLO);
    glRectf(-9.8,-1.9,-8.8,-0.9);

    /*COLOR GRIS CYAN*/
    AsignaColor(CYAN);
    glRectf(-8.5,-1.9,-7.5,-0.9);

    /*COLOR GRIS MAGENTA*/
    AsignaColor(MAGENTA);
    glRectf(-9.8,-0.6,-8.8,0.4);

    /*COLOR GRIS NARANJA*/
    AsignaColor(NARANJA);
    glRectf(-8.5,-0.6,-7.5,0.4);

    /*COLOR GRIS VERDE_AZUL*/
    AsignaColor(VERDE_AZUL);
    glRectf(-9.8,0.7,-8.8,1.7);

    /*COLOR GRIS BABY_BLUE*/
    AsignaColor(BABY_BLUE);
    glRectf(-8.5,0.7,-7.5,1.7);

    /*COLOR GRIS LILA*/
    AsignaColor(LILA);
    glRectf(-9.8,2,-8.8,3);

    /*COLOR GRIS DARK_PURPLE*/
    AsignaColor(DARK_PURPLE);
    glRectf(-8.5,2,-7.5,3);

    /*COLOR GRIS BRONZE*/
    AsignaColor(BRONZE);
    glRectf(-9.8,3.3,-8.8,4.3);

    /*COLOR GRIS DARK_BLUE*/
    AsignaColor(DARK_BLUE);
    glRectf(-8.5,3.3,-7.5,4.3);

    /*COLOR GRIS FOREST_GREEN*/
    AsignaColor(FOREST_GREEN);
    glRectf(-9.8,4.6,-8.8,5.6);

    /*COLOR GRIS BROWN*/
    AsignaColor(BROWN);
    glRectf(-8.5,4.6,-7.5,5.6);


}


void Linea(LINEA L)
{   AsignaColor(L.color);
    glBegin(GL_LINES);
    glVertex2f(L.ini.x,L.ini.y);
    glVertex2f(L.fin.x,L.fin.y);
    glEnd();
}

void Cuadradold(CUADRADO c)
{   //pivote o referencia se ubica en la ezquina inferior izquierda
    AsignaColor(c.color);
      switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }
    glVertex2f(c.piv.x,c.piv.y);
    glVertex2f(c.piv.x+c.lado,c.piv.y);
    glVertex2f(c.piv.x+c.lado,c.piv.y+c.lado);
    glVertex2f(c.piv.x,c.piv.y+c.lado);
    glEnd();
}
void Cuadrado(LINEA c)
{   //pivote o referencia se ubica en la ezquina inferior izquierda
    AsignaColor(c.color);
    glRectf(c.ini.x,c.ini.y, c.fin.x, c.fin.y);


    glEnd();
}

void Rectangulo(RECTANGULO r)
{   //pivote o referencia se ubica en la ezquina inferior izquierda
    AsignaColor(r.color);
      switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }
    glVertex2f(r.piv.x,r.piv.y);
    glVertex2f(r.piv.x+r.ancho,r.piv.y);
    glVertex2f(r.piv.x+r.ancho,r.piv.y+r.alto);
    glVertex2f(r.piv.x,r.piv.y+r.alto);
    glEnd();
}

void Poligono(POLIGONO p)
{
      switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }

    float x,y,theta,Delta;
    Delta=6.28/p.NumLados;
    AsignaColor(p.color);
    //glBegin(GL_LINE_LOOP);
    for(theta=0; theta<6.28; theta+=Delta)
        {   x=p.c.x+p.r*cos(theta);
            y=p.c.y+p.r*sin(theta);
            glVertex2f(x,y);
        }
    glEnd();
}

void Circulo(CIRCULO ci)
{   float x,y,theta;
    AsignaColor(ci.color);
              switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }

    for(theta=0; theta<6.28; theta+=0.1)
        {   x=ci.c.x+ci.r*cos(theta);
            y=ci.c.y+ci.r*sin(theta);
            glVertex2f(x,y);
        }
    glEnd();
}

void Elipse(ELIPSE e)
{     switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }

    float x,y,theta;
    //x/eje_mayor + y/eje_menor =1
    //(x-xc)^2/a^2+ (y-yc)^2/b^2=1
    AsignaColor(e.color);
    //glBegin(GL_LINE_LOOP);
    for(theta=0; theta<6.28; theta+=0.1)
        {   x=e.c.x+e.eje_mayor*cos(theta);
            y=e.c.y+e.eje_menor*sin(theta);
            glVertex2f(x,y);
        }
    glEnd();
}


void TrianguloLEG(TRIANGULO_ISO t)

{
    switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_POLYGON);
        break;
    }

    AsignaColor(t.color);
    glVertex2f(t.piv.x, t.piv.y);
    glVertex2f(t.piv.x+t.base, t.piv.y);
    glVertex2f(t.piv.x+(t.base/2), t.piv.y+t.altura);
    glEnd();
}

void Tachita(LINEA l)
{
    AsignaColor(l.color);
    glBegin(GL_LINES);
    glVertex2f(l.ini.x, l.ini.y);
    glVertex2f(l.fin.x, l.fin.y);
    glEnd();
}
void Triangulo(TRIANGULOG t)
{   AsignaColor(t.color);
    switch (modo)
    {
    case 0:
        glBegin(GL_LINE_LOOP);
        break;
    case 1:
        glBegin(GL_TRIANGLES);
        break;
    }

    glVertex2f(t.piv.x, t.piv.y);
    glVertex2f(t.fin.x, t.fin.y);
    glVertex2f(falso.x, falso.y);



    glEnd();
}
void MenuICONS(){
    //DECLARACION DE FIGURAS
    CIRCULO cir;
    LINEA lin;
    RECTANGULO rect;
    CUADRADO cuad;
    ELIPSE elip;
    POLIGONO poli;
    TRIANGULO_ISO  triIso;

    /*MENU DE FIGURAS GEOMETRICAS*/

    /*FIGURA LINEA*/
    AsignaColor(s1);
    glRectf(-9.95,7,-7.1,10);
    /*Posicion de figura*/
    lin.color=AZUL;
    lin.ini.x=-9.4;
    lin.ini.y=9.4;
    lin.fin.x=-7.5;
    lin.fin.y=7.4;
    Linea(lin);

    /*FIGURA TRIANGULO ISOSCELES*/
    AsignaColor(s2);
    glRectf(-7.1,7,-4.25,10);
    triIso.color=AZUL;
    triIso.piv.x=-6.8;
    triIso.piv.y=7.4;
    triIso.base=2;
    triIso.altura=1.6;
    TrianguloLEG(triIso);

    /*FIGURA CUADRADO*/ //ARRIBA 2
    AsignaColor(s3);
    glRectf(-4.25,7,-1.4,10);
    /*Posicion de figura*/
    cuad.color=AZUL;
    cuad.lado=2;
    cuad.piv.x=-3.85;
    cuad.piv.y=7.4;
    Cuadradold(cuad);

    /*FIGURA RECTANGULO*/ //ABAJO 2
    AsignaColor(s4);
    glRectf(-1.4,7,1.45,10);
    /*Posicion de figura*/
    rect.color=AZUL;
    rect.piv.x=-1;
    rect.piv.y=7.4;
    rect.ancho=2;
    rect.alto=1.5;
    Rectangulo(rect);

    /*FIGURA PENTAGONO*/
    AsignaColor(s5);
    glRectf(1.45,7.,4.3,10);
    /*Posicion de figura*/
    poli.color=AZUL;
    poli.c.x=2.875;
    poli.c.y=8.5;
    poli.r=1.1;
    poli.NumLados=6;
    Poligono(poli);

    /*FIGURA CIRCULO*/
    AsignaColor(s6);
    glRectf(4.3,7,7.15,10);
    /*Posicion de figura*/
    cir.color=AZUL;
    cir.c.x=5.725;
    cir.c.y=8.5;
    cir.r=1.1;
    Circulo(cir);

    /*FIGURA ELIPSE*/ //ARRIBA 3
    AsignaColor(s7);
    glRectf(7.15,7,10,10);
    /*Posicion de figura*/
    elip.color=AZUL;
    elip.c.x=8.575;
    elip.c.y=8.5;
    elip.eje_mayor=1.1;
    elip.eje_menor=0.6;
    Elipse(elip);

//-------------------------------------------------------------------------------

    /*ICONOS DE TRANSFORMACIONES*/
    /*ICONO PARA TRASLACION*/
        //ICONO PARA ESCALAMIENTO*/
    AsignaColor(s8);
    glRectf(-10,-8,-7,-7);
     AsignaColor(s8B);
    DibujarTexto(Escalar,-9.9,-7.5);
    //seguno
    AsignaColor(s9);
    glRectf(-10,-9,-7,-8);
    AsignaColor(s9B);
    DibujarTexto(Traslacion,-9.9,-8.5);

    /*ICONOS DE TRANSFORMACIONES*/
    /*ICONO PARA ROTACION*/
    AsignaColor(s10);
    glRectf(-10,-10,-7,-9);
    AsignaColor(s10B);
    DibujarTexto(Rotacion,-9.9,-9.4);

//
//    //ICONO PARA ESCALAMIENTO*/
//    AsignaColor(BLANCO);
//    glRectf(-10,-8,-7,-7);
//     AsignaColor(NEGRO);
//    DibujarTexto(Escalar,-9.9,-7.2);


}

PUNTO CVent_a_Cplano(int x, int y, int AnchoV, int AltoV, float xini, float xfin, float yini, float yfin)
{
    PUNTO pos;
    float RangoX = xfin - xini;
    float RangoY = yfin - yini;
    float porcentaje;
    porcentaje = ((float)x/AnchoV);
    pos.x = (porcentaje *(RangoX)) - (RangoX) / 2;
    porcentaje = ((float)y / AltoV);
    pos.y = ((1 - porcentaje) * (RangoY)) - (RangoX) / 2;


    return pos;
}


void RatonActivo(int x, int y)
{ float tx,ty;
  float Theta;
  float sx;

  PuntoFinal=CVent_a_Cplano(x,y,600,600,-10,10,-10,10);

  //Escalasao
  if(seleccion==8)
  {
  sx=1.0+((PuntoFinal.x-PuntoInicial.x)/10);
  EscalamientoLinea(&l1,PuntoReferencia.x,PuntoReferencia.y,sx,sx);
  PuntoInicial=PuntoFinal;
  }


  //Traslacion/
  if(seleccion==9)
    { tx=PuntoFinal.x-PuntoInicial.x;
      ty=PuntoFinal.y-PuntoInicial.y;
      TraslacionLinea(&l1,tx,ty);
      PuntoInicial=PuntoFinal; }
  //Rotacion
  if(seleccion==10)
    { Theta=PuntoFinal.x-PuntoInicial.x;
      RotacionLinea(&l1,PuntoReferencia.x,PuntoReferencia.y,Theta);
      PuntoInicial=PuntoFinal; }

  glutPostRedisplay();
}

void Raton(int boton, int estado, int x, int y)
{
    PUNTO pt = CVent_a_Cplano(x, y, 600, 600, -10, 10, -10, 10);
    float x_ = pt.x;
    float y_ = pt.y;
    LINEA master;

    if(estado == GLUT_DOWN)
    {

            switch(boton)
        {
        case GLUT_LEFT_BUTTON:
            ptini=pt;

            //----------------------------------------------------------------------------------------------------------ZONA SELECCIONOSA
            if(pt.x>=-9.5 && pt.x<=-7 && pt.y>=7 && pt.y<=10) //Linea 1
            {
                s1=NEGRO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=BLANCO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                seleccion = 1;
                printf("Seleccionado: %i", seleccion);
            }
            if (pt.x>=-7.1 && pt.x<=-4.25 && pt.y>=7 && pt.y<=10) //Isoceles 2
            {
                seleccion=2;
                s1=BLANCO;s2=NEGRO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=BLANCO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);
            }
              if (pt.x>=-4.25 && pt.x<=-1.4 && pt.y>=7 && pt.y<=10) //Cuadrado 3
            {
                seleccion=3;
                s1=BLANCO;s2=BLANCO;s3=NEGRO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=BLANCO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);
            }
              if (pt.x>=-1.4 && pt.x<=1.45 && pt.y>=7 && pt.y<=10) //Rectangulo 4
            {
                seleccion=4;
                s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=NEGRO;s5=BLANCO;s6=BLANCO;s7=BLANCO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);
            }
                if (pt.x>=1.45 && pt.x<=4.3 && pt.y>=7 && pt.y<=10) //Pentagono 5
            {
                seleccion=5;
                s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=NEGRO;s6=BLANCO;s7=BLANCO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);
            }
                if (pt.x>=4.3 && pt.x<=7.15 && pt.y>=7 && pt.y<=10) //Circulo 6
            {
                seleccion=6;
                s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=NEGRO;s7=BLANCO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);
            }
                if (pt.x>=7.15 && pt.x<=10 && pt.y>=7 && pt.y<=10) //ELIPSE 7
            {
                seleccion=7;
                s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=NEGRO;s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);
            }
             if (pt.x>=-10 && pt.x<=-7 && pt.y>=-8 && pt.y<=-7) //Opcion 8
            {
                seleccion=8;
                s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=BLANCO;s8=NEGRO; s8B=BLANCO; s9=BLANCO; s9B=NEGRO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);

            }
             if (pt.x>=-10 && pt.x<=-7 && pt.y>=-9 && pt.y<=-8) //Opcion 9
            {
                seleccion=9;
               s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=BLANCO; s8=BLANCO; s8B=NEGRO; s9=NEGRO; s9B=BLANCO; s10=BLANCO; s10B=NEGRO;
                printf("Seleccionado: %i", seleccion);

            }
            if (pt.x>=-10 && pt.x<=-7 && pt.y>=-10 && pt.y<=-9) //Opcion 9
            {
                seleccion=10;
               s1=BLANCO;s2=BLANCO;s3=BLANCO;s4=BLANCO;s5=BLANCO;s6=BLANCO;s7=BLANCO; s8=BLANCO; s8B=NEGRO; s9=BLANCO; s9B=NEGRO; s10=NEGRO; s10B=BLANCO;
                printf("Seleccionado: %i", seleccion);

            }


            printf("\nBonton Izquierdo Presionado en posicion (x=%g,y=%g)",ptini.x,ptini.y);
            if (pt.x>=-7 && pt.x<=10 && pt.y>=-10 && pt.y<=7) //---------------------------------------------LIMITES DE ZONA DIBUJOSA
            {
                    switch(seleccion)
                    {
                        case 1: //Linea 1
                        printf("Seleccionado: %i", seleccion);
                        l1.color= selcolor;
                        l1.fin.x = ptini.x;
                        l1.fin.y = ptini.y;
                        l1.ini.x = ptini.x;
                        l1.ini.y = ptini.y;

                        break;
                        case 2:
                        t1.color = selcolor;
                        t1.fin.x = 0;
                        t1.fin.y = 0;
                        t1.piv.x = ptini.x;
                        t1.piv.y = ptini.y;
                        break;

                        case 3:
                        c1.color = selcolor;
                        break;

                        case 4:
                        r1.color = selcolor;
                        break;

                        case 5:
                        p1.color = selcolor;
                        break;

                        case 6:
                        cir1.color = selcolor;
                        break;

                        case 7:
                        e1.color = selcolor;
                        break;

                        case 8:
                            ptescalado = ptini;
                        break;
                        case 9:

                        break;
                        case 10:

                        break;
                    }
                printf("     ------> ANDAMOS DENTRO DE LA ZONA");
            }
            //--------------------------------------------------------------------------------------------------- TODOS LOS COLORES
            if(pt.x>=-8.5 && pt.x<=-7.5 && pt.y>=-5.8 && pt.y<=-4.8) //GRIS
            {
                selcolor = GRIS;
                ptcolor.color=BLANCO; ptcolor.ini.x=-8.5 ; ptcolor.ini.y=-5.8 ; ptcolor.fin.x =-7.5 ; ptcolor.fin.y=-4.8 ;
                tachaex = 1;
            }
            if(pt.x>=-9.8  && pt.y>=-5.8 && pt.x<=-8.8 && pt.y<=-4.8) //AZUL
            {
                selcolor = AZUL;
                ptcolor.color=BLANCO; ptcolor.ini.x=-9.8 ; ptcolor.ini.y=-5.8 ; ptcolor.fin.x =-8.8; ptcolor.fin.y=-4.8 ;
                tachaex = 1;
            }

            if(pt.x>=-9.8  && pt.y>=-4.5 && pt.x<=-8.8 && pt.y<=-3.5) //DARK-G
            {
                selcolor = DARK_GREY;
                ptcolor.color=BLANCO; ptcolor.ini.x=-9.8 ; ptcolor.ini.y=-4.5 ; ptcolor.fin.x =-8.8; ptcolor.fin.y=-3.5 ;
                tachaex = 1;
            }

            if(pt.x>=-8.5  && pt.y>=-4.5 && pt.x<=-7.5 && pt.y<=-3.5) //GRIS CLARO
            {
                selcolor = GRIS_CLARO;
                ptcolor.color=BLANCO; ptcolor.ini.x=-8.5 ; ptcolor.ini.y=-4.5 ; ptcolor.fin.x =-7.5; ptcolor.fin.y=-3.5 ;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=-3.2 && pt.x<=-8.8 && pt.y<=-2.2) //ROJO
            {
                selcolor = ROJO;
                ptcolor.color=NEGRO; ptcolor.ini.x=-9.8 ; ptcolor.ini.y=-3.2 ; ptcolor.fin.x =-8.8; ptcolor.fin.y=-2.2 ;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=-3.2 && pt.x<=-7.5 && pt.y<=-2.2) //VERDE
            {
                selcolor = VERDE;
                ptcolor.color=NEGRO; ptcolor.ini.x=-8.5 ; ptcolor.ini.y=-3.2 ; ptcolor.fin.x =-7.5; ptcolor.fin.y=-2.2 ;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=-1.9 && pt.x<=-8.8 && pt.y<=-0.9) //AMARILLO
            {
                selcolor = AMARILLO;
                ptcolor.color=NEGRO; ptcolor.ini.x=-9.8 ; ptcolor.ini.y=-1.9 ; ptcolor.fin.x =-8.8; ptcolor.fin.y=-0.9 ;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=-1.9 && pt.x<=-7.5 && pt.y<=-0.9) //CYAN
            {
                selcolor = CYAN;
                ptcolor.color=NEGRO; ptcolor.ini.x= -8.5; ptcolor.ini.y= -1.9; ptcolor.fin.x= -7.5; ptcolor.fin.y= -0.9;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=-0.6 && pt.x<=-8.8 && pt.y<=0.4) //MAGENTA
            {
                selcolor = MAGENTA;
                ptcolor.color=NEGRO; ptcolor.ini.x= -9.8; ptcolor.ini.y= -0.6; ptcolor.fin.x= -8.8; ptcolor.fin.y= 0.4;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=-0.6 && pt.x<=-7.5 && pt.y<=0.4) //NARANJA
            {
                selcolor = NARANJA;
                ptcolor.color=NEGRO; ptcolor.ini.x= -8.5; ptcolor.ini.y= -0.6; ptcolor.fin.x= -7.5; ptcolor.fin.y= 0.4;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=0.7 && pt.x<=-8.8 && pt.y<=1.7) //VERDE AZULOIDE
            {
                selcolor = VERDE_AZUL;
                ptcolor.color=NEGRO; ptcolor.ini.x= -9.8; ptcolor.ini.y= 0.7; ptcolor.fin.x= -8.8; ptcolor.fin.y= 1.7;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=0.7 && pt.x<=-7.5 && pt.y<=1.7) //BABY_BLUE
            {
                selcolor = BABY_BLUE;
                ptcolor.color=NEGRO; ptcolor.ini.x= -8.5; ptcolor.ini.y= 0.7; ptcolor.fin.x= -7.5; ptcolor.fin.y= 1.7;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=2 && pt.x<=-8.8 && pt.y<=3) //LILA
            {
                selcolor = LILA;
                ptcolor.color=NEGRO; ptcolor.ini.x= -9.8; ptcolor.ini.y= 2; ptcolor.fin.x= -8.8; ptcolor.fin.y= 3;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=2 && pt.x<=-7.5 && pt.y<=3) //DARK PURP
            {
                selcolor = DARK_PURPLE;
                ptcolor.color=NEGRO; ptcolor.ini.x= -8.5; ptcolor.ini.y= 2; ptcolor.fin.x= -7.5; ptcolor.fin.y= 3;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=3.3 && pt.x<=-8.8 && pt.y<=4.3) //BRONZE
            {
                selcolor = BRONZE;
                ptcolor.color=BLANCO; ptcolor.ini.x= -9.8; ptcolor.ini.y= 3.3; ptcolor.fin.x= -8.8; ptcolor.fin.y= 4.3;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=3.3 && pt.x<=-7.5 && pt.y<=4.3) //DARK BLUE
            {
                selcolor = DARK_BLUE;
                ptcolor.color=BLANCO; ptcolor.ini.x= -8.5; ptcolor.ini.y= 3.3; ptcolor.fin.x= -7.5; ptcolor.fin.y= 4.3;
                tachaex = 1;
            }

            if(pt.x>=-9.8 && pt.y>=4.6 && pt.x<=-8.8 && pt.y<=5.6) //FOREST GREEN
            {
                selcolor = FOREST_GREEN;
                ptcolor.color=BLANCO; ptcolor.ini.x= -9.8; ptcolor.ini.y= 4.6; ptcolor.fin.x= -8.8; ptcolor.fin.y= 5.6;
                tachaex = 1;
            }

            if(pt.x>=-8.5 && pt.y>=4.6 && pt.x<=-7.5 && pt.y<=5.6) //BROWN
            {
                selcolor = BROWN;
                ptcolor.color=BLANCO; ptcolor.ini.x= -8.5; ptcolor.ini.y= 4.6; ptcolor.fin.x= -7.5; ptcolor.fin.y= 5.6;
                tachaex = 1;
            }


                break;


            case GLUT_MIDDLE_BUTTON:
                printf("\nBonton Central Presionado en posicion (x=%g,y=%g)",ptini.x,ptini.y);
                 switch (todo)
                {
                case 0:
                    todo=1;
                    break;
                case 1:
                    todo = 0;
                    break;
                }
                break;
            case GLUT_RIGHT_BUTTON:

                printf("\nBonton Derecho Presionado en posicion (x=%g,y=%g)",ptini.x,ptini.y);
                switch (modo)
                {
                case 0:
                    modo=1;
                    break;
                case 1:
                    modo = 0;
                    break;
                }

                break;
        }

    }

    if(estado == GLUT_UP)
    {

            switch(boton)
        {
            case GLUT_LEFT_BUTTON:
                ptfin=pt;
                printf("\nBonton Izquierdo Liberado en posicion (x=%g,y=%g)",ptfin.x,ptfin.y);
                //La verdadera magia
                //----------------------------------------------------------------------------------------------------------ZONA SELECCIONOSA


              //-------------------------------------------------------------------------------------------------------------//LIMITES DE ZONA DIBUJOSA-//
            if (pt.x>=-7 && pt.x<=10 && pt.y>=-10 && pt.y<=7)
            {
                printf("     ------> ANDAMOS DENTRO DE LA ZONA");

                //-------------------------------------------------------------------------------------------------------AQUI ESCOGEMOS LINEA RARA//
                        switch(seleccion)
                    {
                        case 1: //Linea 1
                        printf("Seleccionado: %i", seleccion);
                        l1.fin.x = ptfin.x;
                        l1.fin.y = ptfin.y;
                        break;

                        case 2:
                        t1.fin.x = ptfin.x;
                        t1.fin.y = ptfin.y;
                        break;

                        case 3:
                        c1.ini.x = ptini.x;
                        c1.ini.y = ptini.y;
                        c1.fin.x = ptfin.x;
                        c1.fin.y = ptfin.y;
                        break;

                        case 4:
                        r1.ini.x = ptini.x;
                        r1.ini.y = ptini.y;
                        r1.fin.x = ptfin.x;
                        r1.fin.y = ptfin.y;

                        break;

                        case 5:
                        p1.ini.x = ptini.x;
                        p1.ini.y = ptini.y;
                        p1.fin.x = ptfin.x;
                        p1.fin.y = ptfin.y;
                        radius = DistanciaXY(cir1.c.x,cir1.c.y,ptfin.x,ptfin.y)-1;

                        break;

                        case 6:
                        cir1.c.x = ptini.x;
                        cir1.c.y = ptini.y;
                        cir1.r = DistanciaXY(cir1.c.x,cir1.c.y,ptfin.x,ptfin.y);
                        break;

                        case 7:
                        e1.c.x = ptini.x;
                        e1.c.y = ptini.y;
                        e1.eje_mayor=DistanciaX(ptini.x, ptfin.x);
                        e1.eje_menor=DistanciaY(ptini.y, ptfin.y);

                        break;
                    }
            }
            else
            {

            }

                break;
            case GLUT_MIDDLE_BUTTON: printf("\nBonton Central Liberado en posicion (x=%g, y=%g)",ptfin.x,ptfin.y);
                                break;
            case GLUT_RIGHT_BUTTON: printf("\nBonton Derecho Liberado en posicion (x=%g,y=%g)",ptfin.x,ptfin.y);
                //exit(0);
                break;
        }
    }

}
void RatonPasivo(int x, int y)
{
    sprintf(coordenadas, "(%d, %d)" ,x, y);
    glutPostRedisplay();
}
/*
void Raton(int boton, int estado, int x, int y)
{
 if(estado==GLUT_DOWN)
     switch(boton)
     { case GLUT_LEFT_BUTTON:   printf("\nBonton Izquierdo Presionado en posicion (x=%i y=%i)",x, y);
                                AsignaColor(BLANCO);
                                break;
     }
  if(estado==GLUT_UP)
     switch(boton)
     { case GLUT_LEFT_BUTTON:   printf("\nBonton Izquierdo Liberado en posicion (x=%i,y=%i)",x,y);

                                break;
     }
}
*/
void EscalamientoLinea(LINEA *L,float xr, float yr, float sx,float sy)
{ L->ini.x= L->ini.x*sx + xr*(1-sx);
  L->ini.y= L->ini.y*sy + yr*(1-sy);
  L->fin.x= L->fin.x*sx + xr*(1-sx);
  L->fin.y= L->fin.y*sy + yr*(1-sy);
}
void RotacionLinea(LINEA *L,float xr, float yr, float Theta)
{ float xp,yp;
  xp=xr + (L->ini.x-xr)*cos(Theta) - (L->ini.y-yr)*sin(Theta);
  yp=yr + (L->ini.x-xr)*sin(Theta) + (L->ini.y-yr)*cos(Theta);
  L->ini.x=xp;
  L->ini.y=yp;
  xp=xr + (L->fin.x-xr)*cos(Theta) - (L->fin.y-yr)*sin(Theta);
  yp=yr + (L->fin.x-xr)*sin(Theta) + (L->fin.y-yr)*cos(Theta);
  L->fin.x=xp;
  L->fin.y=yp;
}

void TraslacionLinea(LINEA *L,float tx,float ty)
{ L->ini.x+=tx;
  L->ini.y+=ty;
  L->fin.x+=tx;
  L->fin.y+=ty;
}


