// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

#include <iostream>
using namespace std;

void staircase(const int n);

int main()
{
    int n;
    cin >> n;
    staircase(n);
    return 0;
}

    void staircase(const int n)
    {
        for (int i {1}; i <= n; ++i) {
            for (int j {}; j < n - i; ++j)
                cout << ' ';
            for (int k {}; k < i; ++k)
                cout << '#';
            cout << '\n';
        }
    }
