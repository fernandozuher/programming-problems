// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int sock_merchant(const int *socks, int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *socks_to_counts = morfo_readln(int, &n);
    printf("%d\n", sock_merchant(socks_to_counts, (int)n));
    free(socks_to_counts);
    return 0;
}

// n: length of socks_to_counts
// 1 <= n <= 100
// T: O(n) => O(1)
// S: O(101) => O(1) extra space
int sock_merchant(const int *socks, int n)
{
    int pairs = 0;
    constexpr static int socks_pairing_limit = 101;
    bool socks_pairing[socks_pairing_limit] = {};

    for (int i = 0; i < n; ++i) {
        if (socks_pairing[socks[i]])
            ++pairs;
        socks_pairing[socks[i]] = !socks_pairing[socks[i]];
    }

    return pairs;
}
