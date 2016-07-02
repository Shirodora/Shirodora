//
//  ActorFactory.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#include "ActorFactory.hpp"
#include "Constants.h"

//=========================================================================
//
// アクター工場テンプレート
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CActorFactoryTemplate::~CActorFactoryTemplate(){}

//=========================================================================
// メンバ関数
//=========================================================================
CActor* CActorFactoryTemplate::createActor(float x, float y){
    CActor* pActor = CCREATE_FUNC::create<CActor>() ;
    
    this->setImage(pActor) ;
    this->setCollisionBody(pActor) ;
    this->setMove(pActor) ;
    pActor->getMove()->setPosition(cocos2d::Vec2(x, y)) ;
    
    pActor->setActivFlag(true) ;
    pActor->setAliveFlag(true) ;
    
    pActor->applyFunc() ;
    
    return pActor ;
}

//=========================================================================
//
// トライアングル工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CTriangleFactory::CTriangleFactory(){}
CTriangleFactory::~CTriangleFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void CTriangleFactory::setImage(CActor* pActor){
    pActor->setTexture("triangle.png") ;
}

void CTriangleFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[3] {
        cocos2d::Vec2(-16.0f, 16.0f),
        cocos2d::Vec2(-16.0f, -16.0f),
        cocos2d::Vec2(16.0f, -16.0f)} ;
    
    CBody collisionBody(3, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void CTriangleFactory::setMove(CActor* pActor){
    
}

//=========================================================================
//
// テトラゴン工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CTetragonFactory::CTetragonFactory(){}
CTetragonFactory::~CTetragonFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void CTetragonFactory::setImage(CActor* pActor){
    pActor->setTexture("tetragon.png") ;
}

void CTetragonFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[4] {
        cocos2d::Vec2(-3.0f, 17.0f),
        cocos2d::Vec2(-15.0f, 0.0f),
        cocos2d::Vec2(0.0f, -21.0f),
        cocos2d::Vec2(26.0f, 5.0f)} ;
    
    CBody collisionBody(4, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void CTetragonFactory::setMove(CActor* pActor){
    
}

//=========================================================================
//
// ペンタゴン工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CPentagonFactory::CPentagonFactory(){}
CPentagonFactory::~CPentagonFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void CPentagonFactory::setImage(CActor* pActor){
    pActor->setTexture("pentagon.png") ;
}

void CPentagonFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[5] {
        cocos2d::Vec2(-7.0f, 19.0f),
        cocos2d::Vec2(-18.0f, 6.0f),
        cocos2d::Vec2(-7.0f, -16.0f),
        cocos2d::Vec2(16.0f, -9.0f),
        cocos2d::Vec2(19.0f, 24.0f)} ;
    
    CBody collisionBody(5, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void CPentagonFactory::setMove(CActor* pActor){
    
}

//=========================================================================
//
// ヘキサゴン工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CHexagonFactory::CHexagonFactory(){}
CHexagonFactory::~CHexagonFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void CHexagonFactory::setImage(CActor* pActor){
    pActor->setTexture("hexagon.png") ;
}

void CHexagonFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[6] {
        cocos2d::Vec2(-4.0f, 31.0f),
        cocos2d::Vec2(-17.0f, 18.0f),
        cocos2d::Vec2(-18.0f, -11.0f),
        cocos2d::Vec2(9.0f, -21.0f),
        cocos2d::Vec2(23.0f, -1.0f),
        cocos2d::Vec2(18.0f, 17.0f)} ;
    
    CBody collisionBody(6, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void CHexagonFactory::setMove(CActor* pActor){
    
}

//=========================================================================
//
// ヘプタゴン工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CHeptagonFactory::CHeptagonFactory(){}
CHeptagonFactory::~CHeptagonFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void CHeptagonFactory::setImage(CActor* pActor){
    pActor->setTexture("heptagon.png") ;
}

void CHeptagonFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[7] {
        cocos2d::Vec2(-6.0f, 24.0f),
        cocos2d::Vec2(-20.0f, 17.0f),
        cocos2d::Vec2(-28.0f, -14.0f),
        cocos2d::Vec2(-21.0f, -28.0f),
        cocos2d::Vec2(-2.0f, -24.0f),
        cocos2d::Vec2(14.0f, -12.0f),
        cocos2d::Vec2(10.0f, 16.0f)} ;
    
    CBody collisionBody(7, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void CHeptagonFactory::setMove(CActor* pActor){
    
}

//=========================================================================
//
// オクタゴン工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
COctagonFactory::COctagonFactory(){}
COctagonFactory::~COctagonFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void COctagonFactory::setImage(CActor* pActor){
    pActor->setTexture("octagon.png") ;
}

void COctagonFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[8] {
        cocos2d::Vec2(15.0f, 20.0f),
        cocos2d::Vec2(-14.0f, 14.0f),
        cocos2d::Vec2(-20.0f, 7.0f),
        cocos2d::Vec2(-21.0f, -1.0f),
        cocos2d::Vec2(-19.0f, -8.0f),
        cocos2d::Vec2(-13.0f, -14.0f),
        cocos2d::Vec2(-4.0f, -15.0f),
        cocos2d::Vec2(5.0f, -10.0f)} ;
    
    CBody collisionBody(8, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void COctagonFactory::setMove(CActor* pActor){
    
}

//=========================================================================
//
// ノナゴン工場
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CNonagonFactory::CNonagonFactory(){}
CNonagonFactory::~CNonagonFactory(){}

//=========================================================================
// メンバ関数
//=========================================================================
void CNonagonFactory::setImage(CActor* pActor){
    pActor->setTexture("nonagon.png") ;
}

void CNonagonFactory::setCollisionBody(CActor* pActor){
    cocos2d::Vec2 apexs[9] {
        cocos2d::Vec2(-17.0f, 22.0f),
        cocos2d::Vec2(-21.0f, 9.0f),
        cocos2d::Vec2(7.0f, -24.0f),
        cocos2d::Vec2(13.0f, -25.0f),
        cocos2d::Vec2(17.0f, -25.0f),
        cocos2d::Vec2(21.0f, -23.0f),
        cocos2d::Vec2(22.0f, -18.0f),
        cocos2d::Vec2(22.0f, -13.0f),
        cocos2d::Vec2(-4.0f, 18.0f)} ;
    
    CBody collisionBody(9, apexs) ;
    pActor->setCollisionBody(collisionBody) ;
}
void CNonagonFactory::setMove(CActor* pActor){
    
}