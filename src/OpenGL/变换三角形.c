/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-09-27 12:15:06
 * @LastEditors: Weidows
 * @LastEditTime: 2021-09-27 22:13:01
 * @FilePath: \C++\Study\OpenGL\1.c
 * @Description:
 * @!: *********************************************************************
 */
#include <GL/glut.h>
#include <stdlib.h>
void Initial(void)
{
  glMatrixMode(GL_PROJECTION); //设置投影参数，表示下面进行投影变换。若改GL_PROJECTION为GL_MODEVIEW则进行视图变换。
  glLoadIdentity();            //通常我们在需要进行投影变换时要把当前矩形设置为单位矩阵，即glLoadIdentity()
  gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix(); //操作矩阵堆栈,调用函数，相当于把矩阵放到堆栈上
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslated(100, 100, 0);
  glTranslated(70, 0, 0);
  glRotated(-90, 0, 0, 1);
  glScaled(0.25, 0.25, 0.0);
  glTranslated(-100, -100, 0);
  glBegin(GL_POLYGON);
  glVertex2f(50, 50);
  glVertex2f(150, 50);
  glVertex2f(100, 150);
  glEnd();
  glPopMatrix();

  glBegin(GL_POLYGON); //opengl要求指定顶点的位置必须在glBegin()后面，同时在glEnd()后面。
  glVertex2f(50, 50);
  glVertex2f(150, 50);
  glVertex2f(100, 150);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //使用单缓存模式，如果GLUT_DOUBLE则为双缓存模式
  glutInitWindowSize(600, 600);                //设置窗口大小
  glutInitWindowPosition(100, 100);            //设置窗口位置
  glutCreateWindow("Triangle");
  glutDisplayFunc(Display);
  Initial();
  glutMainLoop();
}
