﻿#ifndef __USER_MODEL_H__
#define __USER_MODEL_H__

#include <string>
#include <stdio.h>

using namespace std;

class ModelUser final
{
public:
    string id;
    string Email;
    string Nikename;
    string avatar;
    int gender;
    int level;
};

#endif
