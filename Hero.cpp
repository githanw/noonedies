#include "Hero.h"
#include "FlashTool.h"


bool Hero::init() {
	Sprite::init();

	//人物尺寸：
	Size s = Size(44, 52);
	setContentSize(s);
	auto box = PhysicsBody::createBox(getContentSize());   //设置body的边界宽度  
	setAnchorPoint(Point(0,0));
	setPhysicsBody(box);          //让一个精灵具有物理属性 
	//设置动画
	runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));//json数据和动画的频率
	//设置物理


	getPhysicsBody()->setRotationEnable(false);//设置：不旋转的
	getPhysicsBody()->setContactTestBitmask(1);//开启测试碰撞

	return true;
}