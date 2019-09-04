#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "appfacade.h"
#include "data.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Mediator ("MainWindow"),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->leData->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::handleNotification(INotification const& notification)
{
    std::string msg_txt = notification.getName();
    qDebug()<<"MainWindow Mediator:" << msg_txt.c_str();
    if (msg_txt.compare("Msg_DataChanged") == 0)
    {
        const Data *data = static_cast<const Data*>(notification.getBody());
        ui->leData->setText(QString("%1").arg(data->m_data));
        //std::cout << "New_Data:" << data->m_data << endl;
    }
}
Mediator::NotificationNames MainWindow::listNotificationInterests(void) const
{
    typedef StdContainerAggregate<std::list<NotificationNames::element_type::type> > result_t;
    result_t* result = new result_t;
    result->get().push_back("Msg_DataChanged");
    return NotificationNames(result);
}

void MainWindow::on_pbAdd_clicked()
{
    int i=1;
    sendNotification(AppFacade::CHANGE_DATA,&i);
}

void MainWindow::on_pbSubtract_clicked()
{
    int i=-1;
    sendNotification(AppFacade::CHANGE_DATA,&i);
}
