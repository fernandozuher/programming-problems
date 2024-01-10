// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_int_array(const int n);
int sock_merchant(const int* const socks, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);
    printf("%d\n", sock_merchant(array, n));

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int sock_merchant(const int* const socks, const int n)
    {
        int pairs = 0;
        const int socks_pairing_limit = 100;
        bool *socks_pairing = (bool*) calloc(socks_pairing_limit, sizeof(bool));

        for (int i = 0; i < n; ++i) {
            if (socks_pairing[socks[i]])
                ++pairs;
            socks_pairing[socks[i]] = !socks_pairing[socks[i]];
        }

        return pairs;
    }
