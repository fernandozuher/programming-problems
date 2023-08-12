// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_ones {0}, ones {0};
    for (; n > 0; n /= 2) {
        if (n % 2)
            ++ones;
        else {
            max_ones = {max(max_ones, ones)};
            ones = {0};
        }
    }

    max_ones = {max(max_ones, ones)};
    cout << max_ones;

    return 0;
}
