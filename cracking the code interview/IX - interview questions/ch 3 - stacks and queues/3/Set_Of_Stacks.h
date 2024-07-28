#pragma once

#include "Stack.h"

namespace stack_exercises {
    template<class T = int>
    struct Individual_Stack {
        Stack<T> stack{};
        shared_ptr<Individual_Stack> next;
    };

    template<class T = int>
    class Set_Of_Stacks {
        shared_ptr<Individual_Stack<T>> top;
        int threshold;
        int size_of_top_stack{};

    public:
        explicit Set_Of_Stacks(int n);
        void push(const T& data);
        T pop();
        [[nodiscard]] T peek() const;
        [[nodiscard]] bool is_empty();
    };
}

#include "Set_Of_Stacks.tpp"
