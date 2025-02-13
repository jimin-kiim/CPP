//
//  constants.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION

#ifndef constants_hpp
#define constants_hpp

#include <stdio.h>
#include <iostream>
#include "CSphere.hpp"
#include "CWall.hpp"
using namespace std;

#if defined(__linux__) // Or #if __linux__
  #include <GL/glut.h>
#elif _WIN32
  std::cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  #include <GLUT/glut.h>
#endif


extern const int FLOOR_WIDTH;
extern const int FLOOR_HEIGHT;

extern const float SPHERE_RADIUS;
//GLdouble rotMatrix[4][16];
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

extern int space_flag;
extern int currentTime, previousTime;

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
