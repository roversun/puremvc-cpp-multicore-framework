#ifndef UIMEDIATOR_H
#define UIMEDIATOR_H

#include <common.h>

#include <QDebug>
#include "data.h"

class UIMediator: public Mediator
{
public:
    UIMediator();

    Mediator::NotificationNames listNotificationInterests(void) const override
    {
        typedef StdContainerAggregate<std::list<NotificationNames::element_type::type> > result_t;
        result_t* result = new result_t;
        result->get().push_back("Msg_DataChanged");
        return NotificationNames(result);
    }
    void handleNotification(INotification const& notification) override
    {
        std::string msg_txt = notification.getName();
        qDebug() << "UIMediator:" << msg_txt.c_str();
        if (msg_txt.compare("Msg_DataChanged") == 0)
        {
            const Data * data = static_cast<const Data *>(notification.getBody());
            qDebug()<<"data:"<<data->m_data;
        }
    }
};

#endif // UIMEDIATOR_H
