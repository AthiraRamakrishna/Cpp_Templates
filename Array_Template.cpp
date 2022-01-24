#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include <cassert>


template <typename T>
class Array 
{
    int m_length{};
    T* m_data{};
    
public:
    Array(int length)
    {
        assert(length>0);
        m_data = new T[length];
        m_length = length;
    }
    
    ~Array()
    {
        delete[] m_data;
    }
    
    Array(const Array&) = delete;
    
    Array<T>& operator = (const Array&) = delete;
    
    void erase()
    {
        delete[] m_data;
        
        m_data = nullptr;
        m_length = 0;
        
    }
    
    T& operator [] (int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    
    int getLength() const;
    
};

template <typename T>
int Array<T>::getLength() const // note class name is Array<T>, not Array
{
    return m_length;
}


int main()
{
    Array<int> intArray {12};
    Array<double> doubleArray {12};
    
    for (int count{0}; count < intArray.getLength(); ++count)
    {
        intArray[count] = count;
        doubleArray[count] = count+0.5;
    }
    
    for(int count{intArray.getLength()-1}; count >= 0; --count )
    {
        std::cout<<intArray[count] << "\t" << doubleArray[count] << std::endl;
    }
 return 0;
}
#endif 
