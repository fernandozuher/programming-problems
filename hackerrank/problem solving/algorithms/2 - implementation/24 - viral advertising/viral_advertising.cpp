// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>

using namespace std;

int viral_advertising(int days);

int main()
{
    int days;
    cin >> days;
    cout << viral_advertising(days) << '\n';
    return 0;
}

// n = days = length of the iteration
// T = O(n)
// S = O(1)
int viral_advertising(int days)
{
    int shared{5};
    return ranges::fold_left(views::iota(0, days), 0, [&shared](auto cumulative, auto) {
        int liked{shared / 2};
        shared = liked * 3;
        return cumulative + liked;
    });
}
