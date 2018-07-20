﻿#include "Helpers.h"
#include "LayerMenu.h"
#include "ModelUser.h"
#include "ServiceAPI.h"

LayerBase* LayerMenu::createLayer()
{
    return LayerMenu::create();
}

bool LayerMenu::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    buttonJoin = MenuItemLabel::create(Label::createWithTTF("Join Game", "Fonts/arial.ttf", 30), CC_CALLBACK_1(LayerMenu::joinRoom, this));
    buttonNew = MenuItemLabel::create(Label::createWithTTF("New Game", "Fonts/arial.ttf", 30), CC_CALLBACK_1(LayerMenu::newRoom, this));
    logoutButton = MenuItemLabel::create(Label::createWithTTF("Logout", "Fonts/arial.ttf", 20), CC_CALLBACK_1(LayerMenu::logoutEvent, this));
    userIdLabel = Label::createWithTTF("", "Fonts/arial.ttf", 20);

    buttonJoin->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
    buttonNew->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));
    logoutButton->setPosition(Vec2(visibleSize.width - 60, visibleSize.height - 60));
    userIdLabel->setPosition(Vec2(100, visibleSize.height - 50));

    auto menu = Menu::create();
    menu->setPosition(origin);
    menu->addChild(buttonJoin);
    menu->addChild(buttonNew);
    menu->addChild(logoutButton);

    this->addChild(userIdLabel, 1);
    this->addChild(menu, 1);

    initUser();

    return true;
}

void LayerMenu::joinRoom(Ref* pSender)
{
    if (!this->getActive()) return;
    this->updateLayer(Tag::LayerFromMenuToJoinRoom);
}

void LayerMenu::newRoom(Ref* pSender)
{
    if (!this->getActive()) return;
    this->updateLayer(Tag::LayerFromMenuToNewRoom);
}

void LayerMenu::logoutEvent(Ref* pSender)
{
    Singleton<ServiceAPI>::GetInstance()->Logout();
    this->updateScene();
}

void LayerMenu::initUser()
{
    auto userid = Singleton<ModelUser>::GetInstance()->getUserId();
    auto avator = Singleton<ModelUser>::GetInstance()->getAvatar();
    auto nickname = Singleton<ModelUser>::GetInstance()->getNickName();
    auto gender = Singleton<ModelUser>::GetInstance()->getGender();
    auto level = Singleton<ModelUser>::GetInstance()->getLevel();
    userIdLabel->setString(userid);
}