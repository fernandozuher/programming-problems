// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true
// C23

#include <math.h>
#include <stdio.h>

void process_prime_tests(int n_tests);
bool is_prime(int n);

int main()
{
    int n_tests;
    scanf("%d", &n_tests);
    process_prime_tests(n_tests);
    return 0;
}

void process_prime_tests(int n_tests)
{
    for (int n; n_tests-- && scanf("%d", &n);)
        puts(is_prime(n) ? "Prime" : "Not prime");
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int divisor = 3, limit = sqrt(n); divisor <= limit; divisor += 2)
        if (n % divisor == 0)
            return false;
    return true;
}
