//
//  main.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/07.
//

/* Simple geometry viewer:  Left mouse: rotate;  Right mouse:   translate;  ESC to quit. */
#include <assert.h>

#include <stdlib.h>


#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "sources.hpp"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    InitObjects();
    InitGL();
    glutMainLoop();
    return 0;
}
