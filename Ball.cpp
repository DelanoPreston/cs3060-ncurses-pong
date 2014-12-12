/* 
 * File:   Ball.cpp
 * Author: mikewright
 * 
 * Created on August 14, 2014, 9:04 AM
 */

#include "Ball.h"
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

Ball::Ball() {
}


void Ball::Init(int x, int y, int upperBound, int lowerBound, int leftBound, int rightBound){
    _x = x;
    _xLast = x + 1;
    _y = y;
    _yLast = y + 1;
    _upperBound = upperBound;
    _lowerBound = lowerBound;
    _leftBound = leftBound;
    _rightBound = rightBound;
    _xDir = rand() % 2 + 1;
    if (rand() % 2 == 0) {
        _xDir = _xDir * -1;
    }
    _yDir = rand() % 2 + 1;
    if (rand() % 2 == 0) {
        _yDir = _yDir * -1;
    }
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}

void Ball::Render() { 
    mvaddstr(_yLast, _xLast, " ");
    mvaddstr(_y, _x, "*");
}

void Ball::Move(float x, float y) {
    _xLast = _x;
    _yLast = _y;

    if(_x + _xDir >= _rightBound || _x + _xDir <= _leftBound){
        _xDir = _xDir * -1;
    }
    if(_y + _yDir <= _upperBound || _y + _yDir >= _lowerBound){
        _yDir = _yDir * -1;
    }

    _x = _x + _xDir;
    _y = _y + _yDir;
}
int Ball::GetX() { return _x; }
int Ball::GetY() { return _y; }
int Ball::GetUpperBound() { return _upperBound; }
int Ball::GetLowerBound() { return _lowerBound; }
