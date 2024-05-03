// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <iostream>
#include <map>
#include <numeric>

using namespace std;

constexpr int no_index { -1};

int find_minimum_distance_while_read_input(int n);

int main()
{
    int n;
    cin >> n;
    cout << find_minimum_distance_while_read_input(n) << '\n';

    return 0;
}

    int find_minimum_distance_while_read_input(const int n)
    {
        int minimum_distance {numeric_limits<int>::max()};
        map<int, pair<int, int>> first_indexes_of_elements;

        for (int i{}, element; i < n && cin >> element; ++i)
            if (first_indexes_of_elements.contains(element)) {
                auto [first_index, second_index] {first_indexes_of_elements[element]};

                if (second_index == no_index) {
                    first_indexes_of_elements[element].second = second_index = i;
                    int minimum_distance_of_current_element {second_index - first_index};
                    minimum_distance = min(minimum_distance, minimum_distance_of_current_element);
                }
            }
            else
                first_indexes_of_elements[element] = {i, no_index};

        return minimum_distance != numeric_limits<int>::max() ? minimum_distance : no_index;
    }
