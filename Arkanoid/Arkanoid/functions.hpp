//
//  functions.hpp
//  Arkanoid
//
//  Created by 김지민 on 2022/11/12.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include "CWall.hpp"
#include "CSphere.hpp"

void MyIdleFunc(void) { glutPostRedisplay();} /* things to do while idle */
void RunIdleFunc(void) {   glutIdleFunc(MyIdleFunc); }
void PauseIdleFunc(void) {   glutIdleFunc(NULL); }
void renderScene();

CSphere g_sphere[3];
CWall g_wall(11,0.2,11);

void ReshapeCallback(int width, int height);
void DisplayCallback(void);

int space_flag=0;
int currentTime, previousTime=-1;
void KeyboardCallback(unsigned char ch, int x, int y);
void MouseCallback(int button, int state, int x, int y);
void rotate(int id);
void MotionCallback(int x, int y);
void initRotate();
void InitGL();

void renderScene();
void InitObjects();

#endif /* functions_hpp */
