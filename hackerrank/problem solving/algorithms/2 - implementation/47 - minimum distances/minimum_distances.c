// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

struct first_indexes_of_element {
    int first_index;
    int second_index;
};

int find_minimum_distance_while_read_elements(const int size);

int main()
{
    int array_size;
    scanf("%d", &array_size);

    printf("%d\n", find_minimum_distance_while_read_elements(array_size));

    return 0;
}

    int find_minimum_distance_while_read_elements(const int size)
    {
        int minimum_distance = INT_MAX;
        const int limit_value_of_element = 100001;
        struct first_indexes_of_element elements[limit_value_of_element];

        for (int i = 0; i < limit_value_of_element; ++i)
            elements[i].first_index = elements[i].second_index = -1;

        for (int i = 0, element; i < size && scanf("%d", &element); ++i) {
            if (elements[element].first_index != -1) {
                if (elements[element].second_index == -1) {
                    elements[element].second_index = i;

                    const int minimum_distance_of_current_element = elements[element].second_index - elements[element].first_index;
                    if (minimum_distance > minimum_distance_of_current_element)
                        minimum_distance = minimum_distance_of_current_element;
                }
            }
            else
                elements[element].first_index = i;
        }

        return minimum_distance != INT_MAX ? minimum_distance : -1;
    }
