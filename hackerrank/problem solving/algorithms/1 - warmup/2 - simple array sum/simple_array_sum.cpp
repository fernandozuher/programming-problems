// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <iostream>

using namespace std;

int simple_array_sum(int n);

int main()
{
    int n;
    cin >> n;
    cout << simple_array_sum(n);

    return 0;
}

    int simple_array_sum(int n)
    {
        int sum{};
        for (int x; n-- && cin >> x; sum += x);
        return sum;
    }
