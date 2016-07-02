//
//  SingletonTemplate.h
//
//
//  Created by Ryoutarou Onimura on 2016/05/12.
//
//

#ifndef SingletonTemplate_h
#define SingletonTemplate_h

//=========================================================================
// SingletonTemplate
// このクラスを継承させたクラスはシングルトン化する
// テンプレート引数には継承させるクラス自身を渡す
//=========================================================================
//=========================================================================
// クラス継承例
// class Hoge : public CSingletonTemplate<Hoge> {
// private :
//     // friend 指定したクラスにのみHpgeクラスの生成を許可する
//     friend class CSingletonTemplate<Hoge> ;
//     // コンストラクタをprivate指定で外部生成禁止する
//     Hoge(){}
//     virtual ~Hoge() override{}
//
// public :
//     void foo() ;
// };
//
// メンバ関数の使い方例
// Hoge::getInstance()->foo() ;
//
// 破棄例
// Hoge::destroyInstance() ;
//=========================================================================
template <typename Ty>
class CSingletonTemplate {
public :
    // 共有インスタンス
    static Ty* m_pInstance ;
    
    // インスタンス取得
    static Ty* getInstance(){
        if(CSingletonTemplate::m_pInstance == NULL){
            CSingletonTemplate::m_pInstance = new Ty() ;
        }
        return CSingletonTemplate::m_pInstance ;
    }
    
    // インスタンス破棄
    static void destroyInstance(){
        if(CSingletonTemplate::m_pInstance != NULL) {
            delete CSingletonTemplate::m_pInstance ;
            CSingletonTemplate::m_pInstance = NULL ;
        }
    }
    
protected:
    // 外部でのインスタンス作成は禁止
    CSingletonTemplate(){}
    // デストラクタ
    virtual ~CSingletonTemplate(){}
    
private:
    // 代入演算子禁止
    void operator=(const CSingletonTemplate& obj){}
    // コピーコンストラクタ禁止
    CSingletonTemplate(const CSingletonTemplate &obj){}
};

// 共有インスタンス実体
template <typename Ty>
Ty* CSingletonTemplate<Ty>::m_pInstance = NULL ;

#endif /* SingletonTemplate_h */