//
//  Constants.hpp
//  Experiment
//
//  Created by Ryoutarou Onimura on 2016/06/02.
//
//

#ifndef Constants_hpp
#define Constants_hpp

//=========================================================================
// 関数やマクロ定義はここから
//=========================================================================
/**
 *  @desc   引数の正負ゼロを返す
 *  @param  数値
 *  @return 1...正 -1...負 0...ゼロ
 */
template <typename Num>
static int getSign(Num number){
    Num sign = (number > 0) - (number < 0) ;
    return (int)sign ;
}

//=========================================================================
//	CCREATE_FUNC
//      CREATE_FUNCマクロの汎用化静的メンバ関数テンプレート群
//=========================================================================
class CCREATE_FUNC {
public :
    /**
     *  @desc   通常の生成
     */
    template <typename Ty>
    static Ty* create() {
        Ty* pRet = new(std::nothrow)Ty() ;
        if(pRet && pRet->init()) {
            pRet->autorelease() ;
            return pRet ;
        }else{
            delete pRet ;
            pRet = NULL ;
            return NULL ;
        }
    }
    
};

//=========================================================================
// 画面サイズ
//=========================================================================
#define WINDOW_WIDTH    (900)
#define WINDOW_HEIGHT   (600)

//=========================================================================
//	画像ファイルのマクロはここから書く
//=========================================================================

#endif /* Constants_hpp */
