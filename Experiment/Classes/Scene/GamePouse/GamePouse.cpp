//
//  GamePouse.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/14.
//
//

#include "GamePouse.hpp"
#include "ActorFactoryManager.hpp"
#include "CollisionData.hpp"
#include "GameTitle.hpp"

CGamePouse::CGamePouse(){
    
}

CGamePouse::~CGamePouse(){
    
}
//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   init
 */
bool CGamePouse::init(){
    if(cocos2d::Scene::init() == false) return false ;
    
    this->m_pMainLayer = CCREATE_FUNC::create<CInputAndTouchLayer>() ;
    this->addChild(this->m_pMainLayer) ;
    
    this->m_pActor = CActorFactoryManager::getInstance()->createActor(CActorFactoryManager::ACTOR_TYPE::TRIANGLE, 300.f, 300.0f) ;
    this->addChild(this->m_pActor) ;
    
    // スケジューラーに登録
    this->scheduleUpdate();
    
    return true ;
}

/**
 *  @desc   update
 */
void CGamePouse::update(float deltaTime_){
    if(inputflag.m_esc.isPressed() == true){
        this->end(this) ;
    }
    
    /*
    if(inputflag.m_c.isPressed() == true){
        CCollisionData myCollision(CMove(cocos2d::Vec2(300.746368f, 311.989594f)), CBody()) ;
        CCollisionData objCollision(*this->m_pActor->getMove(), *this->m_pActor->getCollisionBody()) ;
        
        if(myCollision.collisionDecision(objCollision) == true){
            CCLOG(" HIT ! ! ") ;
        }else{
            CCLOG("   NO   ") ;
        }
    }
     */
    
    // dotを打ってチェックするやつ
    if(touchData.isTouching() == true){
        //CCLOG("(%f, %f)", touchData.getCurrentPos().x, touchData.getCurrentPos().y) ;
        CCollisionData myCollision(CMove(cocos2d::Vec2(touchData.getCurrentPos())), CBody()) ;
        CCollisionData objCollision(*this->m_pActor->getMove(), *this->m_pActor->getCollisionBody()) ;
        
        if(myCollision.collisionDecision(objCollision) == true){
            this->createDotImage() ;
            CCLOG("HIT (%f, %f)", touchData.getCurrentPos().x, touchData.getCurrentPos().y) ;
        }
    }
    
    if(inputflag.m_z.isPressed() == true){
        this->goTitle(this) ;
    }
}

/**
 *  @desc   checkCollision
 */
bool CGamePouse::checkCollision(){
    
}

/**
 *  @desc   createDotImage
 */
void CGamePouse::createDotImage(){
    cocos2d::Sprite* pDot = cocos2d::Sprite::create() ;
    pDot->setTexture("dot.png") ;
    pDot->setPosition(touchData.getCurrentPos()) ;
    this->addChild(pDot) ;
}

/**
 *  @desc   goTitle
 */
void CGamePouse::goTitle(cocos2d::Ref* pSender){
    CCLOG("終了") ;
    cocos2d::Director::getInstance()->replaceScene(CCREATE_FUNC::create<CGameTitle>()) ;
}

/**
 *  @desc   end
 */
void CGamePouse::end(cocos2d::Ref* pSender){
    CCLOG("終了") ;
    cocos2d::Director::getInstance()->end() ;
}