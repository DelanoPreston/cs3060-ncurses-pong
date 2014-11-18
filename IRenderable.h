/* 
 * File:   IRenderable.h
 * Author: mikewright
 *
 * Created on August 14, 2014, 3:46 PM
 */

#ifndef IRENDERABLE_H
#define	IRENDERABLE_H

class IRenderable {
public:
    virtual void Render() = 0;
    virtual int GetX() = 0; 
    virtual int GetY() = 0;
    virtual int GetUpperBound() = 0;
    virtual int GetLowerBound() = 0;
};

#endif	/* IRENDERABLE_H */

