//
//  main.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/07.
//

/* Simple geometry viewer:  Left mouse: rotate;  Right mouse:   translate;  ESC to quit. */
#include <assert.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "sources.hpp"

#define GL_SILENCE_DEPRECATION

#if defined(__linux__) // Or #if __linux__
  std::cout << "GNU/Linux" << '\n';
  #include<GL/glut.h>
#elif _WIN32
  std::cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  std::cout << "Other Environment." << '\n';
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
