// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
void plus_minus(const int numbers[], int n, float ratios[]);
void print_ratios(const float ratios[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int numbers[n];
    read_numbers(numbers, n);

    constexpr int n_ratios = 3;
    float ratios[n_ratios];
    plus_minus(numbers, n, ratios);
    print_ratios(ratios, n_ratios);

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0, x; i < n && scanf("%d", &x); ++i)
        numbers[i] = x;
}

void plus_minus(const int numbers[], int n, float ratios[])
{
    int positive = 0, negative = 0, zero = 0;

    for (int i = 0; i < n; ++i) {
        if (numbers[i] > 0)
            ++positive;
        else if (numbers[i] < 0)
            ++negative;
        else
            ++zero;
    }

    float total = (float) n;
    ratios[0] = positive / total;
    ratios[1] = negative / total;
    ratios[2] = zero / total;
}

void print_ratios(const float ratios[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%.6f\n", ratios[i]);
}
