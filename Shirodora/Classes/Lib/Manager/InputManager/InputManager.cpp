//
//  inputManager.cpp
//  
//
//  Created by Ryoutarou Onimura on 2016/06/08.
//
//

#include "inputManager.hpp"

//=========================================================================
//
// インプットクラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CInput::CInput(){}

/**
 *  @desc   destructor
 */
CInput::~CInput(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *  @desc   値のクリア
 */
void CInput::clear(){
    this->m_inputing = false ;
    this->m_pressed = false ;
    this->m_released = false ;
}

/**
 *  @desc   キーが押された時に呼ぶ関数
 */
void CInput::pressed(){
    this->m_inputing = true ;
    if(this->m_released == true) this->m_released = false ;
    if(this->m_inputing == true){
        this->m_pressed = true ;
        this->m_pressedCounter = 0 ;
    }
}

/**
 *  @desc   キーが離された時に呼ぶ関数
 */
void CInput::released(){
    this->m_inputing = false ;
    if(this->m_pressed == true) this->m_pressed = false ;
    if(this->m_inputing == false){
        this->m_released = true ;
        this->m_releasedCounter = 0 ;
    }
}

/**
 *  @desc   touched releasedのカウンター更新処理
 */
void CInput::counterUpdate(){
    if(this->m_pressed == true){
        ++this->m_pressedCounter ;
        if(this->m_pressedCounter >= this->COUNTER_MAX){
            this->m_pressed = false ;
        }
    }
    if(this->m_released == true){
        ++this->m_releasedCounter ;
        if(this->m_releasedCounter >= this->COUNTER_MAX){
            this->m_released = false ;
        }
    }
}

/**
 *  @desc   キーが入力されているかを返す
 *  @return true...入力されている false...入力されていない
 */
bool CInput::isInputing(){
    return this->m_inputing ;
}

/**
 *  @desc   キーが押されているかを返す
 *  @return true...押されている false...離されている
 */
bool CInput::isPressed(){
    if(this->m_pressed == true){
        this->m_pressed = false ;
        return true ;
    }
    return false ;
}

/**
 *  @desc   キーが押されているかを返す
 *  @return true...押されている false...離されている
 */
bool CInput::isReleased(){
    if(this->m_released == true){
        this->m_released = false ;
        return true ;
    }
    return false ;
}

//=========================================================================
//
// 入力フラグクラス
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CInputFlag::CInputFlag(){}

/**
 *  @desc   destructor
 */
CInputFlag::~CInputFlag(){}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *	@desc	値のクリア
 */
void CInputFlag::clear(){
    this->m_up.clear() ;
    this->m_down.clear() ;
    this->m_left.clear() ;
    this->m_right.clear() ;
    this->m_esc.clear() ;
    this->m_space.clear() ;
    
    this->m_z.clear() ;
    this->m_x.clear() ;
    this->m_c.clear() ;
    
    this->m_a.clear() ;
    this->m_s.clear() ;
    this->m_d.clear() ;
}

/**
 *	@desc	キーが押されている時の反映
 *	@param	キーコード
 */
void CInputFlag::up(keyInputType keyType){
    switch(keyType){
        case keyInputType::UP : this->m_up.pressed() ; break ;
        case keyInputType::DOWN : this->m_down.pressed() ; break ;
        case keyInputType::LEFT : this->m_left.pressed() ; break ;
        case keyInputType::RIGHT : this->m_right.pressed() ; break ;
        case keyInputType::ESC : this->m_esc.pressed() ; break ;
        case keyInputType::SPACE : this->m_space.pressed() ; break ;
            
        case keyInputType::Z : this->m_z.pressed() ; break ;
        case keyInputType::X : this->m_x.pressed() ; break ;
        case keyInputType::C : this->m_c.pressed() ; break ;
            
        case keyInputType::A : this->m_a.pressed() ; break ;
        case keyInputType::S : this->m_s.pressed() ; break ;
        case keyInputType::D : this->m_d.pressed() ; break ;
            
        default: break ;
    }
}

/**
 *	@desc	キーが離されている時の反映
 *	@param	キーコード
 */
void CInputFlag::down(keyInputType keyType){
    switch(keyType){
        case keyInputType::UP : this->m_up.released() ; break ;
        case keyInputType::DOWN : this->m_down.released() ; break ;
        case keyInputType::LEFT : this->m_left.released() ; break ;
        case keyInputType::RIGHT : this->m_right.released() ; break ;
        case keyInputType::ESC : this->m_esc.released() ; break ;
        case keyInputType::SPACE : this->m_space.released() ; break ;
            
        case keyInputType::Z : this->m_z.released() ; break ;
        case keyInputType::X : this->m_x.released() ; break ;
        case keyInputType::C : this->m_c.released() ; break ;
            
        case keyInputType::A : this->m_a.released() ; break ;
        case keyInputType::S : this->m_s.released() ; break ;
        case keyInputType::D : this->m_d.released() ; break ;
            
        default: break ;
    }
}

/**
 *  @desc   各キーのカウンター更新処理
 */
void CInputFlag::counterUpdata(){
    this->m_up.counterUpdate() ;
    this->m_down.counterUpdate() ;
    this->m_left.counterUpdate() ;
    this->m_right.counterUpdate() ;
    this->m_esc.counterUpdate() ;
    this->m_space.counterUpdate() ;
    
    this->m_z.counterUpdate() ;
    this->m_x.counterUpdate() ;
    this->m_c.counterUpdate() ;
    
    this->m_a.counterUpdate() ;
    this->m_s.counterUpdate() ;
    this->m_d.counterUpdate() ;
}

/**
 *	@desc	指定したキーが入力されているかどうかを取得
 *	@param	キータイプ
 *	@return	true...入力されている
 *	@tips	入力のタイプによって変化
 *			キーボードタイプでは使用する必要はない
 */
bool CInputFlag::isKeyInputed(keyInputType keyType){
    switch(keyType){
        case keyInputType::UP : return this->m_up.isInputing() ; break ;
        case keyInputType::DOWN : return this->m_down.isInputing() ; break ;
        case keyInputType::LEFT : return this->m_left.isInputing() ; break ;
        case keyInputType::RIGHT : return this->m_right.isInputing() ; break ;
        case keyInputType::ESC : return this->m_esc.isInputing() ; break ;
        case keyInputType::SPACE : return this->m_space.isInputing() ; break ;
            
        case keyInputType::Z : return this->m_z.isInputing() ; break ;
        case keyInputType::X : return this->m_x.isInputing() ; break ;
        case keyInputType::C : return this->m_c.isInputing() ; break ;
            
        case keyInputType::A : return this->m_a.isInputing() ; break ;
        case keyInputType::S : return this->m_s.isInputing() ; break ;
        case keyInputType::D : return this->m_d.isInputing() ; break ;
            
        default: break ;
    }
    
    return false ;
}

/**
 *	@desc	指定したキーが押されているかどうかを取得
 *	@param	キータイプ
 *	@return	true...押されている
 *	@tips	入力のタイプによって変化
 *			キーボードタイプでは使用する必要はない
 */
bool CInputFlag::isKeyPressed(keyInputType keyType){
    switch(keyType){
        case keyInputType::UP : return this->m_up.isPressed() ; break ;
        case keyInputType::DOWN : return this->m_down.isPressed() ; break ;
        case keyInputType::LEFT : return this->m_left.isPressed() ; break ;
        case keyInputType::RIGHT : return this->m_right.isPressed() ; break ;
        case keyInputType::ESC : return this->m_esc.isPressed() ; break ;
        case keyInputType::SPACE : return this->m_space.isPressed() ; break ;
            
        case keyInputType::Z : return this->m_z.isPressed() ; break ;
        case keyInputType::X : return this->m_x.isPressed() ; break ;
        case keyInputType::C : return this->m_c.isPressed() ; break ;
            
        case keyInputType::A : return this->m_a.isPressed() ; break ;
        case keyInputType::S : return this->m_s.isPressed() ; break ;
        case keyInputType::D : return this->m_d.isPressed() ; break ;
            
        default: break ;
    }
    
    return false ;
}

/**
 *	@desc	指定したキーが押されているかどうかを取得
 *	@param	キータイプ
 *	@return	true...押されている
 *	@tips	入力のタイプによって変化
 *			キーボードタイプでは使用する必要はない
 */
bool CInputFlag::isKeyReleased(keyInputType keyType){
    switch(keyType){
        case keyInputType::UP : return this->m_up.isReleased() ; break ;
        case keyInputType::DOWN : return this->m_down.isReleased() ; break ;
        case keyInputType::LEFT : return this->m_left.isReleased() ; break ;
        case keyInputType::RIGHT : return this->m_right.isReleased() ; break ;
        case keyInputType::ESC : return this->m_esc.isReleased() ; break ;
        case keyInputType::SPACE : return this->m_space.isReleased() ; break ;
            
        case keyInputType::Z : return this->m_z.isReleased() ; break ;
        case keyInputType::X : return this->m_x.isReleased() ; break ;
        case keyInputType::C : return this->m_c.isReleased() ; break ;
            
        case keyInputType::A : return this->m_a.isReleased() ; break ;
        case keyInputType::S : return this->m_s.isReleased() ; break ;
        case keyInputType::D : return this->m_d.isReleased() ; break ;
            
        default: break ;
    }
    
    return false ;
}

//=========================================================================
//
// インプットマネージャー
//
//=========================================================================
//=========================================================================
// コンストラクタ/デストラクタ
//=========================================================================
/**
 *  @desc   constructor
 */
CInputManager::CInputManager(){
    // 入力フラグの生成と設定
    this->setInputFlag(new CInputFlag()) ;
}

/**
 *  @desc   copy constructor
 */
CInputManager::CInputManager(const CInputManager &manager){}

/**
 *  @desc   destructor
 */
CInputManager::~CInputManager(){
    // 入力フラグの破棄
    if(this->m_pInputFlag != NULL){
        delete this->m_pInputFlag ;
        this->m_pInputFlag = NULL ;
    }
}

//=========================================================================
// Singleton用インスタンス取得/破棄
//=========================================================================
// 共有インスタンス本体
CInputManager* CInputManager::m_pInstance = NULL ;

// アクセスポイント
std::mutex inputmanager_singleton_mtx_;

/**
 *  @desc   インスタンス取得
 *  @return CInputManager
 */
CInputManager* CInputManager::getInstance(){
    std::lock_guard<std::mutex> lock(inputmanager_singleton_mtx_) ;
    if ( CInputManager::m_pInstance == NULL){
        CInputManager::m_pInstance = new CInputManager() ;
    }
    return CInputManager::m_pInstance ;
}

/**
 *  @desc   インスタンス破棄
 */
void CInputManager::destroyInstance(){
    if(CInputManager::m_pInstance != NULL){
        delete CInputManager::m_pInstance ;
        CInputManager::m_pInstance = NULL ;
    }
}

//=========================================================================
// メンバ関数
//=========================================================================
/**
 *	@desc	キーコードからキータイプに変換
 *	@param	キーコード
 *	@return	キータイプ
 */
keyInputType CInputManager::changeToInputTypeFromKeyCode(cocos2d::EventKeyboard::KeyCode keyCode){
    // エスケープキーかどうか判定
    if(cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE == keyCode)
    {
        // エスケープキーを返す
        return keyInputType::ESC ;
    }
    // スペースキーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_SPACE == keyCode)
    {
        // スペースキーを返す
        return keyInputType::SPACE ;
    }
    // 上矢印キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode)
    {
        // 上矢印キーを返す
        return keyInputType::UP ;
    }
    // 下矢印キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW == keyCode)
    {
        // 下矢印キーを返す
        return keyInputType::DOWN ;
    }
    // 左矢印キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode)
    {
        // 左矢印キーを返す
        return keyInputType::LEFT ;
    }
    // 右矢印キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode)
    {
        // 右矢印キーを返す
        return keyInputType::RIGHT ;
    }
    // Z キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_Z == keyCode)
    {
        // Z キーを返す
        return keyInputType::Z ;
    }
    // X キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_X == keyCode)
    {
        // X キーを返す
        return keyInputType::X ;
    }
    // C キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_C == keyCode)
    {
        // C キーを返す
        return keyInputType::C ;
    }
    // A キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_A == keyCode)
    {
        // A キーを返す
        return keyInputType::A ;
    }
    // S キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_S == keyCode)
    {
        // S キーを返す
        return keyInputType::S ;
    }
    // D キーかどうか判定
    else if(cocos2d::EventKeyboard::KeyCode::KEY_D == keyCode)
    {
        // D キーを返す
        return keyInputType::D ;
    }
    
    // エラー
    return keyInputType::NONE ;
}

/**
 *	@desc	キーボードを押した際のイベント
 *	@param	キーコード
 */
void CInputManager::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode){
    if(this->m_pInputFlag){
        this->m_pInputFlag->up( this->changeToInputTypeFromKeyCode(keyCode)) ;
    }
}

/**
 *	@desc	キーボードを離した際のイベント
 *	@param	キーコード
 */
void CInputManager::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode){
    if(this->m_pInputFlag){
        this->m_pInputFlag->down(this->changeToInputTypeFromKeyCode(keyCode)) ;
    }
}

/**
 *	@desc	入力フラグの設定
 *	@param	入力フラグ
 */
void CInputManager::setInputFlag(CInputFlag *pInputFlag){
    if(this->m_pInputFlag){
        printf("既に取り付け済み\n") ;
        return ;
    }
    this->m_pInputFlag = pInputFlag ;
}

/**
 *	@desc	入力フラグの破棄
 */
void CInputManager::destroyInputFlag(){
    if(this->m_pInputFlag){
        delete this->m_pInputFlag ;
        this->m_pInputFlag = NULL ;
    }
}

/**
 *	@desc	CInputFlagのclear
 */
void CInputManager::clearInputFlag(){
    if(this->m_pInputFlag){
        this->m_pInputFlag->clear() ;
    }
}

/**
 *	@desc	入力フラグの取得
 *	@return	CInputFlag
 */
CInputFlag *CInputManager::getInputFlag() {
    return this->m_pInputFlag ;
}