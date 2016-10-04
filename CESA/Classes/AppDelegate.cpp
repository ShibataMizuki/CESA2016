#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include"Scene/TitleScene/TitleScene.h"
#include"ADX2Rapper/ADX2Rapper.h"
#include"GameObjectManager/GameObjectManager.h"
#include"SoundManager/SoundManager.h"
USING_NS_CC;

static Size screenResolution = Size(1280.f, 960.f);

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    
	
	cocos2d::log("shibata:初期化開始");
	// initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("BEAT SHOT", Rect(0, 0, screenResolution.height*0.5f, screenResolution.width*0.5f));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(screenResolution.height,screenResolution.width, ResolutionPolicy::SHOW_ALL);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");
    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	auto scene = TitleScene::createScene();

	cocos2d::log("shibata:ADX2初期化開始");

	auto manager = ADX2Manager::getInstance();
	manager->initialize("TutorialProject.acf");
	auto acbHandle = manager->loadCueSheet("CueSheet_0.acb");
	auto player = manager->createPlayer(acbHandle, 3);
	GameObjectManager::getInstance()->setItemHitPlayer(manager->createPlayer(acbHandle, 2));

	cocos2d::log("shibata:ADX2初期化終了");

	auto soundManager = SoundManager::getInstance();
	soundManager->setBackSound(player, 180.f);
	soundManager->getBackSound()->stop();
	soundManager->getBackSound()->start();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

	cocos2d::EventCustom event("DidEnterBackground");
	Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	cocos2d::EventCustom event("WillEnterBackground");
	Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}
