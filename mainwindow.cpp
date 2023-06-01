#include "mainwindow.h"
#include <QKeyEvent>
#include <QTimer>
#include "stick.h"
#include "circle.h"
#include <QRectF>
#include<QPainter>
#include<QPixmap>
#include <stdlib.h>
#include <hpbar.h>
#include <QPixmap>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>

void MainWindow::gameMusic(){
    auto* player = new QMediaPlayer(this);
    player->setAudioOutput(new QAudioOutput(this));
    player->setSource(QUrl::fromLocalFile(QString("qrc:source/sound.mp3")));
    player->setLoops(QMediaPlayer::Infinite);
    player->play();
}
MainWindow::MainWindow(): QGraphicsScene() {
   gameMusic();
   inventory = new Inventory();
   dialog = new Dialog();
   model = new Model();
   model->player->setDamage(80);
   hpEnemy = new hpBar(model->enemy);
   auto* background = new QGraphicsPixmapItem(*new QPixmap(":source/background.png"));
   background->setPos({-400,-200});
   addItem(background);
   GameTimer = new QTimer(this);
       connect(GameTimer, &QTimer::timeout, [this]() {
       update();
           model->updateModel();
           if (model->player->getHealth() <= 0) {
                  views().front() -> close();
           }
           if (model->enemy->getHealth() <=0 ){
                  views().front() -> close();
           }
       });
   eventAttack();
   auto* hpbar = new hpBar(model->player);
   hpbar->setPosition({300,730});

   addItem(hpbar);
   GameTimer->start(16);
}

void MainWindow::eventAttack(){
   model->sceneDelete();
   flag = 1;
   if (model->player->getPosition().x()!=0 && model->player->getPosition().y() != 0)
    removeItem(model->player);
   hpEnemy->setPosition({300,220});
   addItem(hpEnemy);
   model->vecDelete();
   model->button = new Button();
   addItem(model->button);
   auto* dialog = addRect(0,300,800,200, QPen(Qt::white));
   model->scenePushBack(dialog);
   auto* boss = new Enemy();
   addItem(boss);
   model->scenePushBack(boss);
   auto* fight = new QGraphicsPixmapItem(*new QPixmap(":source/fight.png"));
   fight->setPos(100 - 75 ,600 - 25);
   addItem(fight);
   model->scenePushBack(fight);
   auto* act = new QGraphicsPixmapItem(*new QPixmap(":source/act.png"));
   act->setPos(300 - 75 ,600 - 25);
   addItem(act);
   model->scenePushBack(act);
   auto* item = new QGraphicsPixmapItem(*new QPixmap(":source/item.png"));
   item->setPos(500 - 75 ,600 - 25);
   addItem(item);
   model->scenePushBack(item);
   auto* mercy = new QGraphicsPixmapItem(*new QPixmap(":source/mercy.png"));
   mercy->setPos(700 - 75 ,600 - 25);
   addItem(mercy);
   model->scenePushBack(mercy);
}
void MainWindow::uploadAttack(){
   model->sceneDelete();
   auto* fightArea = addRect(100,100,600,600, QPen(Qt::white, 4));
   model->scenePushBack(fightArea);
   flag = 2;
   removeItem(model->button);
   removeItem(hpEnemy);
   model->vecDelete();
   model->player->setPosition({400,400});
   addItem(model->player);


   srand(time(NULL));
   int rnd = rand() % 5 + 1;
   if (rnd == 1) attack1();
   if (rnd == 2) attack2();
   if (rnd == 3) attack3();
   if (rnd == 4) attack4();
   if (rnd == 5) attack5();
   //if (rnd == 6) attack6();
   //if (rnd == 7) attack7();
   //if (rnd == 8) attack8();
   //if (rnd == 9) attack9();
   //if (rnd == 10) attack10();

}
void MainWindow::attack1(){
    model->setNum(15);
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer]() {
        for (double angle = model->getNum()*10; angle < 360 + model->getNum() * 10 && model->getNum() > 0; angle+=36){
            auto* circle_ = new circle();
            circle_->setRadius(10);
            circle_->setPosition({400 + 400*cos(angle*M_PI/180.), 400 + 400*sin(angle*M_PI/180.)});
            circle_->setDirection({400,400});
            circle_->setSpeed(4);
            addItem(circle_);
            model->vecPushBack(circle_);
        }
        model->setNum(model->getNum() - 1);
        if (model->getNum() == 0) {timer->stop(); model->vecDelete(); eventAttack();}
        });
    timer->start(800);
}

