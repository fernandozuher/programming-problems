#pragma once

// Just for the IDE to find declarations
#include "Stack.h"

template<class T>
stack_exercises::Node<T>::Node(const T& data): data{data} {}

template<class T>
void stack_exercises::Stack<T>::push(const T& data)
{
    auto node{make_shared<Node<T>>(data)};
    node->next = top;
    top = node;
}

template<class T>
T stack_exercises::Stack<T>::pop()
{
    if (!top)
        throw out_of_range("The stack is empty");

    T data{top->data};
    top = top->next;
    return data;
}

template<class T>
T stack_exercises::Stack<T>::peek() const
{
    if (!top)
        throw out_of_range("The stack is empty");
    return top->data;
}

template<class T>
bool stack_exercises::Stack<T>::is_empty() const
{
    return top == nullptr;
}
