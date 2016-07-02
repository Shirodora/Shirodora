//
//  ActorFactoryManager.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/13.
//
//

#ifndef ActorFactoryManager_hpp
#define ActorFactoryManager_hpp

#include <stdio.h>
#include "ActorFactory.hpp"
#include "SingletonTemplate.h"
#include <map>

//=========================================================================
//
// アクター工場管理
//
//=========================================================================
class CActorFactoryManager : public CSingletonTemplate<CActorFactoryManager> {
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
private :
    friend class CSingletonTemplate<CActorFactoryManager> ;
    CActorFactoryManager() ;
    virtual ~CActorFactoryManager() override ;
    
    //=========================================================================
    // アクタータイプ
    //=========================================================================
public :
    enum class ACTOR_TYPE {
        TRIANGLE    = 3,
        TETRAGON    = 4,
        PENTAGON    = 5,
        HEXAGON     = 6,
        HEPTAGON    = 7,
        OCTAGON     = 8,
        NONAGON     = 10,
    };
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // アクター工場
    std::map<ACTOR_TYPE, CActorFactoryTemplate*>* m_pFactories {NULL} ;
    
    //=========================================================================
    // set
    //=========================================================================
public :
    // なし
    
    //=========================================================================
    // get
    //=========================================================================
    // なし
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
private :
    /**
     *  @desc   引数に指定したアクターの工場を返す
     *  @param  ACTOR_TYPE
     *  @return CActorFactoryTemplate
     */
    CActorFactoryTemplate* getFactory(ACTOR_TYPE type) ;
    
public :
    /**
     *  @desc   引数に指定したアクターを生成して返す
     *  @param  ACTOR_TYPE
     *  @return CActor
     */
    CActor* createActor(ACTOR_TYPE type, float x, float y) ;
};

#endif /* ActorFactoryManager_hpp */
