// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int numbers[], int n);
int lcm_array(const int numbers[], int n);
int lcm(int a, int b);
int gcd_array(const int numbers[], int n);
int gcd(int a, int b);

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int numbers1[n1], numbers2[n2];
    read_numbers(numbers1, n1);
    read_numbers(numbers2, n2);

    int lcm_of_numbers1 = lcm_array(numbers1, n1);
    int gcd_of_numbers2 = gcd_array(numbers2, n2);

    int count = 0;
    for (int i = lcm_of_numbers1; i <= gcd_of_numbers2; i += lcm_of_numbers1)
        if (gcd_of_numbers2 % i == 0)
            ++count;

    printf("%d\n", count);

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
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
