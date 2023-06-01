#include "mainwindow.h"

#include <QApplication>
#include <QFrame>
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
     MainWindow scene;
     QGraphicsView view(&scene);
     scene.setSceneRect(80,100 , view.width(), view.height());
     view.setRenderHint(QPainter::Antialiasing);
     view.showFullScreen();
     return QApplication::exec();
}
