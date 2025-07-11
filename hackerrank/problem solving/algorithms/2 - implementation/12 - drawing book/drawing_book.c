// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

#include <stdio.h>

int page_count(int n, int page);
int min(int a, int b);

int main()
{
    int n, page;
    scanf("%d %d", &n, &page);
    printf("%d\n", page_count(n, page));
    return 0;
}

int page_count(int n, int page)
{
    int from_front = page / 2;
    int from_back = n / 2 - from_front;
    return min(from_front, from_back);
}

int min(int a, int b)
{
    return a < b ? a : b;
}
