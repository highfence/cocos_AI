#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Player;
class Enemy;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	
	Player* player;
	Enemy* enemy;
};

#endif // __HELLOWORLD_SCENE_H__
