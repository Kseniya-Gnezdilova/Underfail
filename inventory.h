#pragma once
#include "gameobject.h"
#include <vector>

class Inventory: public GameObject{
    int num;
    std::vector <int> inventory;
public:
    Inventory();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    int getHeal(int num_) const;
    void setNum(const int num_);
    int getNum() const;
    QPixmap getInventoryItem() const;
    int getKey() const;
    int getSize() const;
    void removeItem(int num_);
};

