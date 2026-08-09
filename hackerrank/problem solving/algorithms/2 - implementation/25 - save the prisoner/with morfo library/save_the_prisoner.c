// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <stdio.h>
#include "morfo/io.h"

int save_the_prisoner(int prisoners, int sweets, int start_chair);

int main()
{
    int n = morfo_read(int);

    for (int i = 0; i < n; ++i) {
        int prisoners = morfo_read(int);
        int sweets = morfo_read(int);
        int start_chair = morfo_read(int);
        printf("%d\n", save_the_prisoner(prisoners, sweets, start_chair));
    }
}

// T: O(1)
// S: O(1) extra space
int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
