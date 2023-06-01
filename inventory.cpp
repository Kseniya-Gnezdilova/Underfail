#include "inventory.h"
#include <vector>

Inventory::Inventory(){
    num  = 0;
    inventory = {1,2,3,4,4,4,4};
}

void Inventory::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (inventory[num] == 1){
        painter->scale(1,1);
        painter->drawPixmap( boundingRect().topLeft(), (new QPixmap(":source/inventory1.png"))->scaled(100,50));
    }
    if (inventory[num] == 2){
        painter->scale(1,1);
        painter->drawPixmap( boundingRect().topLeft(), (new QPixmap(":source/inventory2.png"))->scaled(100,50));
    }
    if (inventory[num] == 3){
        painter->scale(1,1);
        painter->drawPixmap( boundingRect().topLeft(), (new QPixmap(":source/inventory3.png"))->scaled(100,50));
    }
    if (inventory[num] == 4){
        painter->scale(1,1);
        painter->drawPixmap( boundingRect().topLeft(), (new QPixmap(":source/inventory4.png"))->scaled(100,50));
    }
}

QRectF Inventory::boundingRect() const {
    return QRect(getPosition().x() - 50, getPosition().y() - 25, 100, 50);
}

QPixmap Inventory::getInventoryItem() const{
    if (inventory[num] == 1){
        return *new QPixmap(":source/inventory1.png");
    }
    if (inventory[num] == 2){
        return *new QPixmap(":source/inventory2.png");
    }
    if (inventory[num] == 3){
         return *new QPixmap(":source/inventory3.png");
    }
    if (inventory[num] == 4){
         return *new QPixmap(":source/inventory4.png");
    }
}
int Inventory::getKey() const{
    return inventory[num];
}
int Inventory::getHeal(int num_) const{
    if (inventory[num_] == 1 ){
        return 900;
    }
    if (inventory[num_] == 2 ){
        return 600;
    }
    if (inventory[num_] == 3){
        return 850;
    }
    if (inventory[num_] == 4){
        return 300;
    }
}
void Inventory::setNum(const int num_){
    num = (int)std::min((unsigned long long)num_, inventory.size());
}
int Inventory::getNum() const {
    return num;
}

int Inventory::getSize() const{
    return inventory.size();
}

void Inventory::removeItem(int num_){
    for(std::vector<int> ::iterator it = inventory.begin(); it!=inventory.end();){
        if (*it == num_){
            inventory.erase(it);
        }
        it++;
    }
}
