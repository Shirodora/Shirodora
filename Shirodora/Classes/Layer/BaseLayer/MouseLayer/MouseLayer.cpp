//
//  MouseLayer.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/25.
//
//

#include "MouseLayer.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Manager.hpp"

//=========================================================================
//
// インプット&マウスレイヤークラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CMouseLayer::CMouseLayer(){}

/**
 *  @desc   destructor
 */
CMouseLayer::~CMouseLayer(){}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CMouseLayer::init(){
    // レイヤーのinit
    if(cocos2d::Layer::init() == false) return false ;
    
    // マウスイベントリスナーを生成
    this->m_pEventListenerMouse = cocos2d::EventListenerMouse::create() ;
    // マウスイベントリスナーにマウスクリック時の処理を登録
    this->m_pEventListenerMouse->onMouseDown = CC_CALLBACK_1(CMouseLayer::mouseClicked, this) ;
    // マウスイベントリスナーにマウスドロップ時の処理を登録
    this->m_pEventListenerMouse->onMouseUp = CC_CALLBACK_1(CMouseLayer::mouseDroped, this) ;
    // マウスイベントリスナーにマウス移動時の処理を登録
    this->m_pEventListenerMouse->onMouseMove = CC_CALLBACK_1(CMouseLayer::mouseMoved, this) ;
    // マウスイベントリスナーにマウススクロール時の処理を登録
    this->m_pEventListenerMouse->onMouseScroll = CC_CALLBACK_1(CMouseLayer::mouseScrolled, this) ;
    
    // マウスイベントリスナーをイベントディスパッチャーに登録
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(this->m_pEventListenerMouse, this) ;
    
    return true ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   マウスクリック時の処理
 *  @param  マウスイベント
 */
void CMouseLayer::mouseClicked(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウスクリック時の処理を委託
    CMouseManager::getInstance()->mouseClicked(pEvent) ;
}

/**
 *  @desc   マウスドロップ時の処理
 *  @param  マウスイベント
 */
void CMouseLayer::mouseDroped(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウスドロップ時の処理を委託
    CMouseManager::getInstance()->mouseDroped(pEvent) ;
}

/**
 *  @desc   マウス移動時の処理
 *  @param  マウスイベント
 */
void CMouseLayer::mouseMoved(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウス移動時の処理を委託
    CMouseManager::getInstance()->mouseMoved(pEvent) ;
}

/**
 *  @desc   マウススクロール時の処理
 *  @param  マウスイベント
 */
void CMouseLayer::mouseScrolled(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウススクロール時の処理を委託
    CMouseManager::getInstance()->mouseScrolled(pEvent) ;
}

/**
 *  @desc   update
 *  @param  deltaTime
 */
void CMouseLayer::update(float deltaTime){
    CMouseManager::getInstance()->getMouse()->counterUpdate() ;
}