//
//  TouchManager.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/10.
//
//

#ifndef TouchManager_hpp
#define TouchManager_hpp

#include <stdio.h>

//#define TAP

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "cocos2d.h"

//=========================================================================
//
// タッチクラス
//
//=========================================================================
class CTouchData {
private :
    // タッチフラグ
    bool m_touching = false ;
    // タッチした瞬間のフラグ
    bool m_touched = false ;
    // 離した瞬間のフラグ
    bool m_released = false ;
    // カウンター
    int m_touchedCounter = 0 ;
    int m_releasedCounter = 0 ;
    const int COUNTER_MAX = 3 ;
    
#ifdef  TAP
    // シングルタップ
    bool m_singleTouch = false ;
    // ダブルタップ
    bool m_doubleTouch = false ;
#endif  // TAP
    
    // 開始位置
    cocos2d::Vec2 m_startPos ;
    // 現在位置
    cocos2d::Vec2 m_currentPos ;
    // 直前の位置
    cocos2d::Vec2 m_previousPos ;
    
public :
    
    // コンストラクタ
    CTouchData() ;
    // デストラクタ
    ~CTouchData() ;
    
    /**
     *	@desc	値のクリア
     */
    virtual void clear() ;
    
    /**
     *	@desc	タッチ開始時に呼ぶ関数
     *	@param	タッチ情報
     */
    virtual void onTouchBegan(cocos2d::Touch* pTouch) ;
    
    /**
     *	@desc	タッチ移動中に呼ぶ関数
     *	@param	タッチ情報
     */
    virtual void onTouchMoved(cocos2d::Touch* pTouch) ;
    
    /**
     *	@desc	タッチ終了時に呼ぶ関数
     *	@param	タッチ情報
     */
    virtual void onTouchEnded(cocos2d::Touch* pTouch) ;
    
    // ???:タッチキャンセル時というのが、いつなのか不明
    /**
     *	@desc	タッチキャンセル時に呼ぶ関数
     *	@param	タッチ情報
     */
    virtual void onTouchCancelled(cocos2d::Touch* pTouch) ;
    
    /**
     *  @desc   タッチされた瞬間のフラグ管理
     */
    void touched() ;
    
    /**
     *  @desc   タッチ移動された瞬間のフラグ管理
     */
    void moved() ;
    
    /**
     *  @desc   離された瞬間のフラグ管理
     */
    void released() ;
    
    /**
     *  @desc   touched releasedのカウンターアップデート
     */
    void counterUpdate() ;
    
    /**
     *  @desc   タッチされているかどうかを取得
     *  @return
     */
    bool isTouching() ;
    
    /**
     *  @desc   タッチされたらtrueを返す
     *  @return true...タッチされた false...時すでに遅し
     *  ptips   一度しか反応しない
     */
    bool isTouched() ;
    
    /**
     *  @desc   離されたらtrueを返す
     *  @return true...離された false...時すでに遅し
     *  ptips   一度しか反応しない
     */
    bool isReleased() ;
    
#ifdef TAP
    /**
     *  @desc   シングルタップされたかどうかを取得
     *  @return
     */
    bool isSingleTouched() ;
    
    /**
     *  @desc   ダブルタップされたどうかを取得
     *  @return
     */
    bool isDoubleTouched() ;
#endif  // TAP
    
    /**
     *  @desc   タッチ開始位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getStartPos() ;
    
    /**
     *  @desc   現在のタッチ位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getCurrentPos() ;
    
    /**
     *  @desc   直前の位置を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getPreviousPos() ;
    
    /**
     *  @desc   タッチ移動方向を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getDirection() ;
    
    /**
     *  @desc   タッチ移動速度を取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getVelocity() ;
    
    /**
     *  @desc   タッチ移動距離を取得
     *  @return float
     */
    float getLength() ;
    
};

//=========================================================================
//
// タッチ管理
// Singleton
//
//=========================================================================
class CTouchManager {
    //=========================================================================
    // ここからSingleton
    //=========================================================================
public :
    // 共有インスタンス
    static CTouchManager* m_pInstance ;
    // インスタンス取得
    static CTouchManager* getInstance() ;
    // インスタンス破棄
    static void destroyInstance() ;
    
private:
    // コンストラクタ
    CTouchManager() ;
    CTouchManager( const CTouchManager& touchMgr_ ) ;
    ~CTouchManager() ;
    
    //=========================================================================
    // ここまでSingleton
    //=========================================================================
    
private:
    // タッチデータクラス
    CTouchData* m_pTouchData = NULL ;
    
public:
    /**
     *  @desc   タッチ開始時イベント
     *  @param  タッチ情報
     */
    virtual void onTouchBegan(cocos2d::Touch* pTouch) ;
    
    /**
     *  @desc   タッチ移動時イベント
     *  @param  タッチ情報
     */
    virtual void onTouchMoved(cocos2d::Touch* pTouch) ;
    
    /**
     *  @desc   タッチ終了時イベント
     *  @param  タッチ情報
     */
    virtual void onTouchEnded(cocos2d::Touch* pTouch) ;
    
    /**
     *  @desc   タッチキャンセル時イベント
     *  @param  タッチ情報
     */
    virtual void onTouchCancelled(cocos2d::Touch* pTouch) ;
    
    /**
     *	@desc	タッチの設定
     *	@param	タッチ
     */
    void setTouch(CTouchData* pTouchData) ;
    
    /**
     *	@desc	入力フラグの削除
     */
    void destroyTouch() ;
    
    /**
     *	@desc	入力フラグのクリア
     */
    void clearTouch() ;
    
    /**
     *	@desc	入力フラグの取得
     *	@return	入力フラグ
     */
    CTouchData* getTouchData() ;
    
} ;


// 入力フラグマクロ
#define touchData (*CTouchManager::getInstance()->getTouchData())

#endif /* TouchManager_hpp */
