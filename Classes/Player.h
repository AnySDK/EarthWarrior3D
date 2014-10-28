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

#ifndef __Moon3d__Player__
#define __Moon3d__Player__

#include "cocos2d.h"
#include "AirCraft.h"

//support controller
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "base/CCEventListenerController.h"
#include "base/CCController.h"
#endif

USING_NS_CC;

class Player : public AirCraft
{
public:
    CREATE_FUNC(Player);
    bool init();
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchMoved(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    void update(float dt);
    
    static const float rollSpeed;// recommended 1.5
    static const float returnSpeed;// recommended 4
    static const float maxRoll;
    static const float rollReturnThreshold;
    void setTargetAngle(float angle){targetAngle = angle;};
    void setTargetPos(Vec2 target){targetPos = target;};
    
    void shoot(float dt);
    void shootMissile(float dt);
    void stop();
    CC_SYNTHESIZE(MotionStreak*, _streak, Trail);
    CC_SYNTHESIZE(ParticleSystemQuad*, _emissionPart, EmissionPart);
    void setPosition(Vec2 pos);
    virtual bool hurt(float damage);
    virtual void die();
    void hideWarningLayer(Node* node);
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //对游戏手柄的响应
    void onKeyDown(Controller *controller, int keyCode, Event *event);
    void onKeyUp(Controller *controller, int keyCode,Event *event);
    void onAxisEvent(Controller* controller, int keyCode,Event* event);
    void onAxisRepeat();
    void onKeyRepeat();
#endif
    
protected:
    float targetAngle;
    Vec2 targetPos;
    Vec2 _trailOffset;
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    float keyX;
    float keyY;
    float axisX;
    float axisY;
#endif
    
};


#endif /* defined(__Moon3d__Player__) */
