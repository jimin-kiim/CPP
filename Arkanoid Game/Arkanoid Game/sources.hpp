//
//  constants.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#ifndef constants_hpp
#define constants_hpp

#include <GLUT/glut.h>
#include <stdio.h>

#include "CSphere.hpp"
#include "CWall.hpp"

//GLdouble rotMatrix[4][16];
extern const int NO_SPHERE=3;
extern const int WALL_ID=1000;

extern int rotate_x, rotate_y;
extern int choice;

extern GLfloat BoxVerts[][3];

extern GLfloat bNorms[][3];

extern int cubeIndices[][4];

/* Viewer state */
extern float sdepth;
extern float zNear, zFar;
extern float aspect;
extern float xcam, ycam;
extern long xsize, ysize;
extern int downX, downY;
extern bool leftButton, middleButton, rightButton;
extern int i,j;
extern GLfloat light0Position[];
extern int displayMenu, mainMenu;

CSphere g_sphere[3];
CWall g_wall(11,0.2,11);
extern int space_flag;
extern int currentTime, previousTime;

extern void MyIdleFunc(void) { glutPostRedisplay();} /* things to do while idle */
extern void RunIdleFunc(void) {   glutIdleFunc(MyIdleFunc); }
extern void PauseIdleFunc(void) {   glutIdleFunc(NULL); }
extern void renderScene();

extern void ReshapeCallback(int width, int height);
extern void DisplayCallback(void);

extern void KeyboardCallback(unsigned char ch, int x, int y);
extern void MouseCallback(int button, int state, int x, int y);
extern void rotate(int id);
extern void MotionCallback(int x, int y);
extern void initRotate();
extern void InitGL();

extern void renderScene();
extern void InitObjects();
#endif
