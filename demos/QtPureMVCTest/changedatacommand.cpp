#include "changedatacommand.h"
#include "data.h"
#include <QDebug>

ChangeDataCommand::ChangeDataCommand()
{

}

void ChangeDataCommand::execute(INotification const& notification)
{
    //if (notification.getName().compare("Cmd_ChangeData") != 0)
    //	return;
    IProxy &proxy=dynamic_cast<IProxy&>(this->getFacade().retrieveProxy("DataProxy"));
    //const Data *data = static_cast<const Data*>(notification.getBody());
    qDebug()<<"ChangeDataCommand::execute";

    proxy.setData(notification.getBody());
}
