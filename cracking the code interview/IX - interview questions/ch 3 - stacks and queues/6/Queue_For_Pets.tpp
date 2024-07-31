#pragma once

// Just for the IDE to find declarations
#include "Queue_For_Pets.h"

template<class T>
queue_exercises::Node<T>::Node(const T& data): data{data} {}

template<class T>
void queue_exercises::Queue_For_Pets<T>::add(const T& data)
{
    auto node{make_shared<Node<T>>(data)};
    if (last)
        last->next = node;
    last = node;
    if (!first)
        first = last;
}

template<class T>
T queue_exercises::Queue_For_Pets<T>::remove()
{
    if (!first)
        throw out_of_range("The queue is empty");

    const T data{first->data};
    first = first->next;
    if (first == nullptr)
        last == nullptr;
    return data;
}

template<class T>
[[nodiscard]] T queue_exercises::Queue_For_Pets<T>::peek() const
{
    if (!first)
        throw out_of_range("The queue is empty");
    return first->data;
}

template<class T>
[[nodiscard]] bool queue_exercises::Queue_For_Pets<T>::is_empty() const
{
    return first == nullptr;
}

template<class T = int>
void print_queue(const queue_exercises::Queue_For_Pets<T>& queue)
{
    for (auto node{queue.first}; node; node = node->next)
        print("{} ", node->data);
}

template<class T>
void dequeue(queue_exercises::Queue_For_Pets<T>& queue, const string_view& pet)
{
    if (queue.is_empty())
        throw out_of_range("The queue is empty");

    shared_ptr<queue_exercises::Node<T>> prev{queue.first}, current{queue.first};
    for (; current && current->data != pet; prev = current, current = current->next);

    if (!current)
        throw out_of_range("The queue doesn't have a "s + string(pet));

    prev->next = current->next;
    if (current == queue.first)
        queue.first = queue.first->next;
}

template<class T>
void dequeue_dog(queue_exercises::Queue_For_Pets<T>& queue)
{
    dequeue<string>(queue, "dog"s);
}

template<class T>
void dequeue_cat(queue_exercises::Queue_For_Pets<T>& queue)
{
    dequeue<string>(queue, "cat"s);
}

template<class T>
void dequeue_any(queue_exercises::Queue_For_Pets<T>& queue)
{
    queue.remove();
}
