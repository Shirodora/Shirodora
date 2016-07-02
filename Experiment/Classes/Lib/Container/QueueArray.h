//
//  QueueArray.h
//  
//
//  Created by Ryoutarou Onimura on 2016/05/17.
//
//

#ifndef QueueArray_h
#define QueueArray_h

#include <stdio.h>

//=========================================================================
// 追加のインクルードはここから
//=========================================================================

// 格納する型がPOINTERの時に定義
//#define POINTER

//=========================================================================
//
// キュー型配列クラス
// enqueueで追加し、配列がいっぱいであれば自動でdequeueしてくれる
//
//=========================================================================
//=========================================================================
// インスタンス格納専用
// ポインタを格納する場合は、マクロの POINTER のコメントアウトを外せば専用のが起動する
//=========================================================================
#ifndef POINTER
template <typename Ty>
class CQueueArray {
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // 最大要素数
    int m_arraySize ;
    // 配列
    Ty* m_pArray = NULL ;
    
    // 配列が空かどうかのフラグ
    bool m_emptyFlag = true ;
    // 配列がいっぱいかどうかのフラグ
    bool m_fullFlag = false ;
    // 要素が入っている最後尾の配列番号
    int m_index = 0 ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
private :
    /**
     *  @desc   コンストラクタ
     *  @tips   引数なしコンストラクタは禁止
     */
    CQueueArray(){}
    
public :
    /**
     *  @desc   コンストラクタ
     *  @param  配列サイズ
     */
    CQueueArray(int arraySize) : m_arraySize(arraySize){
        this->m_pArray = new Ty [arraySize] {} ;
        this->m_index = 0 ;
    }
    
    /**
     *  @desc   デストラクタ
     */
    ~CQueueArray(){
        if(this->m_pArray != NULL){
            delete [] this->m_pArray ;
            this->m_pArray = NULL ;
        }
    }
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    //=========================================================================
    // init
    //=========================================================================
public :
    /**
     *  @desc   init
     */
    void init(){
        if(this->m_pArray != NULL){
            delete [] this->m_pArray ;
            this->m_pArray = NULL ;
        }
        this->m_pArray = new Ty [this->m_arraySize] {} ;
        this->m_index = 0 ;
    }
    
    /**
     *  @desc   init
     */
    void init(int arraySize){
        if(this->m_pArray != NULL){
            delete [] this->m_pArray ;
            this->m_pArray = NULL ;
        }
        this->setArraySize(arraySize) ;
        this->m_pArray = new Ty [arraySize] {} ;
        this->m_index = 0 ;
    }
    
    //=========================================================================
    // set
    //=========================================================================
public :
    /**
     *  @desc   配列に要素を追加する
     *  @param  対応した型の追加する要素のインスタンス
     *  @tips   ポインタを*objで引数に入れるの禁止
     */
    void enqueue(const Ty &obj){
        // 配列がいっぱいではないとき
        if(this->m_fullFlag == false){
            // 現在の最後尾に格納
            this->m_pArray[m_index] = Ty(obj) ;
            this->addIndex() ;
        }else{
            this->dequeue() ;
            // 配列の最後尾に格納
            this->m_pArray[this->m_arraySize - 1] = Ty(obj) ;
            this->addIndex() ;
        }
    }
    
    /**
     *  @desc   配列の要素を削除する
     *  @tips   削除は前から削除される
     */
    void dequeue(){
        this->closeArrya() ;
        this->subIndex() ;
    }
    
    /**
     *  @desc   任意の配列を空にする
     *  @param  添字番号
     */
    void dequeueAt(int index){
        if(index >= this->m_arraySize || index < 0){
            printf("そんな添字番号はねえよ\n") ;
            return ;
        }
        this->closeArrya(index) ;
        this->subIndex() ;
    }
    
    private :
    /**
     *  @desc   initで初期化後に配列サイズを変更する
     *  @param  配列サイズ
     *  @tips   外部からは呼び出せない
     */
    void setArraySize(int arraySize){
        this->m_arraySize = arraySize ;
    }
    
    //=========================================================================
    // get
    //=========================================================================
public :
    /**
     *  @desc   配列サイズを得る
     *  @return 配列サイズ
     */
    int getArraySize() const {
        return this->m_arraySize ;
    }
    
