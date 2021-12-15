/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-12-15 17:26:15
 * @LastEditors: Weidows
 * @LastEditTime: 2021-12-15 17:27:39
 * @FilePath: \C++\src\OpenGL\4.真实感图形\光照壶.cpp
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

void myinit(void)
{
  GLfloat light_position[] = {1.0, 0.0, 1.0, 0.0}; // 光源位置
  GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};  // 环境光
  GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  // 白光
  //    GLfloat light_diffuse[]= { 0.0, 0.0, 1.0, 1.0};    // 蓝光
  //    GLfloat light_diffuse[]= { 1.0, 1.0, 0.0, 1.0};    // 黄光
  //   GLfloat light_diffuse[]= { 0.8, 0.0, 0.8, 1.0 };   // 紫光
  GLfloat light_specular[] = {0.0, 1.0, 1.0, 1.0}; // 镜面光

  //    定义光源 light: 光源号  pname: 光源特性
  //    glLightfv(<#GLenum light#>, <#GLenum pname#>, <#const GLfloat *params#>)
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  //    glShadeModel(GL_SMOOTH);

  // 启动光照
  glEnable(GL_LIGHTING);
  // 使光源有效
  glEnable(GL_LIGHT0);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

void CALLBACK display()
{
  // 环境设置
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glRotatef(30.0, 1.0, 0.0, 0.0);
  glRotatef(10.0, 0.0, 1.0, 0.0);
  glutSolidTeapot(1.0); // 绘制茶壶
  glFlush();
}

// 重画窗口函数设定投影方式
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
  else
    glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // double 用双缓冲
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // 需要加入深度缓冲区GLUT_DEPTH
  glutInitWindowSize(500, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Illumination teapot");

  myinit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutMainLoop();
  return 0;
}
