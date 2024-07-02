// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

int *read_int_array(int n);
int sock_merchant(const int socks[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);
    printf("%d\n", sock_merchant(array, n));

    return 0;
}

    int *read_int_array(const int n)
    {
        auto array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int sock_merchant(const int socks[], const int n)
    {
        int pairs = 0;
        constexpr static int socks_pairing_limit = 100;
        auto socks_pairing = (bool*) calloc(socks_pairing_limit, sizeof(bool));

        for (int i = 0; i < n; ++i) {
            if (socks_pairing[socks[i]])
                ++pairs;
            socks_pairing[socks[i]] = !socks_pairing[socks[i]];
        }

        return pairs;
    }
