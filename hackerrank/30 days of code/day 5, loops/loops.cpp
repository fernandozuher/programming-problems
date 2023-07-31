// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i {1}; i <= 10; ++i)
        cout << n << " x " << i << " = " << n*i << '\n';

    return 0;
}
