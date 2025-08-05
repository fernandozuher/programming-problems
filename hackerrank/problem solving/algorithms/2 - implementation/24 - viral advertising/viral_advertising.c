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

int viral_advertising(int days)
{
    int cumulative = 0;

    for (int shared = 5; days > 0; --days) {
        int liked = shared / 2;
        cumulative += liked;
        shared = liked * 3;
    }

    return cumulative;
}
