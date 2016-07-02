//
//  GameSelect.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/02.
//
//

#ifndef GameSelect_hpp
#define GameSelect_hpp

#include <stdio.h>
#include "InputLayer.hpp"

//=========================================================================
//
// ゲームセレクトシーンクラス
//
//=========================================================================
class CGameSelect : public cocos2d::Scene {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CGameSelect() ;
    
    ~CGameSelect() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    enum class LAYER_NO {
        LAYER_0 = 0,
        LAYER_1 = 1,
    };
    
    LAYER_NO    m_layerNo = LAYER_NO::LAYER_0 ;
    
    cocos2d::Layer*     m_layers[2] {NULL} ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    /**
     *  @desc   init
     */
    bool init() override ;
    
    /**
     *  @desc   update
     */
    virtual void update(float deltaTime_) override ;
    
    /**
     *  @desc   goTitle
     */
    void goDemo(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   end
     */
    void end(cocos2d::Ref* pSender) ;
    
    /**
     *  @LAYER_NO切り替え
     */
    void changeLayerNo() ;
};

#endif /* GameSelect_hpp */
