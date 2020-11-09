#include "dummy.h"

Dummy::Dummy()
{
    //m_data = new int[5];
}

Dummy::Dummy(const Dummy &other){
    m_data = other.m_data;
}

Dummy::Dummy(Dummy &&other){
    m_data = other.m_data;
}

Dummy &Dummy::operator=(const Dummy &other){
    m_data = other.m_data;
    return *this;
}
Dummy &Dummy::operator=(Dummy &&other){
    m_data = other.m_data;
    return *this;
}

int *Dummy::data(){
    return m_data;
}
