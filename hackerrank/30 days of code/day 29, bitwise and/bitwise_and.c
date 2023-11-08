// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

#include <stdio.h>

int bitwise_and(const int n, const int k);

int main()
{
    int n;
    scanf("%d", &n);

    for (int count, lim; n-- && scanf("%d %d", &count, &lim);)
        printf("%d\n", bitwise_and(count, lim));

    return 0;
}

    int bitwise_and(const int n, const int k)
    {
        int maximum_value_less_than_k = 0;

        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                int operation = i & j;

                if (operation < k && operation > maximum_value_less_than_k) {
                    if (operation == k - 1)
                        return operation;
                    else
                        maximum_value_less_than_k = operation;
                }
            }

        return maximum_value_less_than_k;
    }
