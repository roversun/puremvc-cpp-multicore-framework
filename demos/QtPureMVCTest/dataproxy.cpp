#include "dataproxy.h"

DataProxy::DataProxy()
    :Proxy("DataProxy")

{
    //m_data.setData(0);
    m_data.m_data=100;
}

void DataProxy::setData(const void *data)
{
    const Data *d = static_cast<const Data*>(data);
    //m_data.setData(d->data()+m_data.data());
    if(data)
        m_data.m_data+=d->m_data;
    sendNotification("Msg_DataChanged",&m_data);
}
