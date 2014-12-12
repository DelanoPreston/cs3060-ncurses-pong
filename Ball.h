/* 
 * File:   Ball.h
 * Author: mikewright
 *
 * Created on August 14, 2014, 9:04 AM
 */

#ifndef BALL_H
#define	BALL_H

#include "IRenderable.h"
#include <math.h>

class Ball : public IRenderable {
private:
    int _x, _y, _xLast, _yLast, _xDir, _yDir, _upperBound, _lowerBound;
    
public:
    Ball();
    Ball(const Ball& orig);
    void Init(int x, int y, int upperBound, int lowerBound);
    virtual ~Ball();
    
    
    virtual void Render();
    void BounceVertical();
    void BounceHorizontal();
    bool MovingLeft();
    void ResetPosition(int x, int y);
    virtual int GetX();
    virtual int GetY();
    virtual int GetUpperBound();
    virtual int GetLowerBound();
    
    void Move();
};

#endif	/* BALL_H */

