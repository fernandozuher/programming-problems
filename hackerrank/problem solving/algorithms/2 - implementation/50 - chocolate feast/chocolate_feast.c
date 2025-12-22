// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

#include <stdio.h>

int how_many_chocolates_can_be_eaten(int money, int cost, int wrappers_needed);

int main()
{
    unsigned n;
    scanf("%u", &n);

    while (n--) {
        int money, cost, wrappers_needed;
        scanf("%d %d %d", &money, &cost, &wrappers_needed);
        printf("%d\n", how_many_chocolates_can_be_eaten(money, cost, wrappers_needed));
    }

    return 0;
}

int how_many_chocolates_can_be_eaten(int money, int cost, int wrappers_needed)
{
    int chocolates = money / cost;

    for (int wrappers = chocolates; wrappers >= wrappers_needed;) {
        int free_chocolates = wrappers / wrappers_needed;
        wrappers = wrappers % wrappers_needed + free_chocolates;
        chocolates += free_chocolates;
    }

    return chocolates;
}
