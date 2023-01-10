// Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read_line_as_int_array(const int n);
int** read_cats_and_mouse_positions_lines(const int n);
void cat_and_mouse(int **cats_and_mouse_positions_lines, const int n);
    char* find_nearest_cat_or_not(const int *cats_and_mouse_positions);
        char* get_string_result(const int cat_a_position_difference, const int cat_b_position_difference);


int main() {
    const int *input_line = read_line_as_int_array(1);
    const int n = input_line[0];

    int **input_lines = read_cats_and_mouse_positions_lines(n);
    cat_and_mouse(input_lines, n);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *input_line = (int*) calloc(n, sizeof(int));

        for (unsigned i = 0; i < n; i++)
            scanf("%d", &input_line[i]);

        return input_line;
    }

    int** read_cats_and_mouse_positions_lines(const int n) {
        int **input_lines = (int**) calloc(n, sizeof(int*));

        for (unsigned i = 0; i < n; i++)
            input_lines[i] = read_line_as_int_array(3);

        return input_lines;
    }

    void cat_and_mouse(int **cats_and_mouse_positions_lines, const int n) {
        for (unsigned i = 0; i < n; i++) {
            char* result = find_nearest_cat_or_not(cats_and_mouse_positions_lines[i]);

            printf("%s\n", result);

            free(result);
        }
        free(cats_and_mouse_positions_lines);
    }

        char* find_nearest_cat_or_not(const int *cats_and_mouse_positions) {
            const int cat_a_position = cats_and_mouse_positions[0];
            const int cat_b_position = cats_and_mouse_positions[1];
            const int mouse_position = cats_and_mouse_positions[2];

            free(cats_and_mouse_positions);

            const int cat_a_position_difference = abs(cat_a_position - mouse_position);
            const int cat_b_position_difference = abs(cat_b_position - mouse_position);

            const char *result = get_string_result(cat_a_position_difference, cat_b_position_difference);

            return result;
        }

            char* get_string_result(const int cat_a_position_difference, const int cat_b_position_difference) {
                char *result;

                if (cat_a_position_difference != cat_b_position_difference) {
                    result = (char*) calloc(6, sizeof(char));

                    if (cat_a_position_difference < cat_b_position_difference)
                        strcpy(result, "Cat A");
                    else
                        strcpy(result, "Cat B");
                }
                else {
                    result = (char*) calloc(8, sizeof(char));
                    strcpy(result, "Mouse C");
                }

                return result;
            }
