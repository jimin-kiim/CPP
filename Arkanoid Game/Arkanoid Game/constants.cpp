//
//  constants.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#include <GLUT/glut.h>
#include <stdio.h>

//GLdouble rotMatrix[4][16];
const int NO_SPHERE=3;
const int WALL_ID=1000;

int rotate_x=0, rotate_y=0;
int choice=1;

GLfloat BoxVerts[][3] = {
    {-1.0,-1.0,-1.0},
    {-1.0,-1.0,1.0},
    {-1.0,1.0,-1.0},
    {-1.0,1.0,1.0},
    {1.0,-1.0,-1.0},
    {1.0,-1.0,1.0},
    {1.0,1.0,-1.0},
    {1.0,1.0,1.0}
};

GLfloat bNorms[][3] = {
    {-1.0,0.0,0.0},
    {1.0,0.0,0.0},
    {0.0,1.0,0.0},
    {0.0,-1.0,0.0},
    {0.0,0.0,-1.0},
    {0.0,0.0,1.0}
};

int cubeIndices[][4] = {
    {0,1,3,2},
    {4,6,7,5},
    {2,3,7,6},
    {0,4,5,1},
    {0,2,6,4},
    {1,5,7,3}
};

/* Viewer state */
float sdepth = 10;
float zNear=1.0, zFar=100.0;
float aspect = 5.0/4.0;
float xcam = 0, ycam = 0;
long xsize, ysize;
int downX, downY;
bool leftButton = false, middleButton = false, rightButton = false;
int i,j;
GLfloat light0Position[] = { 0, 1, 0, 1.0};
int displayMenu, mainMenu;
