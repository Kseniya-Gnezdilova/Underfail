#pragma once
#include <QGraphicsItem>
class Dialog:  public QGraphicsItem{
    int num;
    std::vector<QPixmap*> dialogs;
public:
    Dialog();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void setNum(const int num_);
    int getNum() const;
    QPixmap getDialog() const;
};

