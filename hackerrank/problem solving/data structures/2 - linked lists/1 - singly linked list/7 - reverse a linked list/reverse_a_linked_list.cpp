// https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true
// C++26

import std;
using namespace std;

template<class T = string>
T read();

template<template<class...> class C = vector, class T = string>
C<T> read(int n);

template<template<class...> class C, class T>
void print(const C<T>& container);

int main()
{
    auto n{ read<int>() };
    vector<forward_list<int> > lists(n);
    for (auto& l : lists) {
        auto n{ read<int>() };
        l = read<forward_list, int>(n);
        l.reverse();
    }

    for (const auto& l : lists) {
        print(l);
        println();
    }

    return 0;
}

template<class T>
T read()
{
    T x;
    cin >> x;
    return x;
}

template<template<class...> class C, class T>
C<T> read(int n)
{
    C<T> container(n);
    for (auto& x : container)
        cin >> x;
    return container;
}

template<template<class...> class C, class T>
void print(const C<T>& container)
{
    if (container.empty())
        return;

    auto it{ container.begin() };
    for (; it != container.end(); ++it) {
        if (next(it, 1) == container.end())
            break;
        cout << *it << ' ';
    }
    cout << *it;
}
