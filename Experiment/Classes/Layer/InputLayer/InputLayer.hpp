//
//  InputLayer.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/03.
//
//

#ifndef InputLayer_hpp
#define InputLayer_hpp

#include <stdio.h>

#include "InputManager.hpp"

class CInputLayer : public cocos2d::Layer {
public :
    CInputLayer(){}
    
    virtual ~CInputLayer(){}
    
    virtual bool init() override {
        if(cocos2d::Layer::init() == false) return false ;
        // キーボード入力イベント受け取り設定
        this->setKeyboardEnabled(true) ;
        
        return true ;
    }
    
    /**
     *	@desc	キーボードのキーを押した際のイベント
     *	@param	キーコード
     *	@param	イベント
     */
    virtual void onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event ) override {
        
        // 入力管理に入力処理を委託
        CInputManager::getInstance()->onKeyPressed( keyCode ) ;
    }
    
    /**
     *	@desc	キーボードのキーを離した際のイベント
     *	@param	キーコード
     *	@param	イベント
     */
    virtual void onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event ) override {
        // 入力管理に入力処理を委託
        CInputManager::getInstance()->onKeyReleased( keyCode ) ;
    }
    
public :
    virtual void update(float deltaTime_) override {
        inputflag.counterUpdata() ;
    }
    
};


#endif /* InputLayer_hpp */
