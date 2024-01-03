// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int divisible_sum_pairs(const int* const array, const int n, const int k);
int compare (const void* const a, const void* const b);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *array = read_int_array(n);

    qsort(array, n, sizeof(int), compare);

    printf("%d\n", divisible_sum_pairs(array, n, k));

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int compare (const void* const a, const void* const b)
    {
        return (*(int*) a - *(int*) b);
    }

    int divisible_sum_pairs(const int* const array, const int n, const int k)
    {
        int n_divisible_sum_pairs = 0;

        for (int i = 0, n2 = n - 1; i < n2; ++i)
            for (int j = i + 1; j < n; ++j)
                if (array[i] <= array[j] && !((array[i] + array[j]) % k))
                    ++n_divisible_sum_pairs;

        return n_divisible_sum_pairs;
    }
