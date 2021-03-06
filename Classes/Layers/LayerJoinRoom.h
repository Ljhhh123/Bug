﻿#ifndef __LAYER_JOIN_ROOM_H__
#define __LAYER_JOIN_ROOM_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "LayerBase.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class LayerJoinRoom final : public LayerBase
{
public:
    static LayerBase* createLayer();

    virtual bool init() override;

    void backMenu(Ref* pSender);
    void getRoomList(float dt);
    void changePage(Ref* pSender, bool);
    void quickJoin(Ref* pSender);
    void search(Ref* pSender);

    CREATE_FUNC(LayerJoinRoom);

private:
    Label* currentPage;
    Label* maxPage;
    Size visibleSize;
    Vec2 origin;
    int pageNum;
    int maxPageNum;
};

#endif // __LAYER_JOIN_ROOM_H__
