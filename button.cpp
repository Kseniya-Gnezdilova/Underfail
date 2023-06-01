#include "button.h"
#include <QPainter>
#include <QGraphicsView>
#include <QPixmap>

Button::Button(){
    setPosition(50,600);
}

void Button::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->scale(1,1);
    auto* heart = new QPixmap(":source/heart.png");
    painter->drawPixmap( boundingRect().topLeft(), heart->scaled(20,20));
}
QRectF Button::boundingRect() const {
    return QRectF(-10, -10, 20, 20);
}


