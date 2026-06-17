// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<template<class...> class C, class T>
C<T> read(int n);
template<class T>
forward_list<T>& insert_at(forward_list<T>& list, int position, T data);

int main()
{
    int n;
    cin >> n;
    auto list{ read<forward_list, int>(n) };

    int data, position;
    cin >> data >> position;
    list = insert_at(list, position, data);

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
template<class T>
forward_list<T>& insert_at(forward_list<T>& list, int position, T data)
{
    auto it{ position ? std::next(list.begin(), position - 1) : list.before_begin() };
    list.insert_after(it, data);
    return list;
}
