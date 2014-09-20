//
//  G_Cover.cpp
//  CrazyMath
//
//  Created by ChenMing on 14-9-15.
//
//

#include "G_Cover.h"
#include "G_Producer.h"
#include "Userdata.h"
#include "G_Level.h"

USING_NS_CC;

CCScene* G_Cover::scene()
{
    CCScene *scene = CCScene::create();
    G_Cover *layer = G_Cover::create();
    scene->addChild(layer, 0);
    return scene;
}

bool G_Cover::init()
{
    bool b_init = false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        
        CCSprite *coverBack = CCSprite::create("images/background/HomeBack1024.jpg");
        float posX = coverBack->getContentSize().width;
        float posY = coverBack->getContentSize().height;
        coverBack->setPosition(ccp(posX/2, posY/2));
        this->addChild(coverBack,0);
        
        CCMenuItemImage *startGame = CCMenuItemImage::create("images/button/button0.png", "images/button/button0over.png", this, menu_selector(G_Cover::startGameCallback));
        startGame->setPosition(ccp(0, -50));
        
        CCMenuItemImage *specification = CCMenuItemImage::create("images/button/button1.png", "images/button/button1over.png", this, menu_selector(G_Cover::specificationCallback));
        specification->setPosition(ccp(-180, -180));
        
        CCMenuItemImage *producer = CCMenuItemImage::create("images/button/button2.png", "images/button/button2over.png", this, menu_selector(G_Cover::producerCallback));
        producer->setPosition(ccp(180, -180));
        
        CCMenuItemImage *closeGame = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this, menu_selector(G_Cover::closeCallback));
        closeGame->setScale(1.5f);
        closeGame->setPosition(ccp(posX/2 - 50, posY/2 - 50));
        
        CCMenu *coverMenu = CCMenu::create(startGame, producer, specification, closeGame, NULL);
        coverMenu->setPosition(posX/2, posY/2);
        this->addChild(coverMenu, 1);
        
        b_init = true;
    }while (0);
    
    return b_init;
}

void G_Cover::startGameCallback(CCObject *pSender)
{
    this->removeFromParent();
    
    CCDirector::sharedDirector()->getRunningScene()->addChild(G_Level::create());
}

void G_Cover::producerCallback(CCObject *pSender)
{
    Userdata::sharedUserdata()->modeId = Userdata::MODE_PRODUCER;
    this->removeFromParent();
    CCDirector::sharedDirector()->getRunningScene()->addChild(G_Producer::create());
}

void G_Cover::specificationCallback(CCObject *pSender)
{
    Userdata::sharedUserdata()->modeId = Userdata::MODE_SPECIFICATION;
    this->removeFromParent();
    CCDirector::sharedDirector()->getRunningScene()->addChild(G_Producer::create());
}

void G_Cover::closeCallback(CCObject *pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}