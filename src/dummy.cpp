#include "dummy.h"

Dummy::Dummy()
{
    m_data = nullptr;
}

int * &Dummy::data(){
    return m_data;
}

bool Dummy::hasData(){
    return (m_data != nullptr);
}