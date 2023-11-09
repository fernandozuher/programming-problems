// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

#include <iostream>

using namespace std;

int solve_me_first(const int a, const int b);

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << solve_me_first(num1, num2);
    return 0;
}

    int solve_me_first(const int a, const int b)
    {
        return a + b;
    }
