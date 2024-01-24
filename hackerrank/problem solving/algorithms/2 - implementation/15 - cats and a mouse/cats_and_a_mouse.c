// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read_int_array(const int n);
char* find_nearest_cat_or_not(const int* const cats_and_mouse_positions);
    char* get_string_result(const int cat_a_position_from_mouse, const int cat_b_position_from_mouse);
void free_array(char *array[], const int n);

int main()
{
    int n;
    scanf("%d", &n);

    char *nearest_cats_or_not[n];
    for (int i = 0, size_string = 8; i < n; ++i)
        nearest_cats_or_not[i] = (char*) calloc(size_string, sizeof(char));

    for (int i = 0, animals = 3; i < n; ++i) {
        int *positions = read_int_array(animals);
        nearest_cats_or_not[i] = find_nearest_cat_or_not(positions);
        free(positions);
    }

    for (int i = 0; i < n; puts(nearest_cats_or_not[i++]));

    free_array(nearest_cats_or_not, n);

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    char* find_nearest_cat_or_not(const int* const cats_and_mouse_positions)
    {
        int cat_a_position = cats_and_mouse_positions[0];
        int cat_b_position = cats_and_mouse_positions[1];
        int mouse_position = cats_and_mouse_positions[2];

        int cat_a_position_from_mouse = abs(cat_a_position - mouse_position);
        int cat_b_position_from_mouse = abs(cat_b_position - mouse_position);

        return get_string_result(cat_a_position_from_mouse, cat_b_position_from_mouse);
    }

        char* get_string_result(const int cat_a_position_from_mouse, const int cat_b_position_from_mouse)
        {
            char *result = NULL;

            if (cat_a_position_from_mouse != cat_b_position_from_mouse) {
                const int string_size = 6;
                result = (char*) calloc(string_size, sizeof(char));

                if (cat_a_position_from_mouse < cat_b_position_from_mouse)
                    strcpy(result, "Cat A");
                else
                    strcpy(result, "Cat B");
            }
            else {
                const int string_size = 8;
                result = (char*) calloc(string_size, sizeof(char));
                strcpy(result, "Mouse C");
            }

            return result;
        }

    void free_array(char *array[], const int n)
    {
        for (int i = 0; i < n; ++i)
            free(array[i]);
    }
