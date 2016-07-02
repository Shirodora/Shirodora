//
//  GameTitle.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/02.
//
//

#ifndef GameTitle_hpp
#define GameTitle_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Constants.h"
#include "InputLayer.hpp"
#include "TouchLayer.hpp"

//=========================================================================
//
// ゲームタイトルシーンクラス
//
//=========================================================================
class CGameTitle : public cocos2d::Scene {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CGameTitle() ;
    
    ~CGameTitle() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    CInputLayer*        m_pMainLayer {NULL} ;
    CTouchLayer*        m_pSubLayer {NULL} ;
    
    cocos2d::Sprite*    m_pMainSprite {NULL} ;
    cocos2d::Label*     m_pLabel {NULL} ;
    
    cocos2d::Menu*      m_pMenu {NULL} ;
    cocos2d::MenuItemImage* m_pCloseButtom {NULL} ;
    
    // 何かしらのカウンター
    int m_counter = 0 ;
    
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
     *  @desc   goSelect
     */
    void goSelect(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   goDemo
     */
    void goDemo(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   goPouse
     */
    void goPouse(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   end
     */
    void end(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   createLabel
     */
    void createLabel(int type) ;
    
    /**
     *  @desc   counterManager
     */
    void counterManager() ;
};

#endif /* GameTitle_hpp */
