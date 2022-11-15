//
//  CSphere.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include "CSphere.hpp"
#include "sources.hpp"

CSphere:: CSphere()
{
    center_x=center_y=center_z=0.0;
}

void CSphere::init()
{
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

bool CSphere::hasIntersected(CSphere& ball) {
    float distance= pow(pow(this->center_x - ball.center_x,2) + pow(this->center_y - ball.center_y,2),1/2);
    if (distance == 1) {
        return true;
    }
    return false;
    // 본인 중심 & 가까운 공의 중심 거리가 지름이랑 같으면 true. 아니면 false
} // check if there is collision between two spheres

void CSphere::hitBy(CSphere& ball) {
    this->dir_x = this->center_x - ball.center_x;
    this->dir_y = this->center_y - ball.center_y;
    this->dir_z = this->center_z - ball.center_z;
} // what needs to be done if there is collision between two spheres.
