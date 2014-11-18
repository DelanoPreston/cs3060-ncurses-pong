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
    int _x, _y, _upperBound, _lowerBound;
    
public:
    Ball();
    Ball(const Ball& orig);
    virtual ~Ball();

    virtual void Render();
    virtual int GetX();
    virtual int GetY();
    virtual int GetUpperBound();
    virtual int GetLowerBound();
    
    void Init(int x, int y, int upperBound, int lowerBound);
    void Move(float x=NAN, float y=NAN);
};

#endif	/* BALL_H */

