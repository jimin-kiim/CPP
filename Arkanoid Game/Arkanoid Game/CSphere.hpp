//
//  CSphere.hpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION

#ifndef CSphere_hpp
#define CSphere_hpp

#include <stdio.h>

#if __linux__ 
  #include <GL/glut.h>
#elif _WIN32
  std::cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  #include <GLUT/glut.h>
#endif

class CSphere
{
public:
    float center_x, center_y, center_z;
    float color_r, color_g, color_b;
    float dir_x, dir_y, dir_z;
    float speed;

public :
    GLdouble m_mRotate[16];
    CSphere();

    void init();
    void setCenter(float x, float y, float z);
    void setColor(float r, float g, float b);
    bool hasIntersected(CSphere& ball, int i);
    void hitBy(CSphere& ball);
    void draw();
};

#endif /* CSphere_hpp */
