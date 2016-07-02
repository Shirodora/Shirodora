//
//  Object.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include <vector>
#include "Move.hpp"
#include "Body.hpp"
#include "SingletonTemplate.h"

//=========================================================================
//
// CObject
//
//=========================================================================
class CObject : public cocos2d::Sprite {
    //=========================================================================
    // メンバ変数
    //=========================================================================
protected :
    // 衝突Body
    CBody *m_pCollisionBody {NULL} ;
    // Move
    CMove *m_pMove {NULL} ;
    //std::vector<CAnimation*>* m_animations ;
    //std::vector<CAction*>* m_actions ;
    // 有効フラグ
    bool m_isActivflag = false ;
    // 生死フラグ
    bool m_isAlive = false ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CObject() ;
    virtual ~CObject() ;
    
    //=========================================================================
    // init
    //=========================================================================
public :
    virtual bool init() override ;
    
    //=========================================================================
    // set
    //=========================================================================
public :
    void setCollisionBody(const CBody &collisionBody) ;
    void setMove(const CMove &move) ;
    void setActivFlag(bool flag) ;
    void setAliveFlag(bool flag) ;
    
    //=========================================================================
    // get
    //=========================================================================
public :
    CBody *getCollisionBody() ;
    CMove *getMove() ;
    bool isActive() ;
    bool isAlive() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    /**
     *  @desc   updata
     */
    virtual void update(float deltaTime) override ;
    
    virtual void moveFunc() = 0 ;
    virtual void animeationFunc() = 0 ;
    virtual void collisionFunc() = 0 ;
    virtual void applyFunc() = 0 ;
    virtual void hitFunc() = 0 ;
    
};

//=========================================================================
//
// オブジェクト走査クラス
//
//=========================================================================
class CObjectAggregate : public CSingletonTemplate<CObjectAggregate> {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
private :
    friend class CSingletonTemplate<CObjectAggregate> ;
    CObjectAggregate() ;
    virtual ~CObjectAggregate() override ;
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // オブジェクトを取り付けるレイヤー
    cocos2d::Layer *m_pLayer {NULL} ;
    // オブジェクト群
    std::vector<CObject*> *m_pObjects {NULL} ;
    
    //=========================================================================
    // set
    //=========================================================================
public :
    /**
     *  @desc   オブジェクトを取り付けるレイヤーの設定
     */
    void setLayer(cocos2d::Layer *pLayer) ;
    
    /**
     *  @desc   オブジェクト群を設定
     */
    void setObjects(std::vector<CObject*> *pObjects) ;
    
    //=========================================================================
    // get
    //=========================================================================
public :
    /**
     *  @desc   取り付けられているオブジェクトの数を返す
     *  @return int
     */
    int getSize() ;
    
    /**
     *  @desc   オブジェクト群を取得
     *  @return std::vector<CObject*>*
     */
    std::vector<CObject*>* getObjects() ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    /**
     *  @desc   オブジェクトの追加
     *  @param  CObject*
     */
    void add(CObject* pObject) ;
    
    /**
     *  @desc   オブジェクトのレイヤーからの取り外しと、vectorからの取り外し
     *  @param  std::vector<CObject*>*
     */
    void checkAndRemove() ;

};

#endif /* Object_hpp */
