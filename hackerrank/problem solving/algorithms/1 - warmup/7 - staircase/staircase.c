// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

#include <stdio.h>

void staircase(int n);

int main()
{
    int n;
    scanf("%d", &n);
    staircase(n);
    return 0;
}

void staircase(int n)
{
    for (int i = 1; i <= n; ++i) {
        printf("%*s", n - i, "");
        for (int k = 0; k < i; ++k)
            printf("#");
        puts("");
    }
}
