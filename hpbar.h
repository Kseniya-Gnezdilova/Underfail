#pragma once
#include <QGraphicsItem>
#include "player.h"
#include "enemy.h"
#include <QPointF>

class hpBar: public QGraphicsItem{
    QPointF pos;
    Player* player;
    Enemy* enemy;
public:
    void setPosition(const QPointF pos_);
    QPointF getPosition() const;
    explicit hpBar(Player* player_): player(player_){};
    explicit hpBar(Enemy* enemy_ ): player(nullptr),enemy(enemy_){};

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

};
