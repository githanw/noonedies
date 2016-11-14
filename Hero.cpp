#include "Hero.h"
#include "FlashTool.h"


bool Hero::init() {
	Sprite::init();

	//����ߴ磺
	Size s = Size(44, 52);
	setContentSize(s);
	auto box = PhysicsBody::createBox(getContentSize());   //����body�ı߽���  
	setAnchorPoint(Point(0,0));
	setPhysicsBody(box);          //��һ����������������� 
	//���ö���
	runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));//json���ݺͶ�����Ƶ��
	//��������


	getPhysicsBody()->setRotationEnable(false);//���ã�����ת��
	getPhysicsBody()->setContactTestBitmask(1);//����������ײ

	return true;
}