// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C23

#include <stdio.h>

#define MAX_VALUE 100

void read_numbers(int numbers[], int n);
int picking_numbers(const int numbers[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int numbers[n];
    read_numbers(numbers, n);
    printf("%d\n", picking_numbers(numbers, n));
    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int picking_numbers(const int numbers[], int n)
{
    int counter[MAX_VALUE] = {0}; // C23
    for (int i = 0; i < n; ++i)
        ++counter[numbers[i]];

    int max_len = 0;
    for (int i = 0, n2 = MAX_VALUE - 1; i < n2; ++i) {
        if (!counter[i])
            continue;
        int current = counter[i] + counter[i + 1];
        max_len = max_len >= current ? max_len : current;
    }

    return max_len;
}
