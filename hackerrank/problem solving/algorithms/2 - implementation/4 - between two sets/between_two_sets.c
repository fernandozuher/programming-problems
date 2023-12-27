// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_FACTORS_SIZE 101


int* read_int_array(const int n);
int compare (const void *const a, const void *const b);

int find_total_factors(const int *const array1, const int n1, const int *const array2, const int n2);
    void find_numbers_divisible_by_set_a(int *const potential_factors, int *const n_potential_factors, const int *const array1,
                                         const int n1, const int first_element_of_set_b);
    void find_factors_of_set_b(int *const potential_factors, const int n_potential_factors, const int *const array2, const int n2);
    int count_factors(int *const potential_factors, const int n_potential_factors);


int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int *array1 = read_int_array(n1);
    int *array2 = read_int_array(n2);

    qsort(array1, n1, sizeof(int), compare);
    qsort(array2, n2, sizeof(int), compare);

    printf("%d\n", find_total_factors(array1, n1, array2, n2));

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int compare(const void const *a, const void const *b)
    {
        return (*(int*) a - *(int*) b);
    }

    int find_total_factors(const int *const array1, const int n1, const int *const array2, const int n2)
    {
        int potential_factors[MAXIMUM_FACTORS_SIZE], n_potential_factors = 0;

        find_numbers_divisible_by_set_a(potential_factors, &n_potential_factors, array1, n1, array2[0]);
        find_factors_of_set_b(potential_factors, n_potential_factors, array2, n2);
        int total_factors = count_factors(potential_factors, n_potential_factors);

        return total_factors;
    }

        void find_numbers_divisible_by_set_a(int *const potential_factors, int *n_potential_factors, 
                                             const int *array1, const int n1, const int first_element_of_set_b)
        {
            for (int potential_factor = array1[n1 - 1]; potential_factor <= first_element_of_set_b; potential_factor += array1[n1-1]) {
                bool is_a_real_potential_factor = true;

                for (int i = 0; i < n1; ++i)
                    if (potential_factor % array1[i]) {
                        is_a_real_potential_factor = false;
                        break;
                    }

                if (is_a_real_potential_factor)
                    potential_factors[(*n_potential_factors)++] = potential_factor;
            }
        }

        void find_factors_of_set_b(int *const potential_factors, const int n_potential_factors, const int *const array2, const int n2)
        {
            for (int i = 0; i < n2; ++i)
                for (int j = 0; j < n_potential_factors; ++j)
                    if (potential_factors[j] && array2[i] % potential_factors[j])
                        potential_factors[j] = 0;
        }

        int count_factors(int *const potential_factors, const int n_potential_factors)
        {
            int n_factors = 0;

            for (int i = 0; i < n_potential_factors; ++i)
                if (potential_factors[i])
                    ++n_factors;

            return n_factors;
        }
