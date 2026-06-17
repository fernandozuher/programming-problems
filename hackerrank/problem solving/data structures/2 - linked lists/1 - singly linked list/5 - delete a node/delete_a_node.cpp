// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<template<class ...> class C, class T>
C<T> read(int n);
template<class T>
forward_list<T>& delete_at(forward_list<T>& list, int position);

int main()
{
    int n;
    cin >> n;
    auto list{ read<forward_list, int>(n) };

    int position;
    cin >> position;
    list = delete_at(list, position);

    for (auto x : list)
        print("{} ", x);

    return 0;
}

template<template<class ...> class C, class T>
C<T> read(int n)
{
    C<T> container(n);
    for (auto& x : container)
        cin >> x;
    return container;
}

// T: O(n)
// S: O(1) extra space
template<class T>
forward_list<T>& delete_at(forward_list<T>& list, int position)
{
    auto it{ position ? std::next(list.begin(), position - 1) : list.before_begin() };
    list.erase_after(it);
    return list;
}
