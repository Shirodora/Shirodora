//
//  CollisionData.cpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/15.
//
//

#include "CollisionData.hpp"

//=========================================================================
//
// 2D衝突判定クラス
//
//=========================================================================
//=========================================================================
// メンバ変数
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   コンストラクタ
 */
CCollisionData::CCollisionData(){}

/**
 *  @desc   コンストラクタ
 *  @param  実体データ
 */
CCollisionData::CCollisionData(const CMove &move, const CBody &body){
    this->set(move, body) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ
 *  @param  減算実体データ
 */
CCollisionData::CCollisionData(const CMove &move, const CBody &addBody, const CBody &subBody){
    this->set(move, addBody, subBody) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ群
 */
CCollisionData::CCollisionData(const CMove &move, const std::vector<CBody*> &addBodys){
    set(move, addBodys) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ
 *  @param  減算実体データ群
 */
CCollisionData::CCollisionData(const CMove &move, const CBody &addBody, const std::vector<CBody*> &subBodys){
    this->set(move, addBody, subBodys) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ群
 *  @param  減算実体データ群
 */
CCollisionData::CCollisionData(const CMove &move, const std::vector<CBody*> &addBodys, const std::vector<CBody*> &subBodys){
    this->set(move, addBodys, subBodys) ;
}

/**
 *  @desc   コピーコンストラクタ
 */
CCollisionData::CCollisionData(const CCollisionData &data){
    this->set(data) ;
}

/**
 *  @desc   デストラクタ
 */
CCollisionData::~CCollisionData(){
    if(this->m_pAddBodys != NULL){
        delete this->m_pAddBodys ;
        this->m_pAddBodys = NULL ;
    }
    if(this->m_pSubBodys != NULL){
        delete this->m_pSubBodys ;
        this->m_pSubBodys = NULL ;
    }
}

//=========================================================================
// init
//=========================================================================
/**
 *  @desc   init
 */
void CCollisionData::init(){
    if(this->m_pAddBodys != NULL){
        delete this->m_pAddBodys ;
        this->m_pAddBodys = NULL ;
    }
    if(this->m_pSubBodys != NULL){
        delete this->m_pSubBodys ;
        this->m_pSubBodys = NULL ;
    }
}

//=========================================================================
// set
//=========================================================================
/**
 *  @desc   移動データ設定
 *  @param  移動データ
 */
void CCollisionData::setMove(const CMove &move){
    this->m_move.set(move) ;
}

/**
 *  @desc   加算実体データ設定
 *  @param  加算実体データ
 */
void CCollisionData::addAddBody(const CBody &body){
    if(this->m_pAddBodys == NULL){
        this->m_pAddBodys = new std::vector<CBody>() ;
    }
    this->m_pAddBodys->push_back(CBody(body)) ;
}

/**
 *  @desc   減算実体データ設定
 *  @param  減算実体データ
 */
void CCollisionData::addSudBody(const CBody &body){
    if(this->m_pSubBodys == NULL){
        this->m_pSubBodys = new std::vector<CBody>() ;
    }
    this->m_pSubBodys->push_back(CBody(body)) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  実体データ
 */
void CCollisionData::set(const CMove &move, const CBody &body){
    this->setMove(move) ;
    this->addAddBody(body) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ
 *  @param  減算実体データ
 */
void CCollisionData::set(const CMove &move, const CBody &addBody, const CBody &subBody){
    this->setMove(move) ;
    this->addAddBody(addBody) ;
    this->addSudBody(subBody) ;
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ群
 */
void CCollisionData::set(const CMove &move, const std::vector<CBody*> &addBodys){
    this->setMove(move) ;
    for(CBody *pBody : addBodys){
        this->addAddBody(*pBody) ;
    }
}

/**
 *  @desc   データ設定
 *  @param  移動データ
 *  @param  加算実体データ群
 */
void CCollisionData::set(const CMove &move, const std::vector<CBody> &addBodys){
    this->setMove(move) ;
    for(CBody body : addBodys){
        this->addAddBody(body) ;
    }
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ
 *  @param  減算実体データ群
 */
void CCollisionData::set(const CMove &move, const CBody &addBody, const std::vector<CBody*> &subBodys){
    this->setMove(move) ;
    this->addAddBody(addBody) ;
    for(CBody *pBody : subBodys){
        this->addSudBody(*pBody) ;
    }
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ
 *  @param  減算実体データ群
 */
void CCollisionData::set(const CMove &move, const CBody &addBody, const std::vector<CBody> &subBodys){
    this->setMove(move) ;
    this->addAddBody(addBody) ;
    for(CBody body : subBodys){
        this->addSudBody(body) ;
    }
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ群
 *  @param  減算実体データ群
 */
void CCollisionData::set(const CMove &move, const std::vector<CBody*> &addBodys, const std::vector<CBody*> &subBodys){
    this->setMove(move) ;
    for(CBody *pBody : addBodys){
        this->addAddBody(*pBody) ;
    }
    for(CBody *pBody : subBodys){
        this->addSudBody(*pBody) ;
    }
}

/**
 *  @desc   コンストラクタ
 *  @param  加算実体データ群
 *  @param  減算実体データ群
 */
void CCollisionData::set(const CMove &move, const std::vector<CBody> &addBodys, const std::vector<CBody> &subBodys){
    this->setMove(move) ;
    for(CBody body : addBodys){
        this->addAddBody(body) ;
    }
    for(CBody body : subBodys){
        this->addSudBody(body) ;
    }
}

/**
 *  @desc   データ設定
 *  @param  CCollisionData
 */
void CCollisionData::set(const CCollisionData &data){
    if(data.getAddBodys() != NULL && data.getSudBodys() != NULL){this->set(data.getMove(), *data.getAddBodys(), *data.getSudBodys()) ;}
    if(data.getAddBodys() != NULL){this->set(data.getMove(), *data.getAddBodys()) ;}
}

//=========================================================================
// get
//=========================================================================
/**
 *  @desc   移動データを返す
 *  @return 移動データ
 */
CMove CCollisionData::getMove() const {return this->m_move ;}

/**
 *  @desc   加算実体データを返す
 *  @return 加算実体データ
 */
const std::vector<CBody> *CCollisionData::getAddBodys() const {return this->m_pAddBodys ;}

/**
 *  @desc   減算実体データを返す
 *  @return 減算実体データ
 */
const std::vector<CBody> *CCollisionData::getSudBodys() const {return this->m_pSubBodys ;}

/**
 *  @desc   CMoveの位置ベクトルを返す
 *  @return 位置ベクトル
 */
cocos2d::Vec2 CCollisionData::getPosition() const {return this->m_move.getPosition() ;}

/**
 *  @desc   CMoveの方向ベクトルを返す
 *  @return 位置ベクトル
 */
cocos2d::Vec2 CCollisionData::getDirection() const {return this->m_move.getDirection() ;}

/**
 *  @desc   CMoveの速度を返す
 *  @return 速度ベクトル
 */
float CCollisionData::getVelocity() const {return this->m_move.getVelocity() ;}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   Bodyデータの座標を移動させる
 *  @param  移動ベクトル
 */
void CCollisionData::move(const cocos2d::Vec2 &vector) {
    if(this->m_pAddBodys != NULL){
        for(CBody body : (*this->m_pAddBodys)){
            body.move(vector) ;
        }
    }
    if(this->m_pSubBodys != NULL){
        for(CBody body : (*this->m_pSubBodys)){
            body.move(vector) ;
        }
    }
}

//=========================================================================
// 衝突関数
//=========================================================================
/**
 *  @desc   衝突判定
 *  @param  対象のCCollisionデータ
 *  @return true...衝突している false...衝突していない
 */
bool CCollisionData::collisionDecision(const CCollisionData &objCollisionData) const {
    // GJKアルゴリズム
    return this->GJKAlgorithm( objCollisionData.getMove(), (*this->m_pAddBodys)[0],(*objCollisionData.getAddBodys())[0]) ;
}

//=========================================================================
// GJK
// ここから下はアルゴリズム内で使用する関数
// 外部から呼び出されることはない
//=========================================================================
/**
 *  @desc   GJKアルゴリズムを用いた衝突判定
 *  @param  自身のCCollisionData
 *  @param  対象のCCollisionData
 *  @tips   衝突判定だけ取らせるので、GJKDistanceとは単体の作り方が異なる
 *  @tips   CCollisionDataを弄くり回すので参照渡しではなく値渡しとしている
 */
bool CCollisionData::GJKAlgorithm(const CMove &objMove, CBody myBody, CBody objBody) const {
        // 対象を自身を原点とした座標系に合わせた座標に移動させる
        cocos2d::Vec2 moveVec = objMove.getPosition() - this->m_move.getPosition() ;
        objBody.move(moveVec) ;
        
        // 最初のサポート支点を得るための方向ベクトル設定
        // TOD:CMoveが導入されたらm_velを初期方向ベクトルとさせる
        cocos2d::Vec2 direction = objBody.getCenter() ;
        
        // 単体オブジェクトを生成
        CSimplex simplex ;
        
        // 最初の支点を追加
        simplex.add(this->getSupportMappingFulcrum(myBody, objBody, direction)) ;
        
        // 次の支点を決定するための方向ベクトル
        direction.negate() ;
        
        // !!!: while内で不具合が起こった時の保険用変数
        // こいつが一定値を超えたら強制的に抜けださせる
        const int MAX_COUNT = 5 ;
        int count = 0 ;
        
        // 原点に最も近い単体を探し出す
        //３、４回もやれば見つかるようになっている
        while(true){
            // !!!: 無限ループを防ぐための保険
            if(count >= MAX_COUNT){
                // こいつが表示されると何かしら問題があるよ
                printf("無限ループに陥りそうだったので強制終了させました\n") ;
                return false ;
            }
            
            // 単体に頂点を追加
            simplex.add(this->getSupportMappingFulcrum(myBody, objBody, direction)) ;
            
            // TODO: 下記の部分は無くても動くはずだが、保険で残しておく
            // if(simplex.getLast().getDot(direction) <= 0.0f)の部分で判定できるはず
            //            CVector2 supportMappingFulcrum = this->getSupportMappingFulcrum(myCollisionData.getBody(), objCollisionData.getBody(), direction) ;
            //            for(int i = 0 ; i < simplex.getCurrentArraySize() ; i++){
            //                if(supportMappingFulcrum == simplex.getApexAt(i)){
            //                    //printf("次のサポート支点をこれ以上得られないため、処理を終了します\n") ;
            //                    return false ;
            //                }
            //            }
            //            // 単体に頂点を追加
            //            simplex.add(supportMappingFulcrum) ;
            
            // 次のサポート支点が得られるかを判定する
            if(simplex.getLastApex().dot(direction) <= 0.0f){
                //printf("これ以上原点を含む可能性のあるサポート支点が得られないため処理を終了します\n") ;
                return false ;
            }else{
                // 単体が原点座標を含むかを調べる
                if(simplex.isContainsPoint(cocos2d::Vec2::ZERO) == true){
                    //printf("ミンコフスキー差が原点を含みました\n") ;
                    return true ;
                }else{
                    // 次のサポート支点を得るための方向ベクトルを決定する
                    direction = this->getDirection(simplex) ;
                }
            }
            // !!!: 無限ループを防ぐための保険
            count++ ;
        }
    return false ;
}

/**
 *  @desc   ミンコフスキー差におけるサポート支点座標を得る
 *  @param  方向ベクトル
 *  @return ミンコフスキー差サポート支点座標
 */
cocos2d::Vec2 CCollisionData::getSupportMappingFulcrum(const CBody &myBody, const CBody &objBody, const cocos2d::Vec2 &direction) const {
    // 自身と対象におけるサポート写像支点を求める
    cocos2d::Vec2 myPoint = myBody.getFarthestPointInDirection(-direction) ;
    cocos2d::Vec2 objPoint = objBody.getFarthestPointInDirection(direction) ;
    
    // ミンコフスキー差座標を求める
    cocos2d::Vec2 minkowskiDifferencePoint = objPoint - myPoint ;
    
    return minkowskiDifferencePoint ;
}

/**
 *  @desc   次のミンコフスキー差サポート支点を得るための方向ベクトルを得る
 *  @param  CSimplex
 *  @return 方向ベクトル
 *  @tips   
 */
cocos2d::Vec2 CCollisionData::getDirection(const CSimplex &simplex) const {
    // 結果となる座標
    cocos2d::Vec2 resultPos ;
    
    // 登録されている頂点数で場合分けする
    // １つも登録されていない
    if(simplex.getCurrentArraySize() == 0){
        printf("呼ばれることはない箇所\n") ;
        // とりあえず原点を返す
        resultPos = cocos2d::Vec2::ZERO ;
        
    }
    // 頂点が１つ
    else if(simplex.getCurrentArraySize() == 1){
        printf("呼ばれることはない箇所\n") ;
        return simplex.getApexAt(0) ;
        
    }
    // 頂点が２つ
    else if(simplex.getCurrentArraySize() == 2){
        CLine line(simplex.getApexAt(0), simplex.getApexAt(1)) ;
        resultPos = line.getRecentlyPosition(cocos2d::Vec2::ZERO) ;
        
    }
    // 頂点が３つ
    else{
        // 頂点が３つで単体が完成している
        // 各辺上での最近点を比べて、最も近かったものを返す
        CLine line(simplex.getApexAt(2), simplex.getApexAt(0)) ;
        resultPos = line.getRecentlyPosition(cocos2d::Vec2::ZERO) ;
        
        for(int i = 0 ; i < 3 - 1 ; i++){
            line.set(simplex.getApexAt(i), simplex.getApexAt(i + 1)) ;
            cocos2d::Vec2 pos = line.getRecentlyPosition(cocos2d::Vec2::ZERO) ;
            if(resultPos.getLength() > pos.getLength()) resultPos = pos ;
        }
    }
    return -resultPos ;
}