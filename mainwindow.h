#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "inventory.h"
#include "model.h"
#include "hpbar.h"
#include <dialog.h>

class MainWindow : public QGraphicsScene {
public:
   explicit MainWindow();
protected:
   void gameMusic();
   void keyPressEvent(QKeyEvent *event) override;
   void keyReleaseEvent(QKeyEvent *event) override;
   void uploadAttack();
   void eventAttack();
   void cycleButton();
   void Event();
   void Attack();
   void Talk();
   void Item();
   void Quit();
   void attack1();
   void attack2();
   void attack3();
   void attack4();
   void attack5();
   void clearInventory();
   void soundMove();
   void soundHeal();
   void soundDamage();
   int flag;
   QTimer* GameTimer;

   Dialog* dialog;
   QGraphicsPixmapItem* dialog_;
   Model* model;
   hpBar* hpEnemy;
   Inventory* inventory;
   std::vector<int> inventory_;
   std::vector<QGraphicsPixmapItem*> inventoryPixmap;
};
