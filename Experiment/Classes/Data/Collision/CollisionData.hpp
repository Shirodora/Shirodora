//
//  CollisionData.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#ifndef CollisionData_hpp
#define CollisionData_hpp

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include <vector>
#include "Body.hpp"
#include "Move.hpp"
#include "Shape.hpp"

//=========================================================================
//
// 衝突判定クラス
//
//=========================================================================
class CCollisionData {
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // 位置データ
    CMove m_move ;
    // 加算実体データ群
    std::vector<CBody> *m_pAddBodys {NULL} ;
    // 減算実体データ群
    std::vector<CBody> *m_pSubBodys {NULL} ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
private :
    /**
     *  @desc   コンストラクタ
     */
    CCollisionData() ;
    
public :
    /**
     *  @desc   コンストラクタ
     *  @param  実体データ
     */
    CCollisionData(const CMove &move, const CBody &body) ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  加算実体データ
     *  @param  減算実体データ
     */
    CCollisionData(const CMove &move, const CBody &addBody, const CBody &subBody) ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  加算実体データ群
     */
    CCollisionData(const CMove &move, const std::vector<CBody*> &addBodys) ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  加算実体データ
     *  @param  減算実体データ群
     */
    CCollisionData(const CMove &move, const CBody &addBody, const std::vector<CBody*> &subBodys) ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  加算実体データ群
     *  @param  減算実体データ群
     */
    CCollisionData(const CMove &move, const std::vector<CBody*> &addBodys, const std::vector<CBody*> &subBodys) ;
    
    /**
     *  @desc   コピーコンストラクタ
     */
    CCollisionData(const CCollisionData &data) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CCollisionData() ;
    
    //=========================================================================
    // init
    //=========================================================================
private :
    /**
     *  @desc   init
     */
    void init() ;
    
    //=========================================================================
    // set
    //=========================================================================
public :
    /**
     *  @desc   移動データ設定
     *  @param  移動データ
     */
    void setMove(const CMove &move) ;
    
    /**
     *  @desc   加算実体データ設定
     *  @param  加算実体データ
     */
    void addAddBody(const CBody &body) ;
    
    /**
     *  @desc   減算実体データ設定
     *  @param  減算実体データ
     */
    void addSudBody(const CBody &body) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  実体データ
     */
    void set(const CMove &move, const CBody &body) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ
     *  @param  減算実体データ
     */
    void set(const CMove &move, const CBody &addBody, const CBody &subBody) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ群
     */
    void set(const CMove &move, const std::vector<CBody*> &addBodys) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ群
     */
    void set(const CMove &move, const std::vector<CBody> &addBodys) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ
     *  @param  減算実体データ群
     */
    void set(const CMove &move, const CBody &addBody, const std::vector<CBody*> &subBodys) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ
     *  @param  減算実体データ群
     */
    void set(const CMove &move, const CBody &addBody, const std::vector<CBody> &subBodys) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ群
     *  @param  減算実体データ群
     */
    void set(const CMove &move, const std::vector<CBody*> &addBodys, const std::vector<CBody*> &subBodys) ;
    
    /**
     *  @desc   データ設定
     *  @param  移動データ
     *  @param  加算実体データ群
     *  @param  減算実体データ群
     */
    void set(const CMove &move, const std::vector<CBody> &addBodys, const std::vector<CBody> &subBodys) ;
    
    /**
     *  @desc   データ設定
     *  @param  CCollisionData
     */
    void set(const CCollisionData &data) ;
    
    //=========================================================================
    // get
    //=========================================================================
public :
    /**
     *  @desc   移動データを返す
     *  @return 移動データ
     */
    CMove getMove() const ;
    
    /**
     *  @desc   加算実体データを返す
     *  @return 加算実体データ
     */
    const std::vector<CBody> *getAddBodys() const ;
    
    /**
     *  @desc   減算実体データを返す
     *  @return 減算実体データ
     */
    const std::vector<CBody> *getSudBodys() const ;
    
    /**
     *  @desc   CMoveの位置ベクトルを返す
     *  @return 位置ベクトル
     */
    cocos2d::Vec2 getPosition() const ;
    
    /**
     *  @desc   CMoveの方向ベクトルを返す
     *  @return 位置ベクトル
     */
    cocos2d::Vec2 getDirection() const ;
    
    /**
     *  @desc   CMoveの速度を返す
     *  @return 速度ベクトル
     */
    float getVelocity() const ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    /**
     *  @desc   Bodyデータの座標を移動させる
     *  @param  移動ベクトル
     */
    void move(const cocos2d::Vec2 &vector) ;
    
    //=========================================================================
    // 衝突関数
    //=========================================================================
public :
    /**
     *  @desc   衝突判定
     *  @param  対象のCCollisionデータ
     *  @return true...衝突している false...衝突していない
     */
    bool collisionDecision(const CCollisionData &objCollisionData) const ;
    
    //=========================================================================
    // GJK
    // ここから下はアルゴリズム内で使用する関数
    // 外部から呼び出されることはない
    //=========================================================================
private :
    /**
     *  @desc   GJKアルゴリズムを用いた衝突判定
     *  @param  自身のCCollisionData
     *  @param  対象のCCollisionData
     *  @tips   衝突判定だけ取らせるので、GJKDistanceとは単体の作り方が異なる
     *  @tips   CCollisionDataを弄くり回すので参照渡しではなく値渡しとしている
     */
    bool GJKAlgorithm(const CMove &objMove, CBody myBody, CBody objBody) const ;
    
    /**
     *  @desc   ミンコフスキー差におけるサポート支点座標を得る
     *  @param  方向ベクトル
     *  @return ミンコフスキー差サポート支点座標
     */
    cocos2d::Vec2 getSupportMappingFulcrum(const CBody &myBody, const CBody &objBody, const cocos2d::Vec2 &direction) const ;
    
    /**
     *  @desc   次のサポート支点を得るための方向ベクトルを得る
     *  @param  CSimplex
     *  @return 方向ベクトル
     *  @tips   return  する値を反転させたものが実際に使用するベクトルとなる
     */
    cocos2d::Vec2 getDirection(const CSimplex &simplex) const ;
    
};

#endif /* CollisionData_hpp */
