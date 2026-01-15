// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// C23

#include <stdio.h>

void generate_heights_utopian_tree(int *heights, int n);
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    scanf("%d", &n);
    constexpr int max_cycles = 60;
    int utopian_tree[max_cycles + 1];
    generate_heights_utopian_tree(utopian_tree, max_cycles + 1);

    for (int i = 0; i < n; ++i) {
        int cycles;
        scanf("%d", &cycles);
        printf("%d\n", utopian_tree[cycles]);
    }

    return 0;
}

// k: length of output array heights = 61
// T: O(k) = O(61) = O(1). S: O(61) = O(1) extra space.
void generate_heights_utopian_tree(int *heights, int n)
{
    for (int cycle = 0, height = 0; cycle < n; ++cycle)
        heights[cycle] = height += is_cycle_happening_during_spring(cycle) ? height : 1;
}

bool is_cycle_happening_during_spring(int cycle)
{
    return cycle & 1;
}
