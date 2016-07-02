//
//  GameSelect.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/02.
//
//

#include "GameSelect.hpp"
#include "Constants.h"
#include "SceneHeaders.h"
#include "GameSelectLayer.hpp"

CGameSelect::CGameSelect(){}

CGameSelect::~CGameSelect(){}

/**
 *  @desc   init
 */
bool CGameSelect::init(){
    if(cocos2d::Scene::init() == false) return false ;
    
    this->m_layers[(int)LAYER_NO::LAYER_0] = CCREATE_FUNC::create<CGameSelectLayer0>() ;
    this->addChild(this->m_layers[(int)LAYER_NO::LAYER_0], 1) ;
    
    this->m_layers[(int)LAYER_NO::LAYER_1] = CCREATE_FUNC::create<CGameSelectLayer1>() ;
    this->addChild(this->m_layers[(int)LAYER_NO::LAYER_1], 0) ;
    
    // スケジューラーに登録
    this->scheduleUpdate();
    
    return true ;
}

/**
 *  @desc   update
 */
void CGameSelect::update(float deltaTime_){
    CCLOG("LAYER_TYPE : %d", (int)this->m_layerNo) ;
    if(inputflag.m_esc.isInput()){
        this->end(this) ;
    }
    
    if(inputflag.m_s.isPressed() == true){
        this->goDemo(this) ;
    }
    
    if(inputflag.m_a.isPressed() == true){
        
        if(this->m_layerNo == LAYER_NO::LAYER_0){
            if(this->m_layers[(int)LAYER_NO::LAYER_1] == NULL){
                CCLOG("NULL LAYER_NO::LAYER_1") ;
            }else{
                CCLOG("LAYER_NO::LAYER_1") ;
                
                this->reorderChild(this->m_layers[(int)LAYER_NO::LAYER_1], 1) ;
                this->reorderChild(this->m_layers[(int)LAYER_NO::LAYER_0], 0) ;
            }
            
        }else if(this->m_layerNo == LAYER_NO::LAYER_1){
            if(this->m_layers[(int)LAYER_NO::LAYER_0] == NULL){
                CCLOG("NULL LAYER_NO::LAYER_0") ;
            }else{
                CCLOG("LAYER_NO::LAYER_0") ;
                
                this->reorderChild(this->m_layers[(int)LAYER_NO::LAYER_0], 1) ;
                this->reorderChild(this->m_layers[(int)LAYER_NO::LAYER_1], 0) ;
            }
        }
        this->changeLayerNo() ;
    }
    
    if(inputflag.m_d.isReleased() == true){
        this->m_layers[(int)LAYER_NO::LAYER_0]->removeFromParent() ;
        this->m_layers[(int)LAYER_NO::LAYER_0] = CCREATE_FUNC::create<CGameSelectLayer1>() ;
        if(this->m_layerNo == LAYER_NO::LAYER_0){
            this->addChild(this->m_layers[(int)LAYER_NO::LAYER_0], 1) ;
        }else{
            this->addChild(this->m_layers[(int)LAYER_NO::LAYER_0], 0) ;
        }
//        if(this->m_layers[(int)LAYER_NO::LAYER_0] == NULL){
//            this->m_layers[(int)LAYER_NO::LAYER_0] = CCREATE_FUNC::create<CGameSelectLayer1>() ;
//        }
    }
    
    if(inputflag.m_c.isPressed() == true){
        cocos2d::Director::getInstance()->replaceScene(CCREATE_FUNC::create<CGameSelect>()) ;
    }
    
    this->m_layers[(int)this->m_layerNo]->update(deltaTime_) ;
}

/**
 *  @desc   goTitle
 */
void CGameSelect::goDemo(cocos2d::Ref* pSender){
    CCLOG("デモへ戻る") ;
    cocos2d::Director::getInstance()->popScene() ;
}

/**
 *  @desc   end
 */
void CGameSelect::end(cocos2d::Ref* pSender){
    CCLOG("終了") ;
    cocos2d::Director::getInstance()->end() ;
}

/**
 *  @desc   LAYER_NO切り替え
 */
void CGameSelect::changeLayerNo(){
    if(this->m_layerNo == LAYER_NO::LAYER_0){
        this->m_layerNo = LAYER_NO::LAYER_1 ;
        return ;
    }else if(this->m_layerNo == LAYER_NO::LAYER_1){
        this->m_layerNo = LAYER_NO::LAYER_0 ;
        return ;
    }
}