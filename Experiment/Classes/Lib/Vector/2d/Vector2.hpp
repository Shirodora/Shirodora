//
//  Vector2.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/11.
//
//

#ifndef Vector2_hpp
#define Vector2_hpp

#include <stdio.h>

//=========================================================================
// 2DVectorClass
//=========================================================================
class CVector2 {
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    float x, y ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
public :
    CVector2(){}
    CVector2(float x, float y) : x(x), y(y){}
    CVector2(const CVector2 &vector){
        this->set(vector);
    }
    
    //=========================================================================
    // set
    //=========================================================================
public :
    /**
     *  @desc   set
     */
    void set(float x, float y){
        this->x = x ;
        this->y = y ;
    }
    
    /**
     *  @desc   set
     */
    void set(const CVector2 &vector){
        this->x = vector.x ;
        this->y = vector.y ;
    }
    //=========================================================================
    // get
    //=========================================================================
    // メンバ変数は public なので特になし
    
    //=========================================================================
    // メンバ変数
    //=========================================================================
public :
    /**
     *  @desc   原点からのベクトルの長さを得る
     *  @return ベクトルの長さ
     */
    float getLength() const {
        float length = sqrtf(this->x * this->x + this->y * this->y) ;
        return length ;
    }
    
    /**
     *  @desc   引数のベクトルとの長さを得る
     *  @param  ベクトル
     *  @return ベクトルの長さ
     */
    float getLength(const CVector2 &vector) const {
        CVector2 vec = vector - (*this) ;
        return vec.getLength() ;
    }
    
    /**
     *  @desc   自身の正規化
     */
    void normalize(){
        float n = this->x * this->x + this->y * this->y ;
        if (n == 1.0f) return;
        
        n = sqrtf(n);
        
        n = 1.0f / n;
        this->x = this->x * n;
        this->y = this->y * n;
    }
    
    /**
     *  @desc   正規化したベクトルを返す
     *  @return 正規化したベクトル
     */
    CVector2 getNormalized() const {
        CVector2 vector(*this);
        vector.normalize();
        return vector ;
    }
    
    /**
     *  @desc   自身の反転
     */
    void negate(){
        this->x = this->x * -1.0f ;
        this->y = this->y * -1.0f ;
    }
    
    /**
     *  @desc   自身を反転させたベクトルを返す
     *  @return 自身を反転させたベクトル
     */
    CVector2 getNegated() const {
        CVector2 vector(*this);
        vector.negate();
        return vector ;
    }
    
    /**
     *  @desc   引数のベクトルとの内積を返す
     *  @param  ベクトル
     *  @return 引数のベクトルとの内積
     */
    float getDot(const CVector2 &vector) const {
        float dot = this->x * vector.x + this->y * vector.y ;
        return dot ;
    }
    
    /**
     *  @desc   引数のベクトルとの外積を返す
     *  @param  ベクトル
     *  @return 引数のベクトルとの外積
     */
    float getCross(const CVector2 &vector) const {
        float cross(vector.x * this->y - this->x * vector.y) ;
        return cross ;
    }
    
    /**
     *  @desc   原点周りで自身を回転させる
     *  @param  degree法の角度(pich, yaw, roll)
     */
    void changeAngle(const CVector2 &angle){}
    
    // TODO:
    /**
     *  @desc   原点周りで自身を回転させた座標を返す
     *  @param  degree法の角度(pich, yaw, roll)
     *  @return 回転後の座標
     */
    CVector2 getChangeAngle(const CVector2 &angle) const {
        return CVector2::ZERO ;
    }
    
    // TODO:
    /**
     *  @desc   特定の点周りで自身を回転させる
     *  @param  degree法の角度(pich, yaw, roll)
     *  @param  回転させる原点となる座標
     */
    void changeAngle(const CVector2 &angle, const CVector2 &point){}
    
    // TODO:
    /**
     *  @desc   特定の点周りで自身を回転させた座標を返す
     *  @param  degree法の角度(pich, yaw, roll)
     *  @param  回転させる原点となる座標
     *  @return 回転後の座標
     */
    CVector2 getChangeAngle(const CVector2 &angle, const CVector2 &point) const {
        return CVector2::ZERO ;
    }
    
    //=========================================================================
    // オペレーター演算子
    //=========================================================================
public :
    // +
    void add(const CVector2 &vector){
        this->x = this->x + vector.x ;
        this->y = this->y + vector.y ;
    }
    
    // -
    void sub(const CVector2 &vector){
        this->x = this->x - vector.x ;
        this->y = this->y - vector.y ;
    }
    
    // * float
    void scale(float value){
        this->x = this->x * value ;
        this->y = this->y * value ;
    }
    
    // * CVector2
    void scale(const CVector2 &vector){
        this->x = this->x * vector.x ;
        this->y = this->y * vector.y ;
    }
    
    // +オペレーター演算子
    CVector2 operator+(const CVector2 &vector) const {
        CVector2 result(*this) ;
        result.add(vector) ;
        return result;
    }
    
    // -オペレーター演算子
    CVector2 operator-(const CVector2 &vector) const {
        CVector2 result(*this) ;
        result.sub(vector) ;
        return result;
    }
    
    // *オペレーター演算子
    CVector2 operator*(float value) const {
        CVector2 result(*this) ;
        result.scale(value) ;
        return result;
    }
    
    // *オペレーター演算子
    CVector2 operator*(const CVector2 &vector) const {
        CVector2 result(*this) ;
        result.scale(vector) ;
        return result;
    }
    
    // *オペレーター演算子
    CVector2 operator/(float value) const {
        CVector2 result(*this) ;
        result.scale(1/value) ;
        return result;
    }
    
    // >オペレーター演算子
    bool operator>(const CVector2 &vector) const {
        CVector2 vec(*this) ;
        return (vec.getLength() > vector.getLength()) ;
    }
    
    // <オペレーター演算子
    bool operator<(const CVector2 &vector) const {
        CVector2 vec(*this) ;
        return (vec.getLength() < vector.getLength()) ;
    }
    
    // >=オペレーター演算子
    bool operator>=(const CVector2 &vector) const {
        CVector2 vec(*this) ;
        return (vec.getLength() >= vector.getLength()) ;
    }
    
    // <=オペレーター演算子
    bool operator<=(const CVector2 &vector) const {
        CVector2 vec(*this) ;
        return (vec.getLength() <= vector.getLength()) ;
    }
    
    // ==オペレーター演算子
    bool operator==(const CVector2 &vector) const {
        return (this->x == vector.x && this->y == vector.y) ;
    }
    
    // !=オペレーター演算子
    bool operator!=(const CVector2 &vector) const {
        return (this->x != vector.x || this->y != vector.y) ;
    }
    
    //=========================================================================
    // 定数
    //=========================================================================
public :
    // (0.0f, 0.0f)
    static const CVector2 ZERO ;
    // (1.0f, 1.0f)
    static const CVector2 ONE ;
    // (1.0f, 0.0f)
    static const CVector2 UNIT_X ;
    // (0.0f, 1.0f)
    static const CVector2 UNIT_Y ;
};

#endif /* Vector2_hpp */
