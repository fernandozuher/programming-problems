// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true
// From C++20 onwards

#include <iostream>
#include <ranges>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (const int i: views::iota(1, 11))
        cout << n << " x " << i << " = " << n * i << '\n';
    return 0;
}
