#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int x2GedungKecil = 10;
int x3GedungKecil = 20;
int z4GedungKecil = 30;
int tGedungKecil = 10;
int tGedungBesar = 20;

struct TTK
{
    float xD;
    float zD;
    float xL;
    float zL;
};
struct TTK titik[10];
void kotak_depanbelakang(float x1, float x2, float y1, float y2, float z)
{
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, z);
    glVertex3f(x1, y2, z);
    glVertex3f(x2, y2, z);
    glVertex3f(x2, y1, z);
    glEnd();

    float Y = -20.2;

    /*Belakang*/
    glColor3f(0, 0, 1);
    kotak_depanbelakang(x2GedungKecil, x3GedungKecil, Y, Y + 10, z4GedungKecil + 5); //Belakang Bawah
    glColor3f(0, 0.5, 1);
    glBegin(GL_QUAD_STRIP); //Belakang Atas
    glVertex3f(x2GedungKecil, Y + 10, z4GedungKecil + 5);
    glVertex3f(x3GedungKecil, Y + 10, z4GedungKecil + 5);
    glVertex3f(x2GedungKecil, tGedungKecil - 2, z4GedungKecil - 2);
    glVertex3f(x3GedungKecil, tGedungKecil - 2, z4GedungKecil - 2);
    glVertex3f(x2GedungKecil, tGedungKecil + 3, z4GedungKecil - 2);
    glVertex3f(x3GedungKecil, tGedungKecil + 3, z4GedungKecil - 2);
    glVertex3f(titik[7].xL, tGedungBesar, titik[7].zL);  //Atap
    glVertex3f(titik[10].xL, tGedungBesar, titik[10].zL);
    glEnd();
    glFlush();
}
void dasar(void)
{
    glBegin(GL_POLYGON);//dasar
    glColor3ub(25,50,50);
    glVertex3f(-200,0,-200);
    glVertex3f(200,0,-200);
    glVertex3f(200,0,200);
    glVertex3f(-200,0,200);
    glEnd();
}
void lapangan(void)
{
    glBegin(GL_POLYGON);//lapangan
    glColor3ub(50,255,50);
    glVertex3f(-25,0.5,-50);//bawah
    glVertex3f(25,0.5,-50);//atas
    glVertex3f(25,0.5,50); //kanan
    glVertex3f(-25,0.5,50);//kiri
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glEnd();
}



