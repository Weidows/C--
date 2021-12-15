/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-10-31 19:39:00
 * @LastEditors: Weidows
 * @LastEditTime: 2021-10-31 19:48:57
 * @FilePath: \C++\src\OpenGL\1.transform_triangular\2.cpp
 * @Description:
 * @!: *********************************************************************
 */
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glaux.h>
#include <GL/glut.h>
#endif

using namespace std;

// 没有写出的函数 则和第一章对应的函数相同
void myinit(void)
{
  glShadeModel(GL_FLAT);
}

void drawTriangle()
{
  //    glBegin(GL_TRIANGLES);    //实心填充
  glBegin(GL_LINE_LOOP); //只画线
  glVertex2f(0.0, 1.0);  //范围在－1到1，线条画了，但在屏幕外面
  glVertex2f(1.0, -1.0);
  glVertex2f(-1.0, -1.0);
  glEnd();
}

void CALLBACK display()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();
  glColor3f(1.0, 0.0, 0.0);
  drawTriangle();

  glLoadIdentity();
  glTranslatef(-0.5, 0.0, 0.0);
  glColor3f(0.0, 1.0, 0.0);
  drawTriangle();

  glLoadIdentity();
  glScalef(1.5, 0.5, 1.0);
  glColor3f(0.0, 0.0, 1.0);
  drawTriangle();

  glLoadIdentity();
  glRotatef(90.0, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.0, 1.0);
  drawTriangle();

  glLoadIdentity();
  glScalef(1.0, -0.5, 1.0);
  glColor3f(1.0, 1.0, 0.0);
  drawTriangle();
  glFlush();
}

void init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);
}

void myReshape(GLsizei w, GLsizei h)
{ //重置窗口大小

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION); //选择投影矩阵

  glLoadIdentity(); //重置投影矩阵

  if (w <= h)
  {
    //需要根据画的对象的大小不同比例来修改参数，为了将实际坐标转化成-1到1之间的值。
    glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.50 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
  }
  else
  {
    glOrtho(-1.5 * (GLfloat)h / (GLfloat)w, 1.50 * (GLfloat)h / (GLfloat)w, -1.5, 1.5, -10.0, 10.0);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  // single是单焕存
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(500, 500);

  glutInitWindowPosition(0, 0);

  glutCreateWindow("gragh");

  init();

  glutReshapeFunc(myReshape);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}
