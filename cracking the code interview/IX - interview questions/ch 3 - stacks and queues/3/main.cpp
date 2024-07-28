// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

#include "Set_Of_Stacks.h"

using namespace std;
using namespace stack_exercises;

template<class T = int>
void test(Set_Of_Stacks<T>& stacks, int n_elements);
template<class T = int>
vector<T> data_test(int n);

int main()
{
    constexpr auto threshold{3};
    Set_Of_Stacks stacks{threshold};
    constexpr auto n_elements{10};
    try {
        test(stacks, n_elements);
    }
    catch (const exception& error) {
        cerr << error.what();
    }

    return 0;
}

template<class T>
void test(Set_Of_Stacks<T>& stacks, const int n_elements)
{
    const auto data{data_test(n_elements)};
    for (const auto& x : data) {
        stacks.push(x);
        println("Pushed/Peeked: {}", stacks.peek());
    }
    println("");
    for ([[maybe_unused]] const auto _ : data)
        println("Popped: {}", stacks.pop());
    println("Popped: {}", stacks.pop());
}

template<class T>
vector<T> data_test(const int n)
{
    vector<T> array(n);
    ranges::iota(array, 0);
    return array;
}
