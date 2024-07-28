#pragma once

// Just for the IDE to find declarations
#include "Set_Of_Stacks.h"

template<class T>
stack_exercises::Set_Of_Stacks<T>::Set_Of_Stacks(const int n): threshold{n} {}

template<class T>
void stack_exercises::Set_Of_Stacks<T>::push(const T data)
{
    if (!top) {
        top = make_shared<Individual_Stack<T>>();
        size_of_top_stack = 1;
    }
    else if (size_of_top_stack < threshold)
        ++size_of_top_stack;
    else {
        println("New stack initialized...");
        auto stack{make_shared<Individual_Stack<T>>()};
        stack->next = top;
        top = stack;
        size_of_top_stack = 1;
    }
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
