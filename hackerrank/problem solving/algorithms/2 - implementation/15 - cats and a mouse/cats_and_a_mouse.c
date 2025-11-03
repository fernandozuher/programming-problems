// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_POSITIONS 3
#define RESULT_SIZE 10

void read_numbers(int numbers[], int n);
char *find_nearest_cat_or_not(const int positions[NUM_POSITIONS]);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, positions[NUM_POSITIONS]; i < n; ++i) {
        read_numbers(positions, 3);
        puts(find_nearest_cat_or_not(positions));
    }

    return 0;
}

void read_numbers(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

char *find_nearest_cat_or_not(const int positions[NUM_POSITIONS])
{
    int cat_a = positions[0];
    int cat_b = positions[1];
    int mouse = positions[2];
    int cat_a_from_mouse = abs(cat_a - mouse);
    int cat_b_from_mouse = abs(cat_b - mouse);

    auto res = (char *) malloc(RESULT_SIZE * sizeof(char));

    if (cat_a_from_mouse < cat_b_from_mouse)
        strcpy(res, "Cat A");
    else if (cat_a_from_mouse > cat_b_from_mouse)
        strcpy(res, "Cat B");
    else
        strcpy(res, "Mouse C");

    return res;
}
