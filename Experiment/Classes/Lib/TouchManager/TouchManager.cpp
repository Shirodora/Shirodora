//
//  TouchManager.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/10.
//
//

#include "TouchManager.hpp"

//=========================================================================
//
// タッチクラス
//
//=========================================================================
// コンストラクタ
CTouchData::CTouchData(){}

// デストラクタ
CTouchData::~CTouchData(){}

/**
 *	@desc	値のクリア
 */
void CTouchData::clear(){
    this->m_touching = false ;
    this->m_touched = false ;
    this->m_released = false ;
    
#ifdef TAP
    this->m_singleTouch = false ;
    this->m_doubleTouch = false ;
#endif  // TAP
    
    this->m_startPos.set(0.0f, 0.0f) ;
    this->m_currentPos.set(0.0f, 0.0f) ;
    this->m_previousPos.set(0.0f, 0.0f) ;
}

/**
 *	@desc	タッチ開始時に呼ぶ関数
 *	@param	タッチ情報
 */
void CTouchData::onTouchBegan(cocos2d::Touch* pTouch){
    this->m_touching = true ;
    this->touched() ;
    this->m_startPos = pTouch->getLocation() ;
    this->m_currentPos = pTouch->getLocation() ;
}

/**
 *	@desc	タッチ移動時に呼ぶ関数
 *	@param	タッチ情報
 */
void CTouchData::onTouchMoved(cocos2d::Touch* pTouch){
    this->moved() ;
    this->m_currentPos = pTouch->getLocation() ;
}

/**
 *	@desc	タッチ終了時に呼ぶ関数
 *	@param	タッチ情報
 */
void CTouchData::onTouchEnded(cocos2d::Touch* pTouch){
    this->m_touching = false ;
    this->released() ;
    this->m_currentPos = pTouch->getLocation() ;
    this->m_previousPos = pTouch->getLocation() ;
}

// ???:タッチキャンセル時というのが、いつなのか不明
/**
 *	@desc	タッチキャンセル時に呼ぶ関数
 *	@param	タッチ情報
 */
void CTouchData::onTouchCancelled(cocos2d::Touch* pTouch){
    CCLOG("タッチキャンセルっていつ行われたん？") ;
}

/**
 *  @desc   タッチされた瞬間のフラグ管理
 */
void CTouchData::touched(){
    if(this->m_released == true) this->m_released = false ;
    if(this->m_touched == false){
        this->m_touched = true ;
        this->m_touchedCounter = 0 ;
    }
}

/**
 *  @desc   タッチ移動された瞬間のフラグ管理
 */
void CTouchData::moved(){
    if(this->m_touched == true) this->m_touched = false ;
}

/**
 *  @desc   離された瞬間のフラグ管理
 */
void CTouchData::released(){
    if(this->m_touched == true) this->m_touched = false ;
    if(this->m_released == false){
        this->m_released = true ;
        this->m_releasedCounter = 0 ;
    }
}

/**
 *  @desc   touched releasedのカウンターアップデート
 */
void CTouchData::counterUpdate(){
    if(this->m_touched == true){
        this->m_touchedCounter++ ;
        if(this->m_touchedCounter >= this->COUNTER_MAX){
            this->m_touched = false ;
        }
    }
    if(this->m_released == true){
        this->m_releasedCounter++ ;
        if(this->m_releasedCounter >= this->COUNTER_MAX){
            this->m_released = false ;
        }
    }
}

/**
 *  @desc   タッチされているかどうかを取得
 *  @return
 */
bool CTouchData::isTouching(){
    return this->m_touching ;
}

/**
 *  @desc   タッチされたらtrueを返す
 *  @return true...タッチされた false...時すでに遅し
 *  ptips   一度しか反応しない
 */
bool CTouchData::isTouched(){
    if(this->m_touched == true){
        this->m_touched = false ;
        return true ;
    }
    return false ;
}

/**
 *  @desc   離されたらtrueを返す
 *  @return true...離された false...時すでに遅し
 *  ptips   一度しか反応しない
 */
bool CTouchData::isReleased(){
    if(this->m_released == true){
        this->m_released = false ;
        return true ;
    }
    return false ;
}

