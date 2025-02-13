//
//  main.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/07.
//

/* Simple geometry viewer:  Left mouse: rotate;  Right mouse:   translate;  ESC to quit. */
#define GL_SILENCE_DEPRECATION

#include <assert.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "sources.hpp"

#if defined(__linux__) // Or #if __linux__
  #include <GL/glut.h>
#elif _WIN32
  std::cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  #include <GLUT/glut.h>
#endif


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    InitObjects();
    InitGL();
    glutMainLoop();
    return 0;
}
