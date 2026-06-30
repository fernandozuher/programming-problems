// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=true
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
        | views::transform([](auto) { return read<T>(); })
        | ranges::to<C>();
}

// n: length of l
// T: O(n)
// S: O(1) extra space
template<Primitive T>
void reverse(list<T>& l)
{
    l.reverse();
}

template<ranges::range C>
void print(const C& c)
{
    for (const auto& x : c)
        print("{} ", x);
}

int main()
{
    auto n{ read<int>() };

    auto lists =
        views::iota(0, n)
        | views::transform([](auto) {
            auto n{ read<int>() };
            auto l{ read<list<int>, int>(n) };
            reverse(l);
            return l;
        })
        | ranges::to<vector<list<int>>>();

    for (const auto& l : lists) {
        print(l);
        println();
    }

    return 0;
}
