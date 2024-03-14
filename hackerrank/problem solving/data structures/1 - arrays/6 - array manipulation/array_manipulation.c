// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long array_manipulation(const int n, int n_queries);

int main()
{
    int n, n_queries;
    scanf("%d %d", &n, &n_queries);
    printf("%ld\n", array_manipulation(n, n_queries));
    return 0;
}

    long array_manipulation(const int n, int n_queries)
    {
        int size = n + 2; // 1-indexed array + range-end
        int *array = (int*) calloc(size, sizeof(int));

        for (int b, e, summand; n_queries--;) {
            scanf("%d %d %d", &b, &e, &summand);
            array[b] += summand;
            array[e + 1] -= summand;
        }

        long sum = 0;
        long max = LONG_MIN;
        for (int i = 0; i < size; ++i) {
            if (!array[i])
                continue;
            sum += array[i];
            max = sum > max ? sum : max;
        }

        free(array);
        array = NULL;

        return max;
    }
