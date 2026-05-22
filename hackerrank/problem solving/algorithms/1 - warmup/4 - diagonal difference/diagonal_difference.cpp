// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int diagonal_difference(int n);
vector<int> read_numbers(int n);

int main()
{
    int n;
    cin >> n;
    println("{}", diagonal_difference(n));
    return 0;
}

// T: O(n^2)
// S: O(n) extra space
int diagonal_difference(int n)
{
    int primary_sum{}, secondary_sum{};

    for (int i{}; i < n; ++i) {
        vector arr{ read_numbers(n) };
        primary_sum += arr.at(i);
        secondary_sum += arr.at(n - i - 1);
    }

    return abs(primary_sum - secondary_sum);
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}
