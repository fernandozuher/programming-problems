#pragma once

// Just for the IDE to find declarations
#include "Queue.h"

template<class T>
void queue_exercises::Queue<T>::add(const T& data)
{
    auto node{make_shared<Node>(data)};
    if (last)
        last->next = node;
    last = node;
    if (!first)
        first = last;
}

template<class T>
T queue_exercises::Queue<T>::remove()
{
    if (!first)
        throw std::out_of_range("There is not element to remove in queue");
    const T data{first->data};
    first = first->next;
    if (!first)
        last = nullptr;
    return data;
}

template<class T>
[[nodiscard]] T queue_exercises::Queue<T>::peek() const
{
    if (!first)
        throw std::out_of_range("There is not element to peek in queue");
    return first->data;
}

template<class T>
[[nodiscard]] bool queue_exercises::Queue<T>::is_empty() const
{
    return first == nullptr;
}
