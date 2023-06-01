#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class GameObject  : public QGraphicsItem{
protected:
   explicit GameObject(const QPointF& pos);
   QPointF pos_;
public:
   GameObject();
   void setPosition(double x, double y);
   void setPosition(const QPointF& pos);
   const QPointF& getPosition() const;
};


