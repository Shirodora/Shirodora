//
//  GameDemo.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/09.
//
//

#include "GameDemo.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include "GameTitle.hpp"
#include "GameSelect.hpp"
#include "ActorFactoryManager.hpp"
#include "CollisionData.hpp"


CGameDemo::CGameDemo(){
    if(this->m_pObjects == NULL){
        this->m_pObjects = new std::vector<CObject*>() ;
    }
}

CGameDemo::~CGameDemo(){
    if(this->m_pObjects != NULL){
        delete this->m_pObjects ;
        this->m_pObjects = NULL ;
    }
}

/**
 *  @desc   init
 */
bool CGameDemo::init(){
    if(cocos2d::Scene::init() == false) return false ;
    
    this->m_pMainLayer = CCREATE_FUNC::create<CInputAndTouchLayer>() ;
    this->addChild(this->m_pMainLayer) ;
    
    CObjectAggregate::getInstance()->setLayer(this->m_pMainLayer) ;
    CObjectAggregate::getInstance()->setObjects(this->m_pObjects) ;
    
    // スケジューラーに登録
    this->scheduleUpdate();
    
    return true;
}

/**
 *  @desc   update
 */
void CGameDemo::update(float deltaTime_){
    //this->m_pMainLayer->update(deltaTime_) ;
    
    if(inputflag.m_space.isInput() == true && touchData.isTouched() == true){
        CObject* pObject = CActorFactoryManager::getInstance()->createActor(CActorFactoryManager::ACTOR_TYPE::TRIANGLE, touchData.getStartPos().x, touchData.getStartPos().y) ;
        CObjectAggregate::getInstance()->add(pObject) ;
    }
    
//    if(inputflag.m_c.isInput() == true && touchData.isTouching() == true){
//        CCollisionData myCollision ;
//        for(CObject* pObj : (*this->m_pObjects)){
//            CCollisionData objCollision(*pObj->getCollisionBody(), *pObj->getMove()) ;
//            if(myCollision.collisionDecision(objCollision) == true){
//                this->hit() ;
//            }
//        }
//        
//    }
    
    if(inputflag.m_d.isReleased() == true ){
        this->goTitle(this) ;
    }
    if(inputflag.m_a.isPressed() == true){
        this->goSelect(this) ;
    }
    if(inputflag.m_z.isInput() == true){
        CCLOG("Demo") ;
    }
    if(inputflag.m_esc.isPressed() == true){
        this->end(this) ;
    }
    
    CObjectAggregate::getInstance()->checkAndRemove() ;
}

/**
 *  @desc   collision
 */
void CGameDemo::hit(){
    CCLOG("HIT!!") ;
}

/**
 *  @desc   goTitle
 */
void CGameDemo::goTitle(cocos2d::Ref* pSender){
    CCLOG("タイトルへ戻る") ;
    cocos2d::Director::getInstance()->popScene() ;
}

/**
 *  @desc   goSelect
 */
void CGameDemo::goSelect(cocos2d::Ref* pSender){
    CCLOG("セレクト画面へ移る") ;
    cocos2d::Director::getInstance()->pushScene(CCREATE_FUNC::create<CGameSelect>()) ;
}

/**
 *  @desc   end
 */
void CGameDemo::end(cocos2d::Ref* pSender){
    CCLOG("終了") ;
    cocos2d::Director::getInstance()->end() ;
}