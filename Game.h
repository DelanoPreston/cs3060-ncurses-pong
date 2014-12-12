/* 
 * File:   Game.h
 * Author: mikewright
 *
 * Created on August 14, 2014, 9:04 AM
 */

#ifndef GAME_H
#define	GAME_H

#include <curses.h>

#include "Ball.h"
#include "Paddle.h"
#include "UserInput.h"

class Game {
private:
    Ball _gameBall;
    Paddle _userPaddle;
    Paddle _cpuPaddle;
    UserInput _input;
    WINDOW* _mainwin;
    bool _playing, _ballMoving;
    int _userScore, _cpuScore, _ballTimer, _ballMove;
    int _width, _height, _paddleMin, _paddleMax;
    
public:
    Game();
    virtual ~Game();
    
    void Play();
    
private:
    Game(const Game& orig);

    void RenderScore();
    void RenderBoard();
    void Initialize();
    void Destroy();
    void Loop();
};

#endif	/* GAME_H */

