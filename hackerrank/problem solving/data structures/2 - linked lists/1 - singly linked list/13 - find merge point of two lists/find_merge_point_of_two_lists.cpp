// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true
// C++26

// BAD INPUT COMPOSED (ADAPTED FROM) BY HACKERRANK SOURCE

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

template<ranges::range C, class T>
C read(int n)
{
    return views::iota(0, n)
        | views::transform([](auto) { return read<T>(); })
        | ranges::to<C>();
}

template<ranges::range C, class T>
pair<C, C> read_2_containers()
{
    int n{ read<T>() };
    auto container1{ read<C, T>(n) };
    n = read<T>();
    auto container2{ read<C, T>(n) };
    return { container1, container2 };
}

// T: It depends on the container type. For forward_list is O(position)
// S: O(1) extra space
template<ranges::range C>
auto value_at(const C& container, int position)
{
    return *std::next(container.begin(), position);
}

template<ranges::range C>
void println(const C& container)
{
    for (const auto& x : container)
        print("{} ", x);
    println();
}

int main()
{
    int n{ read<int>() };
    vector<int> merge_points(n);

    for (auto& x : merge_points) {
        int position{ read<int>() };
        auto [l1, l2] { read_2_containers<forward_list<int>, int>() };
        l1.merge(l2);
        x = value_at(l1, position);
    }

    println(merge_points);

    return 0;
}
