// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <stdio.h>

int save_the_prisoner(int prisoners, int sweets, int start_chair);

// n = test cases
// T = O(n)
// S = O(1)
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int prisoners, sweets, start_chair;
        scanf("%d %d %d", &prisoners, &sweets, &start_chair);
        printf("%d\n", save_the_prisoner(prisoners, sweets, start_chair));
    }
}

// T = O(1)
// S = O(1)
int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
