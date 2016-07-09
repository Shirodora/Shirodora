//
//  MouseManager.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/18.
//
//

#ifndef MouseManager_hpp
#define MouseManager_hpp

#include <stdio.h>

//=========================================================================
//
// マウスクラス
//
//=========================================================================
class CMouse {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CMouse() ;
    
    /**
     *  @desc   destructor
     */
    ~CMouse() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   clear
     */
    void clear() ;
    
    /**
     *  @desc   マウスクリック時の処理
     *  @param  マウスイベント
     */
    void mouseClicked(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウスドロップ時の処理
     *  @param  マウスイベント
     */
    void mouseDroped(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウス移動時の処理
     *  @param  マウスイベント
     */
    void mouseMoved(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウススクロール時の処理
     *  @param  マウスイベント
     */
    void mouseScrolled(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   カウンター更新処理
     */
    void counterUpdate() ;
    
    /**
     *  @desc   クリック時のカーソル位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getClickPosition() ;
    
    /**
     *  @desc   ドロップ時のカーソル位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getDropPosition() ;
    
    /**
     *  @desc   現在のカーソル位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getCurrentCursorPosition() ;
    
    /**
     *  @desc   直前のカーソル位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getPreviousCursorPosition() ;
    
    /**
     *  @desc   微小時間あたりのベクトル方向
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getDeltaDirection() ;
    
    /**
     *  @desc   ドラッグ&ドロップされた時のカーソルのベクトル方向
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getDragAndDropDirection() ;
    
    /**
     *  @desc   クリックされたかどうか
     *  @return true...クリックされた false...クリックされていない
     *  @tips   一度しか判定しない
     */
    bool isClicked() ;
    
    /**
     *  @desc   ドロップされたかどうか
     *  @return true...ドロップされた false...ドロップされていない
     *  @tips   一度しか判定しない
     */
    bool isDroped() ;
    
    /**
     *  @desc   ドラッグされているか
     *  @return true...ドラッグされた false...ドラッグされていない
     */
    bool isDraging() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // クリックフラグ
    bool m_clicked = false ;
    // ドロップ
    bool m_droped = false ;
    // ドラッグフラグ
    bool m_draging = false ;
    //
    bool m_isMoving = false ;
    //
    bool m_isPreviousCursorPositionCaptured = false ;
    
    // カウンター
    int m_clickCounter = 0 ;
    int m_dropCounter = 0 ;
    int m_moveCounter = 0 ;
    const int COUNTER_MAX = 3 ;
    
    // クリック位置
    cocos2d::Vec2 m_clickCursorPosition ;
    // ドロップ位置
    cocos2d::Vec2 m_dropCursorPosition ;
    // 現在のカーソル位置
    cocos2d::Vec2 m_currentCursorPosition ;
    // 直前のカーソル位置
    cocos2d::Vec2 m_previousCursorPosition ;
    
};

//=========================================================================
//
// マウス管理
// Singleton
//
//=========================================================================
class CMouseManager {
public :
    //=========================================================================
    // ここからSingleton
    //=========================================================================
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CMouseManager() ;
    
    /**
     *  @desc   copy constructor
     */
    CMouseManager(const CMouseManager &manager) ;
    
    /**
     *  @desc   destructor
     */
    ~CMouseManager() ;
    
    //=========================================================================
    // Singleton用インスタンス取得/破棄
    //=========================================================================
public :
    // 共有インスタンス
    static CMouseManager *m_pInstance ;
    
    /**
     *  @desc   インスタンス取得
     *  @return CMouseManager
     */
    static CMouseManager *getInstance() ;
    
    /**
     *  @desc   インスタンス破棄
     */
    static void destroyInstance() ;
    //=========================================================================
    // ここまでSingleton
    //=========================================================================
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   マウスクリック時の処理
     *  @param  マウスイベント
     */
    void mouseClicked(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウスドロップ時の処理
     *  @param  マウスイベント
     */
    void mouseDroped(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウス移動時の処理
     *  @param  マウスイベント
     */
    void mouseMoved(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウススクロール時の処理
     *  @param  マウスイベント
     */
    void mouseScrolled(cocos2d::EventMouse *pEvent) ;
    
    /**
     *  @desc   マウスクラスの設定
     *  @param  CMouse
     */
    void setMouse(CMouse *pMouse) ;
    
    /**
     *  @desc   マウスクラスの破棄
     */
    void destroyMouse() ;
    
    /**
     *  @desc   マウスクラスのclear
     */
    void clearMouse() ;
    
    /**
     *  @desc   マウスクラスの取得
     */
    CMouse* getMouse() ;
    
private:
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // マウスクラス
    CMouse* m_pMouse {NULL} ;
    
} ;

// 入力フラグマクロ
#define mouse (*CMouseManager::getInstance()->getMouse())

#endif /* MouseManager_hpp */
