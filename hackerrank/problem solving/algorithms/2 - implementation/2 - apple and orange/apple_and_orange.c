// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int starting_sam, ending_sam;
    int apple_tree_location, orange_tree_location;
    int n_apples, n_oranges;
    int *apples_distance_from_tree;
    int *oranges_distance_from_tree;
} apple_and_orange;

apple_and_orange read_input();
    int *read_int_array(const int n);
void count_apples_and_oranges(const apple_and_orange *input);
    int count_fruits_on_house(const apple_and_orange *input, const char *fruit);
        int **filter_input(const apple_and_orange *input, const char *fruit);

int main()
{
    apple_and_orange input = read_input();
    count_apples_and_oranges(&input);
    return 0;
}

    apple_and_orange read_input()
    {
        apple_and_orange input;
        scanf("%d %d", &input.starting_sam, &input.ending_sam);
        scanf("%d %d", &input.apple_tree_location, &input.orange_tree_location);
        scanf("%d %d", &input.n_apples, &input.n_oranges);
        input.apples_distance_from_tree = read_int_array(input.n_apples);
        input.oranges_distance_from_tree = read_int_array(input.n_oranges);
        return input;
    }

        int *read_int_array(const int n)
        {
            auto array = (int*) malloc(n * sizeof(int));
            for (int i = 0; i < n; ++i)
                scanf("%d", &array[i]);
            return array;
        }

    void count_apples_and_oranges(const apple_and_orange *const input)
    {
        int apples_on_house = count_fruits_on_house(input, "apple");
        int oranges_on_house = count_fruits_on_house(input, "orange");
        printf("%d\n%d", apples_on_house, oranges_on_house);
    }

        int count_fruits_on_house(const apple_and_orange *const input, const char *const fruit)
        {
            int **filtered_input = filter_input(input, fruit);
            int tree_location = *filtered_input[0];
            int fruit_count = *filtered_input[1];
            int *fruits = filtered_input[2];

            int fruits_on_house = 0;
            for (int i = 0; i < fruit_count; ++i) {
                int location = tree_location + fruits[i];
                if (location >= input->starting_sam && location <= input->ending_sam)
                    ++fruits_on_house;
            }

            free(filtered_input[0]);
            free(filtered_input[1]);
            free(filtered_input[2]);
            free(filtered_input);

            return fruits_on_house;
        }

            int **filter_input(const apple_and_orange *const input, const char *const fruit)
            {
                constexpr int data = 3;
                auto filtered_input = (int**) malloc(data * sizeof(int*));
                for (int i = 0; i < data - 1; ++i)
                    filtered_input[i] = (int*) malloc(sizeof(int));

                if (!strcmp(fruit, "apple")) {
                    *filtered_input[0] = input->apple_tree_location;
                    *filtered_input[1] = input->n_apples;
                    filtered_input[2] = input->apples_distance_from_tree;
                }
                else {
                    *filtered_input[0] = input->orange_tree_location;
                    *filtered_input[1] = input->n_oranges;
                    filtered_input[2] = input->oranges_distance_from_tree;
                }

                return filtered_input;
            }
