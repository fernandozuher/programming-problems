// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int diagonal_difference(int n);

int main()
{
    int n = morfo::read();
    println("{}", diagonal_difference(n));
    return 0;
}

// T: O(n^2)
// S: O(n) extra space
int diagonal_difference(int n)
{
    int primary_sum{}, secondary_sum{};

    for (int i{}; i < n; ++i) {
        vector<int> arr = morfo::readln();
        primary_sum += arr.at(i);
        secondary_sum += arr.at(n - i - 1);
    }

    return abs(primary_sum - secondary_sum);
}
