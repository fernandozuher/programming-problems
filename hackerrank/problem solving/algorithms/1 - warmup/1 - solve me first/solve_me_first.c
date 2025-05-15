// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

#include <stdio.h>

int solve_me_first(int n1, int n2);

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d", solve_me_first(n1, n2));
    return 0;
}

int solve_me_first(int n1, int n2)
{
    return n1 + n2;
}
