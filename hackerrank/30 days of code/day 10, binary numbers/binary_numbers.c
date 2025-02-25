// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C23 onwards: constexpr, bool as built-in type, nullptr, auto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int SIZE_OF_BINARY_INT = sizeof(int) * 8;

typedef struct {
    int first, next_after_last;
} range;

char *int_to_binary(int n);
char least_significant_bit(int n);
int max_consecutive_ones_from(const char *binary);
range find_range_bits_1(const char *binary, int i);
int find_begin(const char *binary, int i);
int find_end(const char *binary, int i);
int format_index(const char *ptr, const char *start);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    char *binary = int_to_binary(n); // lest significant bit starting from left
    printf("%d\n", max_consecutive_ones_from(binary));

    free(binary);
    return 0;
}

char *int_to_binary(int n)
{
    auto binary = (char *) calloc(SIZE_OF_BINARY_INT, sizeof(char));
    memset(binary, '0', SIZE_OF_BINARY_INT);
    for (int i = 0; i < SIZE_OF_BINARY_INT && n > 0; ++i, n /= 2)
        binary[i] = least_significant_bit(n);
    return binary;
}

char least_significant_bit(const int n)
{
    return n & 1 ? '1' : '0';
}

int max_consecutive_ones_from(const char *const binary)
{
    int max_n_bits = 0;
    for (int i = 0; i < SIZE_OF_BINARY_INT; ++i) {
        range bits_range = find_range_bits_1(binary, i);
        int n_bits = bits_range.next_after_last - bits_range.first;
        max_n_bits = max(n_bits, max_n_bits);
        i = bits_range.next_after_last;
    }
    return max_n_bits;
}

range find_range_bits_1(const char *const binary, const int i)
{
    range bits_range = {find_begin(binary, i), find_end(binary, i)};
    return bits_range;
}

int find_begin(const char *const binary, const int i)
{
    char *ptr = strchr(binary + i, '1');
    return format_index(ptr, binary);
}

int find_end(const char *const binary, const int i)
{
    char *ptr = strchr(binary + i, '0');
    return format_index(ptr, binary);
}

int format_index(const char *const ptr, const char *const start)
{
    return ptr == nullptr ? (SIZE_OF_BINARY_INT - 1) : (ptr - start);
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
