// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C23 onwards: constexpr, auto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int SIZE_OF_BINARY_INT = sizeof(int) * 8;

char *int_to_binary(int n);
char least_significant_bit(int n);
int find_max_length_of_ones(const char *binary);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    char *binary = int_to_binary(n);
    printf("%d\n", find_max_length_of_ones(binary));

    free(binary);
    return 0;
}

char *int_to_binary(int n)
{
    auto binary = (char *) calloc(SIZE_OF_BINARY_INT, sizeof(char));
    memset(binary, '0', SIZE_OF_BINARY_INT);
    binary[SIZE_OF_BINARY_INT] = '\0';

    for (int i = SIZE_OF_BINARY_INT - 1; i >= 0 && n > 0; --i, n >>= 1)
        binary[i] = least_significant_bit(n);
    return binary;
}

char least_significant_bit(const int n)
{
    return n & 1 ? '1' : '0';
}

int find_max_length_of_ones(const char *const binary)
{
    int max_length = 0;
    int current_length = 0;
    for (int i = 0; i < SIZE_OF_BINARY_INT; ++i) {
        if (binary[i] == '1')
            ++current_length;
        else {
            max_length = max(max_length, current_length);
            current_length = 0;
        }
    }
    max_length = max(max_length, current_length);
    return max_length;
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
