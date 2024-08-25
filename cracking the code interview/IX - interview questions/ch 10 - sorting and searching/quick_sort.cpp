// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
void quick_sort(vector<T>& elements);
template<class T = int>
void quick_sort(vector<T>& elements, int left, int right);
template<class T = int>
int partition(vector<T>& elements, int left, int right);

int main()
{
    constexpr int n{10};
    vector<int> elements(n);
    ranges::iota(elements | views::reverse, 0);

    ranges::copy(elements, ostream_iterator<int>(cout, " "));
    println("");

    quick_sort(elements);
    ranges::copy(elements, ostream_iterator<int>(cout, " "));

    return 0;
}

template<class T>
void quick_sort(vector<T>& elements)
{
    quick_sort(elements, 0, elements.size() - 1);
}

template<class T>
void quick_sort(vector<T>& elements, const int left, const int right)
{
    int index{partition(elements, left, right)};

    if (left < index - 1)
        quick_sort(elements, left, index - 1);

    if (index < right)
        quick_sort(elements, index, right);
}

template<class T>
int partition(vector<T>& elements, int left, int right)
{
    for (int middle{(left + right) / 2}, pivot{elements.at(middle)}; left <= right;) {
        for (; elements.at(left) < pivot; ++left);
        for (; elements.at(right) > pivot; --right);

        if (left <= right)
            swap(elements.at(left++), elements.at(right--));
    }
    return left;
}
