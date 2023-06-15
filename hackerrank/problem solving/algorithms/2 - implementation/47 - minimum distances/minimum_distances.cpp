// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <iostream>
#include <map>
#include <vector>
#include <climits>
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
        map<int, vector<int>> elements;

        // two_elements_size {2} = Only the first 2 indexes of a repeated element matter
        // because they have the minimum distance of it
        for (int i {0}, element, two_elements_size {2}; i < size && cin >> element; ++i)
            if (elements[element].size() < two_elements_size) {
                elements[element].push_back(i);

                if (elements[element].size() == two_elements_size) {
                    const int minimum_distance_of_current_element {elements[element].back() - elements[element].front()};
                    minimum_distance = {min(minimum_distance, minimum_distance_of_current_element)};
                }
            }

        return minimum_distance != INT_MAX ? minimum_distance : -1;
    }
