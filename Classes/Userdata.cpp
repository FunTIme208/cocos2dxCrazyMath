//
//  Userdata.cpp
//  CrazyMath
//
//  Created by ChenMing on 14-9-18.
//
//

#include "Userdata.h"

static Userdata *s_SharedUserdata = NULL;

Userdata *Userdata::sharedUserdata()
{
    if (!s_SharedUserdata) {
        s_SharedUserdata = new Userdata;
    }
    return s_SharedUserdata;
}

Userdata::~Userdata()
{
    s_SharedUserdata = NULL;
}