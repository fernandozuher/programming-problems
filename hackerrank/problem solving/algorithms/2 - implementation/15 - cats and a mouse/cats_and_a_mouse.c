// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

#include <math.h>
#include <stdio.h>
#include <string.h>

#define NUM_POSITIONS 3
#define RESULT_SIZE 10

void read_positions(int *arr);
void find_nearest_cat_or_not(const int positions[NUM_POSITIONS], char *out);

int main()
{
    int n;
    scanf("%d", &n);
    char out[RESULT_SIZE];

    for (int i = 0, positions[NUM_POSITIONS]; i < n; ++i) {
        read_positions(positions);
        find_nearest_cat_or_not(positions, out);
        puts(out);
    }

    return 0;
}

void read_positions(int *arr)
{
    for (int i = 0; i < NUM_POSITIONS; ++i)
        scanf("%d", &arr[i]);
}

// T: O(1)
// S: O(1) extra space
void find_nearest_cat_or_not(const int positions[NUM_POSITIONS], char *out)
{
    int cat_a = positions[0];
    int cat_b = positions[1];
    int mouse = positions[2];
    int cat_a_from_mouse = abs(cat_a - mouse);
    int cat_b_from_mouse = abs(cat_b - mouse);

    if (cat_a_from_mouse < cat_b_from_mouse)
        strcpy(out, "Cat A");
    else if (cat_a_from_mouse > cat_b_from_mouse)
        strcpy(out, "Cat B");
    else
        strcpy(out, "Mouse C");
}
