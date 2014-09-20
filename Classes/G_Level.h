//
//  G_Level.h
//  CrazyMath
//
//  Created by ChenMing on 14-9-20.
//
//

#ifndef __CrazyMath__G_Level__
#define __CrazyMath__G_Level__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class G_Level :public CCLayer
{
public:
    virtual bool init();
    
    void coverCallback(CCObject *pSender);
    
    //gameLevel
    void easyCallback(CCObject *pSender);
    void normalCallback(CCObject *pSender);
    void hardCallback(CCObject *pSender);
    
    CREATE_FUNC(G_Level);
};

#endif /* defined(__CrazyMath__G_Level__) */
