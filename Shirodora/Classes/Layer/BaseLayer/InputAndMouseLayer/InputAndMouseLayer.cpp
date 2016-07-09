//
//  InputAndMouseLayer.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/24.
//
//

#include "InputAndMouseLayer.hpp"

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
CInputAndMouseLayer::CInputAndMouseLayer(){}

/**
 *  @desc   destructor
 */
CInputAndMouseLayer::~CInputAndMouseLayer(){}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CInputAndMouseLayer::init(){
    // レイヤーのinit
    if(cocos2d::Layer::init() == false) return false ;
    
    // キーボード入力イベント受け取り設定
    this->setKeyboardEnabled(true) ;
    
    // マウスイベントリスナーを生成
    this->m_pEventListenerMouse = cocos2d::EventListenerMouse::create() ;
    // マウスイベントリスナーにマウスクリック時の処理を登録
    this->m_pEventListenerMouse->onMouseDown = CC_CALLBACK_1(CInputAndMouseLayer::mouseClicked, this) ;
    // マウスイベントリスナーにマウスドロップ時の処理を登録
    this->m_pEventListenerMouse->onMouseUp = CC_CALLBACK_1(CInputAndMouseLayer::mouseDroped, this) ;
    // マウスイベントリスナーにマウス移動時の処理を登録
    this->m_pEventListenerMouse->onMouseMove = CC_CALLBACK_1(CInputAndMouseLayer::mouseMoved, this) ;
    // マウスイベントリスナーにマウススクロール時の処理を登録
    this->m_pEventListenerMouse->onMouseScroll = CC_CALLBACK_1(CInputAndMouseLayer::mouseScrolled, this) ;
    
    // マウスイベントリスナーをイベンtのディスパッチャーに登録
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(this->m_pEventListenerMouse, this) ;
    
    return true ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *	@desc	キーを押した時の処理
 *	@param	キーコード
 *	@param	イベント
 */
void CInputAndMouseLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent){
    // インプットマネージャーにキーが押された時の処理を委託
    CInputManager::getInstance()->onKeyPressed(keyCode) ;
}

/**
 *	@desc	キーを離した時の処理
 *	@param	キーコード
 *	@param	イベント
 */
void CInputAndMouseLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent){
    // インプットマネージャーにキーが離された時の処理を委託
    CInputManager::getInstance()->onKeyReleased(keyCode) ;
}

/**
 *  @desc   マウスクリック時の処理
 *  @param  マウスイベント
 */
void CInputAndMouseLayer::mouseClicked(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウスクリック時の処理を委託
    CMouseManager::getInstance()->mouseClicked(pEvent) ;
}

/**
 *  @desc   マウスドロップ時の処理
 *  @param  マウスイベント
 */
void CInputAndMouseLayer::mouseDroped(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウスドロップ時の処理を委託
    CMouseManager::getInstance()->mouseDroped(pEvent) ;
}

/**
 *  @desc   マウス移動時の処理
 *  @param  マウスイベント
 */
void CInputAndMouseLayer::mouseMoved(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウス移動時の処理を委託
    CMouseManager::getInstance()->mouseMoved(pEvent) ;
}

/**
 *  @desc   マウススクロール時の処理
 *  @param  マウスイベント
 */
void CInputAndMouseLayer::mouseScrolled(cocos2d::EventMouse *pEvent){
    // マウスマネージャーにマウススクロール時の処理を委託
    CMouseManager::getInstance()->mouseScrolled(pEvent) ;
}

/**
 *  @desc   update
 *  @param  deltaTime
 */
void CInputAndMouseLayer::update(float deltaTime){
    CInputManager::getInstance()->getInputFlag()->counterUpdata() ;
    CMouseManager::getInstance()->getMouse()->counterUpdate() ;
}