void MainWindow::attack2(){
    model->setNum(15);
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer]() {
        for (double split = 800; split > 0 && model->getNum() > 0; split-=70){
            auto* stick_ = new stick();
            stick_->setStick(10,100);
            stick_->setPosition({0,split});
            stick_->setDirection({800 + (double)model ->getNum()*40,split + model->getNum()*25});
            stick_->setSpeed(3);
            stick_->setDamage(3);
            addItem(stick_);
            model -> vecPushBack(stick_);
        }
        model->setNum(model->getNum() - 1);
        if (model->getNum() == 0){timer->stop(); model->vecDelete(); eventAttack();}
    });
    timer->start(800);
}

void MainWindow::attack3(){
    model->setNum(20);
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer](){
            auto* stickLeft = new stick();
            stickLeft->setStick(10,400);
            stickLeft->setPosition({200,0});
            stickLeft->setDirection({200,800});
            stickLeft->setSpeed(5);
            stickLeft->setDamage(3);
            addItem(stickLeft);
            model -> vecPushBack(stickLeft);
            auto* stickRigth = new stick();
            stickRigth->setStick(10,400);
            stickRigth->setPosition({600,800});
            stickRigth->setDirection({600,0});
            stickRigth->setSpeed(5);
            stickRigth->setDamage(3);
            addItem(stickRigth);
            model -> vecPushBack(stickRigth);
            model->setNum(model->getNum() - 1);
            if (model->getNum() == 0){timer->stop(); model->vecDelete(); eventAttack();}
    });
    timer->start(500);
}
void MainWindow::attack4(){
    model->setNum(15);
    srand(time(NULL));
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this,timer](){
        for (int num = 0; num < 10; num++){
            int rnd = (rand() % 20) * 30 + 115;
            auto* circle_ = new circle();
            circle_->setRadius(15);
            circle_->setPosition({(double)rnd,0});
            circle_->setDirection({(double)rnd,800});
            circle_->setSpeed(6);
            addItem(circle_);
            model->vecPushBack(circle_);
        }
        model->setNum(model->getNum() - 1);
         if (model->getNum() == 0){timer->stop(); model->vecDelete(); eventAttack();}
    });
    timer->start(900);
}
void MainWindow::attack5(){
    model->setNum(40);
    srand(time(NULL));
    auto* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timer]() {
        auto* stick_ = new stick();
        stick_->setStick(100,20);
        int rnd = (rand()%600) + 100;
        stick_->setPosition({(double)rnd, 0});
        stick_->setDirection(model->player->getPosition());
        stick_->setSpeed(5);
        stick_->setDamage(3);
        addItem(stick_);
        model->vecPushBack(stick_);
        model->setNum(model->getNum() - 1);
         if (model->getNum() == 0){timer->stop(); model->vecDelete(); eventAttack();}
    });
    timer->start(300);
}
void MainWindow::cycleButton(){
    if (model->button -> getPosition().x() >= 850)
       model->button->setPosition(50,model->button->getPosition().y());
    if (model->button -> getPosition().x() <= -150)
       model->button->setPosition(650, model->button->getPosition().y());
}
void MainWindow::Attack(){
    model->sceneDelete();
    removeItem(model->button);

    auto* dialog = addRect(0,300,800,200, QPen(Qt::white));
    model->scenePushBack(dialog);

    auto* boss = new Enemy();
    addItem(boss);
    model->scenePushBack(boss);

    auto* attackBar = new QGraphicsPixmapItem((new QPixmap(":source/attackBar.png"))->scaled(800,200));
    attackBar->setPos({0,300});
    addItem(attackBar);
    model->scenePushBack(attackBar);

    addItem(model->slider);
}
void MainWindow::Talk(){
    removeItem(model->button);
    auto* head = new QGraphicsPixmapItem((new QPixmap(":source/sansHead.png"))->scaled(200,150));
    head->setPos(0,325);
    addItem(head);
    model->scenePushBack(head);
    dialog_ = new QGraphicsPixmapItem(dialog->getDialog());
    dialog_->setPos(dialog->boundingRect().x(), dialog->boundingRect().y());
    addItem(dialog_);
    auto* player = new QMediaPlayer(this);
    player->setAudioOutput(new QAudioOutput(this));
    player->setSource(QUrl::fromLocalFile(QString("qrc:source/snd_txtsans.mp3")));
    player->setLoops(1);
    player->play();

}
void MainWindow::Item(){
     removeItem(model->button);
    if (inventory->getSize()  > 0){
        addItem(model->button);
        model->button->setZValue(2);
        model->button->setPosition(80,350);
    }
    inventory->setNum(0);
    for (int i = 1; i < 5; i++){
       if (inventory->getNum() < inventory->getSize()) {
           auto item = new QGraphicsPixmapItem(inventory->getInventoryItem());
           inventory_.push_back(inventory->getKey());
           inventory->setNum(inventory->getNum() + 1);
           if (i == 1) item->setPos(100,330);
           if (i == 2) item->setPos(500,340);
           if (i == 3) item->setPos(100,435);
           if (i == 4) item->setPos(500,435);
           addItem(item);
           inventoryPixmap.push_back(item);
       }
    }
}
void MainWindow::clearInventory(){
    while (!inventoryPixmap.empty()){
       auto item = inventoryPixmap.back();
       removeItem(item);
       inventoryPixmap.pop_back();
    }
    inventory_.clear();
}
void MainWindow::Quit(){
    removeItem(model->button);
    addItem(model->button);
    model->button->setZValue(2);
    model->button->setPosition(81,350);
    auto* run = new QGraphicsPixmapItem((new QPixmap(":source/run.png"))->scaled(150,40));
    run->setPos(100,330);
    addItem(run);
}
void MainWindow::Event(){
    auto [x,y] = model->button->getPosition();
    if (x == 50) Attack();
    if (x == 250) Talk();
    if (x == 450) Item();
    if (x == 650) Quit();
}

