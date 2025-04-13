// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n);

int main()
{
    int n_tests;
    cin >> n_tests;
    for (int n; n_tests-- && cin >> n;)
        cout << (is_prime(n) ? "Prime\n" : "Not prime\n");
    return 0;
}

bool is_prime(int n)
{
    if (n == 1)
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
