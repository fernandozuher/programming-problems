#pragma once

// Just for the IDE to find declarations
#include "Queue.h"

template<class T>
queue_exercises::Node<T>::Node(const T& data): data{data} {}

template<class T>
void queue_exercises::Queue<T>::add(const T& data)
{
    auto node{make_shared<Node<T>>(data)};
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
        throw out_of_range("The queue is empty");

    const T data{first->data};
    first = first->next;
    if (first == nullptr)
        last == nullptr;
    return data;
}

template<class T>
[[nodiscard]] T queue_exercises::Queue<T>::peek() const
{
    if (!first)
        throw out_of_range("The queue is empty");
    return first->data;
}

template<class T>
[[nodiscard]] bool queue_exercises::Queue<T>::is_empty() const
{
    return first == nullptr;
}
