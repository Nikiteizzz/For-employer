#include "array.h"
#include <iomanip>
#include <iostream>

void Array::addInfoInArr() 
{
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
                std::cin >> arr[i][j];
        }
};

/*Array Array::arrSum(Array &arr_num)
{
    Array res = Array(this->size);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            res.arr[i][j] = 0;
            res.arr[i][j] += arr[i][j] + arr_num.arr[i][j];
        }
    }
    return res;
}*/

void Array::showArr()
{
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++) 
            std::cout << std::setw(5) << arr[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

Array Array::operator +(Array buf)
{
    Array res = Array(this->size);
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            res.arr[i][j] = 0;
            res.arr[i][j] = this->arr[i][j] + buf.arr[i][j];
        }
    }
    return res;
};

Array& Array::operator =(const Array buf)
{
    if (&buf == this)
    {
        return *this;
    }
    else {
         for (int i = 0; i < size; i++)
                delete[]arr[i];
         delete[]arr;
         arr = new int* [size];
         for (int i = 0; i < size; i++)
             arr[i] = new int[size];
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < this->size; j++)
                 this->arr[i][j] = buf.arr[i][j];
         }
         return *this;
    }
};



