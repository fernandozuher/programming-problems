// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

#include <stdio.h>

int bitwise_and(int n, int k);

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", bitwise_and(n, k));
    }
    return 0;
}

int bitwise_and(int n, int k)
{
    if ((k - 1 | k) <= n)
        return k - 1;
    return k - 2;
}
