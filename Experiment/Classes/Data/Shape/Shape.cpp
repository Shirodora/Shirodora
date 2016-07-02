//
//  Shape.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#include "Shape.hpp"

//=========================================================================
//
// 線分クラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CLine::CLine(){}

/**
 *  @desc   コンストラクタ
 */
CLine::CLine(const cocos2d::Vec2 &startPoint, const cocos2d::Vec2 &endPoint){
    this->set(startPoint, endPoint) ;
}

/**
 *  @desc   デストラクタ
 */
CLine::~CLine(){}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   set
 *  @param  始点座標
 *  @param  終点座標
 */
void CLine::set(const cocos2d::Vec2 &startPoint, const cocos2d::Vec2 &endPoint){
    this->m_point[0] = startPoint ;
    this->m_point[1] = endPoint ;
    this->m_nVec = (endPoint - startPoint).getNormalized() ;
    this->m_length = (endPoint - startPoint).getLength() ;
}

//=========================================================================
// get
//=========================================================================
// メンバ変数は public なので特になし

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   点と線分上での最近点を求める
 *  @param  対象の点
 *  @return 最近点座標
 */
cocos2d::Vec2 CLine::getRecentlyPosition(const cocos2d::Vec2 &point) const {
    cocos2d::Vec2 vector = point - this->m_point[0] ;
    float distance = this->m_nVec.dot(vector) ;
    return this->m_point[0] + (this->m_nVec * distance) ;
}

/**
 *  @desc   点と線分上での最近点を求める
 *  @param  対象の点
 *  @return 最近点座標
 *  @tips   直線上ではなく、線分上という限られた長さであることに注意
 */
cocos2d::Vec2 CLine::getRecentlyPositionInLine(const cocos2d::Vec2 &point) const {
    cocos2d::Vec2 vector = point - this->m_point[0] ;
    float distance = this->m_nVec.dot(vector) ;
    if(this->m_length <= distance) return this->m_point[1] ;
    if(distance <= 0.0f) return this->m_point[0] ;
    return this->m_point[0] + (this->m_nVec * distance) ;
}

/**
 *  @desc   指定された座標がベクトルの内外どちらにあるか
 *  @return 1...外 -1...内 0...線上
 */
int CLine::getInOrOut(const cocos2d::Vec2 &point) const {
    float cross = this->m_nVec.cross(point - this->m_point[0]) ;
    return getSign(cross) ;
}

/**
 *  @desc   線上に点が含まれているか
 *  @return true...含まれている false...含まれていない
 */
bool CLine::isContaintsPoint(const cocos2d::Vec2 &point) const {
    float cross = this->m_nVec.cross(point - this->m_point[0]) ;
    if(-0.001f < cross && cross <= 0.001f){
        float dot = this->m_nVec.dot(point - this->m_point[0]) ;
        if(0.0f <= dot && dot <= this->m_length) return true ;
    }
    return false ;
}

//=========================================================================
//
// 単体クラス(各次元での最小形状)
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CSimplex::CSimplex(){}

/**
 *  @desc   デストラクタ
 */
