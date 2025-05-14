// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

#include <stdio.h>

int bitwise_and(int n, int k);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", bitwise_and(n, k));
    }
    return 0;
}

int bitwise_and(int n, int k)
{
    int maximum_value_less_than_k = 0;

    for (int a = k - 1; a > 0; a--)
        if ((a | a + 1) <= n) {
            maximum_value_less_than_k = a;
            break;
        }

    return maximum_value_less_than_k;
}
