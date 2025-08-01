// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
void utopian_tree(const int test_cases[], int tree_heights[], int n);
int calculate_height(int cycles);
bool is_cycle_happening_during_spring(int cycle);

int main()
{
    int n;
    scanf("%d", &n);
    int test_cases[n];
    read_numbers(test_cases, n);

    int trees_heights[n];
    utopian_tree(test_cases, trees_heights, n);

    for (int i = 0; i < n; ++i)
        printf("%d\n", trees_heights[i]);

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

void utopian_tree(const int test_cases[], int tree_heights[], int n)
{
    for (int i = 0; i < n; i++)
        tree_heights[i] = calculate_height(test_cases[i]);
}

int calculate_height(int cycles)
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
