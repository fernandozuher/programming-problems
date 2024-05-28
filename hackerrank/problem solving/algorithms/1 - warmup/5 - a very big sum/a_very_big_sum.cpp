// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <iostream>

using namespace std;

long a_very_big_sum(int n);

int main()
{
    int n;
    cin >> n;
    cout << a_very_big_sum(n);
    return 0;
}

    long a_very_big_sum(int n)
    {
        long sum{};
        for (long x; n-- && cin >> x; sum += x);
        return sum;
    }
