//
//  Move.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>

//=========================================================================
// マクロ指定
//=========================================================================
// cocos使用
#define cocos

// オリジナルCVector2使用
//#define CVector2

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

//=========================================================================
//
// 移動クラス
//
//=========================================================================
class CMove {
#ifdef cocos
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // 位置
    cocos2d::Vec2 m_position ;
    // 方向
    cocos2d::Vec2 m_direction ;
    // 速度
    float m_velocity = 0.0f ;
    // 加速度
    float m_accele = 0.0f ;
    // 角度
    float m_angle = 0.0f ;
    // 角速度
    float m_rotateVel = 0.0f ;
    // 摩擦係数
    float m_friction = 0.3f ;
    // 最大速度
    float m_maxSpeed = 4.0f ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    /**
     *  @desc   コンストラクタ
     */
    CMove() ;
    
    /**
     *  @desc   コンストラクタ
     */
    CMove(const cocos2d::Vec2 &position,
          const cocos2d::Vec2 &direction = cocos2d::Vec2::ZERO,
          float velocity = 0.0f,
          float accele = 0.0f,
          float angle = 0.0f,
          float rotateVel = 0.0f) ;
    
    /**
     *  @desc   コピーコンストラクタ
     */
    CMove(const CMove &move) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CMove() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    //=========================================================================
    // set
    //=========================================================================
public :
    /**
     *  @desc   setPosition
     *  @param  position
     */
    void setPosition(const cocos2d::Vec2 &position) ;
    
    /**
     *  @desc   setDirection
     *  @param  direction
     */
    void setDirection(const cocos2d::Vec2 &direction) ;
    
    /**
     *  @desc   setVelocity
     *  @param  velocity
     */
    void setVelocity(float velocity) ;
    
    /**
     *  @desc   setAccele
     *  @param  accele
     */
    void setAccele(float accele) ;
    
    /**
     *  @desc   setAngle
     *  @param  angle
     */
    void setAngle(float angle) ;
    
    /**
     *  @desc   setRotateVel
     *  @param  angleVel
     */
    void setRotateVel(float rotateVel) ;
    
    /**
     *  @desc   setFriction
     *  @param  friction
     */
    void setFriction(float friction) ;
    
    /**
     *  @desc   setMaxSpeed
     *  @param  maxSpeed
     */
    void setMaxSpeed(float maxSpeed) ;
    
    /**
     *  @desc   set
     *  @param  CMove
     */
    void set(const CMove &move) ;
    
    //=========================================================================
    // get
    //=========================================================================
public :
    /**
     *  @desc   getPosition
     *  @return position
     */
    cocos2d::Vec2 getPosition() const ;
    
    /**
     *  @desc   getDirection
     *  @return directionon
     */
    cocos2d::Vec2 getDirection() const ;
    
    /**
     *  @desc   getVelocity
     *  @return velocity
     */
    float getVelocity() const ;
    
    /**
     *  @desc   getAccele
     *  @return accele
     */
    float getAccele() const ;
    
    /**
     *  @desc   getAngle
     *  @return angle
     */
    float getAngle() const ;
    
    /**
     *  @desc   getAngleVel
     *  @return angleVel
     */
    float getRotateVel() const ;
    
    /**
     *  @desc   getFriction
     *  @return friction
     */
    float getFriction() const ;
    
    /**
     *  @desc   getMaxSpeed
     *  @return maxSpeed
     */
    float getMaxSpeed() const ;
    
    //=========================================================================
    // 特殊関数
    //=========================================================================
public :
    /**
     *  @desc   移動処理
     */
    void moveBy() ;
    
#endif  // cocos
};

#endif /* Move_hpp */
