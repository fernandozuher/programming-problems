// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int sock_merchant(const int *socks, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int socks_to_counts[n];
    read_numbers(socks_to_counts, n);
    printf("%d\n", sock_merchant(socks_to_counts, n));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array socks_to_counts
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
