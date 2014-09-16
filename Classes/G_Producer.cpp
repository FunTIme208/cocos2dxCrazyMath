//
//  G_Producer.cpp
//  CrazyMath
//
//  Created by ChenMing on 14-9-16.
//
//

#include "G_Producer.h"
#include "G_Cover.h"

USING_NS_CC;

bool G_Producer::init()
{
    bool b_init = false;
    do{
        CC_BREAK_IF(!CCLayer::init());
        
        CCSprite * producerBack = CCSprite::create("images/background/font.png");
        float posX = producerBack->getContentSize().width;
        float posY = producerBack->getContentSize().height;
        producerBack->setPosition(ccp(posX/2, posY/2));
        this->addChild(producerBack);
        
        CCMenuItemImage *coverBack = CCMenuItemImage::create("images/button/back.png", "images/button/backover.png", this, menu_selector(G_Producer::coverCallback));
        coverBack->setPosition(ccp(80 - posX/2, 80 - posY/2));
        
        CCMenuItemImage *goGame = CCMenuItemImage::create("images/button/toGame.png", "images/button/toGameover.png", this, menu_selector(G_Producer::gameCallback));
        goGame->setPosition(ccp(180 - posX/2, 70 - posY/2));
        
        CCMenu *pageMenu = CCMenu::create();
        pageMenu->addChild(coverBack);
        if (stateId == S_Specification){
            pageMenu->addChild(goGame);
        }
        this->addChild(pageMenu);
        
        b_init = true;
    }while (0);
    
    return b_init;
}

void G_Producer::coverCallback(CCObject *pSender)
{
    this->removeFromParent();
    
    CCDirector::sharedDirector()->getRunningScene()->addChild(G_Cover::create());
}

void G_Producer::gameCallback(CCObject *pSender)
{
    
}