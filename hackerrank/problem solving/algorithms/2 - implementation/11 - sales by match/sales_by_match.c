// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int sock_merchant(const int *socks, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int socks[n];
    read_numbers(socks, n);
    printf("%d\n", sock_merchant(socks, n));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array socks
// T: O(n) => O(100) => O(1)
// S: O(101) => O(1) extra space
int sock_merchant(const int *socks, int n)
{
    int pairs = 0;
    constexpr static int socks_pairing_limit = 101;
    bool socks_pairing[socks_pairing_limit] = {0}; // https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2900.htm

    for (int i = 0; i < n; ++i) {
        if (socks_pairing[socks[i]])
            ++pairs;
        socks_pairing[socks[i]] = !socks_pairing[socks[i]];
    }

    return pairs;
}
