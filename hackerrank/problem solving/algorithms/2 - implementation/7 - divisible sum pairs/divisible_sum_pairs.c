// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int divisible_sum_pairs(const int *numbers, int n, int k);
void init_remainder_frequency(int *freq, int k, const int *numbers, int n);
int count_pairs_with_remainder_0(const int *freq);
int pair_count(int n);
int count_complementary_remainder_pairs(const int *freq, int n);
int count_pairs_with_remainder_k_half(const int *freq, int n);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int numbers[n];
    read_numbers(numbers, n);
    printf("%d\n", divisible_sum_pairs(numbers, n, k));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
int divisible_sum_pairs(const int *numbers, int n, int k)
{
    int freq[k] = {};
    init_remainder_frequency(freq, k, numbers, n);
    return count_pairs_with_remainder_0(freq) + count_complementary_remainder_pairs(freq, k) +
           count_pairs_with_remainder_k_half(freq, k);
}

void init_remainder_frequency(int *freq, int k, const int *numbers, int n)
{
    for (int i = 0; i < n; ++i)
        ++freq[numbers[i] % k];
}

int count_pairs_with_remainder_0(const int *freq)
{
    return pair_count(freq[0]);
}

int pair_count(int n)
{
    return n * (n - 1) / 2;
}

int count_complementary_remainder_pairs(const int *freq, int n)
{
    int count = 0;
    for (int i = 1, n2 = (n + 1) / 2; i < n2; ++i)
        count += freq[i] * freq[n - i];
    return count;
}

int count_pairs_with_remainder_k_half(const int *freq, int n)
{
    return n % 2 == 0 ? pair_count(freq[n / 2]) : 0;
}
