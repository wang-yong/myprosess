//
//  GameScene.h
//  2048
//
//  Created by ZeroYang on 5/7/14.
//
//

#ifndef ___048__GameScene__
#define ___048__GameScene__

#include "cocos2d.h"

class CardSprite;
class SimpleRecognizer;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    CREATE_FUNC(GameScene);
    ~GameScene();
    

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    
    //virtual void onEnter() override;
    
private:
    
    void createCardSprite(cocos2d::Size size);
    void createCardNumber(bool animation = true);
    void newNumber(int i, int j, int num);
    void setScore(int score);
    void doCheck();
    bool shouldCreateCardNumber();

    bool isWin();
    void removeSuccessLayer();
    
    void saveStatus();
    void resumeStatus();
    
    void onPause(Ref* pSender);

    
    cocos2d::Point getPosition(int i, int j);
    
    bool doLeft();
    bool doRight();
    bool doUp();
    bool doDown();

private:

    static const int cellSize = 0;
    static const int cellSpace = 125;
    int score;
    cocos2d::Label *cardNumberTTF;
    
    CardSprite *cardArr[4][4];

    SimpleRecognizer *recognizer;
    
    cocos2d::LayerColor *successLayer;
};

#endif /* defined(___048__GameScene__) */
