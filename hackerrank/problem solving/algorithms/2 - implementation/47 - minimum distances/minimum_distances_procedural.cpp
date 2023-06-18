// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <iostream>
#include <map>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

#define NO_INDEX -1

int find_minimum_distance_while_read_elements(const int size);
    int minimum_distance_or_no_index(const int minimum_distance);

int main()
{
    int array_size;
    cin >> array_size;

    cout << find_minimum_distance_while_read_elements(array_size) << "\n";

    return 0;
}

    int find_minimum_distance_while_read_elements(const int size)
    {
        int minimum_distance {INT_MAX};
        map<int, pair<int, int>> first_indexes_of_elements;

        for (int i {0}, element; i < size && cin >> element; ++i)
            if (first_indexes_of_elements.contains(element)) {
                int first_index {first_indexes_of_elements[element].first}, second_index {first_indexes_of_elements[element].second};

                if (second_index == NO_INDEX) {
                    first_indexes_of_elements[element].second = second_index = {i};
                    const int minimum_distance_of_current_element {second_index - first_index};
                    minimum_distance = {min(minimum_distance, minimum_distance_of_current_element)};
                }
            }
            else
                first_indexes_of_elements[element] = {i, NO_INDEX};

        return minimum_distance_or_no_index(minimum_distance);
    }

        int minimum_distance_or_no_index(const int minimum_distance)
        {
            return minimum_distance != INT_MAX ? minimum_distance : NO_INDEX;
        }
