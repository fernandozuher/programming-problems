#pragma once

#include <memory>

using namespace std;

namespace stack_exercises {
    template<class T = int>
    struct Node {
        T data;
        shared_ptr<Node> next;
    };

    template<class T = int>
    class Min_Stack {
        shared_ptr<Node<T>> top;
        T min_ele;

    public:
        void push(const T& data);
        T pop();
        [[nodiscard]] T peek() const;
        [[nodiscard]] bool is_empty() const;
        [[nodiscard]] T min() const;
    };
}

#include "Min_Stack.tpp"
