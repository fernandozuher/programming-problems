// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem?isFullScreen=true
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
    auto l1 = read<forward_list<T>, T>(n);
    n = read<int>();
    auto l2 = read<forward_list<T>, T>(n);
    return { l1, l2 };
}

template<ranges::range C>
void print(const C& container)
{
    for (const auto& x : container)
        print("{} ", x);
}

int main()
{
    auto n{ read<int>() };

    auto lists{
        views::iota(0, n)
        | views::transform([](auto) {
            auto [l1, l2] { read_2_lists<int>() };
            l1.merge(l2);
            return l1;
            })
        | ranges::to<vector<forward_list<int>>>()
    };

    for (const auto& l : lists) {
        print(l);
        println();
    }

    return 0;
}
