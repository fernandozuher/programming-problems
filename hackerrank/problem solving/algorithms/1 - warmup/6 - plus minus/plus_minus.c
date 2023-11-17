// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
void plus_minus(int *array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);
    plus_minus(array, n);

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    void plus_minus(int *array, const int n)
    {
        int positive_quantity = 0;
        int negative_quantity = 0;
        int zero_quantity = 0;

        for (int i = 0; i < n; ++i)
            if (array[i] > 0)
                ++positive_quantity;
            else if (array[i] < 0)
                ++negative_quantity;
            else
                ++zero_quantity;

        float positive_values_proportion = (float) positive_quantity / n;
        float negative_values_proportion = (float) negative_quantity / n;
        float zero_values_proportion = (float) zero_quantity / n;

        printf("%.6f\n%.6f\n%.6f",
               positive_values_proportion,
               negative_values_proportion,
               zero_values_proportion);
    }
