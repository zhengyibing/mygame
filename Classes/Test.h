//
//  Test.h
//  MyGame
//
//  Created by 张国兵 on 14-6-20.
//
//

#ifndef __MyGame__Test__
#define __MyGame__Test__

#include <iostream>
#include "cocos2d.h"
class TestScene : public cocos2d::LayerColor
{
public:
  static cocos2d::Scene* scene();
  bool init();
  CREATE_FUNC(TestScene);
  //test whether scaleFactor affect 
  void testScale();
  void onEnterTransitionDidFinish();
};

#endif /* defined(__MyGame__Test__) */
