#pragma once

// Just for the IDE to find declarations
#include "Min_Stack.h"

template<class T>
stack_exercises::Node<T>::Node(const T& data): data{data} {}

template<class T>
void stack_exercises::Min_Stack<T>::push(const T& data)
{
    if (!top) {
        min_ele = data;
        top = make_shared<Node<T>>(data);
        return;
    }

    T value{data};
    if (data < min_ele) {
        value = 2 * data - min_ele;
        min_ele = data;
    }
    auto node{make_shared<Node<T>>(value)};
    node->next = top;
    top = node;
}

template<class T>
T stack_exercises::Min_Stack<T>::pop()
{
    if (!top)
        throw out_of_range("The stack is empty");

    T value{top->data};
    if (top->data < min_ele) {
        value = min_ele;
        min_ele = 2 * min_ele - top->data;
    }
    top = top->next;
    return value;
}

template<class T>
T stack_exercises::Min_Stack<T>::peek() const
{
    if (!top)
        throw out_of_range("The stack is empty");

    if (top->data < min_ele)
        return min_ele;
    return top->data;
}

template<class T>
bool stack_exercises::Min_Stack<T>::is_empty() const
{
    return top == nullptr;
}

template<class T>
[[nodiscard]] T stack_exercises::Min_Stack<T>::min() const
{
    if (!top)
        throw out_of_range("The stack is empty");
    return min_ele;
}
