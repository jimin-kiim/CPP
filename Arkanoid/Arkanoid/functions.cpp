//
//  functions.cpp
//  Arkanoid
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include <stdlib.h>
#include "functions.hpp"
//#include "CWall.hpp"
//#include "CSphere.hpp"
#include "constants.hpp"

void ReshapeCallback(int width, int height)
{
    xsize = width;
    ysize = height;
    aspect = (float)xsize/(float)ysize;
    glViewport(0, 0, xsize, ysize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(64.0, aspect, zNear, zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void DisplayCallback(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    for (i=0;i<NO_SPHERE;i++) g_sphere[i].draw();
    g_wall.draw();

    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void KeyboardCallback(unsigned char ch, int x, int y)
{
    switch (ch)
    {
    case '1' : choice=1; break;
    case '2' : choice=2; break;
    case '3' : choice=3; break;

    case 32 :
        if (space_flag) space_flag=0;
        else {
            space_flag=1;
            g_sphere[0].dir_x = g_sphere[2].center_x - g_sphere[0].center_x;
            g_sphere[0].dir_y = g_sphere[2].center_y - g_sphere[0].center_y;
            g_sphere[0].dir_z = g_sphere[2].center_z - g_sphere[0].center_z;
        }
        break; // SPACE_KEY

    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void MouseCallback(int button, int state, int x, int y)
{
    downX = x; downY = y;
    leftButton = ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN));
    middleButton = ((button == GLUT_MIDDLE_BUTTON) &&  (state == GLUT_DOWN));
    rightButton = ((button == GLUT_RIGHT_BUTTON) &&  (state == GLUT_DOWN));
    glutPostRedisplay();
}

void rotate(int id)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRotated(((double)rotate_y), 1.0, 0.0, 0.0);
    glRotated(((double)rotate_x), 0.0, 1.0, 0.0);

    if (id<NO_SPHERE) {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_sphere[id].m_mRotate);
    }

    if (id==WALL_ID) {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wall.m_mRotate);
    }
    glPopMatrix();
}

void MotionCallback(int x, int y) {
    int tdx=x-downX,tdy=0,tdz=y-downY,id=choice-1;
    if (leftButton) {
        rotate_x += x-downX;
        rotate_y += y-downY;
        for (i=0;i<NO_SPHERE;i++) rotate(i);
        rotate(WALL_ID);
    } else if (rightButton) {
        if (id<NO_SPHERE) g_sphere[id].setCenter(g_sphere[id].center_x+tdx/100.0,g_sphere[id].center_y+tdy/100.0,g_sphere[id].center_z+tdz/100.0);
    }
    downX = x;   downY = y;
    glutPostRedisplay();
}

void initRotate() {
    g_sphere[0].init();
    g_sphere[1].init();
    g_sphere[2].init();
    g_wall.init();
}

void InitGL() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("OpenGL Applications");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.7, 0.7, 0.7, 0.0);
    glPolygonOffset(1.0, 1.0);
    glDisable(GL_CULL_FACE);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glLightfv (GL_LIGHT0, GL_POSITION, light0Position);
    glEnable(GL_LIGHT0);
    initRotate();

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);

    glutIdleFunc(renderScene);
    glutReshapeFunc(ReshapeCallback);
    glutDisplayFunc(DisplayCallback);
    glutKeyboardFunc(KeyboardCallback);
    glutMouseFunc(MouseCallback);
    glutMotionFunc(MotionCallback);
}

void renderScene()
{
    int timeDelta;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    if (previousTime==-1) timeDelta=0;
    else timeDelta = currentTime - previousTime;
    float x=g_sphere[0].center_x;
    float y=g_sphere[0].center_y;
    float z=g_sphere[0].center_z;

    if (space_flag) g_sphere[0].setCenter(
        x+timeDelta*0.002*g_sphere[0].dir_x,
        y+timeDelta*0.002*g_sphere[0].dir_y,
        z+timeDelta*0.002*g_sphere[0].dir_z);
    glutPostRedisplay();
    previousTime=currentTime;

}

void InitObjects()
{
    // specify initial colors and center positions of each spheres
    g_sphere[0].setColor(0.8,0.2,0.2); g_sphere[0].setCenter(0.0,0.0,0.0);
    g_sphere[1].setColor(0.2,0.8,0.2); g_sphere[1].setCenter(1.0,0.0,0.0);
    g_sphere[2].setColor(0.2,0.2,0.8); g_sphere[2].setCenter(0.0,0.0,1.0);

    // specify initial colors and center positions of a wall
    g_wall.setColor(0.0,1.0,0.0); g_wall.setCenter(0.0,-0.6,0.0);
}