/**
 *  @desc   タッチ開始位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CTouchData::getStartPos(){
    return this->m_startPos ;
}

/**
 *  @desc   現在のタッチ位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CTouchData::getCurrentPos(){
    return this->m_currentPos ;
}

/**
 *  @desc   直前のタッチ位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CTouchData::getPreviousPos(){
    return this->m_previousPos ;
}

/**
 *  @desc   タッチ移動方向を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CTouchData::getDirection(){
    return this->m_currentPos - this->m_startPos ;
}

/**
 *  @desc   タッチ移動速度を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CTouchData::getVelocity(){
    return this->m_currentPos - this->m_previousPos ;
}

/**
 *  @desc   タッチ移動距離を取得
 *  @return float
 */
float CTouchData::getLength(){
    return (this->m_currentPos - this->m_startPos).getLength() ;
}

//=========================================================================
//
// タッチ管理
//
//=========================================================================
// 共有インスタンス本体
CTouchManager* CTouchManager::m_pInstance = NULL ;

// アクセスポイント
std::mutex touchmanager_singleton_mtx_;

// インスタンス取得
CTouchManager* CTouchManager::getInstance() {
    std::lock_guard<std::mutex> lock( touchmanager_singleton_mtx_ ) ;
    if ( CTouchManager::m_pInstance == NULL ) {
        CTouchManager::m_pInstance = new CTouchManager() ;
    }
    return CTouchManager::m_pInstance ;
}

// インスタンス破棄
void CTouchManager::destroyInstance() {
    if(CTouchManager::m_pInstance != NULL){
        delete CTouchManager::m_pInstance ;
        CTouchManager::m_pInstance = NULL ;
    }
}

// コンストラクタ
CTouchManager::CTouchManager() {
    // 入力フラグの生成と設定
    this->setTouch(new CTouchData()) ;
}

// コンストラクタ
CTouchManager::CTouchManager( const CTouchManager& touchMgr_ ) {}

// デストラクタ
CTouchManager::~CTouchManager() {
    // タッチクラスの破棄
    if(this->m_pTouchData != NULL){
        delete this->m_pTouchData ;
        this->m_pTouchData = NULL ;
    }
}

/**
 *  @desc   タッチ開始時イベント
 *  @param  タッチ情報
 */
void CTouchManager::onTouchBegan(cocos2d::Touch* pTouch){
    if(this->m_pTouchData){
        this->m_pTouchData->onTouchBegan(pTouch) ;
    }
}

/**
 *  @desc   タッチ移動時イベント
 *  @param  タッチ情報
 */
void CTouchManager::onTouchMoved(cocos2d::Touch* pTouch){
    if(this->m_pTouchData){
        this->m_pTouchData->onTouchMoved(pTouch) ;
    }
}

/**
 *  @desc   タッチ終了時イベント
 *  @param  タッチ情報
 */
void CTouchManager::onTouchEnded(cocos2d::Touch* pTouch){
    if(this->m_pTouchData){
        this->m_pTouchData->onTouchEnded(pTouch) ;
    }
}

/**
 *  @desc   タッチキャンセル時イベント
 *  @param  タッチ情報
 */
void CTouchManager::onTouchCancelled(cocos2d::Touch* pTouch){
    if(this->m_pTouchData){
        this->m_pTouchData->onTouchCancelled(pTouch) ;
    }
}

/**
 *	@desc	タッチクラスの設定
 *	@param	タッチクラス
 */
void CTouchManager::setTouch(CTouchData* pTouchData){
    if(this->m_pTouchData) {
        printf( "既に取り付け済み\n" ) ;
        return ;
    }
    this->m_pTouchData = pTouchData ;
}

/**
 *	@desc	タッチクラスの削除
 */
void CTouchManager::destroyTouch() {
    if (this->m_pTouchData) {
        delete this->m_pTouchData ;
        this->m_pTouchData = NULL ;
    }
}

/**
 *	@desc	タッチクラスのクリア
 */
void CTouchManager::clearTouch() {
    if ( this->m_pTouchData ) {
        this->m_pTouchData->clear() ;
    }
}

/**
 *	@desc	タッチクラスの取得
 *	@return	タッチクラス
 */
CTouchData* CTouchManager::getTouchData() {
    return this->m_pTouchData ;
}