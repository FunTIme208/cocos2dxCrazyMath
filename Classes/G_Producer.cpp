//
//  G_Producer.cpp
//  CrazyMath
//
//  Created by ChenMing on 14-9-16.
//
//

#include "G_Producer.h"
#include "G_Cover.h"
#include "Userdata.h"

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
        if (Userdata::sharedUserdata()->modeId == Userdata::MODE_SPECIFICATION){
            pageMenu->addChild(goGame);
        }
        this->addChild(pageMenu);
        
        pageLable();
        
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

void G_Producer::pageLable()
{
    float posX = this->getContentSize().width;
    float posY = this->getContentSize().height;
    CCLabelTTF *producer1 = CCLabelTTF::create("陈铭：负责游戏主体框架制作\n\n赵阳：负责游戏主体代码\n\n卢金玲：负责游戏主体代码", "Verdana", 42);
    producer1->setColor(ccc3(0, 0, 0));
    producer1->setHorizontalAlignment(kCCTextAlignmentCenter);
    producer1->setPosition(ccp(posX/2, posY/2 + 234));
    producer1->setVisible(false);
    this->addChild(producer1, 2);
    
    CCLabelTTF *producer2 = CCLabelTTF::create("本作品仅用于娱乐，作品中的维尼熊形象版权隶属于Disney公司。\n本作品是作者们对可爱的维尼的致敬！", "Verdana", 28);
    producer2->setColor(ccc3(0, 0, 0));
    producer2->setHorizontalAlignment(kCCTextAlignmentCenter);
    producer2->setPosition(ccp(posX/2, posY/2 - 224));
    producer2->setVisible(false);
    this->addChild(producer2, 1);
    
    if (Userdata::sharedUserdata()->modeId == Userdata::MODE_PRODUCER) {
        producer1->setVisible(true);
        producer2->setVisible(true);
    }
}