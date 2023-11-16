// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <stdio.h>

long a_very_big_sum(const int *array, int n);

int main()
{
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; scanf("%d", &array[i++]));
    printf("%ld\n", a_very_big_sum(array, n));

    return 0;
}

    long a_very_big_sum(const int *array, int n)
    {
        long sum = 0;
        for (; n--; sum += array[n]);
        return sum;
    }
