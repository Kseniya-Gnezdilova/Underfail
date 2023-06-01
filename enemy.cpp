
#include "enemy.h"
#include <QPainter>

Enemy::Enemy(){
    enemyHealth = 1000;
}
void Enemy::setHealth(const int health){
    enemyHealth = health;
}
int Enemy::getHealth() const{
    return enemyHealth;
}
void Enemy::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->scale(1,1);
    auto* heart = new QPixmap(":source/sansStatic.png");
    painter->drawPixmap( boundingRect().topLeft(), heart->scaled(150,200));
}

QRectF Enemy::boundingRect() const {
    return QRectF(325, 0, 150, 200 );
}

