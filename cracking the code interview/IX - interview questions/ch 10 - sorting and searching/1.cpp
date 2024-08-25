// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;
using namespace views;

template<class T = int>
void merge_sorted_arrays(vector<T>& a, const vector<T>& b);
template<class T = int>
void print_array(const vector<T>& elements);

int main()
{
    constexpr int n1{10}, n2{5};
    vector<int> a(n1), b(n2);
    ranges::iota(a, 5);
    ranges::iota(b, 0);

    print_array(a);
    println("\n+");
    print_array(b);
    println("\n=");

    merge_sorted_arrays(a, b);
    print_array(a);

    return 0;
}

template<class T>
void merge_sorted_arrays(vector<T>& a, const vector<T>& b)
{
    int low{};
    int middle = a.size() - 1;
    int high = a.size() + b.size() - 1;

    ranges::copy(b, back_inserter(a));
    vector<T> helper{a};

    int helper_left{low};
    int helper_right{middle + 1};
    int current{};

    while (helper_left <= middle && helper_right <= high) {
        a.at(current++) = helper.at(helper_left) <= helper.at(helper_right)
                              ? helper.at(helper_left++)
                              : helper.at(helper_right++);

        const int remaining{middle - helper_left + 1};
        ranges::copy(helper | drop(helper_left) | take(remaining), next(a.begin(), current));
    }
}

template<class T>
void print_array(const vector<T>& elements)
{
    ranges::copy(elements, ostream_iterator<T>(cout, " "));
}
