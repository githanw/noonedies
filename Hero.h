#pragma once
#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Hero :public Sprite {

public:
	virtual bool init();
	CREATE_FUNC(Hero);
};
