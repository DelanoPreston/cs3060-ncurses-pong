/* 
 * File:   Padle.cpp
 * Author: mikewright
 * 
 * Created on August 14, 2014, 9:03 AM
 */

#include "Paddle.h"
#include <ncurses.h>

Paddle::Paddle() { }
Paddle::Paddle(const Paddle& orig) { }
Paddle::~Paddle() { }

int Paddle::GetX() { return _x; }
int Paddle::GetY() { return _y; }
int Paddle::GetUpperBound() { return _upperBound; }
int Paddle::GetLowerBound() { return _lowerBound; }

void Paddle::Render() {
    Render(" ");
    _x = _nextX;
    _y = _nextY;
    Render("*");
}

void Paddle::Init(int x, int y, int upperBound, int lowerBound) {
    _x = _nextX = x;
    _y = _nextY = y;
    _upperBound = upperBound;
    _lowerBound = lowerBound;
}

void Paddle::Move(int distance) {
    if (_y + distance < _lowerBound || _y + distance + 6 > _upperBound) {
        return;
    }
    _nextY = _y + distance;
    _nextX = _x;
}

void Paddle::Render(const char* render) {
    for (int i = 0; i < PaddleSize; ++i) {
        mvaddstr(_y+i, _x, render);
    }
}


