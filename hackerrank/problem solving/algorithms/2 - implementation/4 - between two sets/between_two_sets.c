// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_FACTORS_SIZE 101

/*
 * Complete the 'get_total_x' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

void initialize_arrays(int *array1, int n1, int *array2, int n2);
    int compare (const void * a, const void * b);

int get_total_x(int *array1, int n1, int *array2, int n2);
    void find_numbers_divisible_by_set_a(int *potential_factors, int *n_potential_factors, int *array1, int n1, int first_element_of_set_b);
    void find_factors_of_set_b(int *potential_factors, int n_potential_factors, int *array2, int n2);
    int count_factors(int *potential_factors, int n_potential_factors);


int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int array1[n1], array2[n2];
    initialize_arrays(array1, n1, array2, n2);

    int total = get_total_x(array1, n1, array2, n2);
    printf("%d\n", total);

    return 0;
}

    void initialize_arrays(int *array1, int n1, int *array2, int n2) {
        for (int i = 0; i < n1; i++)
            scanf("%d", &array1[i]);
        qsort(array1, n1, sizeof(int), compare);

        for (int i = 0; i < n2; i++)
            scanf("%d", &array2[i]);
        qsort(array2, n2, sizeof(int), compare);
    }

        int compare (const void * a, const void * b) {
            return ( *(int*)a - * (int*)b );
        }

    int get_total_x(int *array1, int n1, int *array2, int n2) {
        int potential_factors[MAXIMUM_FACTORS_SIZE], n_potential_factors = 0;

        find_numbers_divisible_by_set_a(potential_factors, &n_potential_factors, array1, n1, array2[0]);
        find_factors_of_set_b(potential_factors, n_potential_factors, array2, n2);
        int total_factors = count_factors(potential_factors, n_potential_factors);

        return total_factors;
    }

        void find_numbers_divisible_by_set_a(int *potential_factors, int *n_potential_factors, int *array1, int n1, int first_element_of_set_b) {
            for (int potential_factor = array1[n1 - 1]; potential_factor <= first_element_of_set_b; potential_factor += array1[n1 - 1]) {
                bool is_a_real_potential_factor = true;

                for (int i = 0; i < n1; i++)
                    if (potential_factor % array1[i]) {
                        is_a_real_potential_factor = false;
                        break;
                    }

                if (is_a_real_potential_factor)
                    potential_factors[(*n_potential_factors)++] = potential_factor;
            }
        }

        void find_factors_of_set_b(int *potential_factors, int n_potential_factors, int *array2, int n2) {
            for (int i = 0; i < n2; i++)
                for (int j = 0; j < n_potential_factors; j++)
                    if (potential_factors[j] && array2[i] % potential_factors[j])
                        potential_factors[j] = 0;
        }

        int count_factors(int *potential_factors, int n_potential_factors) {
            int n_factors = 0;

            for (int i = 0; i < n_potential_factors; i++)
                if (potential_factors[i])
                    n_factors++;

            return n_factors;
        }
