/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-12-15 17:37:50
 * @LastEditors: Weidows
 * @LastEditTime: 2021-12-15 17:37:51
 * @FilePath: \C++\src\OpenGL\4.真实感图形\材质球.cpp
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
  GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0}; // 环境光
  GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0}; //漫射光
                                            //    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat position[] = {3.0, 3.0, 2.0, 0.0};
  //    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glClearColor(0.6, 0.6, 0.0, 0.0);
}

void CALLBACK display(void)
{
  GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};      //无光效果
  GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0}; //环境光参数
  GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
  GLfloat mat_diffuse[] = {0.1, 0.5, 0.8, 1.0};
  GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat no_shininess[] = {0.0}; // 没有高光效果
  GLfloat low_shininess[] = {5.0};
  GLfloat high_shininess[] = {100.0};
  GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0}; // 辐射光参数

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // 绘制第一行第一列的球，仅有漫反射光而无环境光和镜面反射
  glPushMatrix();
  glTranslatef(-3.75, 3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

  // 第二个参数和第三个参数一起表示球体面的数目，数目越大，球体越精确，但是代价就是速度慢。
  glutSolidSphere(1.0, 35, 35);

  glPopMatrix();

  /* （1，2）*/

  glPushMatrix();
  glTranslatef(-1.25, 3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /* （1，3）*/

  glPushMatrix();
  glTranslatef(1.25, 3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /* （1，4）*/
  glPushMatrix();
  glTranslatef(3.75, 3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /*（2，1）*/
  glPushMatrix();
  glTranslatef(-3.75, 0.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /* （2，2）*/

  glPushMatrix();
  glTranslatef(-1.25, 0.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /*（2，3）*/
  glPushMatrix();
  glTranslatef(1.25, 0.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /*（2，4）*/
  glPushMatrix();
  glTranslatef(3.75, 0.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /*（3，1）*/
  glPushMatrix();
  glTranslatef(-3.75, -3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /* （3，2）*/
  glPushMatrix();
  glTranslatef(-1.25, -3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /*（3，3）*/
  glPushMatrix();
  glTranslatef(1.25, -3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  /* （3，4） */
  glPushMatrix();
  glTranslatef(3.75, -3.0, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
  glutSolidSphere(1.0, 35, 35);
  glPopMatrix();

  glFlush();
}

// 重画窗口函数设定投影方式
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= (h * 2))
    glOrtho(-6.0, 6.0, -3.0 * ((GLfloat)h * 2) / (GLfloat)w, 3.0 * ((GLfloat)h * 2) / (GLfloat)w, -10.0, 10.0);
  else
    glOrtho(-6.0 * (GLfloat)w / ((GLfloat)h * 2), 6.0 * (GLfloat)w / ((GLfloat)h * 2), -3.0, 3.0, -10.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  // double 用双缓冲
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(1000, 800);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Shader");

  myinit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
  glutMainLoop();
  return 0;
}
