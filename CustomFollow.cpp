//  CustomFollow.cpp
//
//  Created by rinov.
//

#include "CustomFollow.h"

USING_NS_CC;

CustomFollow::CustomFollow(){
    _type = ScrollType::Default;
    _margin = Rect::ZERO;
}

CustomFollow::~CustomFollow(){
    CC_SAFE_RELEASE_NULL(_followedNode);
}

CustomFollow* CustomFollow::create(Node* followNode){
    CustomFollow *follow = new CustomFollow();
    if (follow && follow->initWithTarget(followNode, Rect::ZERO))
    {
        follow->autorelease();
        return follow;
    }
    if(follow){
        delete follow;
        follow=nullptr;
    }

    return nullptr;
}

CustomFollow* CustomFollow::create(Node* followNode,ScrollType type){
    CustomFollow *follow = new CustomFollow();
    follow->_type = type;
    if (follow && follow->initWithTarget(followNode, Rect::ZERO))
    {
        follow->autorelease();
        return follow;
    }
    if(follow){
        delete follow;
        follow=nullptr;
    }
    return nullptr;
}

void CustomFollow::step(float dt)
{
    CC_UNUSED_PARAM(dt);
    
    if(_boundarySet){
        
        if(_boundaryFullyCovered){
            return;
        }
        
        Point t = _halfScreenSize - _followedNode->getPosition();
        
        float x = clampf(t.x, _leftBoundary, _rightBoundary);
        float y = clampf(t.y, _bottomBoundary, _topBoundary);
        
        if(_type == ScrollType::OnlyX){
            y = _target->getPositionY();
        }
        else if (_type == ScrollType::OnlyY){
            x = _target->getPositionX();
        }
        
        _target->setPosition(Point(x , y));
        
    }else{
        
        Point p = _target->convertToWorldSpace(_followedNode->getPosition());
        
        if(_margin.containsPoint(p)){
            return;
        }
        
        float x = _halfScreenSize.x - _followedNode->getPositionX();
        float y = _halfScreenSize.y - _followedNode->getPositionY();
        
        if(_type == ScrollType::OnlyX){
            y = _target->getPositionY();
        }
        else if (_type == ScrollType::OnlyY){
            x = _target->getPositionX();
        }
        
        _target->setPosition(Point(x , y));
    }
}
