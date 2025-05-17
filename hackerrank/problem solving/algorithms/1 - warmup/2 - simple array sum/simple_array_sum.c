// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <stdio.h>

int sum_stdin(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum_stdin(n));
    return 0;
}

int sum_stdin(int n)
{
    int sum = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    return sum;
}
