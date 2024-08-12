#pragma once

#include <memory>

namespace queue_exercises {
    template<class T = int>
    class Queue {
        struct Node {
            T data;
            std::shared_ptr<Node> next;
        };

        std::shared_ptr<Node> first, last;

    public:
        void add(const T& data);
        T remove();
        [[nodiscard]] T peek() const;
        [[nodiscard]] bool is_empty() const;
    };
}

#include "Queue.tpp"
