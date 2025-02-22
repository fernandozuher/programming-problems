// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}

int factorial(const int n)
{
    return n == 1 ? 1 : n * factorial(n - 1);
}
