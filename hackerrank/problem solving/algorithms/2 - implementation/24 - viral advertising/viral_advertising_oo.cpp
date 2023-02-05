// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

#include <iostream>

using namespace std;


class Viral_Advertising {

private:
    int _days;
    int _cumulative_likes;

    void _viral_advertising() {
        int shared {5}, liked {0};

        for (int _ {0}; _ < _days; _++) {
            liked = {shared / 2};
            _cumulative_likes += liked;
            shared = {liked * 3};
        }
    }

public:
    Viral_Advertising(int days): _days{days} {
        _cumulative_likes = {0};
        _viral_advertising();
        print_cumulative_likes();
    }

        void print_cumulative_likes() const {
            cout << _cumulative_likes << "\n";
        }
};

int main() {
    int days;
    cin >> days;
    const Viral_Advertising cumulative_likes(days);

    return 0;
}
