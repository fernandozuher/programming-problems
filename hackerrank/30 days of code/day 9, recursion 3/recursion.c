// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

#include <stdio.h>

int factorial(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}

int factorial(const int n)
{
    return n == 1 ? 1 : n * factorial(n - 1);
}
