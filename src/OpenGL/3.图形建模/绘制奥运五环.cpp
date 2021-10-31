/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-10-31 20:06:06
 * @LastEditors: Weidows
 * @LastEditTime: 2021-10-31 20:06:06
 * @FilePath: \C++\src\OpenGL\3.图形建模\绘制奥运五环.cpp
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

GLfloat z = -5.0f;                        // Depth Into The Screen
GLUquadricObj *quadric = gluNewQuadric(); //二次几何体定义变量

int myinit(void)
{
  glEnable(GL_TEXTURE_2D);
  // Enable Texture Mapping
  glShadeModel(GL_SMOOTH);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  // 启用深度测试，格局坐标的远近自动隐藏被遮住的图形
  glEnable(GL_DEPTH_TEST);
  // 指定深度缓冲比较值，如果输入的深度值小于参考值，则配合上面一条语句使用
  glDepthFunc(GL_LESS);
  glClearDepth(1.0f);
  // Depth Buffer Setup
  glDepthFunc(GL_LEQUAL);
  // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  // Really Nice Perspective Calculations
  return 1;
}

//圆环函数
void DrawQuadric(float x, float y, float z)
{
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glPopMatrix();
}

void myReshape(GLsizei w, GLsizei h)
{ //重置窗口大小
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0 * (GLfloat)w / (GLfloat)h, 1.0, 30.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -3.6);
}

// 显示函数，采用堆栈的方式
void display()
{
  glClearColor(1, 1, 1, 0); // set background color as white
  // 清楚颜色缓冲区和深度缓冲区
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity(); // 设置单位矩阵
  glTranslatef(0.0f, 0.0f, z);

  glLoadIdentity();
  glRotatef(1, 1.0f, 0.0f, 0.0f);

  glPushMatrix(); // 绘制蓝色圆环
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glColor4f(0, 0, 1, 0.7);
  glTranslatef(-2.4f, 1.0f, z);
  // 圆盘绘制函数: 二次几何体、圆盘内径、圆盘外径、沿z轴细分数目、圆盘横截面上的细分数目
  gluDisk(quadric, 1.0f, 1.2, 32, 32);
  glPopMatrix();

  glPushMatrix(); // 绘制黄色圆环
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glColor4f(1, 1, 0, 0.7);
  glTranslatef(-1.2f, 0.0f, z);
  gluDisk(quadric, 1.0f, 1.2, 32, 32);
  glPopMatrix();

  glPushMatrix(); //绘制黑色圆环
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glColor4f(0, 0, 0, 0.7);
  glTranslatef(0.1f, 1.0f, z);
  gluDisk(quadric, 1.0f, 1.2, 32, 32);
  glPopMatrix();

  glPushMatrix(); //绘制绿色圆环
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glColor4f(0, 1, 0, 0.7);
  glTranslatef(1.4f, 0.0f, z);
  gluDisk(quadric, 1.0f, 1.2, 32, 32);
  glPopMatrix();

  glPushMatrix(); //绘制红色圆环
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_TEXTURE_GEN_S);
  glEnable(GL_TEXTURE_GEN_T);
  glColor4f(1, 0, 0, 0.7);
  glTranslatef(2.6f, 1.0f, z);
  gluDisk(quadric, 1.0f, 1.2, 32, 32);
  glPopMatrix();

  glFlush();
  glutSwapBuffers(); // 交换前后缓冲,实现双缓冲
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // double 用双缓冲
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(500, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("五环");

  myinit();
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
