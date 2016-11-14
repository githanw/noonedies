//
//  GameController.cpp
//  NoOneDies
//
//  Created by plter on 14-6-3.
//
//

#include "GameController.h"


GameController* GameController::create(cocos2d::Layer *layer, float positionY,int num){
    
    auto _ins = new GameController();
    _ins->init(layer, positionY,num);
    _ins->autorelease();
    return _ins;
}


bool GameController::init(cocos2d::Layer *layer, float positionY,int num){
    
    _layer = layer;
    _positionY = positionY;
    
    visibleSize = Director::getInstance()->getVisibleSize();

	if (num ==1 && positionY == float(0)) {//one person
		//add edge边界框
		edge = Edge::create();
		edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
		//edge->setAnchorPoint(Point(0.5, 0.5));
		edge->setContentSize(visibleSize);
		layer->addChild(edge);

		//add ground地板
		auto ground = Sprite::create();
		ground->setColor(Color3B(0, 0, 0));
		ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
		ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
		layer->addChild(ground);

		//add hero角色
		hero = Hero::create();
		hero->setPosition(50, hero->getContentSize().height / 2 + positionY);
		layer->addChild(hero);
	}
	else if (num == 2) {//two persons
		if (positionY == float(0)) {
			//add edge边界框
			edge = Edge::create();
			edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
			edge->setContentSize(visibleSize);

			layer->addChild(edge);
			//add ground地板
			auto ground = Sprite::create();
			ground->setColor(Color3B(0, 0, 0));
			ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
			ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
			layer->addChild(ground);

			//add hero角色
			hero = Hero::create();
			hero->setPosition(50, hero->getContentSize().height / 2 + positionY);
			layer->addChild(hero);
			
		}
		else {
			//add edge边界框
			edge = Edge::create();
			edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
			edge->setContentSize(visibleSize);

			layer->addChild(edge);
			//add ground地板
			auto ground = Sprite::create();
			ground->setColor(Color3B(0, 0, 0));
			ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
			ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
			layer->addChild(ground);

			//add hero角色
			hero2 = Hero::create();
			hero2->setPosition(50, hero2->getContentSize().height / 2 + positionY);
			layer->addChild(hero2);
		}
		
	}
	else if (num == 3) {//three persons
		if (positionY == float(0)) {
			//add edge边界框
			edge = Edge::create();
			edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
			edge->setContentSize(visibleSize);

			layer->addChild(edge);
			//add ground地板
			auto ground = Sprite::create();
			ground->setColor(Color3B(0, 0, 0));
			ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
			ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
			layer->addChild(ground);

			//add hero角色
			hero = Hero::create();
			hero->setPosition(50, hero->getContentSize().height / 2 + positionY);
			layer->addChild(hero);
		}
		else if(positionY == float(400)){
			//add edge边界框
			edge = Edge::create();
			edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
			edge->setContentSize(visibleSize);
			layer->addChild(edge);
			//add ground地板
			auto ground = Sprite::create();
			ground->setColor(Color3B(0, 0, 0));
			ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
			ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
			layer->addChild(ground);

			//add hero角色
			hero2 = Hero::create();
			hero2->setPosition(50, hero2->getContentSize().height / 2 + positionY);
			layer->addChild(hero2);
		}
		else{
			//add edge边界框
			edge = Edge::create();
			edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
			edge->setContentSize(visibleSize);
			layer->addChild(edge);
			//add ground地板
			auto ground = Sprite::create();
			ground->setColor(Color3B(0, 0, 0));
			ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
			ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
			layer->addChild(ground);

			//add hero角色
			hero3 = Hero::create();
			hero3->setPosition(50, hero3->getContentSize().height / 2 + positionY);
			layer->addChild(hero3);
		}
	} 
    


  
    
    resetFrames();
    return true;
}

void GameController::resetFrames(){
    currentFrameIndex = 0;
    nextFrameCount = (rand()%120) + 100;
}


void GameController::addBlock(){
    auto b = Block::create();
    _layer->addChild(b);
    b->setPositionY(b->getContentSize().height/2+_positionY);
}


void GameController::onUpdate(float dt){
    currentFrameIndex++;
    
    if (currentFrameIndex>=nextFrameCount) {
        resetFrames();
        
        addBlock();
    }
}

bool GameController::hitTestPoint(cocos2d::Vec2 point,int index,int total){
	//log("index=%f,%f,%f",index, point.x, point.y);
	//add edge边界框
	if (total == 1) {
		if (index == 1) {
			if (edge->getBoundingBox().getMaxY() > point.y && edge->getBoundingBox().getMinY()<point.y) {
				return true;
			}
		}
	}
	else if (total > 1) {
		if (index == 1) {
			if (point.y >0 && point.y<400) {
				return true;
			}
		}
		else if (index == 2) {
			/*if (edge2->getBoundingBox().getMaxY() > point.y && edge2->getBoundingBox().getMinY()<point.y) {
			return true;
			}*/
			if (point.y >400 && point.y < 800) {
				return true;
			}
		}
		else if (index == 3) {
			if (point.y >800) {
				return true;
			}
		}
		else {
			return false;
		}
	}
	
	
	//return edge->getBoundingBox().containsPoint(point);

    
}

void GameController::onUserTouch(int person){
	//log("============");
	
	if (person == 1) {
		hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
	}
	else if (person == 2) {
		hero2->getPhysicsBody()->setVelocity(Vec2(401, 800));
	}
	else if (person == 3) {
		hero3->getPhysicsBody()->setVelocity(Vec2(801, 1200));
	}	
	
    
}
