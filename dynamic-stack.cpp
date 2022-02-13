#include "dynamic-stack.h"
#include <iostream>
#include <string>
using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ =  init_capacity_;
    items_ = new StackItem [capacity_];
    size_ = 0;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    int new_capacity = (int)capacity;
    init_capacity_ = new_capacity;
    capacity_ = init_capacity_;
    items_ = new StackItem [capacity_];
    size_ = 0;
}

DynamicStack::~DynamicStack()
{
    delete[] items_;
    items_ = nullptr;
}

bool DynamicStack::empty() const
{
    if (size_ == 0)
        return true;

    else
        return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if (size_ < capacity_)
    {
        items_[size_] = value;
        size_++;
    }
    else
    {
        capacity_ = (capacity_ * 2);
        items_[size_] = value;
        size_++;
    }
}

DynamicStack::StackItem DynamicStack::pop()
{
    if (empty())
        return EMPTY_STACK;

    else
    {
        int top = items_[size_ - 1];

        size_ --;

        if ((capacity_ / 4) >= size_ && (capacity_ / 2) >= init_capacity_)
        {
            capacity_ = (capacity_ / 2);
            int* items_temp = new int[capacity_];
            for (int i = 0; i < size_; i++)
            {
                items_temp[i] = items_[i];
            }
            delete[] items_;
            items_ = items_temp;

        }
        return top;
    }
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if (size_ == 0 || capacity_ < size_)
        return EMPTY_STACK;

    else
        return items_[size_ - 1];
}

void DynamicStack::print() const
{
    for (int i = 0; i < size_ ; i++)
    {
        cout << items_[i] << endl;
    }

}
