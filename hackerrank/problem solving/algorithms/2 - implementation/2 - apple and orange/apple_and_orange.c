// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} house_t;

typedef struct {
    int tree_location;
    int size;
    int *fruit_distances;
} fruit_tree_t;

void read_input(house_t *house, fruit_tree_t *apple_tree, fruit_tree_t *orange_tree);
int *read_numbers(int n);
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
    scanf("%d %d", &house->start, &house->end);
    scanf("%d %d", &apple_tree->tree_location, &orange_tree->tree_location);
    scanf("%d %d", &apple_tree->size, &orange_tree->size);
    apple_tree->fruit_distances = read_numbers(apple_tree->size);
    orange_tree->fruit_distances = read_numbers(orange_tree->size);
}

int *read_numbers(int n)
{
    auto arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    return arr;
}

// n: length of array fruit_tree.fruit_distances
// T: O(n)
// S: O(1) extra space
int count_fruits_on_house(const fruit_tree_t *fruit_tree, const house_t *house)
{
    int count = 0;
    for (int i = 0; i < fruit_tree->size; ++i) {
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
