#include "SplashScene.h"
#include "HelloWorldScene\HelloWorldScene.h"

USING_NS_CC;

Scene* Splash::createScene(){
    auto scene = Scene::create();
    auto layer = Splash::create();
    scene->addChild(layer);
    return scene;
}

bool Splash::init(){
    if( !Layer::init() ){ return false; }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	setUpBG(visibleSize, origin, 0);
	setUpUI(visibleSize, origin, 10);

	auto T = RotateBy::create(2, 0, 0);
	bg_Sprite->runAction(Sequence::create(T, CallFuncN::create( CC_CALLBACK_1(Splash::menuCallback, this)), NULL));

    return true;
}

void Splash::setUpBG(Size visibleSize, Vec2 origin, int z){
	bg_Sprite = Sprite::create("HD/BG/BlackGradiant.png");
	bg_Sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg_Sprite, z);
}

void Splash::setUpUI(Size visibleSize, Vec2 origin, int z){
	auto TPA_sprite = Sprite::create("HD/SPLASH/TeamPhoenixApps.png");
	TPA_sprite->setPosition(bg_Sprite->getPosition());
	this->addChild(TPA_sprite, z);
}


void Splash::menuCallback(Ref* pSender){
	auto director = Director::getInstance();
	auto scene = HelloWorld::createScene();
	director->replaceScene(scene);
}