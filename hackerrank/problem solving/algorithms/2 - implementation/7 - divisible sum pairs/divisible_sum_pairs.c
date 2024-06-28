// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

int *read_int_array(int n);
int divisible_sum_pairs(const int array[], int n, int k);
int compare(const void *a, const void *b);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *array = read_int_array(n);
    qsort(array, n, sizeof(int), compare);
    printf("%d\n", divisible_sum_pairs(array, n, k));
    return 0;
}

    int *read_int_array(const int n)
    {
        auto array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int compare(const void *a, const void *b)
    {
        return *(int*) a - *(int*) b;
    }

    int divisible_sum_pairs(const int array[], const int n, const int k)
    {
        int n_divisible_sum_pairs = 0;

        for (int i = 0, n2 = n - 1; i < n2; ++i)
            for (int j = i + 1; j < n; ++j)
                if (array[i] <= array[j] && !((array[i] + array[j]) % k))
                    ++n_divisible_sum_pairs;

        return n_divisible_sum_pairs;
    }
