//
//  G_Producer.h
//  CrazyMath
//
//  Created by ChenMing on 14-9-16.
//
//

#ifndef __CrazyMath__G_Producer__
#define __CrazyMath__G_Producer__

#include <iostream>
#include "cocos2d.h"

class G_Producer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    //按钮功能
    void coverCallback(CCObject *pSender);
    void gameCallback(CCObject *pSender);
    
    //页面显示判断
    void pageLable();
    
    CREATE_FUNC(G_Producer);
    
};

#endif /* defined(__CrazyMath__G_Producer__) */
