// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <stdio.h>

int simple_array_sum(int array[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; scanf("%d", &array[i++]));
    printf("%d\n", simple_array_sum(array, n));

    return 0;
}

    int simple_array_sum(const int array[], int n)
    {
        int sum = 0;
        for (; n; sum += array[--n]);
        return sum;
    }
