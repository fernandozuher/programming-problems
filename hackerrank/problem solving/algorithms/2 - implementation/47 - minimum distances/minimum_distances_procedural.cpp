// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <iostream>
#include <map>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

int find_minimum_distance_while_read_elements(const int size);

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
        map<int, pair<int, int>> elements;

        for (int i {0}, element; i < size && cin >> element; ++i)
            if (elements.contains(element)) {
                if (elements[element].second == -1) {
                    elements[element].second = {i};

                    const int minimum_distance_of_current_element {elements[element].second - elements[element].first};
                    minimum_distance = {min(minimum_distance, minimum_distance_of_current_element)};
                }
            }
            else {
                elements[element].first = {i};
                elements[element].second = {-1};
            }

        return minimum_distance != INT_MAX ? minimum_distance : -1;
    }
