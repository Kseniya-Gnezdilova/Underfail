#include "dialog.h"
#include <QPainter>

Dialog::Dialog(){
    num = 0;
    dialogs.push_back(new QPixmap(":source/dialog1.png"));
    dialogs.push_back(new QPixmap(":source/dialog2.png"));
    dialogs.push_back(new QPixmap(":source/dialog3.png"));
    dialogs.push_back(new QPixmap(":source/dialog4.png"));
    dialogs.push_back(new QPixmap(":source/dialog5.png"));
    dialogs.push_back(new QPixmap(":source/dialog6.png"));
    dialogs.push_back(new QPixmap(":source/dialog0.png"));


}

void Dialog::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->scale(1,1);
    painter->drawPixmap( boundingRect().topLeft(), dialogs[num]->scaled(575,150));
}

QRectF Dialog::boundingRect() const {
    return QRectF(225, 325, 575, 150);
}

QPixmap Dialog::getDialog() const{
    return *dialogs[num];
}
void Dialog::setNum(const int num_){
    num = std::min((unsigned long long)num_, dialogs.size() - 1);
}
int Dialog::getNum() const {
    return num;
}
