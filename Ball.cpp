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


void Ball::Init(int x, int y, int upperBound, int lowerBound){
    _x = x;
    _y = y;
    ResetPosition(x, y);
    _xLast = x + 1;
    _yLast = y + 1;
    _upperBound = upperBound;
    _lowerBound = lowerBound;
}

Ball::Ball(const Ball& orig) {
}

Ball::~Ball() {
}

void Ball::Render() { 
    mvaddstr(_y, _x, "*");
    mvaddstr(_yLast, _xLast, " ");
}

void Ball::Move() {
    _xLast = _x;
    _yLast = _y;

    if(_y + _yDir <= _upperBound || _y + _yDir >= _lowerBound){
        BounceVertical();
    }

    _x = _x + _xDir;
    _y = _y + _yDir;
}
void Ball::BounceVertical() { _yDir = _yDir * -1; }
void Ball::BounceHorizontal() { _xDir = _xDir * -1;}

bool Ball::MovingLeft(){
    if(_xDir < 0){
        return true;
    }
    return false;
}
void Ball::ResetPosition(int x, int y){
    _xLast = _x;
    _yLast = _y;
    _x = x;
    _y = y;
    _xDir = 1;
    if (rand() % 2 == 0) {
        _xDir = _xDir * -1;
    }
    _yDir = 1;
    if (rand() % 2 == 0) {
        _yDir = _yDir * -1;
    }
}

int Ball::GetX() { return _x; }
int Ball::GetY() { return _y; }
int Ball::GetUpperBound() { return _upperBound; }
int Ball::GetLowerBound() { return _lowerBound; }
