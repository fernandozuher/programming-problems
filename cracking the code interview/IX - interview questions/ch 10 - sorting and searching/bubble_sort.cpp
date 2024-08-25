// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
void bubble_sort(vector<T>& elements);

int main()
{
    constexpr int n{10};
    vector<int> elements(n);
    ranges::iota(elements | views::reverse, 0);

    ranges::copy(elements, ostream_iterator<int>(cout, " "));
    println("");

    bubble_sort(elements);
    ranges::copy(elements, ostream_iterator<int>(cout, " "));

    return 0;
}

template<class T>
void bubble_sort(vector<T>& elements)
{
    for (const auto n{elements.size()}; const auto i : views::iota(0ul, n - 1)) {
        bool swapped{};

        for (const auto& window : elements | views::take(n - i) | views::slide(2))
            if (window.front() > window.back()) {
                swap(window.front(), window.back());
                swapped = true;
            }

        if (!swapped)
            break;
    }
}