CSimplex::~CSimplex(){
    for(int i = 0 ; i < 3 ; i++){
        if(this->m_apexs[i] != NULL){
            delete this->m_apexs[i] ;
            this->m_apexs[i] = NULL ;
        }
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   頂点を追加する
 *  @param  追加する頂点座標
 */
void CSimplex::add(const cocos2d::Vec2 &apex){
    if(this->m_isFull == true){
        this->closeArray() ;
    }
    if(this->m_apexs[this->m_currentIndex] != NULL){
        printf("これが表示されるようでは問題がある\n") ;
    }
    this->m_apexs[this->m_currentIndex] = new cocos2d::Vec2(apex) ;
    this->addIndex() ;
}

/**
 *  @desc   配列を詰める
 */
void CSimplex::closeArray(){
    if(this->m_apexs[0] != NULL){
        delete this->m_apexs[0] ;
        this->m_apexs[0] = NULL ;
    }
    for(int i = 0 ; i < this->ARRAY_SIZE - 1 ; i++){
        this->m_apexs[i] = this->m_apexs[i + 1] ;
    }
    this->m_apexs[this->ARRAY_SIZE - 1] = NULL ;
}

/**
 *  @desc   添字番号を増やす
 */
void CSimplex::addIndex(){
    if(this->m_isFull == true) return ;
    if(this->m_isEmpty == true) this->m_isEmpty = false ;
    this->m_currentIndex++ ;
    if(this->ARRAY_SIZE <= this->m_currentIndex){
        this->m_currentIndex = this->ARRAY_SIZE - 1 ;
        this->m_isFull = true ;
    }
}

/**
 *  @desc   添字番号を減らす
 */
void CSimplex::subIndex(){
    if(this->m_isEmpty == true) return ;
    if(this->m_isFull == true) this->m_isFull = false ;
    this->m_currentIndex-- ;
    if(this->m_currentIndex <= 0){
        this->m_currentIndex = 0 ;
        this->m_isEmpty = true ;
    }
}


//=========================================================================
// get
//=========================================================================
/**
 *  @desc   現在の配列サイズ取得
 *  @return 配列サイズ
 *  @tips   for文のお共にどうぞ
 */
int CSimplex::getCurrentArraySize() const {
    if(this->m_isFull == true) return this->ARRAY_SIZE ;
    if(this->m_isEmpty == true){printf("すまんが空じゃ\n") ; return 0 ;}
    return this->m_currentIndex ;
}

// TODO:配列のサイズ以上のものを要求された時に対応
/**
 *  @desc   指定した添字の頂点座標取得
 *  @return 頂点座標
 */
cocos2d::Vec2 CSimplex::getApexAt(int index) const {
    if(this->m_apexs[index] == NULL){
        printf("すまんが空じゃ\n") ;
        return cocos2d::Vec2::ZERO ;
    }
    return *(this->m_apexs[index]) ;
}

/**
 *  @desc   最後尾添字番号取得
 *  @return 最後尾添字番号
 */
int CSimplex::getLastIndex() const {
    if(this->m_isFull == true) return this->ARRAY_SIZE -1 ;
    if(this->m_isEmpty == true){printf("すまんが空じゃ\n") ; return -1 ;}
    return this->m_currentIndex - 1 ;
}

/**
 *  @desc   最後尾に格納されている頂点座標を返す
 *  @return 頂点座標
 */
cocos2d::Vec2 CSimplex::getLastApex() const {
    if(this->m_isFull == true) return *(this->m_apexs[this->ARRAY_SIZE -1]) ;
    if(this->m_isEmpty == true){printf("すまんが空じゃ\n") ; return cocos2d::Vec2::ZERO ;}
    return *(this->m_apexs[this->m_currentIndex - 1]) ;
}

/**
 *  @desc   配列がいっぱいかを返す
 *  @return true...いっぱい alse...いっぱいではない
 */
bool CSimplex::isFull() const {return this->m_isFull ;}

/**
 *  @desc   配列が空を返す
 *  @return true...空 alse...空ではない
 */
bool CSimplex::isEmpty() const {return this->m_isEmpty ;}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   対象の点と単体上の最近点を求める
 *  @param  対象の点座標
 *  @return 最近点
 */
cocos2d::Vec2 CSimplex::getRecentlyPositionInSinplex(const cocos2d::Vec2 &point) const {
    // 結果となる座標
    cocos2d::Vec2 resultPos ;
    
    // 登録されている頂点数で場合分けする
    // １つも登録されていない
    if(this->getCurrentArraySize() == 0){
        printf("配列が空なので、次回はフラグチェックするように\n") ;
        // とりあえず原点を返す
        resultPos = cocos2d::Vec2::ZERO ;
        
    }
    // 頂点が１つ
    else if(this->getCurrentArraySize() == 1){
        return *(this->m_apexs[0]) ;
        
    }
    // 頂点が２つ
    else if(this->getCurrentArraySize() == 2){
        CLine line(*(this->m_apexs[this->m_currentIndex - 1]), *(this->m_apexs[this->m_currentIndex])) ;
        resultPos = line.getRecentlyPositionInLine(point) ;
        
    }
    // 頂点が３つ
    else{
        // 頂点が３つで単体が完成している
        // 各辺上での最近点を比べて、最も近かったものを返す
        CLine line(*(this->m_apexs[2]), *(this->m_apexs[0])) ;
        resultPos = line.getRecentlyPositionInLine(point) ;
        
        for(int i = 0 ; i < this->ARRAY_SIZE - 1 ; i++){
            line.set(*(this->m_apexs[i]), *(this->m_apexs[i + 1])) ;
            cocos2d::Vec2 pos = line.getRecentlyPositionInLine(point) ;
            if((resultPos - point).getLength() > (pos - point).getLength()) resultPos = pos ;
        }
    }
    return resultPos ;
}

/**
 *  @desc   対象の点が単体内に含まれているかを調べる関数
 *  @param  対象の点座標
 *  @return true...含まれている, false...含まれていない
 */
bool CSimplex::isContainsPoint(const cocos2d::Vec2 &point) const {
    // 単体が完成しているかどうか
    if(this->getCurrentArraySize() == 0){
        return false ;
    }
    else if(this->getCurrentArraySize() == 1){
        return point == *(this->m_apexs[0]) ;
    }
    else if(this->getCurrentArraySize() == 2){
        CLine line(*(this->m_apexs[0]), *(this->m_apexs[1])) ;
        return line.isContaintsPoint(point) ;
    }
    else{
        CLine line(*(this->m_apexs[2]), *(this->m_apexs[0])) ;
        int sign = line.getInOrOut(point) ;
        for(int i = 0 ; i < this->ARRAY_SIZE - 1 ; i++){
            line.set(*(this->m_apexs[i]), *(this->m_apexs[i + 1])) ;
            int nextSign = line.getInOrOut(point) ;
            if(nextSign == 0.0f) return true ;
            if(sign != nextSign) return false ;
        }
        return true ;
    }
    return false ;
}