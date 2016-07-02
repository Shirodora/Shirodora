//
//  Object.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#include "Object.hpp"

//=========================================================================
//
// CObject
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CObject::CObject(){
    if(this->m_pCollisionBody == NULL){this->m_pCollisionBody = new CBody() ;}
    if(this->m_pMove == NULL){this->m_pMove = new CMove() ;}
}
CObject::~CObject(){
    if(this->m_pCollisionBody != NULL){delete this->m_pCollisionBody ; this->m_pCollisionBody = NULL ;}
    if(this->m_pMove != NULL){delete this->m_pMove ; this->m_pMove = NULL ;}
}

//=========================================================================
// init
//=========================================================================
bool CObject::init(){
    if(cocos2d::Sprite::init() == false) return false ;
    this->scheduleUpdate() ;
    return true ;
}

//=========================================================================
// set
//=========================================================================
void CObject::setCollisionBody(const CBody& collisionBody){
    this->m_pCollisionBody->set(collisionBody) ;
}

void CObject::setMove(const CMove& move){
    this->m_pMove->set(move) ;
}

void CObject::setActivFlag(bool flag){this->m_isActivflag = flag ;}

void CObject::setAliveFlag(bool flag){this->m_isAlive = flag ;}

//=========================================================================
// get
//=========================================================================
CBody* CObject::getCollisionBody(){
    return this->m_pCollisionBody ;
}
CMove* CObject::getMove(){
    return this->m_pMove ;
}
bool CObject::isActive(){
    return this->m_isActivflag ;
}
bool CObject::isAlive(){
    return this->m_isAlive ;
}

//=========================================================================
// メンバ関数
//=========================================================================
void CObject::update(float deltaTime){
    //CCLOG("CObjectのupdate") ;
    this->moveFunc() ;
    this->animeationFunc() ;
    this->collisionFunc() ;
    this->applyFunc() ;
    this->hitFunc() ;
}


//=========================================================================
//
// オブジェクト走査クラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CObjectAggregate::CObjectAggregate(){}
CObjectAggregate::~CObjectAggregate(){}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   オブジェクトを取り付けるレイヤーの設定
 */
void CObjectAggregate::setLayer(cocos2d::Layer* pLayer){
    if(this->m_pLayer != NULL) return ;
    this->m_pLayer = pLayer ;
}

/**
 *  @desc   オブジェクト群を設定
 */
void CObjectAggregate::setObjects(std::vector<CObject*>* pObjects){
    if(this->m_pObjects != NULL) return ;
    this->m_pObjects = pObjects ;
}

//=========================================================================
// get
//=========================================================================
/**
 *  @desc   取り付けられているオブジェクトの数を返す
 *  @return int
 */
int CObjectAggregate::getSize(){
    return this->m_pObjects->size() ;
}

/**
 *  @desc   オブジェクト群を取得
 *  @return std::vector<CObject*>*
 */
std::vector<CObject*>* CObjectAggregate::getObjects(){
    return this->m_pObjects ;
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   オブジェクトの追加
 *  @param  CObject*
 */
void CObjectAggregate::add(CObject* pObject){
    this->m_pObjects->push_back(pObject) ;
    this->m_pLayer->addChild(pObject) ;
}

/**
 *  @desc   オブジェクトのレイヤーからの取り外しと、vectorからの取り外し
 *  @param  std::vector<CObject*>*
 */
void CObjectAggregate::checkAndRemove(){
    std::vector<CObject*>::iterator itr = (*this->m_pObjects).begin() ;
    while(itr != (*this->m_pObjects).end()){
        if((*itr)->isActive() == false){
            (*itr)->removeFromParent() ;
            if((*itr) != NULL){
                delete (*itr) ;
                *itr = NULL ;
            }
            this->m_pObjects->erase(itr) ;
        }else{
            itr++ ;
        }
    }
}