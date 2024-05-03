// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

#define NO_INDEX -1

struct first_indexes_of_element {
    int first_index;
    int second_index;
};

int find_minimum_distance_while_read_elements(const int size);
    void initialize_array(struct first_indexes_of_element *first_indexes_of_elements, const int size);
    int min(const int num1, const int num2);
    int minimum_distance_or_no_index(const int minimum_distance);

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
        struct first_indexes_of_element first_indexes_of_elements[limit_value_of_element];

        initialize_array(&first_indexes_of_elements, limit_value_of_element);

        for (int i = 0, element; i < size && scanf("%d", &element); ++i) {
            const int first_index = first_indexes_of_elements[element].first_index;

            if (first_index != NO_INDEX) {
                int second_index = first_indexes_of_elements[element].second_index;

                if (second_index == NO_INDEX) {
                    first_indexes_of_elements[element].second_index = second_index = i;
                    const int minimum_distance_of_current_element = second_index - first_index;
                    minimum_distance = min(minimum_distance, minimum_distance_of_current_element);
                }
            }
            else
                first_indexes_of_elements[element].first_index = i;
        }

        return minimum_distance_or_no_index(minimum_distance);
    }

        void initialize_array(struct first_indexes_of_element *first_indexes_of_elements, const int size)
        {
            for (int i = 0; i < size; ++i)
                first_indexes_of_elements[i].first_index = first_indexes_of_elements[i].second_index = NO_INDEX;
        }

        int min(const int num1, const int num2)
        {
            return num1 <= num2 ? num1 : num2;
        }

        int minimum_distance_or_no_index(const int minimum_distance)
        {
            return minimum_distance != INT_MAX ? minimum_distance : NO_INDEX;
        }
