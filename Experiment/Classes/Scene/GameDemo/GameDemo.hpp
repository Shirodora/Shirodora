//
//  GameDemo.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/09.
//
//

#ifndef GameDemo_hpp
#define GameDemo_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.h"
#include "InputAndTouchLayer.hpp"
#include <vector>
#include "Object.hpp"

//=========================================================================
//
// ゲームデモシーンクラス
//
//=========================================================================
class CGameDemo : public cocos2d::Scene {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CGameDemo() ;
    
    ~CGameDemo() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    CInputAndTouchLayer*        m_pMainLayer {NULL} ;
    std::vector<CObject*>*      m_pObjects {NULL} ;
    
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
     *  @desc   hit
     */
    void hit() ;
    
    /**
     *  @desc   goTitle
     */
    void goTitle(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   goSelect
     */
    void goSelect(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   end
     */
    void end(cocos2d::Ref* pSender) ;
};

#endif /* GameDemo_hpp */
