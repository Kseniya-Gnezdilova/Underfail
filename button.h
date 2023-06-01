#pragma once
#include "gameobject.h"
#include <QMainWindow>
#include <QGraphicsScene>

class Button: public GameObject{
public:
    Button();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

