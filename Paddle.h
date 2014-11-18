/* 
 * File:   Padle.h
 * Author: mikewright
 *
 * Created on August 14, 2014, 9:03 AM
 */

#ifndef PADLE_H
#define	PADLE_H

#include "IRenderable.h"

class Paddle : public IRenderable {
private:
    static const int PaddleSize = 6;
    int _x, _y, _nextX, _nextY;
    int _upperBound, _lowerBound;
    
public:
    Paddle();
    virtual ~Paddle();
    void Init(int x, int y, int upperBound, int lowerBound);
    void Move(int distance);
    
    virtual void Render();
    virtual int GetX();
    virtual int GetY();
    virtual int GetUpperBound();
    virtual int GetLowerBound();
    
private:
    void Render(const char* render);
    Paddle(const Paddle& orig);        
};

#endif	/* PADLE_H */

