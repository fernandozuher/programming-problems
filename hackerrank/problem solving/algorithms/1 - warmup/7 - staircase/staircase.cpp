// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
// C++20

#include <iostream>

using namespace std;

void staircase(int n);

int main()
{
    int n;
    cin >> n;
    staircase(n);
    return 0;
}

void staircase(int n)
{
    for (int i = 1; i <= n; ++i)
        cout << string(n - i, ' ') << string(i, '#') << '\n';
}
