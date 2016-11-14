#include "Menu.h"
#include <cocos2d.h>
#include "HelloWorldScene.h"
using namespace cocos2d;

Scene* HelloWorldMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorldMenu::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorldMenu::init() {
	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();

	//һ������
	label_one = Label::create();
	label_one->setString("One Person");
	label_one->setSystemFontSize(40);
	label_one->setColor(Color3B::BLACK);
	addChild(label_one);
	label_one->setAnchorPoint(Point(0.5, 0.5));//����
	label_one->setPosition(visibleSize.width / 2, (visibleSize.height / 9)*6);

	//��������
	label_two = Label::create();
	label_two->setString("Two Persons");
	label_two->setSystemFontSize(40);
	label_two->setColor(Color3B::BLACK);
	addChild(label_two);
	label_two->setAnchorPoint(Point(0.5, 0.5));//����
	label_two->setPosition(visibleSize.width / 2, (visibleSize.height / 9) * 4);

	//��������
	label_three = Label::create();
	label_three->setString("Three Persons");
	label_three->setSystemFontSize(40);
	label_three->setColor(Color3B::BLACK);
	addChild(label_three);
	label_three->setAnchorPoint(Point(0.5, 0.5));//����
	label_three->setPosition(visibleSize.width / 2, (visibleSize.height / 9) * 2);

	//�˵��¼�
	menu1_start();//һ������
	menu2_start();//��������
	menu3_start();//��������
	


	//�ر�---�˳�
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = [](EventKeyboard::KeyCode code,
		Event *e) {
		switch (code)
		{
		case EventKeyboard::KeyCode::KEY_BACK:
			Director::getInstance()->end();//�رճ���
			break;
		default:
			break;
		}
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool HelloWorldMenu::menu1_start(){
	auto m1_listener = EventListenerTouchOneByOne::create();
	
	m1_listener->onTouchBegan = [this](Touch * t, Event * e) {
			log("one==%f,%f", t->getLocation().x, t->getLocation().y);

			//if (label_one->getBoundingBox().containsPoint(Point(t->getLocation().x, t->getLocation().y - 100))) {
			if (label_one->getBoundingBox().containsPoint(t->getLocation())) {
				log("one1111==%f,%f", t->getLocation().x, t->getLocation().y);
				Director::getInstance()->replaceScene(HelloWorld::createScene((int)1));
			}		
		
		return false;
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(m1_listener, label_one);
	
	return true;
}

bool HelloWorldMenu::menu2_start() {
	auto m2_listener = EventListenerTouchOneByOne::create();

	m2_listener->onTouchBegan = [this](Touch * t, Event * e) {
		log("two==%f,%f", t->getLocation().x, t->getLocation().y);

		//if (label_two->getBoundingBox().containsPoint(Point(t->getLocation().x, t->getLocation().y - 100))) {
		if (label_two->getBoundingBox().containsPoint(t->getLocation())) {
			log("two222==%f,%f", t->getLocation().x, t->getLocation().y);
			Director::getInstance()->replaceScene(HelloWorld::createScene((int)2));
		}
		return false;
		
	};
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(m2_listener, label_two);
	return true;
}

bool HelloWorldMenu::menu3_start() {
	auto m3_listener = EventListenerTouchOneByOne::create();

	m3_listener->onTouchBegan = [this](Touch * t, Event * e) {
		//if (label_three->getBoundingBox().containsPoint(Point(t->getLocation().x, t->getLocation().y - 100))) {
		if (label_three->getBoundingBox().containsPoint(t->getLocation())) {
			log("three333==%f,%f", t->getLocation().x, t->getLocation().y);
			Director::getInstance()->replaceScene(HelloWorld::createScene((int)3));
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(m3_listener, label_three);
	return true;
}