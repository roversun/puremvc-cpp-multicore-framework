#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "common.h"
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow, public Mediator
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2() override;

    Mediator::NotificationNames listNotificationInterests(void) const override;
    void handleNotification(INotification const& notification) override;


private slots:
    void on_pbAdd_clicked();

    void on_pbSubtract_clicked();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
