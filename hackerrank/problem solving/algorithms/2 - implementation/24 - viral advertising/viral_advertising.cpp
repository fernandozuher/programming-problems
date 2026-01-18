// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int viral_advertising(int days);

int main()
{
    int days;
    cin >> days;
    cout << viral_advertising(days);
    return 0;
}

// n: days
// T: O(n)
// S: O(1) extra space
int viral_advertising(int days)
{
    int shared{ 5 };
    return ranges::fold_left(views::iota(0, days), 0, [&shared](auto cumulative, auto) {
        int liked{ shared / 2 };
        shared = liked * 3;
        return cumulative + liked;
        });
}
