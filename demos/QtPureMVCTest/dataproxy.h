#ifndef DATAPROXY_H
#define DATAPROXY_H

#include "common.h"

#include "data.h"

class DataProxy : public Proxy
{
public:
    DataProxy();
    Data m_data;

    void setData(void const * data);

};

#endif // DATAPROXY_H
