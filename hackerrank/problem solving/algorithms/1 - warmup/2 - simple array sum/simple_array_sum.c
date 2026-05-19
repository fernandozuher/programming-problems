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

// T: O(n)
// S: O(1) extra space
int sum_stdin(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    return sum;
}
