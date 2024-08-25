// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
void merge_sort(vector<T>& elements);
template<class T = int>
void merge_sort(vector<T>& elements, vector<T>& helper, int low, int high);
template<class T = int>
void merge(vector<T>& elements, vector<T>& helper, int low, int middle, int high);

int main()
{
    constexpr int n{10};
    vector<int> elements(n);
    ranges::iota(elements | views::reverse, 0);

    ranges::copy(elements, ostream_iterator<int>(cout, " "));
    println("");

    merge_sort(elements);
    ranges::copy(elements, ostream_iterator<int>(cout, " "));

    return 0;
}

template<class T>
void merge_sort(vector<T>& elements)
{
    vector<T> helper(elements.size());
    merge_sort(elements, helper, 0, elements.size() - 1);
}

template<class T>
void merge_sort(vector<T>& elements, vector<T>& helper, const int low, const int high)
{
    if (low >= high)
        return;

    int middle = (low + high) / 2;
    merge_sort(elements, helper, low, middle);
    merge_sort(elements, helper, middle + 1, high);
    merge(elements, helper, low, middle, high);
}

template<class T>
void merge(vector<T>& elements, vector<T>& helper, const int low, const int middle, const int high)
{
    ranges::copy(elements | views::drop(low) | views::take(high - low + 1), helper.begin() + low);

    int helper_left{low};
    int helper_right{middle + 1};
    int current{low};

    while (helper_left <= middle && helper_right <= high)
        elements.at(current++) = helper.at(helper_left) <= helper.at(helper_right)
                                     ? helper.at(helper_left++)
                                     : helper.at(helper_right++);

    int remaining{middle - helper_left + 1};
    ranges::copy(helper | views::drop(helper_left) | views::take(remaining), elements.begin() + current);
}
