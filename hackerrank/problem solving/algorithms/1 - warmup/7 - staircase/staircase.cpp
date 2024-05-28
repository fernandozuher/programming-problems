// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
// From C++20

#include <iostream>
#include <ranges>
using namespace std;

void staircase(int n);

int main()
{
    int n;
    cin >> n;
    staircase(n);
    return 0;
}

    void staircase(const int n)
    {
        for (int i : views::iota(1, n + 1)) {
            for ([[maybe_unused]] int j : views::iota(0, n - i))
                cout << ' ';
            for ([[maybe_unused]] int k : views::iota(0, i))
                cout << '#';
            cout << '\n';
        }
    }
