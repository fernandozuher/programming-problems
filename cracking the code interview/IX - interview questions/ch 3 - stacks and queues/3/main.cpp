// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

#include "Set_Of_Stacks.h"

using namespace std;
using namespace stack_exercises;

template<class T = int>
void test(Set_Of_Stacks<T>& stacks, const vector<T>& data);
template<class T = int>
vector<T> data_test(int n);
template<class T = int>
void pushing(Set_Of_Stacks<T>& stacks, const vector<T>& data);
template<class T = int>
void popping(Set_Of_Stacks<T>& stacks, int n);

int main()
{
    constexpr auto threshold{3};
    Set_Of_Stacks stacks{threshold};
    constexpr auto n_elements{10};
    test(stacks, data_test(n_elements));
    return 0;
}

template<class T>
void test(Set_Of_Stacks<T>& stacks, const vector<T>& data)
{
    pushing(stacks, data);
    println("");
    popping(stacks, data.size());
}

template<class T>
vector<T> data_test(const int n)
{
    vector<T> array(n);
    ranges::iota(array, 0);
    return array;
}

template<class T>
void pushing(Set_Of_Stacks<T>& stacks, const vector<T>& data)
{
    for (const auto& x : data) {
        stacks.push(x);
        println("Pushed, Peeked: {}, {}", x, stacks.peek());
    }
}

template<class T>
void popping(Set_Of_Stacks<T>& stacks, const int n)
{
    // n + 2 to watch exceptions
    for ([[maybe_unused]] const auto _ : views::iota(0, n + 2)) {
        try {
            print("Peeked, Popped: {}, ", stacks.peek());
            println("{}", stacks.pop());
        }
        catch (const out_of_range& error) {
            cerr << error.what() << '\n';
        }
    }
}
