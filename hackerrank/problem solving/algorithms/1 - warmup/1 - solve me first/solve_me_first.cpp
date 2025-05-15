// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

#include <iostream>

using namespace std;

int solve_me_first(int n1, int n2);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << solve_me_first(n1, n2);
    return 0;
}

int solve_me_first(int n1, int n2)
{
    return n1 + n2;
}
