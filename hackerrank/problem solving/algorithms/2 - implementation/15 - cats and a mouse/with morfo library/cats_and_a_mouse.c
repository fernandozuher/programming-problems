// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morfo/io.h"

void find_nearest_cat_or_not(const int *positions, char *out);

int main()
{
    int n = morfo_read(int);

    constexpr size_t n_positions = 3;
    int positions[n_positions];
    constexpr size_t out_size = 10;
    char out[out_size];

    for (int i = 0; i < n; ++i) {
        morfo_read_n(positions, n_positions);
        find_nearest_cat_or_not(positions, out);
        puts(out);
    }

    return 0;
}

// T: O(1)
// S: O(1) extra space
void find_nearest_cat_or_not(const int *positions, char *out)
{
    int cat_a = positions[0], cat_b = positions[1], mouse = positions[2];
    int cat_a_from_mouse = abs(cat_a - mouse);
    int cat_b_from_mouse = abs(cat_b - mouse);

    if (cat_a_from_mouse < cat_b_from_mouse)
        strcpy(out, "Cat A");
    else if (cat_a_from_mouse > cat_b_from_mouse)
        strcpy(out, "Cat B");
    else
        strcpy(out, "Mouse C");
}
