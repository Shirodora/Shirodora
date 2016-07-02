//
//  InputAndTouchLayer.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#ifndef InputAndTouchLayer_hpp
#define InputAndTouchLayer_hpp

#include <stdio.h>

#include "InputManager.hpp"
#include "TouchManager.hpp"

class CInputAndTouchLayer : public cocos2d::Layer {
public :
    CInputAndTouchLayer(){}
    
    virtual ~CInputAndTouchLayer(){}
    
    virtual bool init() override {
        if(cocos2d::Layer::init() == false) return false ;
        // キーボード入力イベント受け取り設定
        this->setKeyboardEnabled(true) ;
        
        // シングルタップ
        this->setTouchMode(cocos2d::Touch::DispatchMode::ONE_BY_ONE) ;
        // マルチタップ
        //this->setTouchMode(cocos2d::Touch::DispatchMode::ALL_AT_ONCE) ;
        // タッチイベント受け取り設定
        this->setTouchEnabled(true) ;
        
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
    
    /**
     *	@desc	タッチした時のイベント
     *	@param	タッチ情報
     *	@param	イベント
     */
    virtual bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* event) override {
        CTouchManager::getInstance()->onTouchBegan(pTouch) ;
        return true ;
    }
    
    /**
     *	@desc	タッチ移動した時のイベント
     *	@param	タッチ情報
     *	@param	イベント
     */
    virtual void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* event) override {
        CTouchManager::getInstance()->onTouchMoved(pTouch) ;
    }
    
    /**
     *	@desc	タッチ終了した時のイベント
     *	@param	タッチ情報
     *	@param	イベント
     */
    virtual void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* event) override {
        CTouchManager::getInstance()->onTouchEnded(pTouch) ;
    }
    
    /**
     *	@desc	タッチキャンセルした時のイベント
     *	@param	タッチ情報
     *	@param	イベント
     */
    virtual void onTouchCancelled(cocos2d::Touch* pTouch, cocos2d::Event* event) override {
        CTouchManager::getInstance()->onTouchCancelled(pTouch) ;
    }
    
public :
    virtual void update(float deltaTime_) override {
        inputflag.counterUpdata() ;
        touchData.counterUpdate() ;
    }
    
};

#endif /* InputAndTouchLayer_hpp */
