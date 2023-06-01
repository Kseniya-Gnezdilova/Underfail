#include "model.h"
#include <QLabel>

Model::Model() : player(new Player()), button(new Button()), enemy(new Enemy()), slider(new Slider()){
}
void Model::vecPushBack(bullet* bullet_){
   bullets.push_back(bullet_);
}
void Model::setNum(const int num){
   numAttack = num;
}
int Model::getNum() const{
   return numAttack;
}
void Model::vecDelete(){
   while (!bullets.empty()){
       auto bullet = bullets.back();
       delete(bullet);
       bullets.pop_back();
   }
}
void Model::scenePushBack(QGraphicsItem* item){
   sceneItems.push_back(item);
}
void Model::sceneDelete(){
   while (!sceneItems.empty()){
       auto item = sceneItems.back();
       delete(item);
       sceneItems.pop_back();
   }
}

 void Model::updateModel() {
   slider->move(slider->getDirection());
   player -> move(player->getDirection());
   for (auto* bullet_: bullets){
      if (player->collidesWithItem(bullet_)) {
          player->setHealth(player->getHealth() - bullet_->getDamage());
      }
      bullet_-> move();
      if (bullet_->getPosition().x() < 0 || bullet_->getPosition().x() > 800 || bullet_->getPosition().y() < 0 || bullet_->getPosition().y() > 800){
          auto comp = std::remove_if(bullets.begin(),bullets.end(),[bullet_](auto* bullet){return bullet == bullet_;});
          bullets.erase(comp, bullets.end());
          delete(bullet_);
      }

   }
}


