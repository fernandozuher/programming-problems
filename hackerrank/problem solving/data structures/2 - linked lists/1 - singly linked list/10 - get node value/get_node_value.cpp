// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true
// C++23

import std;
using namespace std;

pair<forward_list<int>, int> read_test_case();
template<template<class...> class C, class T >
C<T> read(int n);
int node_value_at(const forward_list<int>& l, int pos);

int main()
{
    int n;
    cin >> n;

    vector<int> res(n);
    for (auto& x : res) {
        auto [list, position] { read_test_case() };
        x = node_value_at(list, position);
    }

    for (auto x : res)
        println("{}", x);

    return 0;
}

pair<forward_list<int>, int> read_test_case()
{
    int n;
    cin >> n;
    auto list{ read<forward_list, int>(n) };

    int position_from_tail;
    cin >> position_from_tail;

    int position{ n - position_from_tail - 1 };
    return { list, position };
}

template<template<class...> class C, class T >
C<T> read(int n)
{
    C<T> container(n);
    for (auto& x : container)
        cin >> x;
    return container;
}

// T: O(n)
// S: O(1) extra space
int node_value_at(const forward_list<int>& l, int pos)
{
    return *std::next(l.begin(), pos);
}
