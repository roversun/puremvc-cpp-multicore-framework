#include "data.h"

Data::Data(int data)
    :m_data(data)
{

}
/*
int Data::data() const
{
    return m_data;
}

void Data::setData(int data)
{
    m_data = data;
}*/

Data &Data::operator+(const Data &data)
{
       this->m_data += data.m_data;
       return *this;
}
