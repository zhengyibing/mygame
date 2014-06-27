//
//  Test.cpp
//  MyGame
//
//  Created by 张国兵 on 14-6-20.
//
//

#include "Test.h"

USING_NS_CC;

Scene* TestScene::scene()
{
  Scene* scene = Scene::create();
  Layer* layer = TestScene::create();
  scene->addChild(layer);
  log("%f,%f",scene->getContentSize().width,scene->getContentSize().height);
  
  return scene;
}

bool TestScene::init()
{
  if (!LayerColor::initWithColor(Color4B(0xff,0xff,0xff,128))) {
    return false;
  }
  testScale();
  return true;
}

void TestScene::onEnterTransitionDidFinish()
{
  log("anchorpoint:x%f,point:y%f",this->getAnchorPoint().x,this->getAnchorPoint().y);
  log("positonpoint:x%f,point:y%f",this->getPosition().x,this->getPosition().y);
  Point p = Director::getInstance()->getRunningScene()->getAnchorPoint();
}

void TestScene::testScale()
{
  Size originSize = Director::getInstance()->getVisibleSize();
  Point originPoint  = Director::getInstance()->getVisibleOrigin();
  
  CCLOG("contentScaleFactor:%f",originPoint.x);
//  this->setPosition(50,50);
  this->setAnchorPoint(Point(0 ,0));
  this->setScale(0.5);
  Sprite* bg = Sprite::create("img/grade.png");
  if (bg) {
//    bg->setScale(3);
//    bg->setContentSize(originSize);
    bg->setAnchorPoint(Point(0,0));
    bg->setPosition(Point(this->getContentSize().width/2,0));
    CCLOG("width:%f,height:%f",this->getContentSize().width,this->getContentSize().height);
    Sprite* base = Sprite::create("img/base.png");
//    this->addChild(base,1);
    base->setAnchorPoint(Point(0.5,0.5));
    base->setPosition(base->getContentSize().width/2, base->getContentSize().height/2);
//    base->setScale(0.5);
//    base->setScale(0);
//    bg->addChild(base);
    this->addChild(base);
  }
  
  LayerColor* layer1 = LayerColor::create(Color4B(0x4444,0x4444,0x4444,200));
  this->addChild(layer1);
  layer1->setAnchorPoint(Point(1, 1));
  log("colorwidth:%f",layer1->getContentSize().width);
}

