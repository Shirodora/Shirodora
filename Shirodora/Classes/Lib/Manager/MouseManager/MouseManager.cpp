//
//  MouseManager.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/18.
//
//

#include "MouseManager.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.hpp"

//=========================================================================
//
// マウスクラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CMouse::CMouse() :
m_clickCursorPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5),
m_dropCursorPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5) ,
m_currentCursorPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5) ,
m_previousCursorPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5){}

/**
 *  @desc   destructor
 */
CMouse::~CMouse(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   clear
 */
void CMouse::clear(){
    // クリックフラグ
    this->m_clicked = false ;
    // ドラッグフラグ
    this->m_draging = false ;
    // ドロップ
    this->m_droped = false ;
}

/**
 *  @desc   マウスクリック時の処理
 *  @param  マウスイベント
 */
void CMouse::mouseClicked(cocos2d::EventMouse *pEvent){
    this->m_isMoving = false ;
    this->m_draging = true ;
    
    if(this->m_clicked == false){
        this->m_clicked = true ;
        this->m_clickCounter = 0 ;
    }
    if(this->m_droped == true) this->m_droped = false ;
    
    this->m_clickCursorPosition = pEvent->getLocationInView() + cocos2d::Vec2(0.0f, WINDOW_HEIGHT) ;
    this->m_previousCursorPosition = pEvent->getLocationInView() + cocos2d::Vec2(0.0f, WINDOW_HEIGHT) ;
    this->m_currentCursorPosition = pEvent->getLocationInView() + cocos2d::Vec2(0.0f, WINDOW_HEIGHT) ;
}

/**
 *  @desc   マウスドロップ時の処理
 *  @param  マウスイベント
 */
void CMouse::mouseDroped(cocos2d::EventMouse *pEvent){
    this->m_isMoving = false ;
    this->m_draging = false ;
    
    if(this->m_droped == false){
        this->m_droped = true ;
        this->m_dropCounter = 0 ;
    }
    if(this->m_draging == true){
        this->m_draging = false ;
    }
    if(this->m_clicked == true) this->m_clicked = false ;
    
    this->m_dropCursorPosition = pEvent->getLocationInView() + cocos2d::Vec2(0.0f, WINDOW_HEIGHT) ;
    this->m_currentCursorPosition = pEvent->getLocationInView() + cocos2d::Vec2(0.0f, WINDOW_HEIGHT) ;
    this->m_previousCursorPosition = this->m_currentCursorPosition ;
}

/**
 *  @desc   マウス移動時の処理
 *  @param  マウスイベント
 */
void CMouse::mouseMoved(cocos2d::EventMouse *pEvent){
    this->m_isMoving = true ;
    this->m_moveCounter = 0 ;
    
    if(this->m_clicked == true) this->m_clicked = false ;
    
    if(this->m_isPreviousCursorPositionCaptured == true){
        this->m_previousCursorPosition = this->m_currentCursorPosition ;
        this->m_isPreviousCursorPositionCaptured = false ;
    }
    
    this->m_currentCursorPosition = pEvent->getLocationInView() + cocos2d::Vec2(0.0f, WINDOW_HEIGHT) ;
}

/**
 *  @desc   マウススクロール時の処理
 *  @param  マウスイベント
 */
void CMouse::mouseScrolled(cocos2d::EventMouse *pEvent){
    // 今は使わない
}

/**
 *  @desc   カウンター更新処理
 */
void CMouse::counterUpdate(){
    if(this->m_clicked == true){
        ++this->m_clickCounter ;
        if(this->COUNTER_MAX <= this->m_clickCounter){
            this->m_clicked = false ;
        }
    }
    
    if(this->m_droped == true){
        ++this->m_dropCounter ;
        if(this->COUNTER_MAX <= this->m_dropCounter){
            this->m_droped = false ;
        }
    }
    
    if(this->m_isMoving == true){
        ++this->m_moveCounter ;
        if(this->COUNTER_MAX <= this->m_moveCounter){
            this->m_isMoving = false ;
            this->m_previousCursorPosition = this->m_currentCursorPosition ;
        }
    }
    this->m_isPreviousCursorPositionCaptured = true ;
}

/**
 *  @desc   クリック時のカーソル位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CMouse::getClickPosition(){
    return this->m_clickCursorPosition ;
}

/**
 *  @desc   ドロップ時のカーソル位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CMouse::getDropPosition(){
    return this->m_dropCursorPosition ;
}

/**
 *  @desc   現在のカーソル位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CMouse::getCurrentCursorPosition(){
    return this->m_currentCursorPosition ;
}

/**
 *  @desc   直前のカーソル位置を取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CMouse::getPreviousCursorPosition(){
    return this->m_previousCursorPosition ;
}

/**
 *  @desc   微小時間あたりのベクトル方向
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CMouse::getDeltaDirection(){
    cocos2d::Vec2 vec = this->m_currentCursorPosition - this->m_previousCursorPosition ;
    this->m_previousCursorPosition = this->m_currentCursorPosition ;
    return vec ;
}

/**
 *  @desc   ドラッグ&ドロップされた時のカーソルのベクトル方向
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CMouse::getDragAndDropDirection(){
    return this->m_dropCursorPosition - this->m_clickCursorPosition ;
}

/**
 *  @desc   クリックされたかどうか
 *  @return true...クリックされた false...クリックされていない
 *  @tips   一度しか判定しない
 */
bool CMouse::isClicked(){
    if(this->m_clicked == true){
        this->m_clicked = false ;
        return true ;
    }
    return false ;
}

/**
 *  @desc   ドロップされたかどうか
 *  @return true...ドロップされた false...ドロップされていない
 *  @tips   一度しか判定しない
 */
bool CMouse::isDroped(){
    if(this->m_droped == true){
        this->m_droped = false ;
        return true ;
    }
    return false ;
}

/**
 *  @desc   ドラッグされているか
 *  @return true...ドラッグされた false...ドラッグされていない
 */
bool CMouse::isDraging(){
    return this->m_draging ;
}

//=========================================================================
//
// マウス管理
// Singleton
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CMouseManager::CMouseManager(){
    this->setMouse(new CMouse()) ;
}

/**
 *  @desc   copy constructor
 */
CMouseManager::CMouseManager(const CMouseManager &manager){}

/**
 *  @desc   destructor
 */
CMouseManager::~CMouseManager(){
    if(this->m_pMouse != NULL){
        delete this->m_pMouse ;
        this->m_pMouse = NULL ;
    }
}

//=========================================================================
// Singleton用インスタンス取得/破棄
//=========================================================================
// 共有インスタンス
CMouseManager* CMouseManager::m_pInstance = NULL ;

// アクセスポイント
std::mutex mousemanager_singleton_mtx_;

/**
 *  @desc   インスタンス取得
 *  @return CMouseManager
 */
CMouseManager* CMouseManager::getInstance(){
    std::lock_guard<std::mutex> lock( mousemanager_singleton_mtx_ ) ;
    if ( CMouseManager::m_pInstance == NULL ) {
        CMouseManager::m_pInstance = new CMouseManager() ;
    }
    return CMouseManager::m_pInstance ;
}

/**
 *  @desc   インスタンス破棄
 */
void CMouseManager::destroyInstance(){
    if(CMouseManager::m_pInstance != NULL){
        delete CMouseManager::m_pInstance ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   マウスクリック時の処理
 *  @param  マウスイベント
 */
void CMouseManager::mouseClicked(cocos2d::EventMouse *pEvent){
    if(this->m_pMouse){
        this->m_pMouse->mouseClicked(pEvent) ;
    }
}

/**
 *  @desc   マウスドロップ時の処理
 *  @param  マウスイベント
 */
void CMouseManager::mouseDroped(cocos2d::EventMouse *pEvent){
    if(this->m_pMouse){
        this->m_pMouse->mouseDroped(pEvent) ;
    }
}

/**
 *  @desc   マウス移動時の処理
 *  @param  マウスイベント
 */
void CMouseManager::mouseMoved(cocos2d::EventMouse *pEvent){
    if(this->m_pMouse){
        this->m_pMouse->mouseMoved(pEvent) ;
    }
}

/**
 *  @desc   マウススクロール時の処理
 *  @param  マウスイベント
 */
void CMouseManager::mouseScrolled(cocos2d::EventMouse *pEvent){
    if(this->m_pMouse){
        this->m_pMouse->mouseScrolled(pEvent) ;
    }
}

/**
 *  @desc   マウスクラスの設定
 *  @param  CMouse
 */
void CMouseManager::setMouse(CMouse* pMouse){
    if(this->m_pMouse) {
        printf( "既に取り付け済み\n" ) ;
        return ;
    }
    this->m_pMouse = pMouse ;
}

/**
 *  @desc   マウスクラスの破棄
 */
void CMouseManager::destroyMouse(){
    if (this->m_pMouse) {
        delete this->m_pMouse ;
        this->m_pMouse = NULL ;
    }
}

/**
 *  @desc   マウスクラスのclear
 */
void CMouseManager::clearMouse(){
    if (this->m_pMouse) {
        this->m_pMouse->clear() ;
    }
}

/**
 *  @desc   マウスクラスの取得
 */
CMouse* CMouseManager::getMouse(){
    return this->m_pMouse ;
}