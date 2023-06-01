#include "stick.h"
#include <QPainter>

stick::stick(){
   height = 0;
   width = 0;
   setSpeed(0);
   setPosition({0,0});
   setDamage(0);
}

void stick::setStick(double height_, double width_){
   height = height_;
   width = width_;
}
double stick::getHeight() const{
   return height;
}
double stick::getWidth() const{
   return width;
}
void stick::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
     if (width >= height){
       painter->scale(1,1);
       auto* bone = new QPixmap(":source/sansBone.png");
       painter->drawPixmap( boundingRect().topLeft(), bone->scaled(width,height));
    }
     else{
       painter->scale(1,1);
       auto* bone = new QPixmap(":source/sansBone.png");
       painter->drawPixmap( boundingRect().topLeft(), bone->transformed(QTransform().rotate(90)).scaled(width, height));
     }
}

QRectF stick::boundingRect() const {
   return QRectF(-width/2, -height/2, width, height);
}
