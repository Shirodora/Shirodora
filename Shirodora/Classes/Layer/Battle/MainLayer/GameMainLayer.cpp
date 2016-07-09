//
//  GameMainLayer.cpp
//  Shirodora
//
//  Created by Ryoutarou Onimura on 2016/07/03.
//
//

#include "GameMainLayer.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.hpp"

//=========================================================================
//
// GameMainLayer
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CGameMainLayer::CGameMainLayer(){}

/**
 *  @desc   destructor
 */
CGameMainLayer::~CGameMainLayer(){
    
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CGameMainLayer::init(){
    if(cocos2d::Layer::init() == false) return false ;
    
    // マウスイベントリスナーを生成
    cocos2d::EventListenerMouse *pMouseEvent = cocos2d::EventListenerMouse::create() ;
    // マウスイベントリスナーにマウスクリック時の処理を登録
    pMouseEvent->onMouseDown = CC_CALLBACK_1(CGameMainLayer::mouseClicked, this) ;
    // マウスイベントリスナーにマウスドロップ時の処理を登録
    pMouseEvent->onMouseUp = CC_CALLBACK_1(CGameMainLayer::mouseDroped, this) ;
    // マウスイベントリスナーにマウス移動時の処理を登録
    pMouseEvent->onMouseMove = CC_CALLBACK_1(CGameMainLayer::mouseMoved, this) ;
    // マウスイベントリスナーにマウススクロール時の処理を登録
    pMouseEvent->onMouseScroll = CC_CALLBACK_1(CGameMainLayer::mouseScrolled, this) ;
    
    // マウスイベントリスナーをイベントディスパッチャーに登録
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(pMouseEvent, this) ;
    
    // !!!:テスト用背景
    cocos2d::Sprite *pBackGround = cocos2d::Sprite::create("gameMainBG.png") ;
    pBackGround->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    this->addChild(pBackGround) ;
    
    // !!!:テスト用カーソルスプライト
    this->m_pCursor = cocos2d::Sprite::create("Bone.png") ;
    this->m_pCursor->setColor(cocos2d::Color3B::MAGENTA) ;
    this->m_pCursor->setPosition(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f) ;
    this->addChild(this->m_pCursor) ;
    
    // スケジューラーに登録
    this->scheduleUpdate() ;
    
    return true ;
}

//=========================================================================
// set
//=========================================================================

//=========================================================================
// get
//=========================================================================

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   update
 *  @param  微小時間
 */
void CGameMainLayer::update(float deltaTime){
    
}

/**
 *  @desc   マウスクリック時の処理
 *  @param  マウスイベント
 */
void CGameMainLayer::mouseClicked(cocos2d::EventMouse *pEvent){
    
}

/**
 *  @desc   マウスドロップ時の処理
 *  @param  マウスイベント
 */
void CGameMainLayer::mouseDroped(cocos2d::EventMouse *pEvent){
    
}

/**
 *  @desc   マウス移動時の処理
 *  @param  マウスイベント
 */
void CGameMainLayer::mouseMoved(cocos2d::EventMouse *pEvent){
    // カーソル座標設定
    this->moveCursor(pEvent) ;
}

/**
 *  @desc   マウススクロール時の処理
 *  @param  マウスイベント
 */
void CGameMainLayer::mouseScrolled(cocos2d::EventMouse *pEvent){
    
}

/**
 *  @desc   カーソルスプライト移動処理
 *  @param  マウスイベント
 */
void CGameMainLayer::moveCursor(cocos2d::EventMouse *pEvent){
    // 取得できる座標はOpenGL座標系なので注意
    this->m_pCursor->setPosition(pEvent->getCursorX(), WINDOW_HEIGHT + pEvent->getCursorY()) ;
}