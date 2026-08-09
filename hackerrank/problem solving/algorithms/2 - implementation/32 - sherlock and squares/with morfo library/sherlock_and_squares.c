// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <math.h>
#include <stdio.h>
#include "morfo/io.h"

int squares(int start_num, int end_num);

int main()
{
    int n = morfo_read(int);
    for (int i = 0; i < n; ++i) {
        int a = morfo_read(int);
        int b = morfo_read(int);
        printf("%d\n", squares(a, b));
    }
}

// T: O(1)
// S: O(1) extra space
int squares(int start_num, int end_num)
{
    int max_square = floor(sqrt(end_num));
    int min_square = ceil(sqrt(start_num));
    return max_square - min_square + 1;
}
