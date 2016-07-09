//
//  Character.cpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#include "Character.hpp"

#ifdef  OK

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// Character
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CCharacter::CCharacter(){/*処理なし*/}

/**
 *  @desc   destructor
 */
CCharacter::~CCharacter(){
    // 位置データ解放
    if(this->m_pMove != NULL){
        delete this->m_pMove ;
        this->m_pMove = NULL ;
    }
    // 実体データ解放
    if(this->m_pCollisionBody != NULL){
        delete this->m_pCollisionBody ;
        this->m_pCollisionBody = NULL ;
    }
    // アニメーションデータ群解放
    for(CAnimation *pAnimation : (*this->m_pAnimations)){
        if(pAnimation != NULL){
            delete pAnimation ;
            pAnimation = NULL ;
        }
    }
    if(this->m_pAnimations != NULL){
        delete this->m_pAnimations ;
        this->m_pAnimations = NULL ;
    }
}

#endif  // OK