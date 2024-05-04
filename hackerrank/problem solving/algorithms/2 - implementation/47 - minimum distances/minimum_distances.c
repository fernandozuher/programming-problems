// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

#define NO_INDEX -1

typedef struct {
    int first_index;
    int second_index;
} first_indexes_of_element;

int find_minimum_distance_while_read_elements(const int n);
    void initialize_array(first_indexes_of_element *first_indexes_of_elements, const int n);
    int min(const int num1, const int num2);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", find_minimum_distance_while_read_elements(n));

    return 0;
}

    int find_minimum_distance_while_read_elements(const int n)
    {
        int minimum_distance = INT_MAX;
        const int limit_value = 100001;
        first_indexes_of_element first_indexes_of_elements[limit_value];

        initialize_array(first_indexes_of_elements, limit_value);

        for (int i = 0, element; i < n && scanf("%d", &element); ++i) {
            int first_index = first_indexes_of_elements[element].first_index;

            if (first_index != NO_INDEX) {
                int second_index = first_indexes_of_elements[element].second_index;

                if (second_index == NO_INDEX) {
                    first_indexes_of_elements[element].second_index = second_index = i;
                    int minimum_distance_of_current_element = second_index - first_index;
                    minimum_distance = min(minimum_distance, minimum_distance_of_current_element);
                }
            }
            else
                first_indexes_of_elements[element].first_index = i;
        }

        return minimum_distance != INT_MAX ? minimum_distance : NO_INDEX;
    }

        void initialize_array(first_indexes_of_element *first_indexes_of_elements, const int n)
        {
            for (int i = 0; i < n; ++i)
                first_indexes_of_elements[i].first_index = first_indexes_of_elements[i].second_index = NO_INDEX;
        }

        int min(const int num1, const int num2)
        {
            return num1 <= num2 ? num1 : num2;
        }
