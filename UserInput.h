/* 
 * File:   UserInput.h
 * Author: mikewright
 *
 * Created on August 14, 2014, 4:10 PM
 */

#ifndef USERINPUT_H
#define	USERINPUT_H

enum InputKey {
    None,
    Up, 
    Down, 
    Start,
    Quit
};

class UserInput {
public:
    UserInput();
    virtual ~UserInput();
    InputKey ReadInput();
private:
    UserInput(const UserInput& orig);

};

#endif	/* USERINPUT_H */

