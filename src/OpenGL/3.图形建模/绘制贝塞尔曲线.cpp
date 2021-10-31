/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-10-31 20:07:13
 * @LastEditors: Weidows
 * @LastEditTime: 2021-10-31 20:07:14
 * @FilePath: \C++\src\OpenGL\3.图形建模\绘制贝塞尔曲线.cpp
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

// 定义顶点 4*3 分别表示四个贝塞尔控制点的三维坐标
GLfloat ctrlpoints[4][3] = {
    {-5.0, -0.0, 0.0}, {-3.0, 3.0, 0.0},

    {3.0, 3.0, 0.0},
    {5.0, 0.0, 0.0}};

// 初始化函数
void myinit(void)
{
  // 设置屏幕背景色为黑色
  glClearColor(0.0, 0.0, 0.0, 1.0);

  // glMap1f(<#GLenum target#>, <#GLfloat u1#>, <#GLfloat u2#>, <#GLint stride#>, <#GLint order#>, <#const GLfloat *points#>)
  // target:指定控制顶点的意义，并确定了points应该提供多少值
  // u1和u2参数表示变量u的变化范围
  // stride表示每个存储块之间单精度或双精度浮点数的数量
  // order参数的值就是控制点的数量
  // points参数海子乡第一个控制点的第一个坐标
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
  glEnable(GL_MAP1_VERTEX_3); // 启用求值器
}

void CALLBACK display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_LINE_STRIP); // 采用不闭合折线绘制方式

  // 分30个小段绘制，分段越细则绘制的贝塞尔曲线越精确，但是程序所消耗的时间也会相应加长
  for (int i = 0; i <= 30; i++)
  {
    glEvalCoord1f((GLfloat)i / 30.0);
  }

  glEnd();

  /* 显示控制点 */
  glPointSize(5.0);
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  for (int i = 0; i < 4; i++)
  {
    glVertex3fv(&ctrlpoints[i][0]); //使用数组方式传递参数
  }
  glEnd();
  glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
  {
    glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w, 5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
  }
  else
  {
    glOrtho(-5.0 * (GLfloat)w / (GLfloat)h, 5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // double 用双缓冲
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(500, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Bezier Curves");

  myinit();
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
