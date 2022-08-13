#include "raw_pixel.h"
#include <iostream>
#include <algorithm>

#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

template <typename T>
Pixel<T>::Pixel(T maxValue)
{
    this->data = new T[3];
    this->data[0] = 0;
    this->data[1] = 0;
    this->data[2] = 0;

    this->maxValue = maxValue;
}

template <typename T>
Pixel<T>::Pixel(T *data, T maxValue)
{
    this->data = data;
    this->maxValue = maxValue;
}

template <typename T>
Pixel<T>::Pixel(T c1, T c2, T c3, T maxValue)
{
    this->data = new T[3];
    this->data[0] = c1;
    this->data[1] = c2;
    this->data[2] = c3;
    this->maxValue = maxValue;
}

template <typename T>
Pixel<T> &Pixel<T>::operator=(const Pixel<T> &other)
{
    this->data[0] = other.data[0];
    this->data[1] = other.data[1];
    this->data[2] = other.data[2];
    this->maxValue = other.maxValue;
    return *this;
}


template <typename T>
Pixel<T> &Pixel<T>::operator+=(double value)
{
    this->data[0] = CLAMP(this->data[0] + value, 0, maxValue);
    this->data[1] = CLAMP(this->data[1] + value, 0, maxValue);
    this->data[2] = CLAMP(this->data[2] + value, 0, maxValue);
    return *this;
}

template <typename T>
Pixel<T> &Pixel<T>::operator*=(double value)
{
    static bool first = true;
    if (first)
    {
        first = false;
        std::cout << "Max value: " << +maxValue << std::endl;
    }
    this->data[0] = CLAMP(this->data[0] * value, 0, maxValue);
    this->data[1] = CLAMP(this->data[1] * value, 0, maxValue);
    this->data[2] = CLAMP(this->data[2] * value, 0, maxValue);
    return *this;
}

template <typename T>
T &Pixel<T>::operator[](int channel)
{
    return this->data[channel];
}

template class Pixel<uint8_t>;
template class Pixel<double>;