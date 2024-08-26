// From C++23

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
int search_in_rotated_array(const vector<T>& elements, T x);
template<class T = int>
void print_array(const vector<T>& elements);

int main()
{
    constexpr int n{31};
    auto elements = views::iota(0, n) | views::stride(3) | ranges::to<vector>();
    cout << "Original array: ";
    print_array(elements);
    println("");

    const auto search_for{elements.at(elements.size() / 2)};
    for (vector<int> rotated(elements.size()); const auto i : views::iota(0ul, elements.size())) {
        ranges::rotate_copy(elements, elements.begin() + i, rotated.begin());
        println("Rotate left ({})", i);
        print_array(rotated);
        println("");
        println("{}? -> {}", search_for, search_in_rotated_array(rotated, search_for));
        println("");
    }

    return 0;
}

template<class T>
int search_in_rotated_array(const vector<T>& elements, const T x)
{
    for (int left{}, right = elements.size() - 1; left <= right;) {
        int middle = (left + right) / 2;
        if (elements.at(middle) == x)
            return middle;

        bool is_left_half_range_sorted{middle - 1 >= left && elements.at(left) <= elements.at(middle - 1)};
        bool is_right_half_range_sorted{middle + 1 <= right && elements.at(middle + 1) <= elements.at(right)};

        if (bool without_rotation{is_left_half_range_sorted && is_right_half_range_sorted}) {
            if (x < elements.at(middle))
                right = middle - 1;
            else
                left = middle + 1;
        }
        else {
            bool maybe_in_sorted_left_half{
                is_left_half_range_sorted && !is_right_half_range_sorted
                && x >= elements.at(left) && x <= elements.at(middle - 1)
            };

            bool maybe_in_non_sorted_left_half{
                !is_left_half_range_sorted && is_right_half_range_sorted
                && !(x >= elements.at(middle + 1) && x <= elements.at(right))
            };

            if (maybe_in_sorted_left_half || maybe_in_non_sorted_left_half)
                right = middle - 1;
            else
                left = middle + 1;
        }
    }
    return -1;
}

template<class T>
void print_array(const vector<T>& elements)
{
    ranges::copy(elements, ostream_iterator<int>(cout, " "));
}
