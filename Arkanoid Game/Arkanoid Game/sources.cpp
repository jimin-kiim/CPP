//
//  constants.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//

#define SPHERE_RADIUS 0.5
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sources.hpp"
using namespace std;
//GLdouble rotMatrix[4][16];

CSphere g_user;
CSphere g_shooting_ball;
CSphere g_sphere[45];
CWall g_wall(15,0.2,20); // w, h, d // x, y z
CWall g_walls[3] = {CWall(0.2,5,20),CWall(0.2,5,20),CWall(15,5,0.2)};

const int NO_SPHERE=3;
const int WALL_ID=1000;
int rotate_x=0, rotate_y=0;
int choice=1;

GLfloat BoxVerts[][3] = {
    {-1.0,-1.0,-1.0},
    {-1.0,-1.0,1.0},
    {-1.0,1.0,-1.0},
    {-1.0,1.0,1.0},
    {1.0,-1.0,-1.0},
    {1.0,-1.0,1.0},
    {1.0,1.0,-1.0},
    {1.0,1.0,1.0}
};

GLfloat bNorms[][3] = {
    {-1.0,0.0,0.0},
    {1.0,0.0,0.0},
    {0.0,1.0,0.0},
    {0.0,-1.0,0.0},
    {0.0,0.0,-1.0},
    {0.0,0.0,1.0}
};

int cubeIndices[][4] = {
    {0,1,3,2},
    {4,6,7,5},
    {2,3,7,6},
    {0,4,5,1},
    {0,2,6,4},
    {1,5,7,3}
};

/* Viewer state */
float sdepth = 10;
float zNear=1.0, zFar=100.0;
float aspect = 5.0/4.0;
float xcam = 0, ycam = 0;
long xsize, ysize;
int downX, downY;
bool leftButton = false, middleButton = false, rightButton = false;
int i,j;
GLfloat light0Position[] = { 0, 1, 0, 1.0};
int displayMenu, mainMenu;
int space_flag=0;
int currentTime, previousTime=-1;

