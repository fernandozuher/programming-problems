// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* const a, const void* const b);
int equalize_array(const int* const array, const int n);
    int find_maximum_quantity_of_equal_element(const int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; scanf("%d", &array[i++]));
    qsort(array, n, sizeof(int), cmp);
    printf("%d\n", equalize_array(array, n));

    return 0;
}

    int cmp(const void* const a, const void* const b)
    {
        return (*(int*) a - *(int*) b);
    }

    int equalize_array(const int* const array, const int n)
    {
        int maximum_quantity_of_equal_element = find_maximum_quantity_of_equal_element(array, n);
        int minimum_number_required_deletions = n - maximum_quantity_of_equal_element;
        return minimum_number_required_deletions;
    }

        int find_maximum_quantity_of_equal_element(const int* const array, const int n)
        {
            int maximum_quantity_of_equal_element = 1;

            for (int i = 1, temp_max = 1; i < n; ++i)
                if (array[i - 1] == array[i]) {
                    ++temp_max;
                    if (temp_max > maximum_quantity_of_equal_element)
                        maximum_quantity_of_equal_element = temp_max;
                }
                else
                    temp_max = 1;

            return maximum_quantity_of_equal_element;
        }
