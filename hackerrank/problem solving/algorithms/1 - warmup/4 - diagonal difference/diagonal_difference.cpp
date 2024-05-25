// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <algorithm>
#include <iostream>

using namespace std;

int diagonal_difference(int n);

int main()
{
    int n;
    cin >> n;
    cout << diagonal_difference(n);

    return 0;
}

    int diagonal_difference(const int n)
    {
        int primary_diagonal{}, secondary_diagonal{};

        for (int i = 0; i < n; ++i)
            for (int j = 0, x; j < n && cin >> x; ++j) {
                if (i == j)
                    primary_diagonal += x;
                if (j == n - i - 1)
                    secondary_diagonal += x;
            }

        return abs(primary_diagonal - secondary_diagonal);
    }
