// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
// C++23

import std;
using namespace std;

void staircase(int n);

int main()
{
    int n;
    cin >> n;
    staircase(n);
    return 0;
}

// T: O(n^2)
// S: O(n) extra space
void staircase(int n)
{
    for (int i{ 1 }; i <= n; ++i)
        println("{}{}", string(n - i, ' '), string(i, '#'));
}
