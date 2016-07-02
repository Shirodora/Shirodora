//
//  ActorFactoryManager.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#include "ActorFactoryManager.hpp"

//=========================================================================
//
// アクター工場管理
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
CActorFactoryManager::CActorFactoryManager(){
    if(this->m_pFactories == NULL){
        this->m_pFactories = new std::map<ACTOR_TYPE, CActorFactoryTemplate*>() ;
    }
}

CActorFactoryManager::~CActorFactoryManager(){
    std::map<ACTOR_TYPE, CActorFactoryTemplate*>::iterator itr = (*this->m_pFactories).begin() ;
    while(itr != (*this->m_pFactories).end()){
        if(itr->second != NULL){
            delete itr->second ;
            itr->second = NULL ;
        }
        itr++ ;
    }
    if(this->m_pFactories != NULL){
        delete this->m_pFactories ;
        this->m_pFactories = NULL ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
CActorFactoryTemplate* CActorFactoryManager::getFactory(ACTOR_TYPE type){
    std::map<ACTOR_TYPE, CActorFactoryTemplate*>::iterator itr = (*this->m_pFactories).begin() ;
    while(itr != (*this->m_pFactories).end()){
        if(itr->first == type){
            return itr->second ;
        }
        itr++ ;
    }
    CActorFactoryTemplate* pFactory {NULL} ;
    switch(type){
        case ACTOR_TYPE::TRIANGLE :
            pFactory = new CTriangleFactory() ;
            break ;
            
        case ACTOR_TYPE::TETRAGON :
            pFactory = new CTetragonFactory() ;
            break ;
            
        case ACTOR_TYPE::HEXAGON :
            pFactory = new CHexagonFactory() ;
            break ;
            
        case ACTOR_TYPE::PENTAGON :
            pFactory = new CPentagonFactory() ;
            break ;
            
        case ACTOR_TYPE::HEPTAGON :
            pFactory = new CHeptagonFactory() ;
            break ;
            
        case ACTOR_TYPE::OCTAGON :
            pFactory = new COctagonFactory() ;
            break ;
            
        case ACTOR_TYPE::NONAGON :
            pFactory = new CNonagonFactory() ;
            break ;
            
        default :
            break ;
    }
    (*this->m_pFactories)[type] = pFactory ;
    return pFactory ;
}

CActor* CActorFactoryManager::createActor(ACTOR_TYPE type, float x, float y){
    return this->getFactory(type)->createActor(x, y) ;
}