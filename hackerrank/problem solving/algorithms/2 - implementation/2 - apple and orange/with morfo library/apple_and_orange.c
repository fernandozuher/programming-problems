// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

typedef struct {
    int start, end;
} house_t;

typedef struct {
    int tree_location;
    size_t size;
    int *fruit_distances;
} fruit_tree_t;

void read_input(house_t *house, fruit_tree_t *apple_tree, fruit_tree_t *orange_tree);
int count_fruits_on_house(const fruit_tree_t *fruit_tree, const house_t *house);
bool is_fruit_on_house(const house_t *house, int position);

int main()
{
    house_t house;
    fruit_tree_t apple_tree, orange_tree;
    read_input(&house, &apple_tree, &orange_tree);

    printf("%d\n", count_fruits_on_house(&apple_tree, &house));
    printf("%d\n", count_fruits_on_house(&orange_tree, &house));

    free(apple_tree.fruit_distances);
    free(orange_tree.fruit_distances);

    return 0;
}

void read_input(house_t *house, fruit_tree_t *apple_tree, fruit_tree_t *orange_tree)
{
    house->start = morfo_read(int);
    house->end = morfo_read(int);
    apple_tree->tree_location = morfo_read(int);
    orange_tree->tree_location = morfo_read(int);
    apple_tree->size = morfo_read(int);
    orange_tree->size = morfo_read(int);
    apple_tree->fruit_distances = morfo_read_n_alloc(int, apple_tree->size);
    orange_tree->fruit_distances = morfo_read_n_alloc(int, orange_tree->size);
}

// n: length of fruit_tree.fruit_distances
// T: O(n)
// S: O(1) extra space
int count_fruits_on_house(const fruit_tree_t *fruit_tree, const house_t *house)
{
    int count = 0;
    for (size_t i = 0; i < fruit_tree->size; ++i) {
        int position = fruit_tree->tree_location + fruit_tree->fruit_distances[i];
        if (is_fruit_on_house(house, position))
            ++count;
    }
    return count;
}

bool is_fruit_on_house(const house_t *house, int position)
{
    return house->start <= position && position <= house->end;
}
