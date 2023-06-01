#pragma once
#include "player.h"
#include "enemy.h"
#include <vector>
#include "bullet.h"
#include "button.h"
#include "slider.h"

class Model {
public:
   Model();
   Player *player;
   Button *button;
   Enemy* enemy;
   std::vector<bullet*> bullets;
   Slider* slider;
   void vecPushBack(bullet* bullet_);
   std::vector <QGraphicsItem*> sceneItems;
   void scenePushBack(QGraphicsItem* item);
   void sceneDelete();
   void vecDelete();
   void updateModel();
   bool intersection(QRectF first, QRectF second);
   int numAttack;
   void setNum(const int num);
   int getNum() const;
};


