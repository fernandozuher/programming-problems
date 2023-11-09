// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

#include <stdio.h>

int solve_me_first(const int a, const int b);

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d", solve_me_first(num1, num2));
    return 0;
}

    int solve_me_first(const int a, const int b)
    {
        return a + b;
    }
