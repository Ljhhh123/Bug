#ifndef __SCENE_LOGIN_AND_REGISTER_H__
#define __SCENE_LOGIN_AND_REGISTER_H__

#include "cocos2d.h"
USING_NS_CC;

class SceneLoginAndRegister : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneLoginAndRegister);
};

#endif // __SCENE_LOGIN_AND_REGISTER_H__
