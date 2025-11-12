// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// C23

#include <stdio.h>

int utopian_tree(int cycles);
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int cycles;
        scanf("%d", &cycles);
        printf("%d\n", utopian_tree(cycles));
    }
    return 0;
}

int utopian_tree(int cycles)
{
    int height = 1;
    for (int cycle = 1; cycle <= cycles; ++cycle)
        height = is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;
    return height;
}

bool is_cycle_happening_during_spring(int cycle)
{
    return cycle & 1;
}
