// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int numbers[], int n);
int between_two_sets(const int a[], int n_a, const int b[], int n_b);
int lcm_array(const int numbers[], int n);
int lcm(int a, int b);
int gcd_array(const int numbers[], int n);
int gcd(int a, int b);

int main()
{
    int n_a, n_b;
    scanf("%d %d", &n_a, &n_b);
    int numbers_a[n_a], numbers_b[n_b];
    read_numbers(numbers_a, n_a);
    read_numbers(numbers_b, n_b);
    printf("%d\n", between_two_sets(numbers_a, n_a, numbers_b, n_b));
    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int between_two_sets(const int a[], int n_a, const int b[], int n_b)
{
    int lcm_of_a = lcm_array(a, n_a);
    int gcd_of_b = gcd_array(b, n_b);

    int count = 0;
    for (int i = lcm_of_a; i <= gcd_of_b; i += lcm_of_a)
        if (gcd_of_b % i == 0)
            ++count;
    return count;
}

int lcm_array(const int numbers[], int n)
{
    int result = numbers[0];
    for (int i = 1; i < n; ++i)
        result = lcm(result, numbers[i]);
    return result;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int gcd_array(const int numbers[], int n)
{
    int result = numbers[0];
    for (int i = 1; i < n; ++i)
        result = gcd(result, numbers[i]);
    return result;
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
