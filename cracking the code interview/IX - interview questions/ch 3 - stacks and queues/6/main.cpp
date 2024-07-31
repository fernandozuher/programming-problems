// From C++23

#include <algorithm>
#include <iostream>
#include <memory>
#include <print>
#include <vector>
#include <ranges>

#include "Queue_For_Pets.h"

using namespace std;
using namespace queue_exercises;

tuple<vector<string>, vector<string>> data_set();
template<class T = int>
void adding(Queue_For_Pets<T>& queue, const vector<T>& data_to_enqueue);
template<class T = int>
void removing(Queue_For_Pets<T>& queue, const vector<T>& data_to_dequeue);

int main()
{
    const auto [data_to_enqueue, data_to_dequeue]{data_set()};
    Queue_For_Pets<string> queue;
    adding(queue, data_to_enqueue);

    println("");
    print("Queue: ");
    print_queue(queue);
    println("\n");

    try {
        removing(queue, data_to_dequeue);
    }
    catch (const exception& error) {
        cerr << error.what();
    }
    return 0;
}

tuple<vector<string>, vector<string>> data_set()
{
    vector<string> data_to_enqueue{"dog"s, "dog"s, "dog"s, "cat"s, "cat"s, "dog"s};
    vector<string> data_to_dequeue{"any"s, "any"s};
    ranges::reverse_copy(data_to_enqueue | views::reverse | views::take(data_to_enqueue.size() / 2),
                         back_inserter(data_to_dequeue));
    data_to_dequeue.push_back("any"s);
    return {data_to_enqueue, data_to_dequeue};
}

template<class T>
void adding(Queue_For_Pets<T>& queue, const vector<T>& data_to_enqueue)
{
    println("Adding...");
    cout << "Input to add: ";
    ranges::copy(data_to_enqueue, ostream_iterator<string>(cout, " "));
    println("");

    for (const auto& x : data_to_enqueue) {
        queue.add(x);
        println("Added: {}", x);
    }
}

template<class T>
void removing(Queue_For_Pets<T>& queue, const vector<T>& data_to_dequeue)
{
    println("Removing...");
    cout << "Input to remove: ";
    ranges::copy(data_to_dequeue, ostream_iterator<string>(cout, " "));
    println("");

    for (const auto& x : data_to_dequeue) {
        if (x == "dog"s)
            dequeue_dog(queue);
        else if (x == "cat"s)
            dequeue_cat(queue);
        else if (x == "any"s)
            dequeue_any(queue);
        else
            throw invalid_argument("Unknown data to enqueue");

        println("Removed: {}", x);
        print("\tQueue: ");
        print_queue(queue);
        println("");
    }
}
