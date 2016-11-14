#include "HelloWorldScene.h"
#include "GameOverScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene(int num)
{
	// 'scene' is an autorelease object
	//auto scene = Scene::create();
	auto scene = Scene::createWithPhysics();//引用物理引擎
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);//显示调试信息
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));//增加一个重力加速度	

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create(num);
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


// on "init" you need to initialize your instance
bool HelloWorld::init(int personNum)
{
	//////////////////////////////
	// 1. super init first
	//if (!Layer::init())
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	if (personNum > 0) {
		for (int i = 0;i < personNum;i++) {
			//控制器
			gcs.insert(0, GameController::create(this, i*400,personNum));//1280
		}
	}
	

	
	//gcs.insert(0, GameController::create(this, 250));

	//循环执行动作：	
	scheduleUpdate();

	//添加监听器：
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact & contact) {
		//log(">>>>>");
		//停止更新:
		this->unscheduleUpdate();

		Director::getInstance()->replaceScene(GameOver::createScene());

		return true;
	};
	//绑定监听器1：
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, this);
	
	//交互：
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this, personNum](Touch * t, Event * e) {

		for (auto it = gcs.begin(); it != gcs.end(); it++) {
			int index = 0;
			if ((*it)->hitTestPoint(t->getLocation(),index+1, personNum)) {
				(*it)->onUserTouch(index+1);
				break;
			}
		}

		return false;
	};
	//绑定监听器2：
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

void HelloWorld::update(float dt) {
	//遍历所有的GameController
	for (auto it = gcs.begin();it != gcs.end();it++) {
		(*it)->onUpdate(dt);
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


HelloWorld * HelloWorld::create(int n)
{
	auto _ins = new HelloWorld();
	_ins->init(n);
	_ins->autorelease();
	return _ins;
}


