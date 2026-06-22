// https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true
// C++26

import std;
using namespace std;

template<class T>
concept Primitive = is_fundamental_v<T>;
template<Primitive T>
T read()
{
    T x;
    cin >> x;
    return x;
}

template<ranges::range C, Primitive T>
C read(int n)
{
    return views::iota(0, n)
        | views::transform([](auto) {return read<T>();})
        | ranges::to<C>();
}

template<Primitive T>
pair<forward_list<T>, forward_list<T>> read_2_lists()
{
    auto n{ read<T>() };
    forward_list<T> l1{ read<forward_list<T>, T>(n) };
    n = read<T>();
    forward_list<T> l2{ read<forward_list<T>, T>(n) };
    return { l1, l2 };
}

template<ranges::range C>
void println(const C& container)
{
    for (const auto& x : container)
        println("{}", x);
}

int main()
{
    int n{ read<int>() };

    println(
        views::iota(0, n)
        | views::transform([](auto) { auto [l1, l2] { read_2_lists<int>() }; return l1 == l2; })
        | ranges::to<vector<int>>()
    );

    return 0;
}
