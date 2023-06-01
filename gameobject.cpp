#include "GameObject.h"
#include <QPainter>
void GameObject::setPosition(double x, double y) {
    pos_.setX(x);
    pos_.setY(y);
    setPos(x, y);
}

void GameObject::setPosition(const QPointF& pos) {
    pos_ = pos;
    setPos(pos);
}

const QPointF& GameObject::getPosition() const {
    return pos_;
}

GameObject::GameObject() : pos_() { }

GameObject::GameObject(const QPointF& pos) : pos_(pos) {
    setPos(pos);
}


