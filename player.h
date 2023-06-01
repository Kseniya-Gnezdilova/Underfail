#pragma once
#include "gameobject.h"
#include <vector>
#include <QWidget>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPoint>
#include <QGraphicsView>

class Player : public GameObject {
protected:
   int playerHealth;
   int playerDamage;
   int playerSpeed;
   std::vector<int> inventory;
   QPointF playerDirection;
 public:
   void setHealth(const int health);
   int getHealth() const;
   void setDirection(const QPointF& direction);
   const QPointF& getDirection() const;
   void setDamage(const int dmg);
   int getDamage() const;
   void setSpeed(const int spd);
   int getSpeed() const;
   void move(const QPointF& direction);
   Player();
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
   QRectF boundingRect() const override;
};


