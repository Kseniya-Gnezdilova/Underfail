#pragma once
#include "bullet.h"

class circle: public bullet{
    double radius;
public:
   void setRadius(const double radius_);
   double getRadius() const;
   circle();
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
   QRectF boundingRect() const override;
};

