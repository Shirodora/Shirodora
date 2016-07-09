//
//  Character.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#ifdef  OK

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "Actor.hpp"
#include "Animation.hpp"
#include "Body.hpp"
#include "Move.hpp"

//=========================================================================
//
// Character
//
//=========================================================================
class CCharacter : public CActor {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   constructor
     */
    CCharacter() ;
    
    /**
     *  @desc   destructor
     */
    virtual ~CCharacter() ;
    
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   位置データ設定
     *  @param  CMove*
     */
    inline void setMove(CMove *pMove){this->m_pMove = pMove ;}
    
    /**
     *  @desc   画像設定
     *  @param  cocos2d::Sprite
     */
    inline void setSprite(cocos2d::Sprite *pSprite){this->m_pSprite = pSprite ; this->addChild(this->m_pSprite) ;}
    
    /**
     *  @desc   実体データ設定
     *  @param  CBody*
     */
    inline void setCollisionBody(CBody *pCollisionBody){this->m_pCollisionBody = pCollisionBody ;}
    
    /**
     *  @desc   アニメーションデータ群設定
     *  @param  std::vector<CAnimation*>*
     */
    inline void setAnimations(std::vector<CAnimation*> *pAnimations){this->m_pAnimations = pAnimations ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   位置データ取得
     *  @return CMove*
     */
    inline CMove *getMove(){return this->m_pMove ;}
    
    /**
     *  @desc   画像取得
     *  @return cocos2d::Sprite*
     */
    inline cocos2d::Sprite *getSprite(){return this->m_pSprite ;}
    
    /**
     *  @desc   実体データ取得
     *  @return CBody*
     */
    inline CBody *getCollisionBody(){return this->m_pCollisionBody ;}
    
    /**
     *  @desc   アニメーションデータ群取得
     *  @return std::vector<CAnimation*>*
     */
    inline std::vector<CAnimation*> *getAnimations(){return this->m_pAnimations ;}
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   CCharacter１体との衝突判定
     */
    virtual bool collisionAt(CCharacter*) = 0 ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // 位置データ
    CMove *m_pMove {NULL} ;
    // 画像データ
    cocos2d::Sprite *m_pSprite {NULL} ;
    // 実体データ
    CBody *m_pCollisionBody {NULL} ;
    // アニメーションデータ群
    std::vector<CAnimation*> *m_pAnimations {NULL} ;
    
};

#endif  // OK

#endif /* Character_hpp */