//
//  CSphere.hpp
//  Arkanoid Game
//
//  Created by 김지민 on 2022/11/12.
//

#ifndef CSphere_hpp
#define CSphere_hpp

#include <stdio.h>

class CSphere
{
public:
    float center_x, center_y, center_z; // 현재 위치
    float color_r,color_g,color_b;
    float dir_x,dir_y,dir_z; // 속도
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
