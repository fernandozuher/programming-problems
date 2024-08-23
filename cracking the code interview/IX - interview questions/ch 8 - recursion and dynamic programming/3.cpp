// From C++23

// TODO: Follow up: What if the values are not distinct?

#include <algorithm>
#include <iostream>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

vector<vector<int>> generate_input(int n);
vector<int> generate_sorted_distinc_values_array_with_magic_index(int n, int magic_index);
int find_magic_index(const vector<int>& elements, int left, int right);

int main()
{
    for (constexpr int n{5}; const auto& elements : generate_input(n)) {
        cout << "Array: ";
        ranges::copy(elements, ostream_iterator<int>(cout, " "));
        println("");

        if (const int index{find_magic_index(elements, 0, n - 1)}; index != -1)
            println("array[{}] == {}", elements.at(index), index);
        else
            println("There is not magic number in array");
        println("");
    }
    return 0;
}

vector<vector<int>> generate_input(const int n)
{
    vector<vector<int>> arrays;
    for (const auto magic_index : views::iota(0, n)) {
        const vector magic_index_array{generate_sorted_distinc_values_array_with_magic_index(n, magic_index)};
        vector<int> no_magic_index_array(n);
        ranges::iota(no_magic_index_array, magic_index + 1);
        arrays.push_back(magic_index_array);
        arrays.push_back(no_magic_index_array);
    }
    return arrays;
}

vector<int> generate_sorted_distinc_values_array_with_magic_index(const int n, const int magic_index)
{
    vector<int> elements(n);

    for (const int i : views::iota(0, magic_index))
        elements.at(i) = i - 1;
    elements.at(magic_index) = magic_index;
    for (const int i : views::iota(magic_index + 1, n))
        elements.at(i) = i + 1;

    return elements;
}

int find_magic_index(const vector<int>& elements, const int left, const int right)
{
    if (left <= right) {
        int middle{left + (right - left) / 2};

        if (const auto x{elements.at(middle)}; x == middle)
            return middle;
        else if (middle < x)
            return find_magic_index(elements, left, right - 1);
        return find_magic_index(elements, left + 1, right);
    }

    return -1;
}
