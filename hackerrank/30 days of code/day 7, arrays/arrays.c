// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    for (int i = n; i--;)
        printf("%d ", array[i]);

    return 0;
}
