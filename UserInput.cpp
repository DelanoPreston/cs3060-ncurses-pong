/* 
 * File:   UserInput.cpp
 * Author: mikewright
 * 
 * Created on August 14, 2014, 4:10 PM
 */
#include "UserInput.h"
#include <curses.h>

UserInput::UserInput() {
}

UserInput::UserInput(const UserInput& orig) {
}

UserInput::~UserInput() {
}

InputKey UserInput::ReadInput() {
    timeout(0);
    int input = getch();
    switch (input) {
        case 'Q':
            return Quit;
        case 'i':
        case 'I':
            return Up;
        case 'k':
        case 'K':
            return Down;
        case 'S':
        case 's':
            return Start;
        default:
            return None;
    }
    //if (input != -1) {
}
