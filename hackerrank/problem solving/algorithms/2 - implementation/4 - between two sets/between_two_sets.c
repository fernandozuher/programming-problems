// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *numbers, int n);
int between_two_sets(const int *a, int n1, const int *b, int n2);
int lcm_array(const int *arr, int n);
int lcm(int a, int b);
int gcd_array(const int *arr, int n);
int gcd(int a, int b);

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int a[n1], b[n2];
    read_numbers(a, n1);
    read_numbers(b, n2);
    printf("%d\n", between_two_sets(a, n1, b, n2));
    return 0;
}

void read_numbers(int *numbers, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int between_two_sets(const int *a, int n1, const int *b, int n2)
{
    int lcm_of_a = lcm_array(a, n1);
    int gcd_of_b = gcd_array(b, n2);

    int count = 0;
    for (int i = lcm_of_a; i <= gcd_of_b; i += lcm_of_a)
        if (gcd_of_b % i == 0)
            ++count;
    return count;
}

int lcm_array(const int *arr, int n)
{
    int res = arr[0];
    for (int i = 1; i < n; ++i)
        res = lcm(res, arr[i]);
    return res;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int gcd_array(const int *arr, int n)
{
    int res = arr[0];
    for (int i = 1; i < n; ++i)
        res = gcd(res, arr[i]);
    return res;
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
