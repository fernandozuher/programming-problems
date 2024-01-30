// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_lines(const int n);
int* utopian_tree(const int* const test_cases, const int n);
    int calculate_height(const int cycles);
        bool is_cycle_happening_during_spring(const int cycle);
void print_array(const int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *test_cases = read_lines(n);

    int *trees_heights = utopian_tree(test_cases, n);
    print_array(trees_heights, n);

    free(test_cases);
    free(trees_heights);
    test_cases = trees_heights = NULL;

    return 0;
}

    int* read_lines(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int* utopian_tree(const int* const test_cases, const int n)
    {
        int *trees_heights = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            trees_heights[i] = calculate_height(test_cases[i]);
        return trees_heights;
    }

        int calculate_height(const int cycles)
        {
            int height = 1;
            for (int cycle = 1; cycle <= cycles; ++cycle)
                height = is_cycle_happening_during_spring(cycle) ? height * 2 : height + 1;
            return height;
        }

            bool is_cycle_happening_during_spring(const int cycle)
            {
                return cycle & 1;
            }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d\n", array[i]);
    }
