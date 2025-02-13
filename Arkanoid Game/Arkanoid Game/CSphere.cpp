//
//  CSphere.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION

#include <math.h>
#include "CSphere.hpp"
#include "sources.hpp"
#include <iostream>
using namespace std;


#if __linux__ 
  #include <GL/glut.h>
#elif _WIN32
  cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  #include <GLUT/glut.h>
#endif

CSphere:: CSphere()
{
    center_x=center_y=center_z=0.0;
}

void CSphere::init()
{
    // std::cout << "Test" << '\n';
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glGetDoublev(GL_MODELVIEW_MATRIX, m_mRotate);
    glPopMatrix();
}

void CSphere::setCenter(float x, float y, float z)
{
    center_x=x;    center_y=y;    center_z=z;
}

void CSphere::setColor(float r, float g, float b)
{
    color_r=r; color_g=g; color_b=b;
}

void CSphere::draw()
{
    glLoadIdentity();
    glTranslatef(0.0,0.0,-sdepth);
    glMultMatrixd(m_mRotate);
    glTranslated(center_x,center_y,center_z);
    glColor3f(color_r, color_g, color_b);
    glutSolidSphere(0.5,20,16);
}

bool CSphere::hasIntersected(CSphere& ball, int i ) {
    float distance= sqrt(pow(center_x - ball.center_x, 2) + pow(center_z - ball.center_z, 2));
    
    if (distance <= 2 *SPHERE_RADIUS) {
        return true;
    }
    return false;
} 

void CSphere::hitBy(CSphere& ball) {
    dir_x = center_x - ball.center_x;
    dir_z = center_z - ball.center_z;
}
