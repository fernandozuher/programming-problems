// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int* read_int_array(int* const n);
int designer_pdf_viewer(const int* const letters_heights, const char* const word);

int main()
{
    int n = 0;
    int *letters_heights = read_int_array(&n);
    char word[MAX_LINE_SIZE];
    fgets(word, sizeof(word), stdin);

    printf("%d\n", designer_pdf_viewer(letters_heights, word));

    free(letters_heights);
    letters_heights = NULL;

    return 0;
}

    int* read_int_array(int* const n)
    {
        int *array = (int*) calloc(MAX_LINE_SIZE, sizeof(int));

        int i = 0;
        for (char ch; i < MAX_LINE_SIZE; ++i)
            if (scanf("%d%c", &array[i], &ch) == EOF || ch == '\n')
                break;
        *n = i + 1;

        return realloc(array, *n * sizeof(int));
    }

    int designer_pdf_viewer(const int* const letters_heights, const char* const word)
    {
        int max_height = 0;
        int n = strlen(word);

        for (int i = 0; i < n; i++) {
            int letter_index = word[i] - 'a';
            int letter_height = letters_heights[letter_index];

            if (max_height < letter_height)
                max_height = letter_height;
        }

        int area = max_height * n;
        return area;
    }
