#include "mainwindow2.h"
#include "ui_mainwindow2.h"

#include "appfacade.h"
#include "data.h"

#include <QDebug>
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    Mediator ("MainWindow2"),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    ui->leData->setText("0");
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::handleNotification(INotification const& notification)
{
    std::string msg_txt = notification.getName();
    qDebug()<<"MainWindow2 Mediator:" << msg_txt.c_str();
    if (msg_txt.compare("Msg_DataChanged") == 0)
    {
        const Data *data = static_cast<const Data*>(notification.getBody());
        ui->leData->setText(QString("%1").arg(data->m_data));
        //std::cout << "New_Data:" << data->m_data << endl;
    }
}
Mediator::NotificationNames MainWindow2::listNotificationInterests(void) const
{
    typedef StdContainerAggregate<std::list<NotificationNames::element_type::type> > result_t;
    result_t* result = new result_t;
    result->get().push_back("Msg_DataChanged");
    return NotificationNames(result);
}

void MainWindow2::on_pbAdd_clicked()
{
    int i=1;
    sendNotification(AppFacade::CHANGE_DATA,&i);
}

void MainWindow2::on_pbSubtract_clicked()
{
    int i=-1;
    sendNotification(AppFacade::CHANGE_DATA,&i);
}

