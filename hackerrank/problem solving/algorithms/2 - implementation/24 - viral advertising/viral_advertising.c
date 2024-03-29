// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

#include <stdio.h>

int viral_advertising(const int days);

int main() {
    int days;
    scanf("%d", &days);
    printf("%d\n", viral_advertising(days));

    return 0;
}

    int viral_advertising(int days) {
        int shared = 5, liked = 0, cumulative = 0;

        while (days--) {
            liked = shared / 2;
            cumulative += liked;
            shared = liked * 3;
        }

        return cumulative;
    }
