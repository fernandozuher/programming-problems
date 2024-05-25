// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long *read_array(int n);
int compare(const void *a, const void *b);
long *mini_max_sum(const long *array, int n);
    long *wrap_result(const long *array, int n);

int main()
{
    constexpr int n = 5;
    long *array = read_array(n);
    qsort(array, n, sizeof(long), compare);

    long *result = mini_max_sum(array, n);
    printf("%ld %ld", result[0], result[1]);
    free(array);
    free(result);

    return 0;
}

    long *read_array(const int n)
    {
        auto array = (long*) malloc(n * sizeof(long));
        for (int i = 0; i < n && scanf("%ld", &array[i]); ++i);
        return array;
    }

    int compare(const void *a, const void *b)
    {
        return *(long *) a - *(long *) b;
    }

    long *mini_max_sum(const long *const array, const int n)
    {
        long sum = 0;
        for (int i = 0; i < n; sum += array[i], ++i);
        long min_sum = sum - array[n - 1];
        long max_sum = sum - array[0];

        constexpr int n_result = 2;
        long temp_result[] = {min_sum, max_sum};
        return wrap_result(temp_result, n_result);
    }

        long *wrap_result(const long *const array, const int n)
        {
            auto result = (long*) malloc(n * sizeof(long));
            memcpy(result, array, n * sizeof(long));
            return result;
        }
