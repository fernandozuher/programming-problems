// From C++23

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
void test(Stack<T>& stack, const vector<T>& data);
template<class T = int>
void pushing(Stack<T>& stack, const vector<T>& data);
template<class T = int>
void popping(Stack<T>& stack, int n);

int main()
{
    const auto data{data_test()};
    Stack stack;
    test(stack, data);
    return 0;
}

template<class T>
vector<T> data_test()
{
    return {3, 5, 2, 1, 1, -1};
}

template<class T>
void test(Stack<T>& stack, const vector<T>& data)
{
    pushing(stack, data);
    println("");
    popping(stack, data.size());
}

template<class T>
void pushing(Stack<T>& stack, const vector<T>& data)
{
    println("Pushing...");
    for (const auto x : data) {
        stack.push(x);
        println("pushed/peeked number {}", stack.peek());
    }
}

template<class T>
void popping(Stack<T>& stack, const int n)
{
    println("Popping...");
    // n + 2 to watch exceptions
    for ([[maybe_unused]] const auto _ : views::iota(0, n + 2)) {
        try {
            print("peeked number {}, ", stack.peek());
            println("popped number {}", stack.pop());
        }
        catch (const out_of_range& error) {
            cerr << error.what() << '\n';
        }
    }
}
