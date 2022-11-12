//
//  main.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/07.
//

/* Simple geometry viewer:  Left mouse: rotate;  Right mouse:   translate;  ESC to quit. */
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include <GLUT/glut.h>
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
