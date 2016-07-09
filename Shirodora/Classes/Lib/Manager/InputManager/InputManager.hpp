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

//=========================================================================
//
// 入力タイプ
//
//=========================================================================
enum class keyInputType {
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
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CInput() ;
    
    /**
     *  @desc   destructor
     */
    ~CInput() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   値のクリア
     */
    virtual void clear() ;
    
    /**
     *  @desc   キーが押された時に呼ぶ関数
     */
    virtual void pressed() ;
    
    /**
     *  @desc   キーが離された時に呼ぶ関数
     */
    virtual void released() ;
    
    /**
     *  @desc   pressed releasedのカウンター更新処理
     */
    void counterUpdate() ;
    
    /**
     *  @desc   キーが入力フラグを返す
     *  @return true...入力されている false...入力されていない
     */
    virtual bool isInputing() ;
    
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
    
private :
    //=========================================================================
    // メンバ変数
    //=========================================================================
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
    
};

//=========================================================================
//
// 入力フラグクラス
//
//=========================================================================
class CInputFlag {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CInputFlag() ;
    
    /**
     *  @desc   destructor
     */
    ~CInputFlag() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    /**
     *	@desc	値のクリア
     */
    virtual void clear() ;
    
    /**
     *	@desc	キーのフラグを上げる
     *	@param	キーコード
     */
    virtual void up(keyInputType keyType) ;
    /**
     *	@desc	キーのフラグを下げる
     *	@praram	キーコード
     */
    virtual void down(keyInputType keyType) ;
    
    /**
     *  @desc   各キーのカウンター更新処理
     */
    virtual void counterUpdata() ;
    
    /**
     *	@desc	指定したキーが入力されているかどうかを取得
     *	@param	キータイプ
     *	@return	true...入力されている
     *	@tips	入力のタイプによって変化
     *			キーボードタイプでは使用する必要はない
     */
    virtual bool isKeyInputed(keyInputType keyType) ;
    
    /**
     *	@desc	指定したキーが押されたかどうかを取得
     *	@param	キータイプ
     *	@return	true...押された
     *	@tips	入力のタイプによって変化
     *			キーボードタイプでは使用する必要はない
     */
    virtual bool isKeyPressed(keyInputType keyType) ;
    
    /**
     *	@desc	指定したキーが離されたかどうかを取得
     *	@param	キータイプ
     *	@return	true...離された
     *	@tips	入力のタイプによって変化
     *			キーボードタイプでは使用する必要はない
     */
    virtual bool isKeyReleased(keyInputType keyType) ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
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
};

//=========================================================================
//
// インプットマネージャー
// Singleton
//
//=========================================================================
class CInputManager {
    //=========================================================================
    // ここからSingleton
    //=========================================================================
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
private:
    /**
     *  @desc   constructor
     */
    CInputManager() ;
    
    /**
     *  @desc   copy constructor
     */
    CInputManager(const CInputManager &manager) ;
    
    /**
     *  @desc   destructor
     */
    ~CInputManager() ;
    
    //=========================================================================
    // Singleton用インスタンス取得/破棄
    //=========================================================================
public :
    // 共有インスタンス
    static CInputManager *m_pInstance ;
    
    /**
     *  @desc   インスタンス取得
     *  @return CInputManager
     */
    static CInputManager *getInstance() ;
    
    /**
     *  @desc   インスタンス破棄
     */
    static void destroyInstance() ;
    
    //=========================================================================
    // ここまでSingleton
    //=========================================================================
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
private:
    // 入力フラグクラス
    CInputFlag *m_pInputFlag {NULL} ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public:
    /**
     *	@desc	キーコードからキータイプに変換
     *	@param	キーコード
     *	@return	キータイプ
     */
    keyInputType changeToInputTypeFromKeyCode(cocos2d::EventKeyboard::KeyCode keyCode) ;
    
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
    void setInputFlag(CInputFlag *pInputFlag) ;
    
    /**
     *	@desc	入力フラグの破棄
     */
    void destroyInputFlag() ;
    
    /**
     *	@desc	CInputFlagのclear
     */
    void clearInputFlag() ;
    
    /**
     *	@desc	入力フラグの取得
     *	@return	CInputFlag
     */
    CInputFlag *getInputFlag() ;
    
} ;


// 入力フラグマクロ
#define inputflag (*CInputManager::getInstance()->getInputFlag())

#endif /* inputManager_hpp */
