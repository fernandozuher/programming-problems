#pragma once

#include <memory>

#include "Stack.h"

using namespace std;
using namespace stack_exercises;

namespace queue_exercises {
    template<class T = int>
    struct Node {
        T data;
        shared_ptr<Node> next;
        explicit Node(const T& data);
    };

    template<class T = int>
    class My_Queue {
        Stack<T> addition_stack;
        Stack<T> removal_stack;

    public:
        void add(const T& data);
        T remove();
        [[nodiscard]] T peek();
        [[nodiscard]] bool is_empty() const;
        void populate_removal_stack();
    };
}

#include "My_Queue.tpp"
