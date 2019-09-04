#include "mainwindow.h"
#include "mainwindow2.h"
#include <QApplication>

#include "appfacade.h"
#include "dataproxy.h"
#include "uimediator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppFacade& facade = AppFacade::getInstance();

    MainWindow w;
    facade.registerMediator(&w);

    MainWindow2 w2;
    facade.registerMediator(&w2);

    UIMediator m;
    facade.registerMediator(&m);

    DataProxy proxy;
    facade.registerProxy(&proxy);

    facade.sendNotification(AppFacade::GET_DATA);

    w.show();
    w2.show();

    return a.exec();
}
