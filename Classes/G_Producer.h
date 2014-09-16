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
    
    static int stateId;
    
    CREATE_FUNC(G_Producer);
    
private:
    static const int S_Producer = 100;
    static const int S_Specification = 101;
};

#endif /* defined(__CrazyMath__G_Producer__) */