    /**
     *  @desc   現在の配列サイズを返す
     *  @return 要素が入っている配列の数を返す
     *  @tips   for文のお共にどうぞ
     */
    int getCurrentArraySize() const {
        return this->m_index ;
    }
    
    /**
     *  @desc   最後尾配列の添字番号を返す
     *  @tips   for文回す上限ならgetCurrentArraySize()をどうぞ
     */
    int getLastIndex() const {
        return this->m_index - 1 ;
    }
    
    /**
     *  @desc   配列を返す
     *  @return 配列
     */
    Ty* getArray() const {
        return this->m_pArray ;
    }
    
    /**
     *  @desc   指定した配列番号の要素を返す
     *  @param  配列番号
     *  @return 指定された配列番号の要素
     */
    Ty getItemAt(int index) const {
        // 配列そのものが空っぽだった場合
        if(this->m_emptyFlag == true){
            printf("現在配列は全て空なのでデフォルトコンストラクタで生成されるインスタンスを返します\n") ;
            return Ty() ;
        }
        // 現在の最後尾以上なら、最後尾を返す
        if(index >= this->m_arraySize){
            printf("指定された配列は空なので、最後尾の要素を返します\n") ;
            return this->m_pArray[this->m_index - 1] ;
        }
        // ０以下なら先頭を返す
        if(index < 0){
            printf("そんな要素番号はねえよ\n") ;
            return this->m_pArray[0] ;
        }
        return this->m_pArray[index] ;
    }
    
    /**
     *  @desc   先頭の配列要素を返す
     *  @return 先頭の配列要素
     */
    Ty getFirstItem() const {
        // 配列そのものが空っぽだった場合
        if(this->m_emptyFlag == true){
            printf("現在配列は全て空なのでデフォルトコンストラクタで生成されるインスタンスを返します\n") ;
            return Ty() ;
        }
        return this->m_pArray[0] ;
    }
    
    /**
     *  @desc   最後尾の配列要素を返す
     *  @return 最後尾の配列要素
     */
    Ty getLastItem() const {
        // 配列そのものが空っぽだった場合
        if(this->m_emptyFlag == true){
            printf("現在配列は全て空なのでデフォルトコンストラクタで生成されるインスタンスを返します\n") ;
            return Ty() ;
        }
        return this->m_pArray[this->m_index - 1] ;
    }
    
    /**
     *  @desc   配列が空かどうか
     *  @return true...空 false...空ではない
     */
    bool getEmptyFlag() const {
        return this->m_emptyFlag ;
    }
    
    /**
     *  @desc   配列がいっぱいかどうか
     *  @return true...いっぱい false...いっぱいではない
     */
    bool getFullFlag() const {
        return this->m_fullFlag ;
    }
    
    //=========================================================================
    // 特殊関数
    //=========================================================================
private :
    /**
     *  @desc   配列を先頭へ１つ詰める
     *  param   詰め開始添字番号
     */
    void closeArrya(int index = 0){
        for(int i = index ; i < this->m_index - 1 ; i++){
            this->m_pArray[i] = this->m_pArray[i + 1] ;
        }
        this->m_pArray[this->m_index - 1] = Ty() ;
    }
    
    /**
     *  @desc   要素が入っている最後尾の配列番号を加算する
     */
    void addIndex(){
        if(this->m_fullFlag == true) return ;
        if(this->m_emptyFlag == true) this->m_emptyFlag = false ;
        this->m_index++ ;
        
        if(this->m_index == this->m_arraySize) this->m_fullFlag = true ;
    }
    
    /**
     *  @desc   要素が入っている最後尾の配列番号を減算する
     */
    void subIndex(){
        if(this->m_emptyFlag == true) return ;
        if(this->m_fullFlag == true) this->m_fullFlag = false ;
        if(this->m_index > 0) this->m_index-- ;
        
        if(this->m_index == 0) this->m_emptyFlag = true ;
    }
    
};
#endif  // POINTER

#ifdef  POINTER
//=========================================================================
//
// キュー型配列クラス
// enqueueで追加し、配列がいっぱいであれば自動でdequeueしてくれる
//
//=========================================================================
//=========================================================================
// この配列にポインタが格納された場合は、受け取ったポインタをそのまま格納し
// dequeueされたものはこのクラス内で自動で破棄する
// queueArray.enqueue(new Hoge()) ; という記述を推奨
// Hoge* pHoge = new Hoge() ; として
// queueArray.enqueue(pHoge) ; のようにenqueue して delete pHoge ; をすると二重破棄が起こる
//=========================================================================
template <typename Ty>
class CQueueArray {
    //=========================================================================
    // メンバ変数
    //=========================================================================
private :
    // 最大要素数
    int m_arraySize ;
    // 配列
    Ty* m_pArray = NULL ;
    
