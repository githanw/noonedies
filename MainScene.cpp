//
//  MainScene.cpp
//  NoOneDies
//
//  Created by 王俊斌 on 16/7/15.
//
//
#include "MainScene.hpp"
#include "GamePlayScene.hpp"
#include "MenuLabel.hpp"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion; 

std::string items[] = {"EASY","NORMAL","HARD","HELL"};

Scene* MainScene::createScene(){
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init(){
    LayerColor::initWithColor(Color4B::WHITE);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    //add title
    auto titleImg = Sprite::create("title.png");
    titleImg->setPosition(visibleSize.width/2-95,visibleSize.height-70);
    titleImg->setScale(0.9f);
    addChild(titleImg);
    auto title = Label::create();
    title->setString("No One Dies");
    title->setSystemFontName("chalkduster");
    title->setSystemFontSize(28);
    title->setColor(Color3B::BLACK);
    title->setPosition(visibleSize.width/2+30,visibleSize.height-78);
    addChild(title);
    
    //add music sprite
    auto music = Sprite::create();
    if (UserDefault::getInstance()->getBoolForKey("music")) {
        music->setTexture("music_icon.jpg");
    }else{
        music->setTexture("music_icon_cancel.jpg");
    }
    addChild(music);
    music->setPosition(visibleSize.width-40,visibleSize.height-30);
    music->setScale(0.3);
    auto musicListener = EventListenerTouchOneByOne::create();
    musicListener->onTouchBegan = [music](Touch * t,Event * e){
        if (UserDefault::getInstance()->getBoolForKey("music")) {
            music->setTexture("music_icon_cancel.jpg");
            UserDefault::getInstance()->setBoolForKey("music", false);
        }else{
            music->setTexture("music_icon.jpg");
            UserDefault::getInstance()->setBoolForKey("music", true);
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(musicListener, this);
    
    //add menu
    auto menu = Menu::create();
    menu->setPosition(visibleSize.width/2,visibleSize.height/2-60);
    int count = sizeof(items)/sizeof(items[0]);
    for (auto i =0; i<count; i++) {
        auto label = MenuLabel::create();
        label->setString(items[i]);
        auto item = MenuItemLabel::create(label, [i](Object* o){
            playEffect();
            GamePlayScene::_degree = i+1;
            Director::getInstance()->replaceScene(GamePlayScene::createScene());
        });
        menu->addChild(item);
    }
    menu->alignItemsVerticallyWithPadding(15);
    addChild(menu);
    
    //add physical button "Backspace" listener
    auto physicalButtonListener = EventListenerKeyboard::create();
    physicalButtonListener->onKeyReleased = [](EventKeyboard::KeyCode code,Event* e){
        switch (code) {
            case cocos2d::EventKeyboard::KeyCode::KEY_BACK:
                Director::getInstance()->end();
                break;
            default:
                break;
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(physicalButtonListener, this);
    
    //preload effect
    SimpleAudioEngine::sharedEngine()->preloadEffect(FileUtils::sharedFileUtils()->fullPathForFilename("1.mp3").c_str());
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
    
    return true;
}

//play effect
void MainScene::playEffect(){
    if (UserDefault::getInstance()->getBoolForKey("music")) {
        SimpleAudioEngine::sharedEngine()->playEffect(FileUtils::sharedFileUtils()->fullPathForFilename("effect.mp3").c_str());
    }
}