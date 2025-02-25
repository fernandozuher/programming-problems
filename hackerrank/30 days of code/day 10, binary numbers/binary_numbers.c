// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C23 onwards: constexpr, bool as built-in type, nullptr, auto

#include <stdio.h>
#include <stdlib.h>

constexpr int N_BITS_OF_BINARY_INT = sizeof(int) * 8;

bool *int_to_binary(int n);
bool is_least_significant_bit_on(int n);
int max_consecutive_ones_from(const bool *binary);
int *count_ones_in_sequence(int i, const bool *binary);
int find_last_index_with_consecutive_ones(int i, const bool *binary);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    bool *binary = int_to_binary(n); // lest significant bit starting from the left
    printf("%d\n", max_consecutive_ones_from(binary));

    free(binary);
    return 0;
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
    if (binary == nullptr)
        return 0;

    int max_consecutive_ones = 0;
    for (int i = 0; i < N_BITS_OF_BINARY_INT; ++i) {
        bool is_bit_set = binary[i];

        if (is_bit_set) {
            int *i_and_consecutive_ones = count_ones_in_sequence(i, binary);
            i = i_and_consecutive_ones[0];
            max_consecutive_ones = max(i_and_consecutive_ones[1], max_consecutive_ones);
            free(i_and_consecutive_ones);
        }
    }
    return max_consecutive_ones;
}

int *count_ones_in_sequence(const int i, const bool *const binary)
{
    int first_index = i;
    int last_index = find_last_index_with_consecutive_ones(i, binary);
    int consecutive_ones = last_index - first_index + 1;

    auto output = (int *) malloc(2 * sizeof(int));
    output[0] = last_index;
    output[1] = consecutive_ones;
    return output;
}

int find_last_index_with_consecutive_ones(int i, const bool *const binary)
{
    if (binary == nullptr)
        return 0;
    ++i;
    for (; i < N_BITS_OF_BINARY_INT && binary[i]; ++i);
    return i - 1;
}

int max(const int a, const int b)
{
    return a >= b ? a : b;
}
