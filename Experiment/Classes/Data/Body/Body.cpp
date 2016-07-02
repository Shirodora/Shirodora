//
//  Body.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/14.
//
//

#include "Body.hpp"

//=========================================================================
//
// Bodyクラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
#ifdef cocos
/**
 *  @desc   コンストラクタ
 *  @tips   頂点数0の原点のみの点として生成
 */
CBody::CBody() : m_center(0.0f, 0.0f){}

/**
 *  @desc   コンストラクタ
 *  @param  中心座標
 */
CBody::CBody(const cocos2d::Vec2 &center){
    this->set(center) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  頂点座標群
 *  @param  中心座標
 */
CBody::CBody(const std::vector<cocos2d::Vec2> &apexs, const cocos2d::Vec2 &center){
    this->set(apexs, center) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  頂点数
 *  @param  頂点座標配列
 *  @param  中心座標
 */
CBody::CBody(int apexSize, const cocos2d::Vec2 apexs[], const cocos2d::Vec2 &center){
    this->set(apexSize, apexs, center) ;
}

/**
 *  @desc   コピーコンストラクタ
 */
CBody::CBody(const CBody &body){
    this->set(body) ;
}

/**
 *  @desc   デストラクタ
 */
CBody::~CBody(){
    if(this->m_pApexs != NULL){
        delete this->m_pApexs ;
        this->m_pApexs = NULL ;
    }
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc
 *  @param  頂点座標群
 *  @param  中心座標
 */
void CBody::init(){
    this->m_center = cocos2d::Vec2(0.0f, 0.0f) ;
    if(this->m_pApexs != NULL){
        delete this->m_pApexs ;
        this->m_pApexs = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   頂点座標追加
 *  @param  頂点座標
 */
void CBody::addApex(const cocos2d::Vec2 &apex){
    if(this->m_pApexs == NULL){
        this->m_pApexs = new std::vector<cocos2d::Vec2>() ;
    }
    this->m_pApexs->push_back(cocos2d::Vec2(apex)) ;
}

/**
 *  @desc   中心座標設定
 *  @param  中心座標
 */
void CBody::set(const cocos2d::Vec2 &center){
    this->m_center = center ;
}

/**
 *  @desc   座標設定
 *  @param  頂点座標群
 *  @param  中心座標
 */
void CBody::set(const std::vector<cocos2d::Vec2> &apexs, const cocos2d::Vec2 &center){
    this->init() ;
    for(cocos2d::Vec2 apex : apexs){
        this->addApex(apex) ;
    }
    this->set(center) ;
}

/**
 *  @desc   座標設定
 *  @param  頂点数
 *  @param  頂点座標配列
 *  @param  中心座標
 */
void CBody::set(int apexSize, const cocos2d::Vec2 apexs[], const cocos2d::Vec2 &center){
    this->init() ;
    for(int i = 0 ; i < apexSize ; i++){
        this->addApex(apexs[i]) ;
    }
    this->set(center) ;
}

/**
 *  @desc   座標設定
 *  @param  CBody
 */
void CBody::set(const CBody &body){
    if(body.getApexs() == NULL){
        this->set(body.getCenter()) ;
        return ;
    }else{
        this->set(*body.getApexs(), body.getCenter()) ;
    }
}

/**
 *  @desc   重さ設定
 *  @param  重さ
 */
void CBody::setWeight(float weight){
    this->m_weight = weight ;
}

//=========================================================================
// get
//=========================================================================
/**
 *  @desc   頂点数取得
 *  @return 頂点数
 */
int CBody::getApexSize() const {return this->m_pApexs->size() ;}

/**
 *  @desc   頂点座標群取得
 *  @return const std::vector<cocos2d::Vec2>*
 */
const std::vector<cocos2d::Vec2>* CBody::getApexs() const {return this->m_pApexs ;}

/**
 *  @desc   頂点座標取得
 *  @param  添字番号
 *  @return array
 *  @tips   受け値は const float* apex ;
 */
cocos2d::Vec2 CBody::getApexAt(int index) const {return (*this->m_pApexs)[index] ;}

/**
 *  @desc   中心座標取得
 *  @return cocos2d::Vec2
 */
cocos2d::Vec2 CBody::getCenter() const {return this->m_center ;}

/**
 *  @desc   重さ取得
 *  @return 重さ
 */
float CBody::getWeight() const {return this->m_weight ;}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   座標移動
 *  @param  移動ベクトル
 */
void CBody::move(const cocos2d::Vec2 &vector){
    if(vector == cocos2d::Vec2::ZERO) return ;
    
    std::vector<cocos2d::Vec2>::iterator itr = this->m_pApexs->begin() ;
    while(itr != this->m_pApexs->end()){
        *itr = *itr + vector ;
        itr++ ;
    }
    this->m_center = this->m_center + vector ;
}

/**
 *  @desc   座標回転
 *  @param  回転角度
 */
void CBody::rotate(float angle, const cocos2d::Vec2 &point){
    if(angle == 0.0f) return ;
    for(cocos2d::Vec2 apex : (*this->m_pApexs)){
        apex.rotate(point, angle) ;
    }
}

/**
 *  @desc   指定された向きで最も遠くにある頂点座標を返す
 *  @param  方向ベクトル
 *  @return 最も遠い頂点座標
 */
cocos2d::Vec2 CBody::getFarthestPointInDirection(const cocos2d::Vec2 &direction) const {
    // 中心点のみであればその点を返す
    if(this->m_pApexs == NULL) return this->m_center ;
    
    // 誤差を抑えるために方向ベクトルを正規化する
    cocos2d::Vec2 vec = direction.getNormalized() ;
    // 暫定戻り値座標と、その頂点までの長さを最初の頂点で登録する
    cocos2d::Vec2 result((*this->m_pApexs)[0]) ;
    float maxLength = (*this->m_pApexs)[0].dot(vec) ;
    // 登録されている全ての頂点と比べる
    for(cocos2d::Vec2 apex : (*this->m_pApexs)){
        float length = apex.dot(vec) ;
        if(maxLength < length){maxLength = length ; result = apex ;}
    }
    return result ;
}
    
#endif  // cocos