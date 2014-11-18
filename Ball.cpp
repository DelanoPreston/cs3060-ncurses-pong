/* 
 * File:   Ball.cpp
 * Author: mikewright
 * 
 * Created on August 14, 2014, 9:04 AM
 */

#include "Ball.h"
#include <stdlib.h>

Ball::Ball() {
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}

void Ball::Render() {
    
}

void Ball::Move(float x, float y) {
    if (isnan(x)) {
        x = rand() % 2 + 1;
        if (rand() % 2 == 0) {
            x = x * -1;
        }
    }
    if (isnan(y)) {
        y = rand() % 2 + 1;
        if (rand() % 2 == 0) {
            y = y * -1;
        }
    }
}

int Ball::GetX() { return _x; }
int Ball::GetY() { return _y; }
int Ball::GetUpperBound() { return _upperBound; }
int Ball::GetLowerBound() { return _lowerBound; }
