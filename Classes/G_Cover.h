//
//  G_Cover.h
//  CrazyMath
//
//  Created by ChenMing on 14-9-15.
//
//

#ifndef __CrazyMath__G_Cover__
#define __CrazyMath__G_Cover__

#include <iostream>
#include "cocos2d.h"

class G_Cover :public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene *scene();
    
    //menu button callback
    void startGameCallback(CCObject *pSender);
    void specificationCallback(CCObject *pSender);
    void producerCallback(CCObject *pSender);
    void closeCallback(CCObject *pSender);
    
    CREATE_FUNC(G_Cover);

private:
    static const int S_Producer = 100;
    static const int S_Specification = 101;
    

};

#endif /* defined(__CrazyMath__G_Cover__) */
