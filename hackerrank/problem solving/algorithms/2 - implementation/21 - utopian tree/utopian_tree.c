// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_OF_INPUT_LINE_ARRAY 1024

int* read_n_test_cases_cycles(const int n_test_cases);
int read_line_as_int();
void* free_pointer_and_return_null(void* pointer);
int* utopian_tree(const int *n_test_cases_cycles, const int n_test_cases);
int calculate_height(const int cycles);
bool is_cycle_happening_during_spring(const int cycle);
void print_trees_heights(const int *result, const int n);


int main() {
    int n_test_cases = read_line_as_int();
    int *n_test_cases_cycles = read_n_test_cases_cycles(n_test_cases);

    int *trees_heights = utopian_tree(n_test_cases_cycles, n_test_cases);
    n_test_cases_cycles = free_pointer_and_return_null(n_test_cases_cycles);

    print_trees_heights(trees_heights, n_test_cases);
    trees_heights = free_pointer_and_return_null(trees_heights);

    return 0;
}

int* read_n_test_cases_cycles(const int n_test_cases) {
    int *n_test_cases_cycles = (int*) calloc(n_test_cases, sizeof(int));

    for (int i = 0; i < n_test_cases; i++)
        n_test_cases_cycles[i] = read_line_as_int();

    return n_test_cases_cycles;
}

int read_line_as_int() {
    int n;
    char white_space_or_eof;
    scanf("%d%c", &n, &white_space_or_eof);
    return n;
}

void* free_pointer_and_return_null(void* pointer) {
    free(pointer);
    return NULL;
}

int* utopian_tree(const int *n_test_cases_cycles, const int n_test_cases) {
    int *trees_heights = (int*) calloc(n_test_cases, sizeof(int));

    for (int i = 0; i < n_test_cases; i++)
        trees_heights[i] = calculate_height(n_test_cases_cycles[i]);

    return trees_heights;
}

int calculate_height(const int cycles) {
    int height = 1;

    for (int cicle = 1; i <= cycles; cicle++)
        height = is_cycle_happening_during_spring(cicle) ? height * 2 : height + 1;

    return height;
}

bool is_cycle_happening_during_spring(const int cycle) {
    return cycle & 1;
}

void print_trees_heights(const int *trees_heights, const int n) {
    for (int i = 0; i < n; i++)
        printf("%d\n", trees_heights[i]);
}