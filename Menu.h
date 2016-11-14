#pragma once
//
//  Menu.h
//  NoOneDies
//

#include <cocos2d.h>

using namespace cocos2d;

class HelloWorldMenu :public LayerColor {

private:
	Size visibleSize;
	Label *label_one;
	Label *label_two;
	Label *label_three;

public:
	virtual bool init();

	virtual bool menu1_start();
	virtual bool menu2_start();
	virtual bool menu3_start();

	CREATE_FUNC(HelloWorldMenu);

	static Scene* createScene();
};