void ReshapeCallback(int width, int height)
{
    xsize = width;
    ysize = height;
    aspect = (float)xsize/(float)ysize;
    glViewport(0, 0, xsize, ysize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(64.0, aspect, zNear, zFar);
    gluLookAt(0,15,10, 0,5,0, 0,1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void DisplayCallback(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    g_user.draw();
    g_shooting_ball.draw();
    for (i=0;i<NO_SPHERE;i++) g_sphere[i].draw();
    for (i=0;i<3;i++) g_walls[i].draw();
    g_wall.draw();
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//CSphere g_user;
//CSphere g_shooting_ball;
void KeyboardCallback(unsigned char ch, int x, int y)
{
    switch (ch)
    {
        case '1' :
            cout << "<<<<case1" << endl;
            choice=1;
            break;
        case '2' : choice=2; break;
        case '3' : choice=3; break;
            
        case 32 :
            if (space_flag) break;
            else {
                space_flag=1;
//                g_shooting_ball.dir_x = g_user.center_x - g_shooting_ball.center_x;
//                g_shooting_ball.dir_y = g_user.center_y - g_shooting_ball.center_y;
//                g_shooting_ball.dir_z = g_user.center_z - g_shooting_ball.center_z;
                g_shooting_ball.dir_x = g_shooting_ball.center_x - g_user.center_x;
                g_shooting_ball.dir_y = g_shooting_ball.center_y - g_user.center_y;
                g_shooting_ball.dir_z = g_shooting_ball.center_z - g_user.center_z;
            }
            break; // SPACE_KEY
            
        case 37 :
            g_user.center_x -= 1.0;
            g_shooting_ball.center_x -= 1.0;
            
            break; // LEFT ARROW
            
        case 39 :
            g_user.center_x += 1.0;
            g_shooting_ball.center_x += 1.0;
            break; // RIGHT ARROW
            
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

//CSPhere g_user;
//CSPhere g_shooting_ball;

void rotate(int id)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glRotated(((double)rotate_y), 1.0, 0.0, 0.0);
    glRotated(((double)rotate_x), 0.0, 1.0, 0.0);
    
    if (id<NO_SPHERE) {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_sphere[id].m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_user.m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_shooting_ball.m_mRotate);
    }
    
    if (id==WALL_ID) {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wall.m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_walls[0].m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_walls[1].m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_walls[2].m_mRotate);
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
//CSPhere g_user;
//CSPhere g_shooting_ball;
void initRotate() {
    for (i=0;i<NO_SPHERE;i++) g_sphere[i].init();
    for (i=0;i<3;i++) g_walls[i].init();
    g_wall.init();
    g_user.init();
    g_shooting_ball.init();
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
//CSphere g_user;
//CSphere g_shooting_ball;
//CSphere g_sphere[45];
//CWall g_wall(20,0.2,15); // w, h, d
//CWall g_walls[3] = {CWall(20,5,0.2),CWall(20,5,0.2),CWall(0.2,5,15)};

void detectCollision(){
//    cout << "detectCollision";
    for (int i = 0; i<3; i++){
        bool has_intersected = g_shooting_ball.hasIntersected(g_sphere[i] ,i);
        if(has_intersected) {
            g_shooting_ball.hitBy(g_sphere[i]);
            g_sphere[i].center_x = -999;
        }
    }
    
    for (int i = 1; i<3; i++){
        bool has_intersected = g_walls[i].hasIntersected(g_shooting_ball);
//        cout << has_intersected << endl;
        if(has_intersected) g_walls[i].hitBy(g_shooting_ball);
    }
    
    if (g_shooting_ball.hasIntersected(g_user, 10)) {
        g_shooting_ball.hitBy(g_user);
    }
    
}

void MyIdleFunc(void) { glutPostRedisplay();} /* things to do while idle */
void RunIdleFunc(void) {   glutIdleFunc(MyIdleFunc); }
void PauseIdleFunc(void) {   glutIdleFunc(NULL); }


//CSPhere g_user;
//CSPhere g_shooting_ball;
void renderScene()
{
    int timeDelta;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    if (previousTime==-1) timeDelta=0;
    else timeDelta = currentTime - previousTime;
    float x=g_shooting_ball.center_x;
    float y=g_shooting_ball.center_y;
    float z=g_shooting_ball.center_z;
//    cout << x << endl;
    detectCollision();
    if (space_flag) {
        g_shooting_ball.setCenter(x+timeDelta*0.002*g_shooting_ball.dir_x,
                              y+timeDelta*0.002*g_shooting_ball.dir_y,
                              z+timeDelta*0.002*g_shooting_ball.dir_z);
//        g_user.setCenter(x+timeDelta*0.002*g_user.dir_x,
//                         y+timeDelta*0.002*g_user.dir_y,
//                         z+timeDelta*0.002*g_user.dir_z);
//        g_shooting_ball.setCenter(x+timeDelta*0.002*g_shooting_ball.dir_x,
//                                  y+timeDelta*0.002*g_shooting_ball.dir_y,
//                                  z+timeDelta*0.002*g_shooting_ball.dir_z);
    }
        
    glutPostRedisplay();
    previousTime=currentTime;
    
}

//CSPhere g_user;
//CSPhere g_shooting_ball;
void InitObjects()
{
    g_user.setColor(0.0, 0.0, 1.0); g_user.setCenter(0.0, 0.0, 10.0-SPHERE_RADIUS);
    g_shooting_ball.setColor(1.0, 0.0, 0.0); g_shooting_ball.setCenter(0.0, 0.0, 10.0- 3*SPHERE_RADIUS);
    g_sphere[0].setColor(0.8, 0.2, 0.2); g_sphere[0].setCenter(-2.0, 0.0, 6.0);
    g_sphere[1].setColor(0.2, 0.8, 0.2); g_sphere[1].setCenter(0.0, 0.0, -1.0);
    g_sphere[2].setColor(0.2, 0.2, 0.8); g_sphere[2].setCenter(1.0, 0.0, 0.0);
    
    // specify initial colors and center positions of a wall
    g_wall.setColor(0.0,0.6,0.0); g_wall.setCenter(0.0,-0.6,0.0);
    
    for (int i = 0; i<3; i++){
        g_walls[i].setColor(0.0,0.6,0.0);
    }
    
    g_walls[0].setCenter(-7.5,0.0,0.0);
    g_walls[1].setCenter(7.5,0.0,0.0);
    g_walls[2].setCenter(0.0,0.0,-10.0);
}
