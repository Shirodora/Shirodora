//
//  InputLayer.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/25.
//
//

#include "InputLayer.hpp"

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
CInputLayer::CInputLayer(){}

/**
 *  @desc   destructor
 */
CInputLayer::~CInputLayer(){}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
bool CInputLayer::init(){
    // レイヤーのinit
    if(cocos2d::Layer::init() == false) return false ;
    
    // キーボード入力イベント受け取り設定
    this->setKeyboardEnabled(true) ;
    
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
void CInputLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent){
    // インプットマネージャーにキーが押された時の処理を委託
    CInputManager::getInstance()->onKeyPressed(keyCode) ;
}

/**
 *	@desc	キーを離した時の処理
 *	@param	キーコード
 *	@param	イベント
 */
void CInputLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent){
    // インプットマネージャーにキーが離された時の処理を委託
    CInputManager::getInstance()->onKeyReleased(keyCode) ;
}

/**
 *  @desc   update
 *  @param  deltaTime
 */
void CInputLayer::update(float deltaTime){
    CInputManager::getInstance()->getInputFlag()->counterUpdata() ;
}