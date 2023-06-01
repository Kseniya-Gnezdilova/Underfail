#include "bullet.h"

bullet::bullet(){
   bulletSpeed = 8;
   bulletDamage = 2;
}

void bullet::setSpeed(int speed){
   bulletSpeed = speed;
}
int bullet::getSpeed() const{
   return bulletSpeed;
}
void bullet::setDirection(const QPointF& direction_){
   direction = direction_ - getPosition();
}
QPointF bullet::getDirection() const{
   return direction;
}
int bullet::getDamage() const{
   return bulletDamage;
}
void bullet::move(){
   move(getDirection());
}
void bullet::move(const QPointF& direction){
   double length = sqrt(pow(direction.x(),2) + pow(direction.y(),2));
   if (length == 0)
       return;
   setPosition({pos_.x() + getSpeed() * direction.x() / length, pos_.y() + getSpeed() * direction.y() / length});
}

void bullet::setDamage(const int dmg){
   bulletDamage = dmg;
}
