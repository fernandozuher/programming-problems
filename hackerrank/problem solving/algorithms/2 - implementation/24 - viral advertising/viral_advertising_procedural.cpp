// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

#include <iostream>

using namespace std;

int viral_advertising(const int days);


int main() {
	int days;
	cin >> days;

	const int cumulative_likes {viral_advertising(days)};
	cout << cumulative_likes << "\n";

	return 0;
}

	int viral_advertising(const int days) {
		int shared {5}, liked {0}, cumulative {0};

		for (int _ {0}; _ < days; _++) {
			liked = {shared / 2};
			cumulative += liked;
			shared = {liked * 3};
		}

		return cumulative;
	}
