// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int compare (const void *a, const void *b);
void mini_max_sum(int *array, const int n);

int main()
{
    const int n = 5;
    int *array = read_int_array(n);
    qsort(array, n, sizeof(int), compare);
    mini_max_sum(array, n);

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int compare (const void *a, const void *b)
    {
        return (*(int*) a - *(int*) b);
    }

    void mini_max_sum(int *array, const int n)
    {
        long total_sum = 0;
        for (int i = 0; i < n; total_sum += array[i++]);

        long min_sum = total_sum - array[n - 1];
        long max_sum = total_sum - array[0];
        printf("%ld %ld", min_sum, max_sum);
    }
