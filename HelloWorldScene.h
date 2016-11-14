#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameController.h"


//class HelloWorld : public cocos2d::Layer

class HelloWorld : public cocos2d::LayerColor
{
private:
	cocos2d::Vector<GameController*> gcs;
	int personNum;
public:
    static cocos2d::Scene* createScene(int n);
    
	//随机添加
	virtual void update(float dt);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
   // CREATE_FUNC(HelloWorld);

	//传参:
	static HelloWorld* create(int n);
	virtual bool init(int n);
	
};

#endif // __HELLOWORLD_SCENE_H__
