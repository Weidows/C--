/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-12-15 16:48:27
 * @LastEditors: Weidows
 * @LastEditTime: 2021-12-15 16:59:32
 * @FilePath: \C++\src\OpenGL\2.变换与建模\二维几何体.cpp
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
// 如果没有显示图形可能是坐标没有归一化到-1和1范围内，可以调整reshape函数的参数。

void CALLBACK draw_my_obj()
{
  //    画点
  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-1.0, 15.0);
  glColor3f(1.0, 1.0, 0.0);
  glVertex2f(1.0, 15.0);
  glColor3f(0.0, 1.0, 1.0);
  glVertex2f(3.0, 15.0);
  glEnd();

  //   画不闭合折线
  glBegin(GL_LINE_STRIP);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(-3.0, 9.0);
  glVertex2f(2.0, 6.0);
  glVertex2f(3.0, 9.0);
  glVertex2f(-2, 6.0);
  glVertex2f(-3.0, 9.0);
  glEnd();

  //    画闭合折线
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(7.0, 7.0);
  glVertex2f(9.0, 9.0);
  glVertex2f(10.0, 8.0);
  glVertex2f(11.0, 9.0);
  glVertex2f(13.0, 7.0);
  glVertex2f(11.0, 5.0);
  glVertex2f(10.0, 6.0);
  glVertex2f(9.0, 5.0);
  glEnd();

  //    画填充多边形
  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 0.2);
  glVertex2f(-10.0, 4.0);
  glVertex2f(-8.0, 4.0);
  glVertex2f(-6.0, 1.0);
  glVertex2f(-8.0, -2.0);
  glVertex2f(-10.0, -2.0);
  glVertex2f(-12.0, 1.0);
  glEnd();

  //    画线型连续填充三角形串
  glBegin(GL_TRIANGLE_STRIP);
  glVertex2f(-1.0, -8.0);
  glVertex2f(-2.5, -5.0);

  glColor3f(0.8, 0.8, 0.0);
  glVertex2f(1.0, -7.0);

  glColor3f(0.0, 0.8, 0.8);
  glVertex2f(2.0, -4.0);

  glColor3f(0.8, 0.0, 0.8);
  glVertex2f(4.0, -6.0);

  glEnd();

  //    画扇形连续填充三角形串
  glBegin(GL_TRIANGLE_FAN);

  glVertex2f(8.0, -6.0);
  glVertex2f(10.0, -3.0);
  glColor3f(0.8, 0.2, 0.5);
  glVertex2f(12.5, -4.5);
  glColor3f(0.2, 0.5, 0.8);
  glVertex2f(13.0, -7.5);
  glColor3f(0.8, 0.5, 0.2);
  glVertex2f(10.5, -9.0);

  glEnd();
}

void CALLBACK display()
{
  glColor3f(1.0, 1.0, 0.0);
  draw_my_obj();
  glFlush();
}

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
