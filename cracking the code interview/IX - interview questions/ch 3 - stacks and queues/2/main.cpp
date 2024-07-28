// From C++23

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
void test(Min_Stack<T>& min_stack, const vector<T>& data);
template<class T = int>
void pushing(Min_Stack<T>& min_stack, const vector<T>& data);
template<class T = int>
void popping(Min_Stack<T>& min_stack, int n);

int main()
{
    const auto data{data_test()};
    Min_Stack stack;
    test(stack, data);
    return 0;
}

template<class T>
vector<T> data_test()
{
    return {3, 5, 2, 1, 1, -1};
}

template<class T>
void test(Min_Stack<T>& min_stack, const vector<T>& data)
{
    pushing(min_stack, data);
    println("");
    popping(min_stack, data.size());
}

template<class T>
void pushing(Min_Stack<T>& min_stack, const vector<T>& data)
{
    println("Pushing...");
    for (const auto x : data) {
        min_stack.push(x);
        println("Pushed, Peeked, Min: {}, {}, {}", x, min_stack.peek(), min_stack.min());
    }
}

template<class T>
void popping(Min_Stack<T>& min_stack, const int n)
{
    println("Popping...");
    println("Min: {}", min_stack.min());
    // n + 2 to watch exceptions
    for ([[maybe_unused]] const auto _ : views::iota(0, n + 2)) {
        try {
            print("Peeked, Popped, Min: {}, ", min_stack.peek());
            print("{}, ", min_stack.pop());
            println("{}", min_stack.min());
        }
        catch (const out_of_range& error) {
            cerr << error.what() << '\n';
        }
    }
}
