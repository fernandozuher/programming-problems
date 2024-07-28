#include <exception>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

#include "Min_Stack.h"

using namespace std;
using namespace stack_exercises;

template<class T = int>
vector<T> data_test();
template<class T = int>
void pushing(const vector<T>& data, Min_Stack<T>& stack);
template<class T = int>
void popping(int size, Min_Stack<T>& stack);

int main()
{
    const auto data{data_test()};
    Min_Stack stack;
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
void pushing(const vector<T>& data, Min_Stack<T>& stack)
{
    println("Pushing...");
    for (const auto x : data) {
        stack.push(x);
        println("number inserted {}, peeked number {}, min element {}", x, stack.peek(), stack.min());
    }
}

template<class T>
void popping(const int size, Min_Stack<T>& stack)
{
    println("Popping...");
    println("min element {}", stack.min());
    for ([[maybe_unused]] const auto _ : views::iota(0, size)) {
        print("peeked number {}, ", stack.peek());
        print("popped number {}, ", stack.pop());
        println("min element {}", stack.min());
    }
}
