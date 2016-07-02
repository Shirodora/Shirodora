//
//  InputAndMouseLayer.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/24.
//
//

#ifndef InputAndMouseLayer_hpp
#define InputAndMouseLayer_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// インプット&マウスレイヤークラス
//
//=========================================================================
class CInputAndMouseLayer : public cocos2d::Layer {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    /**
     *  @desc   constructor
     */
    CInputAndMouseLayer() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CInputAndMouseLayer() override ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    // マウスイベントリスナー
    cocos2d::EventListenerMouse *m_pEventListenerMouse ;
    
    //=========================================================================
    // init
    //=========================================================================
public :
    /**
     *  @desc   init
     */
    virtual bool init() override ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    /**
     *	@desc	キーを押した時の処理
     *	@param	キーコード
     *	@param	イベント
     */
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) override ;
    
    /**
     *	@desc	キーを離した時の処理
     *	@param	キーコード
     *	@param	イベント
     */
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) override ;
    
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
     *  @desc   update
     *  @param  deltaTime
     */
    virtual void update(float deltaTime) override ;
    
};

#endif /* InputAndMouseLayer_hpp */
