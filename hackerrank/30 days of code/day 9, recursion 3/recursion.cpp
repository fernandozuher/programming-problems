// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

#include <iostream>

using namespace std;

int factorial(int n)
{
    return n == 1 ? 1 : n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);

    return 0;
}
