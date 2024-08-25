// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
void selection_sort(vector<T>& elements);

int main()
{
    constexpr int n{10};
    vector<int> elements(n);
    ranges::iota(elements | views::reverse, 0);

    ranges::copy(elements, ostream_iterator<int>(cout, " "));
    println("");

    selection_sort(elements);
    ranges::copy(elements, ostream_iterator<int>(cout, " "));

    return 0;
}

template<class T>
void selection_sort(vector<T>& elements)
{
    for (auto [i, x] : elements | views::take(elements.size() - 1) | views::enumerate)
        swap(x, *ranges::min_element(elements | views::drop(i)));
}
