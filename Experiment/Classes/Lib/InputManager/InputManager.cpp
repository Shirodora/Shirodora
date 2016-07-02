//
//  inputManager.cpp
//  
//
//  Created by Ryoutarou Onimura on 2016/06/08.
//
//

#include "inputManager.hpp"

//=========================================================================
// インプットクラス
//=========================================================================
void CInput::clear(){
    this->m_inputing = false ;
    this->m_pressed = false ;
    this->m_released = false ;
}

/**
 *  @desc   キーが押された時に呼ぶ関数
 */
void CInput::input(){
    this->m_inputing = true ;
    this->pressed() ;
}

/**
 *  @desc   キーが離された時に呼ぶ関数
 */
void CInput::unInput(){
    this->m_inputing = false ;
    this->released() ;
}

/**
 *  @desc   キーが押されているフラグを上げる
 */
void CInput::pressed(){
    if(this->m_released == true) this->m_released = false ;
    if(this->m_inputing == true){
        this->m_pressed = true ;
        this->m_pressedCounter = 0 ;
    }
}

/**
 *  @desc   キーが押されているフラグを下げる
 */
void CInput::released(){
    if(this->m_pressed == true) this->m_pressed = false ;
    if(this->m_inputing == false){
        this->m_released = true ;
        this->m_releasedCounter = 0 ;
    }
}

/**
 *  @desc   touched releasedのカウンターアップデート
 */
void CInput::counterUpdate(){
    if(this->m_pressed == true){
        this->m_pressedCounter++ ;
        if(this->m_pressedCounter >= this->COUNTER_MAX){
            this->m_pressed = false ;
        }
    }
    if(this->m_released == true){
        this->m_releasedCounter++ ;
        if(this->m_releasedCounter >= this->COUNTER_MAX){
            this->m_released = false ;
        }
    }
}

/**
 *  @desc   キーが入力されているかを返す
 *  @return true...入力されている false...入力されていない
 */
