//
//  GameSelectLayer.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/03.
//
//

#ifndef GameSelectLayer_hpp
#define GameSelectLayer_hpp

#include <stdio.h>
#include "Constants.h"
#include "InputLayer.hpp"

class CGameSelectLayer0 : public CInputLayer {
public :
    CGameSelectLayer0(){}
    ~CGameSelectLayer0(){}
    
    virtual bool init() override {
        if(CInputLayer::init() == false) return false ;
        cocos2d::Sprite* pSprite = cocos2d::Sprite::create() ;
        pSprite->setTexture("test1.png") ;
        pSprite->setPosition(320.0f, 240.0f) ;
        this->addChild(pSprite) ;
        return true ;
    }
    
    virtual void update(float deltaTime_) override {
        CCLOG("LAYER_NO : 0") ;
        if(inputflag.m_z.isInput() == true){
            CCLOG("LAYER_NO : 0 pressed") ;
        }
    }
};

class CGameSelectLayer1 : public CInputLayer {
public :
    CGameSelectLayer1(){}
    ~CGameSelectLayer1(){}
    
    virtual bool init() override {
        if(CInputLayer::init() == false) return false ;
        cocos2d::Sprite* pSprite = cocos2d::Sprite::create() ;
        pSprite->setTexture("test2.png") ;
        pSprite->setPosition(320.0f, 240.0f) ;
        this->addChild(pSprite) ;
        return true ;
    }
    
    virtual void update(float deltaTime_) override {
        CCLOG("LAYER_NO : 1") ;
        if(inputflag.m_z.isInput() == true){
            CCLOG("LAYER_NO : 1 pressed") ;
        }
    }
};

#endif /* GameSelectLayer_hpp */
