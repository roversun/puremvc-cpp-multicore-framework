/*#include "getdatacommand.h"
#include "data.h"
#include <QtDebug>

GetDataCommand::GetDataCommand()
{

}
void GetDataCommand::execute(INotification const& notification)
{
    qDebug()<<"ChangeDataCommand::execute";
    IProxy &proxy=dynamic_cast<IProxy&>(this->getFacade().retrieveProxy("DataProxy"));
    proxy.setData(notification.getBody());
}*/
