// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_line_as_int_array(const int n);
int sock_merchant(const int *socks, const int n);

int main() {
    const int *array_size = read_line_as_int_array(1);
    const int n = array_size[0];
    const int *socks = read_line_as_int_array(n);

    const int result = sock_merchant(socks, n);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int sock_merchant(const int *socks, const int n) {
        int pairs = 0;
        bool *socks_pairing = (bool*) calloc(100, sizeof(bool));

        for (int i = 0; i < n; i++) {
            if (socks_pairing[socks[i]])
                pairs++;
            socks_pairing[socks[i]] = !socks_pairing[socks[i]];
        }
        
        return pairs;
    }
