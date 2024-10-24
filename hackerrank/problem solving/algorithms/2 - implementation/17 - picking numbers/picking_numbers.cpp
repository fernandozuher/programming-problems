// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// From C++23 onwards

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

template <class T = int>
vector<T> read_array(int n);
int picking_numbers(const vector<int>& numbers);
tuple<int, int, int> update_indexes_and_size(
    const vector<int>& numbers, int i, int second_reference_number_index);

int main()
{
    int n;
    cin >> n;
    vector<int> array{read_array(n)};
    ranges::sort(array);
    cout << picking_numbers(array);
    return 0;
}

template <class T>
vector<T> read_array(const int n)
{
    vector<T> array(n);
    ranges::generate(array, [] {T x; cin >> x; return x;});
    return array;
}

int picking_numbers(const vector<int>& numbers)
{
    int subarray_biggest_length{1};
    int subarray_current_size{1};

    for (int first_reference_number_index{}, second_reference_number_index{};
         const auto [i, number] : numbers | views::enumerate | views::drop(1)) {
        switch (int difference{number - numbers.at(first_reference_number_index)}) {
        case 0:
            ++subarray_current_size;
            break;

        case 1:
            ++subarray_current_size;
            if (numbers.at(second_reference_number_index) != number)
                second_reference_number_index = i;
            break;

        default:
            subarray_biggest_length = max(subarray_current_size, subarray_biggest_length);
            tie(first_reference_number_index, second_reference_number_index, subarray_current_size) =
                update_indexes_and_size(numbers, i, second_reference_number_index);
        }
    }

    return max(subarray_biggest_length, subarray_current_size);
}

tuple<int, int, int> update_indexes_and_size(
    const vector<int>& numbers, const int i, const int second_reference_number_index)
{
    int first_reference_number_index, subarray_current_size;

    if (numbers.at(i) - numbers.at(second_reference_number_index) == 1) {
        first_reference_number_index = second_reference_number_index;
        subarray_current_size = i - second_reference_number_index + 1;
    }
    else {
        first_reference_number_index = i;
        subarray_current_size = 1;
    }

    return {first_reference_number_index, i, subarray_current_size};
}
