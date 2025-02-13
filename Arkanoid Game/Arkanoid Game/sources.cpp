//
//  constants.cpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//
#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sources.hpp"
using namespace std;

#if defined(__linux__) // Or #if __linux__
  #include <GL/glut.h>
#elif _WIN32
  std::cout << "Windows" << '\n';
#else // MacOS, Xcode. 
  #include <GLUT/glut.h>
#endif


//GLdouble rotMatrix[4][16];

const int FLOOR_WIDTH = 15;
const int FLOOR_HEIGHT = 20;
const float SPHERE_RADIUS = 0.5;
const int NO_SPHERE = 50;
const int WALL_ID = 1000;

enum wallDirection {LEFT = 0, RIGHT, TOP};

CSphere g_user;
CSphere g_shooting_ball;
CSphere g_sphere[50];

CWall g_wall(FLOOR_WIDTH, 0.2, FLOOR_HEIGHT); // w, h, d // x, y, z
CWall g_walls[3] = {CWall(0.2, 1, FLOOR_HEIGHT), CWall(0.2, 1, FLOOR_HEIGHT), CWall(FLOOR_WIDTH, 1, 0.2)};

int rotate_x = 0, rotate_y = 0;
int choice = 1;
int life = 3;

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
float zNear = 1.0, zFar = 100.0;
float aspect = 5.0/4.0;
float xcam = 0, ycam = 0;
long xsize, ysize;
int downX, downY;
bool leftButton = false, middleButton = false, rightButton = false;
int i,j;
GLfloat light0Position[] = { 0, 15, -10, 1.0};
int displayMenu, mainMenu;
int space_flag = 0;
int currentTime, previousTime = -1;

void ReshapeCallback(int width, int height)
{
    xsize = width;
    ysize = height;
    aspect = (float)xsize/(float)ysize;
    glViewport(0, 0, xsize, ysize);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(64.0, aspect, zNear, zFar);
    gluLookAt(0,25,10, 0,0,-8, 0,1,0);
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
    for (i=0; i<NO_SPHERE; i++) g_sphere[i].draw();
    for (i=0; i<3; i++) g_walls[i].draw();
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
            
        case 32 : // SPACE_KEY
            if (space_flag) break; // 게임 시작했으면
            else {
                space_flag=1; // 게임 시작 전
                g_shooting_ball.dir_x = g_shooting_ball.center_x - g_user.center_x;
                g_shooting_ball.dir_y = g_shooting_ball.center_y - g_user.center_y;
                g_shooting_ball.dir_z = g_shooting_ball.center_z - g_user.center_z;
            }
            break;
            
            //        case 37 :  // LEFT ARROW
            //            cout << "<<<<case37" << endl;
            //            if (space_flag){// 게임 시작했으면
            //                g_user.center_x -= 1.0;
            //            }
            //            else {// 게임 시작 전
            //                g_user.center_x -= 1.0;
            //                g_shooting_ball.center_x -= 1.0;
            //            }
            //            break;
            //
            //        case 39 :
            //            if (space_flag){// 게임 시작했으면
            //                g_user.center_x += 1.0;
            //            }
            //            else {// 게임 시작 전
            //                g_user.center_x += 1.0;
            //                g_shooting_ball.center_x += 1.0;
            //            }
            //            break; // RIGHT ARROW
            
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
    
    if (id < NO_SPHERE) {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_sphere[id].m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_user.m_mRotate);
        glGetDoublev(GL_MODELVIEW_MATRIX, g_shooting_ball.m_mRotate);
    }
    
    if (id == WALL_ID) {
        glGetDoublev(GL_MODELVIEW_MATRIX, g_wall.m_mRotate);
        for (i=0; i<3; i++)  glGetDoublev(GL_MODELVIEW_MATRIX, g_walls[i].m_mRotate);
    }
    glPopMatrix();
}

void MotionCallback(int x, int y) {
    int tdx = x - downX;
    if (rightButton) {
        rotate_x += x-downX;
        rotate_y += y-downY;
        for (i=0; i<NO_SPHERE; i++) rotate(i);
        rotate(WALL_ID);
    } else if (leftButton) {
        if (space_flag){// 게임 시작했으면
            g_user.center_x = g_user.center_x + tdx/25.0;
        }
        else {// 게임 시작 전
            g_user.center_x = g_user.center_x + tdx/25.0;
            g_shooting_ball.center_x = g_shooting_ball.center_x + tdx/25.0;
        }
    }
    downX = x;   downY = y;
    glutPostRedisplay();
}

