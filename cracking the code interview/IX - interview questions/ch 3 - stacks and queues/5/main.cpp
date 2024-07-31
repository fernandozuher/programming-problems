// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

#include "Stack.h"

using namespace std;
using namespace stack_exercises;

template<class T = int>
vector<vector<T>> data_set();
vector<vector<int>> permutations_from_0_to_n_elements(int n);
template<class T = int>
void pushing(Stack<T>& stack, const vector<T>& data);
template<class T = int>
void sort_in_place(Stack<T>& stack);
template<class T = int>
void popping_stack_pushing_buffer(Stack<T>& stack, Stack<T>& buffer);
template<class T = int>
bool is_popping_buffer_pushing_stack_sorted(Stack<T>& stack, Stack<T>& buffer);
template<class T = int>
void popping(Stack<T>& stack);

int main()
{
    for (Stack stack; const auto& data : data_set()) {
        cout << "Input: ";
        ranges::copy(data, ostream_iterator<int>(cout, " "));
        println("");

        pushing(stack, data);
        println("");
        sort_in_place(stack);
        println("");
        popping(stack);
        println("----------------------");
    }

    return 0;
}

template<class T>
vector<vector<T>> data_set()
{
    constexpr int n{3};
    return permutations_from_0_to_n_elements(n);
}

vector<vector<int>> permutations_from_0_to_n_elements(const int n)
{
    vector<vector<int>> array;

    for (const auto n2 : views::iota(0, n + 1)) {
        vector<int> temp_array(n2);
        ranges::iota(temp_array, 1);
        do {
            array.push_back(temp_array);
        }
        while (ranges::next_permutation(temp_array).found);
    }

    return array;
}

template<class T>
void pushing(Stack<T>& stack, const vector<T>& data)
{
    println("Pushing...");
    for (const auto& x : data) {
        stack.push(x);
        println("Pushed, Peeked: {}, {}", x, stack.peek());
    }
}

template<class T>
void sort_in_place(Stack<T>& stack)
{
    println("Sorting...");
    if (stack.is_empty())
        return;

    for (bool sorted{}; !sorted;) {
        Stack<T> buffer;
        popping_stack_pushing_buffer(stack, buffer);
        sorted = is_popping_buffer_pushing_stack_sorted(stack, buffer);
    }
}

template<class T>
void popping_stack_pushing_buffer(Stack<T>& stack, Stack<T>& buffer)
{
    buffer.push(stack.pop());
    while (!stack.is_empty()) {
        if (const auto& x{stack.pop()}, y{buffer.peek()}; x < y) {
            buffer.pop();
            buffer.push(x);
            buffer.push(y);
        }
        else
            buffer.push(x);
    }
}

template<class T>
bool is_popping_buffer_pushing_stack_sorted(Stack<T>& stack, Stack<T>& buffer)
{
    stack.push(buffer.pop());
    while (!buffer.is_empty() && buffer.peek() < stack.peek())
        stack.push(buffer.pop());

    if (buffer.is_empty())
        return true;

    while (!buffer.is_empty())
        stack.push(buffer.pop());
    return false;
}

template<class T>
void popping(Stack<T>& stack)
{
    println("Popping...");
    while (!stack.is_empty()) {
        print("Peeked, Popped: {}, ", stack.peek());
        println("{}", stack.pop());
    }
}
