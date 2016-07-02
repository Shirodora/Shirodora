//
//  Actor.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#include "Actor.hpp"

//=========================================================================
//
// CActor
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CActor::CActor(){
    if(this->m_attackBody == NULL){this->m_attackBody = new CBody() ;}
}

CActor::~CActor(){
    if(this->m_attackBody != NULL){delete this->m_attackBody ; this->m_attackBody = NULL ;}
}

//=========================================================================
// init
//=========================================================================
bool CActor::init(){
    if(CObject::init() == false) return false ;
    return true ;
}

//=========================================================================
// set
//=========================================================================
void CActor::setAttackBody(const CBody& attackBody){
    this->m_attackBody->set(attackBody) ;
}

//=========================================================================
// get
//=========================================================================
CBody* CActor::getAttackBody(){
    return this->m_attackBody ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   updata
 */
void CActor::update(float deltaTime){
    CObject::update(deltaTime) ;
    //CCLOG("CActorのupdate") ;
    this->attackFunc() ;
}

void CActor::moveFunc(){
    //CCLOG("move") ;
}

void CActor::animeationFunc(){
    //CCLOG("animation") ;
}

void CActor::collisionFunc(){
    //CCLOG("collision") ;
}

void CActor::applyFunc(){
    this->setPosition(this->getMove()->getPosition().x, this->getMove()->getPosition().y) ;
}

void CActor::hitFunc(){
    //CCLOG("hit") ;
}

void CActor::attackFunc(){
    //CCLOG("attack") ;
}