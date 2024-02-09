// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int* permutation_equation(const int* const array, const int n);
    int* generate_elements_positions_array(const int* const array, const int n);
    int* generate_permutated_array(const int* const array, const int n);
void print_array(const int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);
    int *permutated_array = permutation_equation(array, n);
    print_array(permutated_array, n);

    free(array);
    free(permutated_array);
    array = permutated_array = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int* permutation_equation(const int* const array, const int n)
    {
        int *elements_positions_array = generate_elements_positions_array(array, n);
        int *permutated_array = generate_permutated_array(elements_positions_array, n);

        free(elements_positions_array);
        elements_positions_array = NULL;

        return permutated_array;
    }

        int* generate_elements_positions_array(const int* const array, const int n)
        {
            int *elements_positions_array = (int*) calloc(n, sizeof(int));
            for (int i = 0; i < n; ++i)
                elements_positions_array[array[i] - 1] = i;
            return elements_positions_array;
        }

        int* generate_permutated_array(const int* const array, const int n)
        {
            int *permutated_array = (int*) calloc(n, sizeof(int));
            for (int i = 0; i < n; i++)
                permutated_array[i] = array[array[i]] + 1;
            return permutated_array;
        }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; i++)
            printf("%d\n", array[i]);
    }
