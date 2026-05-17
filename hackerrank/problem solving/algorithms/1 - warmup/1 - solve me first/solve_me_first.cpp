// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int solve_me_first(int n1, int n2);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << solve_me_first(n1, n2);
    return 0;
}

// T: O(1)
// S: O(1) extra space
int solve_me_first(int n1, int n2)
{
    return n1 + n2;
}
