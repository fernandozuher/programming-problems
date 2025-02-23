// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C23 onwards: constexpr, bool as built-in type, nullptr, auto

#include <stdio.h>
#include <stdlib.h>

constexpr int N_BITS_OF_BINARY_INT = sizeof(int) * 8;

int count_max_consecutive_ones_in_binary_from(int n);
bool *int_to_binary(int n);
int max_consecutive_ones_from(const bool *binary);
bool is_least_significant_bit_on(int n);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", count_max_consecutive_ones_in_binary_from(n));
    return 0;
}

int count_max_consecutive_ones_in_binary_from(const int n)
{
    bool *binary = int_to_binary(n);
    int max_consecutive_ones = max_consecutive_ones_from(binary);
    free(binary);
    binary = nullptr;
    return max_consecutive_ones;
}

bool *int_to_binary(int n)
{
    auto binary = (bool *) calloc(N_BITS_OF_BINARY_INT, sizeof(bool));
    for (int i = 0; i < N_BITS_OF_BINARY_INT && n > 0; ++i, n /= 2)
        binary[i] = is_least_significant_bit_on(n);
    return binary;
}

bool is_least_significant_bit_on(const int n)
{
    return n & 1;
}

int max_consecutive_ones_from(const bool *const binary)
{
    int consecutive_ones = 0, max_consecutive_ones = 0;
    for (int i = 0; i < N_BITS_OF_BINARY_INT; ++i)
        if (binary[i])
            ++consecutive_ones;
        else {
            max_consecutive_ones = max(consecutive_ones, max_consecutive_ones);
            consecutive_ones = 0;
        }
    return max(consecutive_ones, max_consecutive_ones);
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
