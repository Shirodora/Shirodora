//
//  Body.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/14.
//
//

#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>

//=========================================================================
// マクロ指定
//=========================================================================
// cocos使用する
#define cocos

// オリジナルCVector2使用
//#define CVector2

//=========================================================================
// 追加のインクルードはここから
//=========================================================================
#include <vector>

//=========================================================================
// 関数やマクロ定義はここから
//=========================================================================

//=========================================================================
//
// Bodyクラス
//
//=========================================================================
class CBody {
#ifdef cocos
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // 頂点座標群
    std::vector<cocos2d::Vec2> *m_pApexs {NULL} ;
    // 中心座標
    cocos2d::Vec2 m_center ;
    // 重さ
    float m_weight = 1.0f ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    /**
     *  @desc   コンストラクタ
     *  @tips   頂点数0の原点のみの点として生成
     */
    CBody() ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  中心座標
     */
    CBody(const cocos2d::Vec2 &center) ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  頂点座標群
     *  @param  中心座標
     */
    CBody(const std::vector<cocos2d::Vec2> &apexs, const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   コンストラクタ
     *  @param  頂点数
     *  @param  頂点座標配列
     *  @param  中心座標
     */
    CBody(int apexSize, const cocos2d::Vec2 apexs[], const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   コピーコンストラクタ
     */
    CBody(const CBody &body) ;
    
    /**
     *  @desc   デストラクタ
     */
    ~CBody() ;
    
    //=========================================================================
    // init
    //=========================================================================
private :
    /**
     *  @desc
     *  @param  頂点座標群
     *  @param  中心座標
     */
    void init() ;
    
    //=========================================================================
    // set
    //=========================================================================
private :
    /**
     *  @desc   頂点座標追加
     *  @param  頂点座標
     */
    void addApex(const cocos2d::Vec2 &apex) ;
public :
    
    /**
     *  @desc   中心座標設定
     *  @param  中心座標
     */
    void set(const cocos2d::Vec2 &center) ;
    
    /**
     *  @desc   座標設定
     *  @param  頂点座標群
     *  @param  中心座標
     */
    void set(const std::vector<cocos2d::Vec2> &apexs, const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   座標設定
     *  @param  頂点数
     *  @param  頂点座標配列
     *  @param  中心座標
     */
    void set(int apexSize, const cocos2d::Vec2 apexs[], const cocos2d::Vec2 &center = cocos2d::Vec2(0.0f, 0.0f)) ;
    
    /**
     *  @desc   座標設定
     *  @param  CBody
     */
    void set(const CBody &body) ;
    
    /**
     *  @desc   重さ設定
     *  @param  重さ
     */
    void setWeight(float weight) ;
    
    //=========================================================================
    // get
    //=========================================================================
public :
    /**
     *  @desc   頂点数取得
     *  @return 頂点数
     */
    int getApexSize() const ;
    
    /**
     *  @desc   頂点座標群取得
     *  @return const std::vector<cocos2d::Vec2>*
     */
    const std::vector<cocos2d::Vec2>* getApexs() const ;
    
    /**
     *  @desc   頂点座標取得
     *  @param  添字番号
     *  @return array
     *  @tips   受け値は const float* apex ;
     */
    cocos2d::Vec2 getApexAt(int index) const ;
    
    /**
     *  @desc   中心座標取得
     *  @return cocos2d::Vec2
     */
    cocos2d::Vec2 getCenter() const ;
    
    /**
     *  @desc   重さ取得
     *  @return 重さ
     */
    float getWeight() const ;
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
public :
    /**
     *  @desc   座標移動
     *  @param  移動ベクトル
     */
    void move(const cocos2d::Vec2 &vector) ;
    
    /**
     *  @desc   座標回転
     *  @param  回転角度
     */
    void rotate(float angle, const cocos2d::Vec2 &point = cocos2d::Vec2::ZERO) ;
    
    /**
     *  @desc   指定された向きで最も遠くにある頂点座標を返す
     *  @param  方向ベクトル
     *  @return 最も遠い頂点座標
     */
    cocos2d::Vec2 getFarthestPointInDirection(const cocos2d::Vec2 &direction) const ;
    
#endif  // cocos
};

#endif /* Body_hpp */
