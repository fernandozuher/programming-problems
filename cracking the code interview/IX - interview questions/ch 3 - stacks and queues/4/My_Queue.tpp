#pragma once

// Just for the IDE to find declarations
#include "My_Queue.h"

template<class T>
queue_exercises::Node<T>::Node(const T& data): data{data} {}

template<class T>
void queue_exercises::My_Queue<T>::add(const T& data)
{
    addition_stack.push(data);
}

template<class T>
T queue_exercises::My_Queue<T>::remove()
{
    populate_removal_stack();
    try {
        return removal_stack.pop();
    }
    catch (const out_of_range&) {
        throw out_of_range("The queue is empty");
    }
}

template<class T>
[[nodiscard]] T queue_exercises::My_Queue<T>::peek()
{
    populate_removal_stack();
    try {
        return removal_stack.peek();
    }
    catch (const out_of_range&) {
        throw out_of_range("The queue is empty");
    }
}

template<class T>
[[nodiscard]] bool queue_exercises::My_Queue<T>::is_empty() const
{
    return addition_stack.empty && removal_stack.empty();
}

template<class T>
void queue_exercises::My_Queue<T>::populate_removal_stack()
{
    if (!addition_stack.is_empty() && removal_stack.is_empty())
        while (!addition_stack.is_empty())
            removal_stack.push(addition_stack.pop());
}