void initRotate() {
    for (i=0; i<NO_SPHERE; i++) g_sphere[i].init();
    for (i=0; i<3; i++) g_walls[i].init();
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

void detectCollision(){
    for (int i = 0; i<NO_SPHERE; i++){
        bool has_intersected = g_shooting_ball.hasIntersected(g_sphere[i] ,i);
        if(has_intersected) {
            g_shooting_ball.hitBy(g_sphere[i]);
            g_sphere[i].center_x = -999;
        }
    }
    
    for (int i = 0; i<3; i++){
        bool has_intersected = g_walls[i].hasIntersected(g_shooting_ball);
        if(has_intersected) g_walls[i].hitBy(g_shooting_ball);
    }
    
    if (g_shooting_ball.hasIntersected(g_user, 10)) {
        g_shooting_ball.hitBy(g_user);
    }
}

bool detectFalling(){
    if (g_shooting_ball.center_z >= FLOOR_HEIGHT/2 + SPHERE_RADIUS){
        return true;
    }
    return false;
}

void restartGame(){
    g_shooting_ball.setCenter(g_user.center_x, 0.0, g_user.center_z - SPHERE_RADIUS);
    space_flag = 0;
}

void MyIdleFunc(void) { glutPostRedisplay(); } /* things to do while idle */
void RunIdleFunc(void) { glutIdleFunc(MyIdleFunc); }
void PauseIdleFunc(void) { glutIdleFunc(NULL); }

void renderScene()
{
    int timeDelta;
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    if (previousTime == -1) timeDelta = 0;
    else timeDelta = currentTime - previousTime;
    float x = g_shooting_ball.center_x;
    float y = g_shooting_ball.center_y;
    float z = g_shooting_ball.center_z;
    
    detectCollision();
    if (detectFalling()){
        restartGame();
    }else{
        if (space_flag) {
            g_shooting_ball.setCenter(x+timeDelta*0.009*g_shooting_ball.dir_x,
                                      y+timeDelta*0.009*g_shooting_ball.dir_y,
                                      z+timeDelta*0.009*g_shooting_ball.dir_z);
        }
    }
    
    glutPostRedisplay();
    previousTime=currentTime;
    
}

void InitObjects()
{
    g_user.setColor(1.0, 1.0, 1.0); g_user.setCenter(0.0, 0.0, FLOOR_HEIGHT/2 - SPHERE_RADIUS);
    g_shooting_ball.setColor(1.0, 0.0, 0.0); g_shooting_ball.setCenter(0.0, 0.0, FLOOR_HEIGHT/2 - 3 * SPHERE_RADIUS);
    
    g_sphere[0].setCenter(-2.0, 0.0, -2.0);
    g_sphere[48].setCenter(-1.0, 0.0, -1.0);
    g_sphere[28].setCenter(-3.0, 0.0, -1.0);
    
    g_sphere[8].setCenter(2.0, 0.0, -2.0);
    g_sphere[49].setCenter(1.0, 0.0, -1.0);
    g_sphere[47].setCenter(3.0, 0.0, -1.0);
    
    g_sphere[1].setCenter(-3.0, 0.0, 6.0);
    g_sphere[2].setCenter(-2.0, 0.0, 6.0);
    g_sphere[3].setCenter(-1.0, 0.0, 6.0);
    g_sphere[4].setCenter(0.0, 0.0, 6.0);
    g_sphere[5].setCenter(1.0, 0.0, 6.0);
    g_sphere[6].setCenter(2.0, 0.0, 6.0);
    g_sphere[7].setCenter(3.0, 0.0, 6.0);
    
    g_sphere[9].setCenter(-4.0, 0.0, 5.0);
    g_sphere[10].setCenter(-5.0, 0.0, 4.0);
    g_sphere[11].setCenter(-5.0, 0.0, 3.0);
    g_sphere[12].setCenter(-5.0, 0.0, 2.0);
    g_sphere[13].setCenter(-5.0, 0.0, 1.0);
    g_sphere[14].setCenter(-5.0, 0.0, 0.0);
    g_sphere[15].setCenter(-5.0, 0.0, -1.0);
    g_sphere[16].setCenter(-5.0, 0.0, -2.0);
    g_sphere[17].setCenter(-5.0, 0.0, -3.0);
    
    g_sphere[18].setCenter(-4.0, 0.0, -4.0);
    g_sphere[19].setCenter(-3.0, 0.0, -5.0);
    g_sphere[20].setCenter(-2.0, 0.0, -5.0);
    g_sphere[21].setCenter(-1.0, 0.0, -5.0);
    g_sphere[22].setCenter(0.0, 0.0, -5.0);
    g_sphere[23].setCenter(1.0, 0.0, -5.0);
    g_sphere[24].setCenter(2.0, 0.0, -5.0);
    g_sphere[25].setCenter(3.0, 0.0, -5.0);
    g_sphere[26].setCenter(4.0, 0.0, -4.0);
    
    g_sphere[29].setCenter(0.0, 0.0, 1.0);
    g_sphere[30].setCenter(0.0, 0.0, 2.0);
    g_sphere[27].setCenter(-5.0, 0.0, -6.0);
    
    g_sphere[31].setCenter(5.0, 0.0, -3.0);
    g_sphere[32].setCenter(5.0, 0.0, -2.0);
    g_sphere[33].setCenter(5.0, 0.0, -1.0);
    g_sphere[34].setCenter(5.0, 0.0, 0.0);
    g_sphere[35].setCenter(5.0, 0.0, 1.0);
    g_sphere[36].setCenter(5.0, 0.0, 2.0);
    g_sphere[37].setCenter(5.0, 0.0, 3.0);
    g_sphere[38].setCenter(5.0, 0.0, 4.0);
    g_sphere[39].setCenter(4.0, 0.0, 5.0);
    
    g_sphere[40].setCenter(-3.0, 0.0, 3.0);
    g_sphere[41].setCenter(-2.0, 0.0, 4.0);
    g_sphere[42].setCenter(-1.0, 0.0, 4.0);
    g_sphere[43].setCenter(0.0, 0.0, 4.0);
    g_sphere[44].setCenter(1.0, 0.0, 4.0);
    g_sphere[45].setCenter(2.0, 0.0, 4.0);
    g_sphere[46].setCenter(3.0, 0.0, 3.0);
    
    g_wall.setColor(0.0, 0.6, 0.0); g_wall.setCenter(0.0, -0.6, 0.0);
    
    for (int i = 0; i<3; i++){
        g_walls[i].setColor(0.0,0.0,0.0);
    }
    for (int i = 0; i<NO_SPHERE; i++){
        g_sphere[i].setColor(0.7, 0.7, 0.1);
    }
    
    g_walls[LEFT].setCenter(-FLOOR_WIDTH/2, 0.0, 0.0);
    g_walls[RIGHT].setCenter(FLOOR_WIDTH/2, 0.0, 0.0);
    g_walls[TOP].setCenter(0.0, 0.0, -FLOOR_HEIGHT/2);
}
