// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

#include <iostream>

using namespace std;

int viral_advertising(const int days);

int main() {
    int days;
    cin >> days;
    cout << viral_advertising(days) << '\n';

    return 0;
}

    int viral_advertising(int days) {
        int shared{5}, liked{}, cumulative{};

        while (days--) {
            liked = shared / 2;
            cumulative += liked;
            shared = liked * 3;
        }

        return cumulative;
    }