    // 配列が空かどうかのフラグ
    bool m_emptyFlag = true ;
    // 配列がいっぱいかどうかのフラグ
    bool m_fullFlag = false ;
    // 要素が入っている最後尾の配列番号
    int m_index = 0 ;
    
    //=========================================================================
    // コンストラクタ/デストラクタ
    //=========================================================================
private :
    /**
     *  @desc   コンストラクタ
     *  @tips   引数なしコンストラクタは禁止
     */
    CQueueArray(){}
    
public :
    /**
     *  @desc   コンストラクタ
     *  @param  配列サイズ
     */
    CQueueArray(int arraySize) : m_arraySize(arraySize){
        this->m_pArray = new Ty [arraySize] {NULL} ;
        this->m_index = 0 ;
    }
    
    /**
     *  @desc   デストラクタ
     */
    ~CQueueArray(){
        for(int i = 0 ; i < this->m_arraySize ; i++){
            if(this->m_pArray[i] != NULL){
                delete this->m_pArray[i] ;
                this->m_pArray[i] = NULL ;
            }
        }
        if(this->m_pArray != NULL){
            delete [] this->m_pArray ;
            this->m_pArray = NULL ;
        }
    }
    
    //=========================================================================
    // メンバ関数
    //=========================================================================
    //=========================================================================
    // init
    //=========================================================================
public :
    /**
     *  @desc   init
     */
    void init(){
        for(int i = 0 ; i < this->m_arraySize ; i++){
            if(this->m_pArray[i] != NULL){
                delete this->m_pArray[i] ;
                this->m_pArray[i] = NULL ;
            }
        }
        this->m_pArray = new Ty* [this->m_arraySize] {NULL} ;
        if(this->m_pArray != NULL){
            delete [] this->m_pArray ;
            this->m_pArray = NULL ;
        }
        this->m_index = 0 ;
    }
    
    /**
     *  @desc   init
     */
    void init(int arraySize){
        for(int i = 0 ; i < this->m_arraySize ; i++){
            if(this->m_pArray[i] != NULL){
                delete this->m_pArray[i] ;
                this->m_pArray[i] = NULL ;
            }
        }
        if(this->m_pArray != NULL){
            delete [] this->m_pArray ;
            this->m_pArray = NULL ;
        }
        this->setArraySize(arraySize) ;
        this->m_pArray = new Ty* [arraySize] {NULL} ;
        this->m_index = 0 ;
    }
    
    //=========================================================================
    // set
    //=========================================================================
public :
    /**
     *  @desc   配列に要素を追加する
     *  @param  対応した型の追加する要素のインスタンス
     *  @tips   ポインタを*objで引数に入れるの禁止
     */
    void enqueue(const Ty &obj){
        // 配列がいっぱいではないとき
        if(this->m_fullFlag == false){
            // 現在の最後尾に格納
            this->m_pArray[m_index] = Ty(obj) ;
            this->addIndex() ;
        }else{
            this->dequeue() ;
            // 配列の最後尾に格納
            this->m_pArray[this->m_arraySize - 1] = Ty(obj) ;
            this->addIndex() ;
        }
    }
    
    /**
     *  @desc   配列の要素を削除する
     *  @tips   削除は前から削除される
     */
    void dequeue(){
        this->closeArrya() ;
        this->subIndex() ;
    }
    
    /**
     *  @desc   任意の配列を空にする
     *  @param  添字番号
     */
    void dequeueAt(int index){
        if(index >= this->m_arraySize || index < 0){
            printf("そんな添字番号はねえよ\n") ;
            return ;
        }
        this->closeArrya(index) ;
        this->subIndex() ;
    }
    
private :
    /**
     *  @desc   initで初期化後に配列サイズを変更する
     *  @param  配列サイズ
     *  @tips   外部からは呼び出せない
     */
    void setArraySize(int arraySize){
        this->m_arraySize = arraySize ;
    }
    
