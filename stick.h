#pragma once
#include "bullet.h"

class stick: public bullet{
    double height;
    double width;
public:
   stick();
   void setStick(const double height_, const double width_);
   double getHeight() const;
   double getWidth() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
   QRectF boundingRect() const override;
};


