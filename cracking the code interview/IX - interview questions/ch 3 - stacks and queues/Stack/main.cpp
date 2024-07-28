// From C++23

#include <exception>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

#include "Stack.h"

using namespace std;
using namespace stack_exercises;

template<class T = int>
vector<T> data_test();
template<class T = int>
void pushing(const vector<T>& data, Stack<T>& stack);
template<class T = int>
void popping(int size, Stack<T>& stack);

int main()
{
    const auto data{data_test()};
    Stack stack;
    try {
        pushing(data, stack);
        println("");
        popping(data.size(), stack);
    }
    catch (const exception& error) {
        cerr << error.what();
    }

    return 0;
}

template<class T>
vector<T> data_test()
{
    return {3, 5, 2, 1, 1, -1};
}

template<class T>
void pushing(const vector<T>& data, Stack<T>& stack)
{
    println("Pushing...");
    for (const auto x : data) {
        stack.push(x);
        println("pushed/peeked number {}", stack.peek());
    }
}

template<class T>
void popping(const int size, Stack<T>& stack)
{
    println("Popping...");
    // size + 1 to see exception
    for ([[maybe_unused]] const auto _ : views::iota(0, size + 1)) {
        print("peeked number {}, ", stack.peek());
        println("popped number {}", stack.pop());
    }
}
