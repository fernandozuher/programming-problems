// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <stdio.h>

int simple_array_sum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", simple_array_sum(n));
    return 0;
}

    int simple_array_sum(int n)
    {
        int sum = 0;
        for (int x; n-- && scanf("%d", &x); sum += x);
        return sum;
    }
