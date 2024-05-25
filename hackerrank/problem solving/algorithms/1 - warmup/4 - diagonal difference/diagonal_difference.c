// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int diagonal_difference(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", diagonal_difference(n));

    return 0;
}

    int diagonal_difference(const int n)
    {
        int primary_diagonal = 0, secondary_diagonal = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0, x; j < n && scanf("%d", &x); ++j) {
                if (i == j)
                    primary_diagonal += x;
                if (j == n - i - 1)
                    secondary_diagonal += x;
            }
        return abs(primary_diagonal - secondary_diagonal);
    }
