//
//  CWall.hpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION

#ifndef CWall_hpp
#define CWall_hpp

#include <stdio.h>
#if __linux__ 
  #include <GL/glut.h>
#elif _WIN32
  std::cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  #include <GLUT/glut.h>
#endif

#include "CSphere.hpp"
class CWall
{

public:
    float width, height, depth;
    float center_x, center_y, center_z;
    float color_r,color_g,color_b;

    GLfloat Verts[8][3];

public :
    GLdouble m_mRotate[16];
    CWall(float w=0.0, float h=0.0, float d=0.0);

    void init();
    void setSize(float w, float h, float d);
    void setCenter(float x, float y, float z);
    void setColor(float r, float g, float b);
    bool hasIntersected(CSphere& ball);
    void hitBy(CSphere& ball);
    void draw();
};

#endif /* CWall_hpp */
