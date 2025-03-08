// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C23 onwards: constexpr, bool as built-in type, nullptr, auto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int SIZE_OF_BINARY_INT = sizeof(int) * 8;

char *int_to_binary(int n);
char least_significant_bit(int n);
int find_size_widest_range_bits_1_from(char *binary);
int find_size_next_range_bits_1_from(const char *binary);
char *find_bit_0(const char *binary);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    char *binary = int_to_binary(n);
    printf("%d\n", find_size_widest_range_bits_1_from(binary));

    free(binary);
    return 0;
}

// lest significant bit starting from left
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

int find_size_widest_range_bits_1_from(char *binary)
{
    int size_widest_range = 0;
    for (int i = 0; i < SIZE_OF_BINARY_INT; ++i)
        if (binary[i] == '1') {
            char *binary_from_i = binary + i;
            int size_range = find_size_next_range_bits_1_from(binary_from_i);
            size_widest_range = max(size_range, size_widest_range);
            i += size_range;
        }
    return size_widest_range;
}

int find_size_next_range_bits_1_from(const char *const binary)
{
    char *ptr = find_bit_0(binary);
    if (ptr == nullptr)
        return SIZE_OF_BINARY_INT;
    int size = ptr - binary;
    return size;
}

char *find_bit_0(const char *const binary)
{
    return strchr(binary, '0');
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
