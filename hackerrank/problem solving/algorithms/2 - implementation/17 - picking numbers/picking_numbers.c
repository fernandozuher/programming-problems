// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C23

#include <stdio.h>

#define MAX_VALUE 100

void read_numbers_into_map(int counter[], int n);
int picking_numbers(const int counter[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int counter[MAX_VALUE] = {0}; // C23
    read_numbers_into_map(counter, n);
    printf("%d\n", picking_numbers(counter, n));
    return 0;
}

void read_numbers_into_map(int counter[], int n)
{
    for (int i = 0, num; i < n; ++i) {
        scanf("%d", &num);
        ++counter[num];
    }
}

int picking_numbers(const int counter[], int n)
{
    int max_len = 0;
    for (int i = 0, n2 = MAX_VALUE - 1; i < n2; ++i) {
        if (!counter[i])
            continue;
        int current = counter[i] + counter[i + 1];
        max_len = max_len >= current ? max_len : current;
    }
    return max_len;
}
