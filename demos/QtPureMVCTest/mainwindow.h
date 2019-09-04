#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Mediator
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    Mediator::NotificationNames listNotificationInterests(void) const override;
    void handleNotification(INotification const& notification) override;

private slots:
    void on_pbAdd_clicked();

    void on_pbSubtract_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
