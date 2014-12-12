/* 
 * File:   Game.cpp
 * Author: mikewright
 * 
 * Created on August 14, 2014, 9:04 AM
 */

#include "Game.h"
#include "CursesColors.h"
#include <stdio.h>
#include <unistd.h>     
#include <stdlib.h>

Game::Game(const Game& orig) {}

Game::Game() {
    _width = 90;
    _height = 30;
    _paddleMin = 4;
    _paddleMax = _height - 7;
    _ballMove = 15000;
}

Game::~Game() {
    Destroy();
}

void Game::Play() {
    Initialize();
    while (_playing) {
        Loop();
    }
}

void Game::Initialize() {
    /*  Initialize ncurses  */
    if ((_mainwin = initscr()) == NULL ) {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }
    start_color();
    noecho();
    curs_set(0);
    RenderBoard();

    _gameBall.Init(45, 15, 2, _height);
    _userPaddle.Init(3, 10, _height, 3);
    _cpuPaddle.Init(_width-3, 10, _height, 3);
    _playing = true;
    _ballMoving = false;
    _userScore = _cpuScore = 0;
}

void Game::Destroy() {
    /*  Clean up after ourselves  */
    if (_mainwin) {
        delwin(_mainwin);
        endwin();
        refresh();
    }
}

void Game::Loop() {    
    InputKey key = _input.ReadInput();
    switch (key) {
        case Quit:
            _playing = false;
            break;
        case Up:
            _userPaddle.Move(-1);
            break;
        case Down:
            _userPaddle.Move(1);
            break;
        case Start:
            _ballMoving = true;
        default:
            break;
    }
    
    if(_ballMoving){
        if(_ballTimer >= _ballMove){    
            if(_gameBall.GetX() <= 1){
                //give cpu player a point
                _cpuScore = _cpuScore + 1;
                _gameBall.ResetPosition(45, 15);
                _ballMoving = false;
            }
            if(_gameBall.GetX() >= _width - 1){
                //git player a point
                _userScore = _userScore + 1;
                _gameBall.ResetPosition(45, 15);
                _ballMoving = false;
            }
            if(_gameBall.GetX() == 4){
                if(_gameBall.GetY() > _userPaddle.GetY() - 1 && _gameBall.GetY() < _userPaddle.GetY() + 7){
                    _gameBall.BounceHorizontal();
                }
            }
            if(_gameBall.GetX() == _width - 4){
                if(_gameBall.GetY() > _cpuPaddle.GetY() - 1 && _gameBall.GetY() < _cpuPaddle.GetY() + 7){
                    _gameBall.BounceHorizontal();
                }
            }
            _gameBall.Move();
            _ballTimer = 0;
            
            //cpu paddle stuff
            if(_gameBall.GetX() >= _width * 7 / 8 && !_gameBall.MovingLeft()){
                if(_gameBall.GetY() - 3 > _cpuPaddle.GetY()){
                    _cpuPaddle.Move(1);
                }
                if(_gameBall.GetY() - 3 < _cpuPaddle.GetY()){
                    _cpuPaddle.Move(-1);
                } 
            }
        }
        _ballTimer++;
    }
    //clear();
//    RenderBoard();
    RenderScore();
    _gameBall.Render();
    _userPaddle.Render();
    _cpuPaddle.Render();
    //refresh();
}

void Game::RenderBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int k = 0; k <= _width; ++k) {
            if (k == 0 || k == 15 || k == _width || k == _width - 15) {
                mvaddstr(i, k, "|");
            } else if (i == 0 || i == 2) {
                mvaddstr(i, k, "-");
            } 
        }
    }
    
    for (int i = 3; i < _height; ++i) {
        mvaddstr(i, 0, "|");
        mvaddstr(i, _width, "|");
    }
    
    mvaddstr(_height, 0, "|");
    for (int i = 1; i <= _width-1; ++i) {
        mvaddstr(_height, i, "-");
    }
    mvaddstr(_height, _width, "|");
}

void Game::RenderScore() {
    mvaddstr(1, 7, "   ");
    mvaddstr(1, _width-8, "   ");
    char buffer[10];
    sprintf(buffer, "%d", _userScore);
    mvaddstr(1, 7, buffer);
    sprintf(buffer, "%d", _cpuScore);
    mvaddstr(1, _width-8, buffer);    
}
