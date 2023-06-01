#include "circle.h"
#include <QPainter>

circle::circle(){
    radius = 0;
    setSpeed(0);
    setPosition({0,0});
}

void circle::setRadius(double radius_){
   radius = radius_;
}
double circle::getRadius() const{
   return radius;
}
void circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->scale(1,1);
   auto* heart = new QPixmap(":source/sansBall.png");
   painter->drawPixmap( boundingRect().topLeft(), heart->scaled(radius*2,radius*2));
}

QRectF circle::boundingRect() const {
   return QRectF(-radius, -radius, radius*2, radius*2);
}
