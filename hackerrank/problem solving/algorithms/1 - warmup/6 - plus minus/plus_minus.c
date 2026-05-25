// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
void plus_minus(const int *arr, int n, float *ratios);
void print_ratios(const float *ratios, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    read_numbers(arr, n);

    constexpr int n_ratios = 3;
    float ratios[n_ratios];
    plus_minus(arr, n, ratios);
    print_ratios(ratios, n_ratios);

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// T: O(n)
// S: O(1) extra space
void plus_minus(const int *arr, int n, float *ratios)
{
    int positive, negative, zero;
    positive = negative = zero = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0)
            ++positive;
        else if (arr[i] < 0)
            ++negative;
        else
            ++zero;
    }

    float total = (float) n;
    ratios[0] = positive / total;
    ratios[1] = negative / total;
    ratios[2] = zero / total;
}

void print_ratios(const float *ratios, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%.6f\n", ratios[i]);
}
