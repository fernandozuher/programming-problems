#pragma once

// Just for the IDE to find declarations
#include "Set_Of_Stacks.h"

template<class T>
stack_exercises::Set_Of_Stacks<T>::Set_Of_Stacks(const int n): threshold{n} {}

template<class T>
void stack_exercises::Set_Of_Stacks<T>::push(const T& data)
{
    auto stack{make_shared<Individual_Stack<T>>()};
    if (!top)
        top = stack;
    else if (size_of_top_stack == threshold) {
        println("New stack initialized...");
        stack->next = top;
        top = stack;
        size_of_top_stack = 0;
    }
    ++size_of_top_stack;
    top->stack.push(data);
}

template<class T>
T stack_exercises::Set_Of_Stacks<T>::pop()
{
    if (!top)
        throw out_of_range("The stack is empty");

    T data{top->stack.pop()};
    if (--size_of_top_stack == 0) {
        println("Stack removed after popping returned element...");
        top = top->next;
        if (top)
            size_of_top_stack = threshold;
    }
    return data;
}

template<class T>
T stack_exercises::Set_Of_Stacks<T>::peek() const
{
    if (!top)
        throw out_of_range("The stack is empty");
    return top->stack.peek();
}

template<class T>
bool stack_exercises::Set_Of_Stacks<T>::is_empty()
{
    return top == nullptr;
}
