#include "player.h"
#include <QPainter>
Player::Player(){
   playerHealth = 1000;
   playerSpeed = 5;
   playerDamage = 0;
   //setHitBox({0,0},{30,30});
   setPosition({0,0});
   setDirection({0, 0});
}
void Player::setHealth(const int health){
   playerHealth = std::min(1000,health);
}
int Player::getHealth() const{
   return playerHealth;
}
void Player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
   painter->scale(1,1);
   auto* heart = new QPixmap(":source/heart.png");
   painter->drawPixmap( boundingRect().topLeft(), heart->scaled(20,20));
}

QRectF Player::boundingRect() const {
   return QRectF(-10, -10, 20, 20);
}

void Player::setDirection(const QPointF& direction){
   playerDirection = direction;
}
const QPointF& Player:: getDirection() const{
   return playerDirection;
}
void Player::setDamage(const int dmg){
   playerDamage = dmg;
}
int Player::getDamage() const{
   return playerDamage;
}
void Player::setSpeed(const int spd){
   playerSpeed = spd;
}
int Player::getSpeed() const{
   return playerSpeed;
}
void Player::move(const QPointF& direction){
   double length = sqrt(pow(direction.x(),2) + pow(direction.y(),2));
   if (length == 0)
      return;
   setPosition({std::max(std::min(pos_.x() + playerSpeed * direction.x() / length, 690.),110.), std::max(std::min(pos_.y() + playerSpeed * direction.y() / length, 690.),110.)});
}
