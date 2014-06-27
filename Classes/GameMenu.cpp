//
//  GameMenu.cpp
//  MyGame
//
//  Created by 张国兵 on 14-6-3.
//
//

#include "GameMenu.h"

USING_NS_CC;
using namespace std;
Scene* GameMenu::scene()
{
  Scene* scene = Scene::create();
  auto layer = GameMenu::create();
  scene->addChild(layer);
  return scene;
}

bool GameMenu::init()
{
  Size originSize = Director::getInstance()->getVisibleSize();
  Point originPoint = Director::getInstance()->getVisibleOrigin();
  Size winSize = Director::getInstance()->getWinSize();
  if(!Layer::init())
  {
    return false;
  }
  
  Sprite* bg = Sprite::create("img/bg.png");
  bg->setAnchorPoint(Point(0,0));
  bg->setPosition(originPoint.x,originPoint.y+10);
//  bg->setScale(0.5);
  this->addChild(bg);
  
  LayerColor* content = LayerColor::create(Color4B(255,255,255,0));
  this->addChild(content);
//  content->setPosition(originSize.width/2,originSize.height/2);
//  content->setContentSize(Size(originSize.width/2,originSize.height/2));
  
  
  Sprite* fbTitle = Sprite::create("img/flappybird.png");
  fbTitle->setPosition(originSize.width/2,originSize.height/4*3);
  content->addChild(fbTitle);
  Sprite* bird = Sprite::create("img/bird1.png");
  bird->setPosition(originSize.width/2+85,originSize.height/2+100);
  content->addChild(bird);
  
//  vect<Animation*> *animations = new vect<Animation*>();
//  animations->add
  Animation* flyAnimation = Animation::create();
  for (int i = 1; i<=3; i++) {
    char frameName[100] = {0};
    sprintf(frameName, "img/bird%d.png",i);
    flyAnimation->addSpriteFrameWithFile(frameName);
  }
  flyAnimation->setDelayPerUnit(0.2f);
  flyAnimation->setRestoreOriginalFrame(false);
  Animate* flayAnimate = Animate::create(flyAnimation);
  MoveBy* updownAct = MoveBy::create(0.3, Point(0,5));
  MoveBy* updownRev = updownAct->reverse();
  Sequence* updown = Sequence::create(updownAct,updownRev ,NULL);
  auto repeat = RepeatForever::create(Spawn::create(updown,flayAnimate,NULL));
  bird->runAction(repeat);
  
  Sprite* rate = Sprite::create("img/rate.png");
  rate->setPosition(bird->getPosition()-(fbTitle->getPosition()-bird->getPosition()));
  content->addChild(rate);
  
  Sprite* grade = Sprite::create("img/grade.png");
  content->addChild(grade);
  
  Sprite* start = Sprite::create("img/start.png");
  content->addChild(start);
  printf("content width:%f  height:%f",bg->getContentSize().width,bg->getContentSize().height);
  printf("framesize width:%f  height:%f",Director::getInstance()->getOpenGLView()->getFrameSize().width,Director::getInstance()->getOpenGLView()->getFrameSize().height);
  printf("winsize width:%f  height:%f",Director::getInstance()->getWinSize().width,Director::getInstance()->getWinSize().height);
  printf("visible width:%f  height:%f",originSize.width,originSize.height);
  printf("scaleFactor,%f",Director::getInstance()->getContentScaleFactor());
  
  return true;
}

void GameMenu::menuCallback(Ref sender)
{
  
}
