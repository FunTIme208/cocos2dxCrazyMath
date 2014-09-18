//
//  Userdata.h
//  CrazyMath
//
//  Created by ChenMing on 14-9-18.
//
//

#ifndef __CrazyMath__Userdata__
#define __CrazyMath__Userdata__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class Userdata :public CCObject
{
public:
    static Userdata *sharedUserdata();
    virtual bool init();
    virtual ~Userdata();
    
    int modeId;
    
    static const char MODE_START = 0;
    static const char MODE_SPECIFICATION = 1;
    static const char MODE_PRODUCER = 2;
};

#endif /* defined(__CrazyMath__Userdata__) */