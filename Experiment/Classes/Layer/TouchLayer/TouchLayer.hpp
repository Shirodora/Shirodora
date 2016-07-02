//
//  TouchLayer.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/10.
//
//

#ifndef TouchLayer_hpp
#define TouchLayer_hpp

#include <stdio.h>

#include "TouchManager.hpp"

class CTouchLayer : public cocos2d::Layer {
public :
    CTouchLayer(){}
    
    virtual ~CTouchLayer(){}
    
    virtual bool init() override {
        if(cocos2d::Layer::init() == false) return false ;
        // シングルタップ
        this->setTouchMode(cocos2d::Touch::DispatchMode::ONE_BY_ONE) ;
        // マルチタップ
        //this->setTouchMode(cocos2d::Touch::DispatchMode::ALL_AT_ONCE) ;
        // タッチイベント受け取り設定
        this->setTouchEnabled(true) ;
        
        return true ;
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
        touchData.counterUpdate() ;
    }
    
};

#endif /* TouchLayer_hpp */
