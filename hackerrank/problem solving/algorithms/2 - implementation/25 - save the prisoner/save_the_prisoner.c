// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <stdio.h>

int save_the_prisoner(int prisoners, int sweets, int start_chair);

int main()
{
    int n;
    scanf("%d", &n);
    int results[n];

    for (int i = 0; i < n; ++i) {
        int prisoners, sweets, start_chair;
        scanf("%d %d %d", &prisoners, &sweets, &start_chair);
        results[i] = save_the_prisoner(prisoners, sweets, start_chair);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", results[i]);
}

int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
