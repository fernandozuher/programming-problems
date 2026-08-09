// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morfo/io.h"

int designer_pdf_viewer(const int *letters_heights, const char *word);

int main()
{
    constexpr int n1 = 26;

    int letters_heights[n1];
    morfo_read_n(letters_heights, n1);

    char *word = morfo_read(char *);

    printf("%d\n", designer_pdf_viewer(letters_heights, word));

    free(word);
    return 0;
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
int designer_pdf_viewer(const int *letters_heights, const char *word)
{
    int max_height = 0;
    int n = strlen(word);

    for (int i = 0; i < n; ++i) {
        int height = letters_heights[word[i] - 'a'];
        if (max_height < height)
            max_height = height;
    }

    return max_height * n;
}
