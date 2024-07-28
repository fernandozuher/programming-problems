// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

#include "My_Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = int>
vector<T> data_test(int n);
template<class T = int>
void test(My_Queue<T>& my_queue, const vector<T>& data);
template<class T = int>
void adding(My_Queue<T>& my_queue, const vector<T>& data);
template<class T = int>
void removing(My_Queue<T>& my_queue, int n);

int main()
{
    constexpr auto n{5};
    auto data{data_test(n)};
    My_Queue my_queue;
    test(my_queue, data);
    return 0;
}

template<class T>
vector<T> data_test(const int n)
{
    vector<T> array(n);
    ranges::iota(array, 0);
    return array;
}

template<class T>
void test(My_Queue<T>& my_queue, const vector<T>& data)
{
    adding(my_queue, data);
    println("");
    removing(my_queue, data.size());
}

template<class T>
void adding(My_Queue<T>& my_queue, const vector<T>& data)
{
    println("Adding...");
    for (const auto& x : data) {
        my_queue.add(x);
        println("Added: {}", x);
    }
}

template<class T>
void removing(My_Queue<T>& my_queue, const int n)
{
    println("Removing...");
    //n + 2 to watch exceptions
    for ([[maybe_unused]] const auto& _ : views::iota(0, n + 2)) {
        try {
            print("Peeked, Removed: {}, ", my_queue.peek());
            println("{}", my_queue.remove());
        }
        catch (const out_of_range& error) {
            cerr << error.what() << '\n';
        }
    }
}
