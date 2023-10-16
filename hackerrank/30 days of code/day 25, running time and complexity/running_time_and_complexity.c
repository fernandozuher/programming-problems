// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int number; n-- && scanf("%d", &number);) {
        if (number == 1) {
            puts("Not prime");
            continue;
        }

        int i = 2, limit = sqrt(number);
        for (; i <= limit; ++i)
            if (!(number % i)) {
                puts("Not prime");
                break;
            }

        if (i > limit)
            puts("Prime");
    }

    return 0;
}
