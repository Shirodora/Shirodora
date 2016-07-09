//
//  Pawn.hpp
//  BarrageGame
//
//  Created by Ryoutarou Onimura on 2016/07/08.
//
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// Pawn
//
//=========================================================================
class CPawn : public cocos2d::Node {
public :
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
    /**
     *  @desc   destructor
     */
    virtual ~CPawn(){}
    
    //=========================================================================
    // init
    //=========================================================================
    /**
     *  @desc   init
     */
    virtual bool init() override {
        if(cocos2d::Node::init() == false) return false ;
        
        // 各フラグを立ておく
        this->m_isActive = true ;
        this->m_isAlive = true ;
        
        return true ;
    }
    
    //=========================================================================
    // set
    //=========================================================================
    /**
     *  @desc   setActiveFlag
     */
    inline void setActive(bool flag){this->m_isActive = flag ;}
    
    /**
     *  @desc   setAliveFlag
     */
    inline void setAlive(bool flag){this->m_isAlive = flag ;}
    
    //=========================================================================
    // get
    //=========================================================================
    /**
     *  @desc   getActive
     */
    inline bool isActive(){return this->m_isActive ;}
    
    /**
     *  @desc   getAliveFlag
     */
    inline bool isAlive(){return this->m_isAlive ;}
    
    /**
     *  @desc   pause
     *  @tips   ポーズをかけた時に、自身に取り付けた子供も一緒にポーズさせる
     */
    inline virtual void pause() override {
        cocos2d::Node::pause() ;
        cocos2d::Vector<cocos2d::Node*> pChildren = this->getChildren() ;
        for(cocos2d::Node *pNode : pChildren){
            pNode->pause() ;
        }
    }
    
    /**
     *  @desc   resume
     *  @tips   ポーズを解除する時に、自身に取り付けた子供も一緒にポーズ解除する
     */
    inline virtual void resume() override {
        cocos2d::Node::resume() ;
        cocos2d::Vector<cocos2d::Node*> pChildren = this->getChildren() ;
        for(cocos2d::Node *pNode : pChildren){
            pNode->resume() ;
        }
    }
    
    /**
     *  @desc   衝突判定処理
     */
    virtual void collision() = 0 ;
    
    /**
     *  @desc   状態チェック処理
     */
    virtual void checkState() = 0 ;
    
    /**
     *  @desc   反映処理
     */
    virtual void apply() = 0 ;
    
protected :
    //=========================================================================
    // メンバ変数
    //=========================================================================
    // アクティブフラグ
    bool m_isActive = false ;
    // 生死フラグ
    bool m_isAlive = false ;
    
};

#endif /* Pawn_hpp */
