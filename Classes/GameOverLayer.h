/****************************************************************************
 Copyright (c) 2014 Chukong Technologies Inc.

 http://github.com/chukong/EarthWarrior3D

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __Moon3d__GameOverLayer__
#define __Moon3d__GameOverLayer__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

//support controller need header files
#include "base/CCEventListenerController.h"
#include "base/CCController.h"

USING_NS_CC;
using namespace CocosDenshion;

class GameOverLayer : public LayerColor
{
public:
    
    static GameOverLayer* create(int score);
    
    virtual bool init();
    
    //event listener
    void onKeyDown(Controller *controller, int keyCode,Event *event);
    
private:
    
    int m_score;
    MenuItemSprite* backtomenu_Item;
    MenuItemSprite* playagain_Item;
    
    void ShowScore();
    
    void menu_backtomenu_Callback(Ref* sender);
    void menu_playagain_Callback(Ref* sender);
    void menu_backtomenu();
    void menu_playagain();
    
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchMoved(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
};

#endif /* defined(__Moon3d__GameOverLayer__) */