bool CInput::isInput(){
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
void CInputFlag::up( kInputType keyType_ ){
    switch( keyType_ ){
        case kInputType::UP : this->m_up.input() ; break ;
        case kInputType::DOWN : this->m_down.input() ; break ;
        case kInputType::LEFT : this->m_left.input() ; break ;
        case kInputType::RIGHT : this->m_right.input() ; break ;
        case kInputType::ESC : this->m_esc.input() ; break ;
        case kInputType::SPACE : this->m_space.input() ; break ;
            
        case kInputType::Z : this->m_z.input() ; break ;
        case kInputType::X : this->m_x.input() ; break ;
        case kInputType::C : this->m_c.input() ; break ;
            
        case kInputType::A : this->m_a.input() ; break ;
        case kInputType::S : this->m_s.input() ; break ;
        case kInputType::D : this->m_d.input() ; break ;
            
        default: break ;
    }
}
/**
 *	@desc	キーが離されている時の反映
 *	@param	キーコード
 */
void CInputFlag::down( kInputType keyType_ ){
    switch( keyType_ ){
        case kInputType::UP : this->m_up.unInput() ; break ;
        case kInputType::DOWN : this->m_down.unInput() ; break ;
        case kInputType::LEFT : this->m_left.unInput() ; break ;
        case kInputType::RIGHT : this->m_right.unInput() ; break ;
        case kInputType::ESC : this->m_esc.unInput() ; break ;
        case kInputType::SPACE : this->m_space.unInput() ; break ;
            
        case kInputType::Z : this->m_z.unInput() ; break ;
        case kInputType::X : this->m_x.unInput() ; break ;
        case kInputType::C : this->m_c.unInput() ; break ;
            
        case kInputType::A : this->m_a.unInput() ; break ;
        case kInputType::S : this->m_s.unInput() ; break ;
        case kInputType::D : this->m_d.unInput() ; break ;
            
        default: break ;
    }
}

/**
 *  @desc   カウンターアップデート
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
bool CInputFlag::isKeyInputed( kInputType keyType_ ){
    switch( keyType_ ){
        case kInputType::UP : return this->m_up.isInput() ; break ;
        case kInputType::DOWN : return this->m_down.isInput() ; break ;
        case kInputType::LEFT : return this->m_left.isInput() ; break ;
        case kInputType::RIGHT : return this->m_right.isInput() ; break ;
        case kInputType::ESC : return this->m_esc.isInput() ; break ;
        case kInputType::SPACE : return this->m_space.isInput() ; break ;
            
        case kInputType::Z : return this->m_z.isInput() ; break ;
        case kInputType::X : return this->m_x.isInput() ; break ;
        case kInputType::C : return this->m_c.isInput() ; break ;
            
        case kInputType::A : return this->m_a.isInput() ; break ;
        case kInputType::S : return this->m_s.isInput() ; break ;
        case kInputType::D : return this->m_d.isInput() ; break ;
            
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
bool CInputFlag::isKeyPressed( kInputType keyType_ ){
    switch( keyType_ ){
        case kInputType::UP : return this->m_up.isPressed() ; break ;
        case kInputType::DOWN : return this->m_down.isPressed() ; break ;
        case kInputType::LEFT : return this->m_left.isPressed() ; break ;
        case kInputType::RIGHT : return this->m_right.isPressed() ; break ;
        case kInputType::ESC : return this->m_esc.isPressed() ; break ;
        case kInputType::SPACE : return this->m_space.isPressed() ; break ;
            
        case kInputType::Z : return this->m_z.isPressed() ; break ;
        case kInputType::X : return this->m_x.isPressed() ; break ;
        case kInputType::C : return this->m_c.isPressed() ; break ;
            
        case kInputType::A : return this->m_a.isPressed() ; break ;
        case kInputType::S : return this->m_s.isPressed() ; break ;
        case kInputType::D : return this->m_d.isPressed() ; break ;
            
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
bool CInputFlag::isKeyReleased( kInputType keyType_ ){
    switch( keyType_ ){
        case kInputType::UP : return this->m_up.isReleased() ; break ;
        case kInputType::DOWN : return this->m_down.isReleased() ; break ;
        case kInputType::LEFT : return this->m_left.isReleased() ; break ;
        case kInputType::RIGHT : return this->m_right.isReleased() ; break ;
        case kInputType::ESC : return this->m_esc.isReleased() ; break ;
        case kInputType::SPACE : return this->m_space.isReleased() ; break ;
            
        case kInputType::Z : return this->m_z.isReleased() ; break ;
        case kInputType::X : return this->m_x.isReleased() ; break ;
        case kInputType::C : return this->m_c.isReleased() ; break ;
            
        case kInputType::A : return this->m_a.isReleased() ; break ;
        case kInputType::S : return this->m_s.isReleased() ; break ;
        case kInputType::D : return this->m_d.isReleased() ; break ;
            
        default: break ;
    }
    
    return false ;
}

//=========================================================================
//
// 入力管理
//
//=========================================================================
// 共有インスタンス本体
CInputManager* CInputManager::m_pInstance = NULL ;

// アクセスポイント
std::mutex inputmanager_singleton_mtx_;

// インスタンス取得
CInputManager* CInputManager::getInstance() {
    std::lock_guard<std::mutex> lock( inputmanager_singleton_mtx_ ) ;
    if ( CInputManager::m_pInstance == NULL ) {
        CInputManager::m_pInstance = new CInputManager() ;
    }
    return CInputManager::m_pInstance ;
}

// インスタンス破棄
void CInputManager::destroyInstance() {
    if(CInputManager::m_pInstance != NULL){
        delete CInputManager::m_pInstance ;
        CInputManager::m_pInstance = NULL ;
    }
}

// コンストラクタ
CInputManager::CInputManager() {
    // 入力フラグの生成と設定
    this->setInputFlag( new CInputFlag() ) ;
}

// コンストラクタ
CInputManager::CInputManager( const CInputManager& inputMgr_ ) {}

// デストラクタ
CInputManager::~CInputManager() {
    // 入力フラグの破棄
    if(this->m_pInputFlag != NULL){
        delete this->m_pInputFlag ;
        this->m_pInputFlag = NULL ;
    }
}

/**
 *	@desc	キーコードからキータイプに変換
 *	@param	キーコード
 *	@return	キータイプ
 */
kInputType CInputManager::changeToInputTypeFromKeyCode( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
    
    // エスケープキーかどうか判定
    if ( cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE == keyCode_ )
    {
        // エスケープキーを返す
        return kInputType::ESC ;
    }
    // スペースキーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_SPACE == keyCode_ )
    {
        // スペースキーを返す
        return kInputType::SPACE ;
    }
    // 上矢印キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode_ )
    {
        // 上矢印キーを返す
        return kInputType::UP ;
    }
    // 下矢印キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW == keyCode_ )
    {
        // 下矢印キーを返す
        return kInputType::DOWN ;
    }
    // 左矢印キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode_ )
    {
        // 左矢印キーを返す
        return kInputType::LEFT ;
    }
    // 右矢印キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode_ )
    {
        // 右矢印キーを返す
        return kInputType::RIGHT ;
    }
    // Z キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_Z == keyCode_ )
    {
        // Z キーを返す
        return kInputType::Z ;
    }
    // X キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_X == keyCode_ )
    {
        // X キーを返す
        return kInputType::X ;
    }
    // C キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_C == keyCode_ )
    {
        // C キーを返す
        return kInputType::C ;
    }
    // A キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_A == keyCode_ )
    {
        // A キーを返す
        return kInputType::A ;
    }
    // S キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_S == keyCode_ )
    {
        // S キーを返す
        return kInputType::S ;
    }
    // D キーかどうか判定
    else if ( cocos2d::EventKeyboard::KeyCode::KEY_D == keyCode_ )
    {
        // D キーを返す
        return kInputType::D ;
    }
    
    // エラー
    return kInputType::NONE ;
}

/**
 *	@desc	キーボードを押した際のイベント
 *	@param	キーコード
 */
void CInputManager::onKeyPressed( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
    if ( this->m_pInputFlag ) {
        this->m_pInputFlag->up( this->changeToInputTypeFromKeyCode( keyCode_ ) ) ;
    }
}

/**
 *	@desc	キーボードを離した際のイベント
 *	@param	キーコード
 */
void CInputManager::onKeyReleased( cocos2d::EventKeyboard::KeyCode keyCode_ ) {
    if ( this->m_pInputFlag ) {
        this->m_pInputFlag->down( this->changeToInputTypeFromKeyCode( keyCode_ ) ) ;
    }
}

/**
 *	@desc	入力フラグの設定
 *	@param	入力フラグ
 */
void CInputManager::setInputFlag( CInputFlag* pInputFlag_ ) {
    if ( this->m_pInputFlag ) {
        printf( "既に取り付け済み\n" ) ;
        return ;
    }
    this->m_pInputFlag = pInputFlag_ ;
}

/**
 *	@desc	入力フラグの削除
 */
void CInputManager::destroyInputFlag() {
    if ( this->m_pInputFlag ) {
        delete this->m_pInputFlag ;
        this->m_pInputFlag = NULL ;
    }
}

/**
 *	@desc	入力フラグのクリア
 */
void CInputManager::clearInputFlag() {
    if ( this->m_pInputFlag ) {
        this->m_pInputFlag->clear() ;
    }
}

/**
 *	@desc	入力フラグの取得
 *	@return	入力フラグ
 */
CInputFlag* CInputManager::getInputFlag() {
    return this->m_pInputFlag ;
}