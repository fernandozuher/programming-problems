// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

#include <iostream>

using namespace std;

int bitwise_and(int n, int k);

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n, k;
        cin >> n >> k;
        cout << bitwise_and(n, k) << '\n';
    }
    return 0;
}

int bitwise_and(int n, int k)
{
    if ((k - 1 | k) <= n)
        return k - 1;
    return k - 2;
}
