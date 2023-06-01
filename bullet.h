#pragma once
#include "gameobject.h"
#include <QPoint>

class bullet: public GameObject{
   int bulletSpeed;
   int bulletDamage;
   QPointF direction;
public:
   bullet();
   void setSpeed(int speed);
   int getSpeed() const;
   void setDirection(const QPointF& direction_);
   void setDamage(const int dmg);
   QPointF getDirection() const;
   int getDamage() const;
   void move();
   void move(const QPointF& direction);
};


