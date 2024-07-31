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
    class Queue_For_Pets {
        shared_ptr<Node<T>> first;
        shared_ptr<Node<T>> last;

    public:
        void add(const T& data);
        T remove();
        [[nodiscard]] T peek() const;
        [[nodiscard]] bool is_empty() const;

        friend void print_queue<T>(const Queue_For_Pets<T>& queue);
        friend void dequeue_dog<T>(Queue_For_Pets<T>& queue);
        friend void dequeue_cat<T>(Queue_For_Pets<T>& queue);
        friend void dequeue_any<T>(Queue_For_Pets<T>& queue);
        friend void dequeue<T>(Queue_For_Pets<T>& queue, const string_view& pet);
    };
}

#include "Queue_For_Pets.tpp"
