// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=true
// C++26

import std;
using namespace std;

template<template<class...> class C, class T>
C<T> read(int n);

forward_list<int>& remove_duplicates(forward_list<int>& l);

int main()
{
    int n;
    cin >> n;
    vector<forward_list<int>> unique_lists(n);
    for (auto& x : unique_lists) {
        int n;
        cin >> n;
        auto l{ read<forward_list, int>(n) };
        x = remove_duplicates(l);
    }

    for (const auto& l : unique_lists) {
        for (auto x : l)
            print("{} ", x);
        println();
    }

    return 0;
}

template<template<class...> class C, class T>
C<T> read(int n)
{
    C<T> container(n);
    for (auto& x : container)
        cin >> x;
    return container;
}

// n: length of l
// T: O(n)
// S: O(1) extra space
forward_list<int>& remove_duplicates(forward_list<int>& l)
{
    l.unique();
    return l;
}
