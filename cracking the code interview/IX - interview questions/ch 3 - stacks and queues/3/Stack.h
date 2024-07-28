#pragma once

#include <memory>

using namespace std;

namespace stack_exercises {
    template<class T = int>
    struct Node {
        T data;
        shared_ptr<Node> next;
        explicit Node(const T& data);
    };

    template<class T = int>
    class Stack {
        shared_ptr<Node<T>> top;

    public:
        void push(const T& data);
        T pop();
        [[nodiscard]] T peek() const;
        [[nodiscard]] bool is_empty() const;
    };
}

#include "Stack.tpp"
