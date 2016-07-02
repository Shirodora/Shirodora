//
//  Move.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#include "Move.hpp"

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// 移動クラス
//
//=========================================================================
#ifdef cocos
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CMove::CMove() : m_position(0.0f, 0.0f), m_direction(0.0f, 0.0f){
    
}

/**
 *  @desc   コンストラクタ
 */
CMove::CMove(const cocos2d::Vec2 &position,
             const cocos2d::Vec2 &direction,
             float velocity,
             float accele,
             float angle,
             float rotateVel){
    this->setPosition(position) ;
    this->setVelocity(velocity) ;
    this->setAccele(accele) ;
    this->setAngle(angle) ;
    this->setRotateVel(rotateVel) ;
}

/**
 *  @desc   コピーコンストラクタ
 */
CMove::CMove(const CMove &move){
    this->set(move) ;
}

/**
 *  @desc   デストラクタ
 */
CMove::~CMove(){}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   setPosition
 *  @param  position
 */
void CMove::setPosition(const cocos2d::Vec2 &position){
    this->m_position = position ;
}

/**
 *  @desc   setDirection
 *  @param  direction
 */
void CMove::setDirection(const cocos2d::Vec2 &direction){
    // 方向は常に正規化しておく
    this->m_direction = direction.getNormalized() ;
}

/**
 *  @desc   setVelocity
 *  @param  velocity
 */
void CMove::setVelocity(float velocity){
    this->m_velocity = velocity ;
}

/**
 *  @desc   setAccele
 *  @param  accele
 */
void CMove::setAccele(float accele){
    this->m_accele = accele ;
}

/**
 *  @desc   setAngle
 *  @param  angle
 */
void CMove::setAngle(float angle){
    this->m_angle = angle ;
}

/**
 *  @desc   setRotateVel
 *  @param  angleVel
 */
void CMove::setRotateVel(float rotateVel){
    this->m_rotateVel = rotateVel ;
}

/**
 *  @desc   setFriction
 *  @param  friction
 */
void CMove::setFriction(float friction){
    this->m_friction = friction ;
}

/**
 *  @desc   setMaxSpeed
 *  @param  speed
 */
void CMove::setMaxSpeed(float maxSpeed){
    this->m_maxSpeed = maxSpeed ;
}

/**
 *  @desc   set
 *  @param  CMove
 */
void CMove::set(const CMove &move){
    this->setPosition(move.getPosition()) ;
    this->setDirection(move.getDirection()) ;
    this->setVelocity(move.getVelocity()) ;
    this->setAccele(move.getAccele()) ;
    this->setAngle(move.getAngle()) ;
    this->setRotateVel(move.getRotateVel()) ;
    this->setFriction(move.getFriction()) ;
    this->setMaxSpeed(move.getMaxSpeed()) ;
}

//=========================================================================
// get
//=========================================================================
/**
 *  @desc   getPosition
 *  @return position
 */
cocos2d::Vec2 CMove::getPosition() const {return this->m_position ;}

/**
 *  @desc   getDirection
 *  @return directionon
 */
cocos2d::Vec2 CMove::getDirection() const {return this->m_direction ;}

/**
 *  @desc   getVelocity
 *  @return velocity
 */
float CMove::getVelocity() const {return this->m_velocity ;}

/**
 *  @desc   getAccele
 *  @return accele
 */
float CMove::getAccele() const {return this->m_accele ;}

/**
 *  @desc   getAngle
 *  @return angle
 */
float CMove::getAngle() const {return this->m_angle ;}

/**
 *  @desc   getAngleVel
 *  @return angleVel
 */
float CMove::getRotateVel() const {return this->m_rotateVel ;}

/**
 *  @desc   getFriction
 *  @return friction
 */
float CMove::getFriction() const {return this->m_friction ;}

/**
 *  @desc   getMaxSpeed
 *  @return maxSpeed
 */
float CMove::getMaxSpeed() const {return this->m_maxSpeed ;}

//=========================================================================
// メンバ関数
//=========================================================================
// TODO:説明不足
/**
 *  @desc   移動処理
 */
void CMove::moveBy(){
    float friction = 0.0f ;
    if(this->m_friction < this->m_velocity){
        friction = this->m_friction ;
    }else if(0 < this->m_velocity){
        friction = -this->m_velocity ;
    }
    this->m_velocity = this->m_accele + friction ;
    if(this->m_maxSpeed < this->m_velocity){
        this->m_velocity = this->m_maxSpeed ;
    }else if(this->m_velocity < -this->m_maxSpeed){
        this->m_velocity = -this->m_maxSpeed ;
    }
    this->m_position = this->m_position + (this->m_direction * this->m_velocity) ;
    this->m_accele = 0.0f ;
    
    if(this->m_rotateVel != 0.0f){
        this->m_angle = this->m_angle + this->m_rotateVel ;
    }
    
}

#endif  // cocos