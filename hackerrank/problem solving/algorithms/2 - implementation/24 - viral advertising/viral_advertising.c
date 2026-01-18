// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

#include <stdio.h>

int viral_advertising(int days);

int main()
{
    int days;
    scanf("%d", &days);
    printf("%d\n", viral_advertising(days));
    return 0;
}

// n: days
// T: O(n)
// S: O(1) extra space
int viral_advertising(int days)
{
    int cumulative = 0;
    for (int shared = 5; days > 0; --days) {
        int liked = shared / 2;
        shared = liked * 3;
        cumulative += liked;
    }
    return cumulative;
}
