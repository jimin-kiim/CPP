//
//  Cwall.cpp
//  Arkanoid
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "CWall.hpp"
#include "constants.hpp"

CWall::CWall(float w, float h, float d)
{
    width=w; height=h; depth=d;
    color_r=0.0; color_g=1.0; color_b=0.0;
    
    int i,j;
    float coef;
    for (i=0;i<8;i++) {
        for (j=0;j<3;j++) {
            if (j==0) coef=w/2.0;
            if (j==1) coef=h/2.0;
            if (j==2) coef=d/2.0;
            Verts[i][j]=coef*BoxVerts[i][j];
        }
    }
}

void CWall::init()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glGetDoublev(GL_MODELVIEW_MATRIX, m_mRotate);
    glPopMatrix();
}

void CWall::setSize(float w, float h, float d)
{
    width=w;
    height=h;
    depth=d;
}

void CWall::setCenter(float x, float y, float z)
{
    center_x=x;    center_y=y;    center_z=z;
}

void CWall::setColor(float r, float g, float b)
{
    color_r=r; color_g=g; color_b=b;
}

void CWall::draw()
{
    glLoadIdentity();
    glTranslatef(0.0,0.0,-sdepth);
    glMultMatrixd(m_mRotate);
    glTranslatef(center_x,center_y,center_z);
    
    glColor3f(color_r, color_g, color_b);
    
    int i;
    int v1,v2,v3,v4;
    
    for (i = 0 ; i < 6 ; i++) {
        v1 = cubeIndices[i][0];
        v2 = cubeIndices[i][1];
        v3 = cubeIndices[i][2];
        v4 = cubeIndices[i][3];

        glBegin (GL_QUADS) ;
        glNormal3f( bNorms[i][0],bNorms[i][1],bNorms[i][2]);
        glVertex3f( Verts[v1][0],Verts[v1][1],Verts[v1][2]);
        glNormal3f( bNorms[i][0],bNorms[i][1],bNorms[i][2]);
        glVertex3f( Verts[v2][0],Verts[v2][1],Verts[v2][2]);
        glNormal3f( bNorms[i][0],bNorms[i][1],bNorms[i][2]);
        glVertex3f( Verts[v3][0],Verts[v3][1],Verts[v3][2]);
        glNormal3f( bNorms[i][0],bNorms[i][1],bNorms[i][2]);
        glVertex3f( Verts[v4][0],Verts[v4][1],Verts[v4][2]);
        glEnd () ;
    }
}

