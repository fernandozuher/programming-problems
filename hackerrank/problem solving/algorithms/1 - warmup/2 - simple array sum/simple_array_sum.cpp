// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <iostream>

using namespace std;

int sum_stdin(int n);

int main()
{
    int n;
    cin >> n;
    cout << sum_stdin(n);
    return 0;
}

int sum_stdin(int n)
{
    int sum{};
    while (n--) {
        int x;
        cin >> x;
        sum += x;
    }
    return sum;
}
