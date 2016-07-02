//
//  inputManager.hpp
//  
//
//  Created by Ryoutarou Onimura on 2016/06/08.
//
//

#ifndef inputManager_hpp
#define inputManager_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "cocos2d.h"
#include "Constants.h"

//=========================================================================
//
// 入力タイプ
//
//=========================================================================
enum class kInputType {
    NONE	= -1,
    UP		= 0,
    DOWN	= 1,
    LEFT	= 2,
    RIGHT	= 3,
    ESC		= 4,
    SPACE	= 5,
    Z		= 6,
    X		= 7,
    C		= 8,
    A		= 9,
    S		= 10,
    D		= 11,
};

//=========================================================================
//
// 入力クラス
//
//=========================================================================
class CInput {
private :
    // キー入力フラグ
    bool m_inputing = false ;
    // キーが押された時に一度だけ認識できるフラグ
    bool m_pressed = false ;
    // キーが離された時に一度だけ認識できるフラグ
    bool m_released = false ;
    // カウンター
    int m_pressedCounter = 0 ;
    int m_releasedCounter = 0 ;
    const int COUNTER_MAX = 3 ;
    
public :
    /**
     *  @desc   値のクリア
     */
    virtual void clear() ;
    
    /**
     *  @desc   キーが押された時に呼ぶ関数
     */
    virtual void input() ;
    
    /**
     *  @desc   キーが離された時に呼ぶ関数
     */
    virtual void unInput() ;
    
    /**
     *  @desc   キーが押されているフラグを上げる
     */
    virtual void pressed() ;
    
    /**
     *  @desc   キーが押されているフラグを下げる
     */
    virtual void released() ;
    
    /**
     *  @desc   pressed releasedのカウンターアップデート
     */
    void counterUpdate() ;
    
    /**
     *  @desc   キーが入力フラグを返す
     *  @return true...入力されている false...入力されていない
     */
    virtual bool isInput() ;
    
    /**
     *  @desc   キーが押されたらtrueを返す
     *  @return true...押されてた false...時すでに遅し
     *  ptips   一度しか反応しない
     */
    virtual bool isPressed() ;
    
    /**
     *  @desc   キーが離されたらtrueを返す
     *  @return true...離された false...時すでに遅し
     *  ptips   一度しか反応しない
     */
    virtual bool isReleased() ;
};

//=========================================================================
//
// 入力フラグクラス
//
//=========================================================================
class CInputFlag {
public :
    // 上キー
    CInput m_up ;
    // 下キー
    CInput m_down ;
    // 左キー
    CInput m_left ;
    // 右キー
    CInput m_right ;
    // ESC キー
    CInput m_esc ;
    // スペースキー
    CInput m_space ;
    
    // z キー
    CInput m_z ;
    // x キー
    CInput m_x ;
    // c キー
    CInput m_c ;
    // a キー
    CInput m_a ;
    // s キー
    CInput m_s ;
    // d キー
    CInput m_d ;
    
    /**
     *	@desc	値のクリア
     */
    virtual void clear() ;
    
    /**
     *	@desc	キーのフラグを上げる ( フラグアップ )
     *	@param	キーコード
     */
    virtual void up( kInputType keyType_ ) ;
    /**
     *	@desc	キーのフラグを下げる ( フラグダウン )
     *	@praram	キーコード
     */
    virtual void down( kInputType keyType_ ) ;
    
    /**
     *  @desc   カウンターアップデート
     */
    virtual void counterUpdata() ;
    
    /**
     *	@desc	指定したキーが入力されているかどうかを取得
     *	@param	キータイプ
     *	@return	true...入力されている
     *	@tips	入力のタイプによって変化
     *			キーボードタイプでは使用する必要はない
     */
    virtual bool isKeyInputed( kInputType keyType_ ) ;
    
    /**
     *	@desc	指定したキーが押されたかどうかを取得
     *	@param	キータイプ
     *	@return	true...押された
     *	@tips	入力のタイプによって変化
     *			キーボードタイプでは使用する必要はない
     */
    virtual bool isKeyPressed( kInputType keyType_ ) ;
    
    /**
     *	@desc	指定したキーが離されたかどうかを取得
     *	@param	キータイプ
     *	@return	true...離された
     *	@tips	入力のタイプによって変化
     *			キーボードタイプでは使用する必要はない
     */
    virtual bool isKeyReleased( kInputType keyType_ ) ;
};

//=========================================================================
//
// 入力管理
// Singleton
//
//=========================================================================
class CInputManager {
    //=========================================================================
    // ここからSingleton
    //=========================================================================
public :
    // 共有インスタンス
    static CInputManager* m_pInstance ;
    // インスタンス取得
    static CInputManager* getInstance() ;
    // インスタンス破棄
    static void destroyInstance() ;
    
private:
    // コンストラクタ
    CInputManager() ;
    CInputManager( const CInputManager& inputMgr_ ) ;
    ~CInputManager() ;
    
    //=========================================================================
    // ここまでSingleton
    //=========================================================================
    
private:
    // 入力フラグクラス
    CInputFlag* m_pInputFlag = NULL ;
    
public:
    /**
     *	@desc	キーコードからキータイプに変換
     *	@param	キーコード
     *	@return	キータイプ
     */
    kInputType changeToInputTypeFromKeyCode(cocos2d::EventKeyboard::KeyCode keyCode) ;
    
    /**
     *	@desc	キーボードを押した際のイベント
     *	@param	キーコード
     *	@tips	入力管理を使用する際は入力受けつけが可能となっているノードの onKeyPressed で呼び出す
     */
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode) ;
    
    /**
     *	@desc	キーボードを離した際のイベント
     *	@param	キーコード
     *	@tips	入力管理を使用する際は入力受けつけが可能となっているノードの onKeyReleased で呼び出す
     */
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode) ;
    
    /**
     *	@desc	入力フラグの設定
     *	@param	入力フラグ
     */
    void setInputFlag(CInputFlag* pInputFlag) ;
    
    /**
     *	@desc	入力フラグの削除
     */
    void destroyInputFlag() ;
    
    /**
     *	@desc	入力フラグのクリア
     */
    void clearInputFlag() ;
    
    /**
     *	@desc	入力フラグの取得
     *	@return	入力フラグ
     */
    CInputFlag* getInputFlag() ;
    
} ;


// 入力フラグマクロ
#define inputflag (*CInputManager::getInstance()->getInputFlag())



#endif /* inputManager_hpp */
