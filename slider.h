#pragma once
#include "gameobject.h"
class Slider: public GameObject{
    int sliderSpeed;
    QPointF sliderDirection;
public:
    Slider();
    void setDirection(const QPointF& direction);
    const QPointF& getDirection() const;
    void move(const QPointF& direction);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};