void tribun2(void)
{
    double y1max = 10.0;
    double y2max = 20.0;
    double y3max = 30.0;
    double y = 1.0;
    double x1 = -30.0;
    double x2 = 30;
    double z1 = 55;
    while(-y>=-y1max)
    {
        glBegin(GL_POLYGON);//blkgsandaran
        glColor3ub(255,100,100);
        glVertex3f(x1,y,-z1);
        glVertex3f(x2,y,-z1);
        glVertex3f(x2,y+0.5,-z1);
        glVertex3f(x1,y+0.5,-z1);
        glEnd();
        glBegin(GL_POLYGON);//depansandaran
        glColor3ub(255,100,100);
        glVertex3f(x1,y,z1);
        glVertex3f(x2,y,z1);
        glVertex3f(x2,y+0.5,z1);
        glVertex3f(x1,y+0.5,z1);
        glEnd();
        glBegin(GL_POLYGON);//blkgdudukan
        glColor3ub(255,0,0);
        glVertex3f(x1,y,-z1);
        glVertex3f(x1,y,-z1+0.5);
        glVertex3f(x2,y,-z1+0.5);
        glVertex3f(x2,y,-z1);
        glEnd();
        glBegin(GL_POLYGON);//depandudukan
        glColor3ub(255,0,0);
        glVertex3f(x1,y,z1);
        glVertex3f(x1,y,z1-0.5);
        glVertex3f(x2,y,z1-0.5);
        glVertex3f(x2,y,z1);
        glEnd();
        glBegin(GL_POLYGON);//blkgbawahan
        glColor3ub(100,100,100);
        glVertex3f(x1,y,-z1);
        glVertex3f(x2,y,-z1);
        glVertex3f(x2,y-0.5,-z1);
        glVertex3f(x1,y-0.5,-z1);
        glEnd();
        glBegin(GL_POLYGON);//depanbawahan
        glColor3ub(100,100,100);
        glVertex3f(x1,y,z1);
        glVertex3f(x2,y,z1);
        glVertex3f(x2,y-0.5,z1);
        glVertex3f(x1,y-0.5,z1);
        glEnd();
        glBegin(GL_POLYGON);//blkglt
        glColor3ub(145,145,145);
        glVertex3f(x1,y-0.5,-z1);
        glVertex3f(x2,y-0.5,-z1);
        glVertex3f(x2,y-0.5,-z1+1);
        glVertex3f(x1,y-0.5,-z1+1);
        glEnd();
        glBegin(GL_POLYGON);//depanlt
        glColor3ub(145,145,145);
        glVertex3f(x1,y-0.5,z1);
        glVertex3f(x2,y-0.5,z1);
        glVertex3f(x2,y-0.5,z1-1);
        glVertex3f(x1,y-0.5,z1-1);
        glEnd();
        x1--;
        x2++;
        y++;
        z1++;
    }
}
void tribun1(void)
{
    double y1max = 10.0;
    double y2max = 20.0;
    double y3max = 30.0;
    double y = 1.0;
    double x1 = -30.0;
    double x2 = 30;
    double z1 = 55;
    while(-y>=-y1max)
    {
        glBegin(GL_POLYGON);//kirisandaran
        glColor3ub(255,100,100);
        glVertex3f(x1,y,-z1);
        glVertex3f(x1,y,z1);
        glVertex3f(x1,y+0.5,z1);
        glVertex3f(x1,y+0.5,-z1);
        glEnd();
        glBegin(GL_POLYGON);//kanansandaran
        glColor3ub(255,100,100);
        glVertex3f(x2,y,-z1);
        glVertex3f(x2,y,z1);
        glVertex3f(x2,y+0.5,z1);
        glVertex3f(x2,y+0.5,-z1);
        glEnd();
        glBegin(GL_POLYGON);//kiridudukan
        glColor3ub(255,0,0);
        glVertex3f(x1,y,-z1);
        glVertex3f(x1+0.5,y,-z1);
        glVertex3f(x1+0.5,y,z1);
        glVertex3f(x1,y,z1);
        glEnd();
        glBegin(GL_POLYGON);//kanandudukan
        glColor3ub(255,0,0);
        glVertex3f(x2,y,-z1);
        glVertex3f(x2-0.5,y,-z1);
        glVertex3f(x2-0.5,y,z1);
        glVertex3f(x2,y,z1);
        glEnd();
        glBegin(GL_POLYGON);//kiribawahan
        glColor3ub(100,100,100);
        glVertex3f(x1,y,-z1);
        glVertex3f(x1,y,z1);
        glVertex3f(x1,y-0.5,z1);
        glVertex3f(x1,y-0.5,-z1);
        glEnd();
        glBegin(GL_POLYGON);//kanansbawahan
        glColor3ub(100,100,100);
        glVertex3f(x2,y,-z1);
        glVertex3f(x2,y,z1);
        glVertex3f(x2,y-0.5,z1);
        glVertex3f(x2,y-0.5,-z1);
        glEnd();
        glBegin(GL_POLYGON);//kirilt
        glColor3ub(145,145,145);
        glVertex3f(x1,y-0.5,-z1);
        glVertex3f(x1+1,y-0.5,-z1);
        glVertex3f(x1+1,y-0.5,z1);
        glVertex3f(x1,y-0.5,z1);
        glEnd();
        glBegin(GL_POLYGON);//kananlt
        glColor3ub(145,145,145);
        glVertex3f(x2,y-0.5,-z1);
        glVertex3f(x2-1,y-0.5,-z1);
        glVertex3f(x2-1,y-0.5,z1);
        glVertex3f(x2,y-0.5,z1);
        glEnd();
        y++;
        z1++;
        x1--;
        x2++;
    }
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(10.0);
}
void display(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    lapangan();
    tribun1();
    tribun2();
    dasar();
    glPopMatrix();
    glutSwapBuffers();;
}
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case'+'://kamera maju
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case'-'://kamera mundur
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case'd'://kamera geser kanan
        case'D':
                glTranslatef(-3.0, 0.0, 0.0);
        break;
    case'a'://kamera geser kiri
        case'A':
                glTranslatef(3.0, 0.0, 0.0);
        break;
    case'7'://kamera turun
            glTranslatef(0.0, 3.0, 0.0);
        break;
    case'9'://kamera naik
            glTranslatef(0.0, -3.0, 0.0);
        break;
    case'2'://kamera putar vertikal naik
            glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case'8'://kamera putar vertikal turun
            glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case'6'://kamera putar horizontal kanan
            glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case'4'://kamera putar horizontal kiri
            glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case'1'://kamera putar miring kiri
            glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case'3'://kamera putar miring kanan
            glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
//        case'5'://buka atap
//            if(is_depth)
//            {
//                is_depth = 0;
//                tampil();
//            }
//            else
//            {
//                is_depth = 1;
//                hilang();
//            }
//            break;
    }
    display();
}
void idle()
{
    if (!mouseDown)
    {
        xrot == 0.3f;
        yrot == 0.4f;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}
void lookat()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}
void mouseMotion(int x, int y)
{
    lookat();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0)
        tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, lebar / tinggi, 5, 500);
    glTranslatef(0, 0, -225);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1100,900);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR Grafkom B Stadium");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
