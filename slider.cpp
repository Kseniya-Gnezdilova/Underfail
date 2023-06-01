#include "slider.h"

Slider::Slider(){
    sliderSpeed = 10;
    setPosition(200,400);
    setDirection({800,400});
}

void Slider::setDirection(const QPointF& direction){
   sliderDirection = direction - getPosition();
}
const QPointF& Slider::getDirection() const{
    return sliderDirection;
}
void Slider::move(const QPointF& direction){
    double length = sqrt(pow(direction.x(),2) + pow(direction.y(),2));
    if (length == 0)
        return;

    if (getPosition().x() >= 800)
        setDirection({0,400});
    if (getPosition().x() <= 0)
        setDirection({800,400});
    setPosition(pos_.x() + sliderSpeed * direction.x() / length, pos_.y() + sliderSpeed * direction.y() / length);
}
void Slider::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen(Qt::white);
    painter->setBrush(Qt::white);
    painter->drawRect( boundingRect());
}

QRectF Slider::boundingRect() const {
    return QRectF(-10, -100, 20, 200);
}
