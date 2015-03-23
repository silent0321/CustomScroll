//  CustomFllow.h
//
//  Created by rinov.
//

#ifndef __COCOS2DX__CustomFollow__
#define __COCOS2DX__CustomFollow__

#include "cocos2d.h"

enum class ScrollType{
    OnlyX,
    OnlyY,
    Default,
};

class CustomFollow : public cocos2d::Follow
{
public:
    
    static CustomFollow* create(cocos2d::Node *followedNode);
    static CustomFollow* create(cocos2d::Node *followedNode,ScrollType type);
    virtual void step(float dt) override;

private:

    CustomFollow();
    virtual ~CustomFollow();
    ScrollType _type;
    cocos2d::Rect _margin;

};

#endif
