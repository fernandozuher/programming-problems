// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
int sock_merchant(const int socks[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int socks[n];
    read_numbers(socks, n);
    printf("%d\n", sock_merchant(socks, n));
    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int sock_merchant(const int socks[], int n)
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
