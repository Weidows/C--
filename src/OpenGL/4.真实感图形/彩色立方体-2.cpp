/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-12-15 17:11:47
 * @LastEditors: Weidows
 * @LastEditTime: 2021-12-15 17:32:59
 * @FilePath: \C++\src\OpenGL\4.真实感图形\彩色立方体-2.cpp
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

GLfloat step = 0.0;

void myinit();
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display();
void DrawColorBox();

// 设置八个顶点的颜色
static GLfloat c1[] = {0.0, 0.0, 1.0}, c2[] = {0.0, 1.0, 1.0},
               c3[] = {1.0, 1.0, 1.0}, c4[] = {1.0, 0.0, 1.0},
               c5[] = {1.0, 0.0, 0.0}, c6[] = {1.0, 1.0, 0.0},
               c7[] = {0.0, 1.0, 0.0}, c8[] = {1.0, 1.0, 1.0};

void myinit()
{
  // GL_LESS表示如果输入的深度值小于参考值则通过
  glDepthFunc(GL_LESS); // 指定深度缓冲比较值
  glEnable(GL_DEPTH_TEST);

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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glRotatef(step, 0.0, 1.0, 1.0);
  DrawColorBox();
  glFlush();
  glutSwapBuffers();
}

// 自动运动函数，设定彩色正方体可以旋转，采用设定计时器的方法
void CALLBACK stepDisplay(void)
{
  step = step + 0.0001;
  if (step > 360.0)
  {
    step = step - 360.0;
  }
  display();
}

// 实现交互
void CALLBACK myMouse(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  { // 按下鼠标键
    if (button == GLUT_RIGHT_BUTTON)
    { // 右键：停止旋转
      glutIdleFunc(0);
    }
    else if (button == GLUT_LEFT_BUTTON)
    { //左键：开始旋转
      glutIdleFunc(stepDisplay);
    }
  }
}

// 重画窗口
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
            1.50 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
  else
    glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
            1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void DrawColorBox(void)
{
  glBegin(GL_QUADS); // 多组独立填充四边形
  // 绘制右侧平面
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.5, -0.5, -0.5);
  glColor3fv(c2);
  glVertex3f(0.5, 0.5, -0.5);
  glColor3fv(c3);
  glVertex3f(0.5, 0.5, 0.5);
  glColor3fv(c4);
  glVertex3f(0.5, -0.5, 0.5);
  // 绘制左侧平面
  glColor3fv(c5);
  glVertex3f(-0.5, -0.5, 0.5);
  glColor3fv(c6);
  glVertex3f(-0.5, 0.5, 0.5);
  glColor3fv(c7);
  glVertex3f(-0.5, 0.5, -0.5);
  glColor3fv(c8);
  glVertex3f(-0.5, -0.5, -0.5);
  // 前面
  glColor3fv(c5);
  glVertex3f(-0.5, -0.5, 0.5);
  glColor3fv(c6);
  glVertex3f(-0.5, 0.5, 0.5);
  glColor3fv(c3);
  glVertex3f(0.5, 0.5, 0.5);
  glColor3fv(c4);
  glVertex3f(0.5, -0.5, 0.5);
  // 背面
  glColor3fv(c1);
  glVertex3f(0.5, -0.5, -0.5);
  glColor3fv(c2);
  glVertex3f(0.5, 0.5, -0.5);
  glColor3fv(c7);
  glVertex3f(-0.5, 0.5, -0.5);
  glColor3fv(c8);
  glVertex3f(-0.5, -0.5, -0.5);
  // 顶面
  glColor3fv(c2);
  glVertex3f(0.5, 0.5, -0.5);
  glColor3fv(c3);
  glVertex3f(0.5, 0.5, 0.5);
  glColor3fv(c6);
  glVertex3f(-0.5, 0.5, 0.5);
  glColor3fv(c7);
  glVertex3f(-0.5, 0.5, -0.5);

  glColor3fv(c1);
  glVertex3f(0.5, -0.5, -0.5);
  glColor3fv(c4);
  glVertex3f(0.5, -0.5, 0.5);
  glColor3fv(c5);
  glVertex3f(-0.5, -0.5, 0.5);
  glColor3fv(c8);
  glEnd();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // double 用双缓冲
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(500, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("colorful cube");

  myinit();
  glutIdleFunc(stepDisplay);
  glutMouseFunc(myMouse);
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutMainLoop();
  return 0;
}
