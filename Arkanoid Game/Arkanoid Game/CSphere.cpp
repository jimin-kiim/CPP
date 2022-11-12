//
//  CSphere.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#include <GLUT/glut.h>
#include "CSphere.hpp"

class CSphere
{
public:
    float center_x, center_y, center_z;
    float color_r,color_g,color_b;
    float dir_x,dir_y,dir_z;
    float speed;

public :
    GLdouble m_mRotate[16];
    CSphere()
    {
        center_x=center_y=center_z=0.0;
    }

    void init()
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glGetDoublev(GL_MODELVIEW_MATRIX, m_mRotate);
        glPopMatrix();
    }

    void setCenter(float x, float y, float z)
    {
        center_x=x;    center_y=y;    center_z=z;
    }

    void setColor(float r, float g, float b)
    {
        color_r=r; color_g=g; color_b=b;
    }

    void draw()
    {
        glLoadIdentity();
        glTranslatef(0.0,0.0,-sdepth);
        glMultMatrixd(m_mRotate);
        glTranslated(center_x,center_y,center_z);
        glColor3f(color_r, color_g, color_b);
        glutSolidSphere(0.5,20,16);
    }
};