    //=========================================================================
    // get
    //=========================================================================
public :
    /**
     *  @desc   配列サイズを得る
     *  @return 配列サイズ
     */
    int getArraySize() const {
        return this->m_arraySize ;
    }
    
    /**
     *  @desc   現在の配列サイズを返す
     *  @return 要素が入っている配列の数を返す
     *  @tips   for文のお共にどうぞ
     */
    int getCurrentArraySize() const {
        return this->m_index ;
    }
    
    /**
     *  @desc   最後尾配列の添字番号を返す
     *  @tips   for文回す上限ならgetCurrentArraySize()をどうぞ
     */
    int getLastIndex() const {
        return this->m_index - 1 ;
    }
    
    /**
     *  @desc   配列を返す
     *  @return 配列
     */
    Ty* getArray() const {
        return this->m_pArray ;
    }
    
    /**
     *  @desc   指定した配列番号の要素を返す
     *  @param  配列番号
     *  @return 指定された配列番号の要素
     */
    Ty getItemAt(int index) const {
        // 配列そのものが空っぽだった場合
        if(this->m_emptyFlag == true){
            printf("現在配列は全て空なのでNULLを返します\n") ;
            return NULL ;
        }
        // 現在の最後尾以上なら、最後尾を返す
        if(index >= this->m_arraySize){
            printf("指定された配列は空なので、最後尾の要素を返します\n") ;
            return this->m_pArray[this->m_index - 1] ;
        }
        // ０以下なら先頭を返す
        if(index < 0){
            printf("そんな要素番号はねえよ\n") ;
            return this->m_pArray[0] ;
        }
        return this->m_pArray[index] ;
    }
    
    /**
     *  @desc   先頭の配列要素を返す
     *  @return 先頭の配列要素
     */
    Ty getFirstItem() const {
        // 配列そのものが空っぽだった場合
        if(this->m_emptyFlag == true){
            printf("現在配列は全て空なのでNULLを返します\n") ;
            return NULL ;
        }
        return this->m_pArray[0] ;
    }
    
    /**
     *  @desc   最後尾の配列要素を返す
     *  @return 最後尾の配列要素
     */
    Ty getLastItem() const {
        // 配列そのものが空っぽだった場合
        if(this->m_emptyFlag == true){
            printf("現在配列は全て空なのでNULLを返します\n") ;
            return NULL ;
        }
        return this->m_pArray[this->m_index - 1] ;
    }
    
    /**
     *  @desc   配列が空かどうか
     *  @return true...空 false...空ではない
     */
    bool getEmptyFlag() const {
        return this->m_emptyFlag ;
    }
    
    /**
     *  @desc   配列がいっぱいかどうか
     *  @return true...いっぱい false...いっぱいではない
     */
    bool getFullFlag() const {
        return this->m_fullFlag ;
    }
    
    //=========================================================================
    // 特殊関数
    //=========================================================================
private :
    /**
     *  @desc   配列を先頭へ１つ詰める
     *  param   詰め開始添字番号
     */
    void closeArrya(int index = 0){
        this->deleteAt(index) ;
        for(int i = index ; i < this->m_index - 1 ; i++){
            this->m_pArray[i] = this->m_pArray[i + 1] ;
        }
        this->m_pArray[this->m_index - 1] = NULL ;
    }
    
    /**
     *  @desc   指定した配列の要素を空にする
     *  @param  空にする配列の添字番号
     */
    void deleteAt(int index){
        if(this->m_pArray[index] != NULL){
            delete this->m_pArray[index] ;
            this->m_pArray[index] = NULL ;
        }
    }
    
    /**
     *  @desc   要素が入っている最後尾の配列番号を加算する
     */
    void addIndex(){
        if(this->m_fullFlag == true) return ;
        if(this->m_emptyFlag == true) this->m_emptyFlag = false ;
        this->m_index++ ;
        
        if(this->m_index == this->m_arraySize) this->m_fullFlag = true ;
    }
    
    /**
     *  @desc   要素が入っている最後尾の配列番号を減算する
     */
    void subIndex(){
        if(this->m_emptyFlag == true) return ;
        if(this->m_fullFlag == true) this->m_fullFlag = false ;
        if(this->m_index > 0) this->m_index-- ;
        
        if(this->m_index == 0) this->m_emptyFlag = true ;
    }
    
};
#endif  // POINTER

#endif /* QueueArray_h */