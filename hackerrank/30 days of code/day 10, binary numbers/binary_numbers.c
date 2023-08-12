// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int max_ones = 0, ones = 0;
    for (; n > 0; n /= 2) {
        if (n % 2)
            ++ones;
        else {
            if (ones > max_ones)
                max_ones = ones;
            ones = 0;
        }
    }

    max_ones = max_ones > ones ? max_ones : ones;
    printf("%d\n", max_ones);

    return 0;
}
