//
//  GameOverScene.h
//  NoOneDies
//
//  Created by plter on 14-6-4.
//
//

#include <cocos2d.h>

using namespace cocos2d;

class GameOver:public LayerColor {
    
private:
    Size visibleSize;
	Label *label_restart;
    
public:
    virtual bool init();

	virtual bool restart();
    
    CREATE_FUNC(GameOver);
    
	static Scene* createScene();
};