// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

#define NO_INDEX -1

class Minimum_Distances
{
private:
    vector<int> elements;
    int minimum_distance;

    void find_minimum_distance_while_read_elements()
    {
        map<int, pair<int, int>> first_indexes_of_elements;

        for (int i {0}, size {static_cast<int>(this->elements.size())}, element; i < size && cin >> element; ++i) {
            this->elements.at(i) = {element};

            if (first_indexes_of_elements.contains(element)) {
                int first_index {first_indexes_of_elements[element].first}, second_index {first_indexes_of_elements[element].second};

                if (second_index == NO_INDEX) {
                    first_indexes_of_elements[element].second = second_index = {i};
                    const int minimum_distance_of_current_element {second_index - first_index};
                    this->minimum_distance = {min(this->minimum_distance, minimum_distance_of_current_element)};
                }
            }
            else
                first_indexes_of_elements[element] = {i, NO_INDEX};
        }

        this->minimum_distance = this->minimum_distance_or_no_index();
    }

        int minimum_distance_or_no_index() const
        {
            return this->minimum_distance != INT_MAX ? this->minimum_distance : NO_INDEX;
        }

public:
    Minimum_Distances(const int size)
    {
        this->elements = {vector<int>(size)};
        this->minimum_distance = {INT_MAX};
        this->find_minimum_distance_while_read_elements();
    }

    int get_minimum_distance() const
    {
        return minimum_distance;
    }
};

int main()
{
    int array_size;
    cin >> array_size;

    const Minimum_Distances obj(array_size);
    cout << obj.get_minimum_distance() << "\n";

    return 0;
}
