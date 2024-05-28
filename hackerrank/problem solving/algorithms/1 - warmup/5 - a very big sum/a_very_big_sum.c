// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <stdio.h>

long a_very_big_sum(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld\n", a_very_big_sum(n));
    return 0;
}

    long a_very_big_sum(int n)
    {
        long sum = 0;
        for (long x; n-- && scanf("%ld", &x); sum += x);
        return sum;
    }
