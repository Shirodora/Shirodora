//
//  GamePouse.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/14.
//
//

#ifndef GamePouse_hpp
#define GamePouse_hpp

#include <stdio.h>

#include "Constants.h"
#include "InputAndTouchLayer.hpp"
#include "Actor.hpp"

//=========================================================================
//
// ゲームポーズシーンクラス
//
//=========================================================================
class CGamePouse : public cocos2d::Scene {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CGamePouse() ;
    
    ~CGamePouse() ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    CInputAndTouchLayer*        m_pMainLayer {NULL} ;
    CActor* m_pActor {NULL} ;
    std::vector<CActor*>* m_pActors {NULL} ;
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
     *  @desc   checkCollision
     */
    bool checkCollision() ;
    
    /**
     *  @desc   createDotImage
     */
    void createDotImage() ;
    
    /**
     *  @desc   goTitle
     */
    void goTitle(cocos2d::Ref* pSender) ;
    
    /**
     *  @desc   end
     */
    void end(cocos2d::Ref* pSender) ;
};

#endif /* GamePouse_hpp */
