#ifndef __Splash_SCENE_H__
#define __Splash_SCENE_H__

#include "cocos2d.h"

class Splash : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void setUpBG(cocos2d::Size, cocos2d::Vec2, int);
	void setUpUI(cocos2d::Size, cocos2d::Vec2, int);
	
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Splash);
private:
	cocos2d::Sprite* bg_Sprite;
};

#endif // __Splash_SCENE_H__