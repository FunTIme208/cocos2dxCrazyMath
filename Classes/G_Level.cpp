//
//  G_Level.cpp
//  CrazyMath
//
//  Created by ChenMing on 14-9-20.
//
//

#include "G_Level.h"
#include "G_Cover.h"

bool G_Level::init()
{
    bool b_init = false;
    do{
        CC_BREAK_IF(!CCLayer::init());
        
        CCSprite *levelBackground = CCSprite::create("images/background/levelbackground.jpg");
        float posX = this->getContentSize().width;
        float posY = this->getContentSize().height;
        levelBackground->setPosition(ccp(posX/2, posY/2));
        this->addChild(levelBackground);
        
        CCSprite *levelFlower = CCSprite::create("images/flash/sakurua.png");
        levelFlower->setPosition(ccp(posX/2 + 20, posY/2 + 300));
        this->addChild(levelFlower);
        
        CCMenuItemImage *coverBack = CCMenuItemImage::create("images/button/back.png", "images/button/backover.png", this, menu_selector(G_Level::coverCallback));
        coverBack->setPosition(ccp(80 - posX/2, 80 - posY/2));
        coverBack->setScale(0.8);
        
        CCMenuItemImage *easyLevel = CCMenuItemImage::create("images/button/easy.png", "images/button/easy.png", this, menu_selector(G_Level::easyCallback));
        easyLevel->setPosition(ccp(200, 200));
        
        CCMenuItemImage *normalLevel = CCMenuItemImage::create("images/button/normal.png", "images/button/normal.png", this, menu_selector(G_Level::normalCallback));
        normalLevel->setPosition(ccp(200, 0));
        
        CCMenuItemImage *hardLevel = CCMenuItemImage::create("images/button/difficult.png", "images/button/difficult.png", this, menu_selector(G_Level::hardCallback));
        hardLevel->setPosition(ccp(200, 200));
        
        CCMenu *levelMenu = CCMenu::create(coverBack, easyLevel, normalLevel, hardLevel, NULL);
        levelMenu->setPosition(ccp(posX/2, posY/2));
        this->addChild(levelMenu);
        
        b_init = true;
    }while (0);
    return b_init;
}

void G_Level::coverCallback(CCObject *pSender)
{
    this->removeFromParent();
    
    CCDirector::sharedDirector()->getRunningScene()->addChild(G_Cover::create());
}

void G_Level::easyCallback(CCObject *pSender)
{
    
}

void G_Level::normalCallback(CCObject *pSender)
{
    
}

void G_Level::hardCallback(CCObject *pSender)
{
    
}