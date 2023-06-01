#pragma once
#include "gameobject.h"
#include <QWidget>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsView>

class Enemy: public GameObject {
protected:
    int enemyHealth;
public:
    void setHealth(const int health);
    int getHealth() const;
    Enemy();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};


