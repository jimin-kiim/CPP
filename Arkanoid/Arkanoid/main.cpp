//
//  main.cpp
//  Arkanoid
//
//  Created by 김지민 on 2022/11/12.
//
/* Simple geometry viewer:  Left mouse: rotate;  Right mouse:   translate;  ESC to quit. */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "functions.hpp"

// you may try "#include <GL/glut.h>" if "#include <GLUT/glut.h>" wouldn't work
//#include <GL/glut.h>


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    InitObjects();
    InitGL();
    glutMainLoop();
    return 0;
}
