//
//  InputLayer.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/06/25.
//
//

#ifndef InputLayer_hpp
#define InputLayer_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// インプット&マウスレイヤークラス
//
//=========================================================================
class CInputLayer : public cocos2d::Layer {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    /**
     *  @desc   constructor
     */
    CInputLayer() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CInputLayer() override ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    
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
     *  @desc   update
     *  @param  deltaTime
     */
    virtual void update(float deltaTime) override ;
    
};

#endif /* InputLayer_hpp */
