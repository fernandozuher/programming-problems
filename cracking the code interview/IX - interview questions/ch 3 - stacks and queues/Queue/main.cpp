// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

#include "Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = int>
vector<T> data_test(int n);
template<class T = int>
void test(Queue<T>& queue, const vector<T>& data);
template<class T = int>
void adding(Queue<T>& queue, const vector<T>& data);
template<class T = int>
void removing(Queue<T>& queue, int n);

int main()
{
    constexpr auto n{5};
    auto data{data_test(n)};
    Queue queue;
    test(queue, data);
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
void test(Queue<T>& queue, const vector<T>& data)
{
    adding(queue, data);
    println("");
    removing(queue, data.size());
}

template<class T>
void adding(Queue<T>& queue, const vector<T>& data)
{
    println("Adding...");
    for (const T x : data) {
        queue.add(x);
        println("Added: {}", x);
    }
}

template<class T>
void removing(Queue<T>& queue, const int n)
{
    println("Removing...");
    // n + 2 to watch exceptions
    for ([[maybe_unused]] const auto _ : views::iota(0, n + 2)) {
        try {
            print("Peeked, Removed: {} ", queue.peek());
            println("{}", queue.remove());
        }
        catch (const out_of_range& error) {
            cerr << error.what() << '\n';
        }
    }
}
