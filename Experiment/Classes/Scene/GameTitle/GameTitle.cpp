//
//  GameTitle.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/02.
//
//

#include "GameTitle.hpp"
#include "SceneHeaders.h"
#include "GameDemo.hpp"
#include "GamePouse.hpp"

CGameTitle::CGameTitle(){}

CGameTitle::~CGameTitle(){}

/**
 *  @desc   init
 */
bool CGameTitle::init(){
    if(cocos2d::Scene::init() == false) return false ;
    
    // InputLayer
    this->m_pMainLayer = CCREATE_FUNC::create<CInputLayer>() ;
    this->addChild(this->m_pMainLayer) ;
    
    // touchLayer
    this->m_pSubLayer = CCREATE_FUNC::create<CTouchLayer>() ;
    this->addChild(this->m_pSubLayer) ;
    
    // Sprite
    this->m_pMainSprite = cocos2d::Sprite::create() ;
    this->m_pMainSprite->setTexture("H.png") ;
    this->m_pMainSprite->setPosition(320.0f, 240.0f) ;
    this->m_pMainLayer->addChild(this->m_pMainSprite) ;
    
//    // Label
//    this->m_pLabel = cocos2d::Label::createWithTTF("痴漢なう", "fonts/arial.ttf", 64) ;
//    this->m_pLabel->setPosition(320.0f, 100.0f) ;
//    this->m_pLabel->setColor(cocos2d::Color3B(0, 200, 200)) ;
//    this->addChild(this->m_pLabel) ;
    
    // MenuItemImage(Node)
    this->m_pCloseButtom = cocos2d::MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(CGameTitle::end, this)) ;
    this->m_pCloseButtom->setPosition(120.0f, 200.0f) ;
    
    // Menu(Layer)
    this->m_pMenu = cocos2d::Menu::createWithItem(this->m_pCloseButtom) ;
    this->m_pMenu->setPosition(0.0f, 0.0f) ;
    this->addChild(this->m_pMenu) ;
    
    // スケジューラーに登録
    this->scheduleUpdate();
    
    return true;
}

/**
 *  @desc   update
 */
void CGameTitle::update(float deltaTime_){
    this->m_pMainLayer->update(deltaTime_) ;
    this->m_pSubLayer->update(deltaTime_) ;
    
    // TODO:
    // 離した時だとタッチしている方が優先される
    // つまり、タッチしているのと、離した瞬間の判定を両立させたい
    if(touchData.isTouched() == true){
        cocos2d::Vec2 pos = touchData.getCurrentPos() ;
        CCLOG("ツンツン : (%f, %f)", pos.x, pos.y) ;
        if(250.0f <= pos.x && pos.x <= 260.0f && 150.0f <= pos.y && pos.y <= 170.0f){
            this->createLabel(0) ;
            CCLOG("ピンポイントタッチ") ;
        }
        this->createLabel(1) ;
    }
    
    if(touchData.isTouching() == true){
        cocos2d::Vec2 pos = touchData.getCurrentPos() ;
        CCLOG("さわさわ : (%f, %f)", pos.x, pos.y) ;
        if(250.0f <= pos.x && pos.x <= 260.0f && 150.0f <= pos.y && pos.y <= 170.0f){
            CCLOG("痴漢なう") ;
            this->createLabel(2) ;
        }
        this->createLabel(3) ;
    }
    
    if(inputflag.m_s.isInput() == true){
        this->goSelect(this) ;
    }
    if(inputflag.m_d.isReleased() == true){
        this->goDemo(this) ;
    }
    if(inputflag.m_z.isInput() == true){
        CCLOG("ここはTitle") ;
    }
    if(inputflag.m_a.isPressed() == true){
        this->goPouse(this) ;
    }
    
    this->counterManager() ;
}

/**
 *  @desc   goSelect
 */
void CGameTitle::goSelect(cocos2d::Ref* pSender){
    CCLOG("セレクトへ") ;
    cocos2d::Director::getInstance()->replaceScene(CCREATE_FUNC::create<CGameSelect>()) ;
}

/**
 *  @desc   goDemo
 */
void CGameTitle::goDemo(cocos2d::Ref* pSender){
    CCLOG("デモへ") ;
    cocos2d::Director::getInstance()->pushScene(CCREATE_FUNC::create<CGameDemo>()) ;
}

/**
 *  @desc   goPouse
 */
void CGameTitle::goPouse(cocos2d::Ref* pSender){
    CCLOG("ポーズへ") ;
    cocos2d::Director::getInstance()->replaceScene(CCREATE_FUNC::create<CGamePouse>()) ;
}

/**
 *  @desc   end
 */
void CGameTitle::end(cocos2d::Ref* pSender){
    CCLOG("終了") ;
    cocos2d::Director::getInstance()->end() ;
}

/**
 *  @desc   createLabel
 */
void CGameTitle::createLabel(int type){
    if(this->m_pLabel == NULL){
        if(type == 0){
            this->m_pLabel = cocos2d::Label::createWithTTF("JUST CHIKAN!!", "fonts/arial.ttf", 64) ;
        }else if(type == 1){
            this->m_pLabel = cocos2d::Label::createWithTTF("SOKOJANAI!", "fonts/arial.ttf", 64) ;
        }else if(type == 2){
            this->m_pLabel = cocos2d::Label::createWithTTF("CHIKAN NOW!", "fonts/arial.ttf", 64) ;
        }else if(type == 3){
            this->m_pLabel = cocos2d::Label::createWithTTF("SAWA SAWA!", "fonts/arial.ttf", 64) ;
        }
        this->m_pLabel->setPosition(320.0f, 400.0f) ;
        this->m_pLabel->setColor(cocos2d::Color3B(0, 200, 200)) ;
        this->m_pMainLayer->addChild(this->m_pLabel) ;
    }
}

/**
 *  @desc   counterManager
 */
void CGameTitle::counterManager(){
    if(this->m_pLabel != NULL){
        if(this->m_counter >= 60){
            this->m_counter = 0 ;
            this->m_pLabel->removeFromParent() ;
            this->m_pLabel = NULL ;
        }else{
            this->m_counter++ ;
        }
    }
}
