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
int size_of_next_range_of_bits_1(const char *binary, int begin_index);
int find_next_after_last_index_of_consecutive_1s(const char *binary, int begin_index);
int format_index(const char *next_after_last_index, const char *binary);
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
        if (binary[i] == '1') {
            int n_bits = size_of_next_range_of_bits_1(binary, i);
            max_n_bits = max(n_bits, max_n_bits);
            i += n_bits;
        }
    }
    return max_n_bits;
}

int size_of_next_range_of_bits_1(const char *const binary, const int begin_index)
{
    int next_after_last_index = find_next_after_last_index_of_consecutive_1s(binary, begin_index);
    return next_after_last_index - begin_index;
}

int find_next_after_last_index_of_consecutive_1s(const char *const binary, const int begin_index)
{
    constexpr char off_bit = '0';
    char *next_after_last_index = strchr(binary + begin_index, off_bit);
    return format_index(next_after_last_index, binary);
}

int format_index(const char *const next_after_last_index, const char *const binary)
{
    return next_after_last_index == nullptr ? SIZE_OF_BINARY_INT : (next_after_last_index - binary);
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
