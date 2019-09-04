#ifndef DATA_H
#define DATA_H


class Data
{
public:
    Data(int data=0);
    //int data() const;
    //void setData(int data);

    Data &operator+(const Data&data);

//private:
    int m_data;

};

#endif // DATA_H
