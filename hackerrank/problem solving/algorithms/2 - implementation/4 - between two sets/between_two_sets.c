// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, size_t n);
int between_two_sets(const int *a, size_t n1, const int *b, size_t n2);
int reduce(const int *arr, size_t n, int func(int a, int b));
int lcm(int a, int b);
int gcd(int a, int b);

int main()
{
    size_t n1, n2;
    scanf("%zu %zu", &n1, &n2);
    int a[n1], b[n2];
    read_numbers(a, n1);
    read_numbers(b, n2);
    printf("%d\n", between_two_sets(a, n1, b, n2));
    return 0;
}

void read_numbers(int *arr, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n1, n2: length of a, b
// k: number of multiples tested = gcd_of_b / lcm_of_a
// T: O(n1 + n2 + k)
// S: O(1) extra space
int between_two_sets(const int *a, size_t n1, const int *b, size_t n2)
{
    int lcm_of_a = reduce(a, n1, lcm);
    int gcd_of_b = reduce(b, n2, gcd);

    int count = 0;
    for (int i = lcm_of_a; i <= gcd_of_b; i += lcm_of_a)
        if (gcd_of_b % i == 0)
            ++count;
    return count;
}

int reduce(const int *arr, size_t n, int func(int a, int b))
{
    int acc = arr[0];
    for (size_t i = 1; i < n; ++i)
        acc = func(acc, arr[i]);
    return acc;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int gcd(int a, int b)
{
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
