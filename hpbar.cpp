#include "hpbar.h"

void hpBar::setPosition(const QPointF pos_){
    pos = pos_;
}
QPointF hpBar::getPosition() const{
    return pos;
}
void hpBar::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (player!=nullptr) {
        painter->setPen(QPen(QColorConstants::Svg::orange, 2));
        painter->setBrush(Qt::black);
        painter->drawRect(boundingRect());
        painter->setBrush(QColorConstants::Svg::orange);
        painter->drawRect(getPosition().x(), getPosition().y(), boundingRect().width() * player->getHealth() / 1000.,boundingRect().height());
    }
    else{
        painter->setPen(Qt::green);
        painter->setBrush(Qt::black);
        painter->drawRect(boundingRect());
        painter->setBrush(Qt::green);
        painter->drawRect(getPosition().x(), getPosition().y(), boundingRect().width() * enemy->getHealth() / 1000.,boundingRect().height());
    }

}

QRectF hpBar::boundingRect() const {
    return QRectF(getPosition().x(), getPosition().y(), 200, 40);
}

