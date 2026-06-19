// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<template<class ...> class C, class T>
C<T> read(int n);
template<template<class ...> class C, class T>
void print_reverse(C<T>& container);

int main()
{
    int test_cases;
    cin >> test_cases;
    vector<forward_list<int>> lists(test_cases);

    for (int n{}; auto& list : lists) {
        cin >> n;
        list = read<forward_list, int>(n);
    }

    for (auto& list : lists)
        print_reverse(list);

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
template<template<class ...> class C, class T>
void print_reverse(C<T>& container)
{
    container.reverse();
    for (const auto& x : container)
        println("{}", x);
    container.reverse();
}
