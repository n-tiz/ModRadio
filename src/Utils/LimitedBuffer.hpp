#ifndef __LIMITEDBUFFER_HPP__
#define __LIMITEDBUFFER_HPP__

#include <stddef.h>

template <class T, size_t S>
class LimitedBuffer
{
public:
    LimitedBuffer() : _actualSize(0)
    {
    }

    void Push(T item)
    {
        if (_actualSize == S)
            _beginIndex++;
        else
            _actualSize++;
        _itemsArray[(_beginIndex + _actualSize) % S] = item;
    }

    size_t GetMaxSize() const
    {
        return S;
    }

    size_t GetActualSize() const
    {
        return _actualSize;
    }

    const T &operator[](unsigned int index) const
    {
        index = (_beginIndex + index) % S;
        return _itemsArray[index];
    }

private:
    T _itemsArray[S];
    size_t _actualSize;

    unsigned int _beginIndex;
};

#endif /*__LIMITEDBUFFER_HPP__*/