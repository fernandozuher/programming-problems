// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int sum_stdin(int n);

int main()
{
    int n;
    cin >> n;
    cout << sum_stdin(n);
    return 0;
}

// T: O(n)
// S: O(1) extra space
int sum_stdin(int n)
{
    int sum{};
    for (int i{}; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    return sum;
}
