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
        coverBack->setPosition(ccp(60 - posX/2, posY/2 - 60));
        coverBack->setScale(0.8);
        
        CCMenuItemImage *goGame = CCMenuItemImage::create("images/button/toGame.png", "images/button/toGameover.png", this, menu_selector(G_Producer::gameCallback));
        goGame->setPosition(ccp(posX/2 - 60, posY/2 - 60));
        goGame->setScale(0.8);
        
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
    CCDirector::sharedDirector()->getRunningScene()->removeAllChildren();
    
    CCDirector::sharedDirector()->getRunningScene()->addChild(G_Cover::create());
}

void G_Producer::gameCallback(CCObject *pSender)
{
    
}

void G_Producer::pageLable()
{
    float posX = this->getContentSize().width;
    float posY = this->getContentSize().height;
    CCLabelTTF *producer1 = CCLabelTTF::create("陈铭：负责游戏主体框架制作\n\n赵阳：负责游戏主体代码\n\n卢金玲：负责游戏主体代码", "", 42, CCSizeMake(0, 680), kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter);
    producer1->setColor(ccc3(0, 0, 0));
    producer1->setPosition(ccp(posX/2, posY/2 + 104));
    producer1->setVisible(false);
    this->addChild(producer1);
    
    CCLabelTTF *producer2 = CCLabelTTF::create("本作品仅用于娱乐，作品中的维尼熊形象版权隶属于Disney公司。\n本作品是作者们对可爱的维尼的致敬！", "", 28);
    producer2->setColor(ccc3(0, 0, 0));
    producer2->setHorizontalAlignment(kCCTextAlignmentCenter);
    producer2->setPosition(ccp(posX/2, posY/2 - 184));
    producer2->setVisible(false);
    this->addChild(producer2);
    
    //specification
    CCScrollView *scrollView = CCScrollView::create(CCSizeMake(1000, 580));
    CCLayer *scrollLayer = CCLayer::create();
    scrollView->setVisible(false);
    scrollLayer->setContentSize(CCSizeMake(1000, 2000));
    
    CCLabelTTF *specification1 = CCLabelTTF::create("1、温馨提示：\n\n本游戏只能通过鼠标控制,建议你从游戏界面以外将鼠标切入,\n否则你可能会在游戏开始时就因碰到错误蜜罐或蜜蜂而结束游戏。\n\n2、特别帮助：", "", 28, CCSizeMake(0, 680), kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
    specification1->setColor(ccc3(0, 0, 0));
    specification1->setPosition(ccp(posX/2, posY + 1100));
//    specification1->setVisible(false);
    scrollLayer->addChild(specification1);
    
    CCSprite *specification2 = CCSprite::create("images/table/AddTable.jpg");
    specification2->setPosition(ccp(posX/2, posY/2 + 966));
//    specification2->setVisible(false);
    scrollLayer->addChild(specification2);
    
    CCSprite *specification3 = CCSprite::create("images/table/MulTable.jpg");
    specification3->setPosition(ccp(posX/2, posY/2 + 148));
    scrollLayer->addChild(specification3);
    
    scrollView->setPosition(ccp(0, posY/2 - 234));
    scrollView->setContainer(scrollLayer);
    scrollView->setTouchMode(kCCTouchesOneByOne);
    scrollView->setTouchEnabled(true);
    scrollView->setContentOffset(ccp(0, -1404));
//    scrollView->setDelegate(this);
    scrollView->setDirection(kCCScrollViewDirectionVertical);
    CCDirector::sharedDirector()->getRunningScene()->addChild(scrollView, 1);
    
    if (Userdata::sharedUserdata()->modeId == Userdata::MODE_PRODUCER) {
        producer1->setVisible(true);
        producer2->setVisible(true);
    }else if (Userdata::sharedUserdata()->modeId == Userdata::MODE_SPECIFICATION) {
        scrollView->setVisible(true);
    }
}