void MainWindow::soundMove(){
    auto* player = new QMediaPlayer(this);
    player->setAudioOutput(new QAudioOutput(this));
    player->setSource(QUrl::fromLocalFile(QString("qrc:source/snd_squeak.wav")));
    player->setLoops(1);
    player->play();
}
void MainWindow::soundHeal(){
    auto* player = new QMediaPlayer(this);
    player->setAudioOutput(new QAudioOutput(this));
    player->setSource(QUrl::fromLocalFile(QString("qrc:source/snd_heal_c.wav")));
    player->play();
}
void MainWindow::soundDamage(){
    auto* player = new QMediaPlayer(this);
    player->setAudioOutput(new QAudioOutput(this));
    player->setSource(QUrl::fromLocalFile(QString("qrc:source/snd_damage_c.wav")));
    player->play();
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
   QGraphicsScene::keyPressEvent(event);
   auto [x,y] = model->player -> getDirection();
   if (flag == 1){
        if (event->key() == Qt::Key_A) {
           model->button->setPosition(model->button->getPosition().x() - 200, model->button->getPosition().y());
           cycleButton();
           soundMove();
       } else if (event->key() == Qt::Key_D) {
           model->button->setPosition(model->button->getPosition().x() + 200, model->button->getPosition().y());
           cycleButton();
           soundMove();
       }
       if ((event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter) ){
           Event();
       }
   }
   if (flag == 2){
       if (event->key() == Qt::Key_W) {
             model->player -> setDirection({x,-1});
           } else if (event->key() == Qt::Key_A) {
             model->player -> setDirection({-1,y});
           } else if (event->key() == Qt::Key_S) {
             model->player -> setDirection({x,1});
           } else if (event->key() == Qt::Key_D) {
             model->player -> setDirection({1,y});
           }
   }
   if (flag == 4){
           if (event->key() == Qt::Key_W) {
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 450 && inventory->getSize()>=1){
                 model->button -> setPosition(80.,350.);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 350){
                 model->button -> setPosition(80.,350.);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 450 && inventory->getSize()>=2){
                 model->button -> setPosition(480.,350.);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480  && model->button->getPosition().y() == 350){
                 model->button -> setPosition(480.,350.);
                 soundMove();
             }
           } else if (event->key() == Qt::Key_A) {

             if (model->button->getPosition().x() == 80. && model->button->getPosition().y() == 450. && inventory->getSize() >= 4){
                 model->button -> setPosition(480.,450.);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 80. && model->button->getPosition().y() == 350. && inventory->getSize() >= 2){
                 model->button -> setPosition(480.,350.);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480. && model->button->getPosition().y() == 450.  && inventory->getSize() >= 3){
                 model->button -> setPosition(80.,450.);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480.  && model->button->getPosition().y() == 350.  && inventory->getSize() >= 1){
                 model->button -> setPosition(80., 350.);
                 soundMove();
             }
           } else if (event->key() == Qt::Key_S) {
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 450){
                 model->button -> setPosition(80,450);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 350 && inventory->getSize() >= 3){
                 model->button -> setPosition(80, 450);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 450){
                 model->button -> setPosition(480, 450);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 350 && inventory->getSize() >= 4){
                 model->button -> setPosition(480,450);
                 soundMove();
             }
           } else if (event->key() == Qt::Key_D) {
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 450 && inventory->getSize() >= 4){
                 model->button -> setPosition(480,450);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 350 && inventory->getSize() >= 2){
                 model->button -> setPosition(480,350);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 450 && inventory->getSize() >= 1){
                 model->button -> setPosition(80,450);
                 soundMove();
             } else
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 350 && inventory->getSize() >= 3){
                 model->button -> setPosition(80, 350);
                 soundMove();
             }
           }
           if (event->key() == Qt::Key_Space){
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 450){
                model->player->setHealth(model->player->getHealth() + inventory->getHeal(inventory_[3]));
                inventory->removeItem(inventory_[3]);
                soundHeal();
                clearInventory();
                uploadAttack();
             }
             if (model->button->getPosition().x() == 80 && model->button->getPosition().y() == 350){
                model->player->setHealth(model->player->getHealth() + inventory->getHeal(inventory_[0]));
                inventory->removeItem(inventory_[0]);
                soundHeal();
                clearInventory();
                uploadAttack();
             }
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 450){
                model->player->setHealth(model->player->getHealth() + inventory->getHeal(inventory_[2]));
                inventory->removeItem(inventory_[2]);
                soundHeal();
                clearInventory();
                uploadAttack();
             }
             if (model->button->getPosition().x() == 480 && model->button->getPosition().y() == 350){
                model->player->setHealth(model->player->getHealth() + inventory->getHeal(inventory_[1]));
                inventory->removeItem(inventory_[1]);
                soundHeal();
                clearInventory();
                uploadAttack();
             }
           }
   }
   if ((event->key() == Qt::Key_Space) && flag == 3){
     removeItem(dialog_);
     dialog->setNum(dialog->getNum() + 1);
     uploadAttack();
   }
   if ((event->key() == Qt::Key_Space) && flag == 5){
     views().front()->close();
   }
   if ((event->key() == Qt::Key_Space) && flag == 6){
     model->enemy->setHealth(model->enemy->getHealth() - model->player->getDamage()*(400 - fabs(400 - model->slider->getPosition().x() ) )/400 );
     removeItem(model->slider);
     model->sceneDelete();
     soundDamage();
     uploadAttack();
   }
}
void MainWindow::keyReleaseEvent(QKeyEvent* event){
      QGraphicsScene::keyReleaseEvent(event);
       auto key = event->key();
       auto [x, y] = model->player->getDirection();
       if (key == Qt::Key_Space  && flag == 1 && model->button->getPosition().x() == 250){
         flag = 3;
       }

       if (key == Qt::Key_Space  && flag == 1 && model->button->getPosition().x() == 80 && model->button->getPosition().y() == 350){
         flag = 4;
       }
       if (key == Qt::Key_Space  && flag == 1 && model->button->getPosition().x() == 81 && model->button->getPosition().y() == 350){
         flag = 5;
       }
       if (key == Qt::Key_Space  && flag == 1 && model->button->getPosition().x() == 50){
         flag = 6;
       }
       if ((key == Qt::Key_W && y == -1) || (key == Qt::Key_S && y == 1))
           y = 0;
       else if ((key == Qt::Key_D && x == 1) || (key == Qt::Key_A && x == -1))
           x = 0;
       else
           return;
      model->player->setDirection({x, y});

}


