/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-10-31 18:44:28
 * @LastEditors: Weidows
 * @LastEditTime: 2021-10-31 19:26:02
 * @FilePath: \C++\src\OpenGL\0.概述\cube.cpp
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

void init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);
}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT); //清楚屏幕所有内容

  //  glutWireTeapot(0.8);

  //  glutSolidCube(1);

  gluLookAt(1.0, 1.0, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0); //  //确定了一个可用于为摄像机定位和定向的矩阵，涉及的参数包括摄像机的位置(视点eye),被观察点(点at)以及所期望的up方向。

  glutWireCube(1);

  //  gluSphere(<#GLUquadric *quad#>, <#GLdouble radius#>, <#GLint slices#>, <#GLint stacks#>);

  //  gluCylinder(<#GLUquadric *quad#>, <#GLdouble base#>, <#GLdouble top#>, <#GLdouble height#>, <#GLint slices#>, <#GLint stacks#>);

  glFlush();
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
