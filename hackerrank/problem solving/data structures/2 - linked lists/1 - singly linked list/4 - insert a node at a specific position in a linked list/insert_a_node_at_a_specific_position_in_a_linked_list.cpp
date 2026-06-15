// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<template<class...> class C, class T>
C<T> read(int n);
forward_list<int>& insert_at_position(forward_list<int>& list, int position, int data);

int main()
{
    int n;
    cin >> n;
    auto list{ read<forward_list, int>(n) };

    int data, position;
    cin >> data >> position;
    list = insert_at_position(list, position, data);

    for (auto x : list)
        print("{} ", x);

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

// n: length of nodes in list
// T: O(n)
// S: O(1) extra space
forward_list<int>& insert_at_position(forward_list<int>& list, int position, int data)
{
    auto it{ position ? std::next(list.begin(), position - 1) : list.before_begin() };
    list.insert_after(it, data);
    return list;
}
