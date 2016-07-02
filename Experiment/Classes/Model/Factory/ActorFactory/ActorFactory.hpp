//
//  ActorFactory.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#ifndef ActorFactory_hpp
#define ActorFactory_hpp

#include <stdio.h>
#include "Actor.hpp"

//=========================================================================
//
// アクター工場テンプレート
//
//=========================================================================
class CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    virtual ~CActorFactoryTemplate() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor*) = 0 ;
    virtual void setCollisionBody(CActor*) = 0 ;
    virtual void setMove(CActor*) = 0 ;
    
    virtual CActor* createActor(float x, float y) ;
};

//=========================================================================
//
// トライアングル工場
//
//=========================================================================
class CTriangleFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CTriangleFactory() ;
    virtual ~CTriangleFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};

//=========================================================================
//
// テトラゴン工場
//
//=========================================================================
class CTetragonFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CTetragonFactory() ;
    virtual ~CTetragonFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};

//=========================================================================
//
// ペンタゴン工場
//
//=========================================================================
class CPentagonFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CPentagonFactory() ;
    virtual ~CPentagonFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};

//=========================================================================
//
// ヘキサゴン工場
//
//=========================================================================
class CHexagonFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CHexagonFactory() ;
    virtual ~CHexagonFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};

//=========================================================================
//
// ヘプタゴン工場
//
//=========================================================================
class CHeptagonFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CHeptagonFactory() ;
    virtual ~CHeptagonFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};

//=========================================================================
//
// オクタゴン工場
//
//=========================================================================
class COctagonFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    COctagonFactory() ;
    virtual ~COctagonFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};

//=========================================================================
//
// ノナゴン工場
//
//=========================================================================
class CNonagonFactory : public CActorFactoryTemplate {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CNonagonFactory() ;
    virtual ~CNonagonFactory() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    virtual void setImage(CActor* pActor) override ;
    virtual void setCollisionBody(CActor* pActor) override ;
    virtual void setMove(CActor* pActor) override ;
};


#endif /* ActorFactory_hpp */
