#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>
#include <cassert>


template <typename T>
class Storage 
{
    T m_value{};
    
    public:
    Storage(T val):m_value{val}
    {
        
    }
    
    void print()
    {
        std::cout << m_value << '\n';
    }
    
    ~Storage()
    {
        
    };
};

template<>
Storage<char*>::Storage(char* s)
{
    if(!s)
        return;
    unsigned int length {0};
    while(s[length]!='\0') 
        ++length;
    ++length;
    
    m_value = new char[length];
    
    for( int count=0; count<length;count++)
        m_value[count] = s[count];
}

template <>
Storage<char*>::~Storage()
{
    delete[] m_value;
}

int main()
{
    std::string s;
    std::cout<< "Enter your name: ";
    std::cin >>s;
    Storage<int> iVal{5};
    Storage<double> dVal {4.3};
    Storage<char*> sVal(s.data());
    sVal.print();
    s.clear();// clear the std::string
    iVal.print();
    dVal.print();
    sVal.print();//sVal is not affected even if s is cleared
}

#endif
