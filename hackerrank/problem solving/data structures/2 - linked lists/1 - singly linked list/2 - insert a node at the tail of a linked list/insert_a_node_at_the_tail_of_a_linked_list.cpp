// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<template<class ...> class C, class T>
C<T> read_nums(int n);

int main()
{
    int n;
    cin >> n;
    auto list{ read_nums<forward_list, int>(n) };
    for (auto x : list)
        println("{}", x);

    return 0;
}

// T: O(n)
// S: O(n) extra space
template<template<class ...> class C, class T>
C<T> read_nums(int n)
{
    return views::iota(0, n) | views::transform([](auto) {T x; cin >> x; return x;}) | ranges::to<C<T>>();
}
