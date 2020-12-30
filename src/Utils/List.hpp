#ifndef __LIMITEDBUFFER_HPP__
#define __LIMITEDBUFFER_HPP__

#include <stddef.h>

template <class T>
class LimitedBuffer
{
public:
    LimitedBuffer(size_t maxSize) : _maxSize(maxSize), _actualSize(0)
    {

    }

    void Push(T item)
    {
        BufferItem* previousRoot;
        BufferItem* bufferItem = new BufferItem();
        bufferItem->Item = item;
        bufferItem->Next = nullptr;
        if (_rootItem == nullptr)
            _rootItem = bufferItem;
        else
        {
            _lastItem.Next = item;
            _actualSize++;
            if (_actualSize > _maxSize)
            previousRoot = _rootItem;
            _rootItem = _rootItem.Next;
           delete previousRoot;
        }
        _lastItem = item;
    }

    size_t GetMaxSize() const
    {
        return _maxSize;
    }

    size_t GetActualSize() const
    {
        return _actualSize;
    }

private:
    typedef struct bufferItem
    {
        T Item;
        struct bufferItem *Next;
    } BufferItem;
 
    BufferItem *_rootItem;
    BufferItem *_lastItem;
    size_t _maxSize;
    size_t _actualSize;
};

#endif /*__LIMITEDBUFFER_HPP__*/