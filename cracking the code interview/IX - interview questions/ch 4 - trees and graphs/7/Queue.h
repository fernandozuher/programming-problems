#pragma once

#include <memory>

using namespace std;

namespace queue_exercises {
    template<class T = int>
    struct Node {
        T data;
        shared_ptr<Node> next;
        explicit Node(const T& data);
    };

    template<class T = int>
    class Queue {
        shared_ptr<Node<T>> first;
        shared_ptr<Node<T>> last;

    public:
        void add(const T& data);
        T remove();
        [[nodiscard]] T peek() const;
        [[nodiscard]] bool is_empty() const;
    };
}

#include "Queue.tpp"
