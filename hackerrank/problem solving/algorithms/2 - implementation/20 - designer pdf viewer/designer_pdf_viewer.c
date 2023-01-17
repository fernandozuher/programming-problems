// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_OF_INPUT_LINE_ARRAY 1024

void read_line_as_int_array_and_initialize_parameters(int **input_line, int **n);
char* read_line_as_char_array();
void* free_pointer_and_return_null(void* pointer);
int _designerPdfViewer(const int *lettersHeights, const char *word);


int main() {
    int *input_line1, *n;
    read_line_as_int_array_and_initialize_parameters(&input_line1, &n);

    char *input_line2 = read_line_as_char_array();

    const int result = _designerPdfViewer(input_line1, input_line2);

    input_line1 = free_pointer_and_return_null(input_line1);
    n = free_pointer_and_return_null(n);
    input_line2 = free_pointer_and_return_null(input_line2);

    printf("%d\n", result);

    return 0;
}

    void read_line_as_int_array_and_initialize_parameters(int **input_line, int **n) {
        *input_line = (int*) calloc(SIZE_OF_INPUT_LINE_ARRAY, sizeof(int));
        *n = (int*) calloc(1, sizeof(int));

        int input_line_size = 0;
        for (char character; true; input_line_size++)
            if (scanf("%d%c", &((*input_line)[input_line_size]), &character) == EOF || character == '\n') {
                input_line_size++;
                break;
            }

        *input_line = (int*) realloc(*input_line, input_line_size * sizeof(int));
        **n = input_line_size;
    }

    char* read_line_as_char_array() {
        char *string = (char*) calloc(SIZE_OF_INPUT_LINE_ARRAY, sizeof(char));
        scanf("%s", string);
        string = (char*) realloc(string, strlen(string + 1) * sizeof(char));

        return string;
    }

    void* free_pointer_and_return_null(void* pointer) {
        free(pointer);
        return NULL;
    }

    int _designerPdfViewer(const int *lettersHeights, const char *word) {
        int max_height = 0;
        int word_size = strlen(word);

        for (int i = 0; i < word_size; i++) {
            int letter_index = word[i] - 'a';
            int letter_height = lettersHeights[letter_index];

            if (max_height < letter_height)
                max_height = letter_height;
        }

        const int area = max_height * word_size;
        return area;
    }
