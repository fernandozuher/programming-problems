// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <string.h>

void read_numbers(int *arr, int n);
int designer_pdf_viewer(const int *letters_heights, const char *word);

int main()
{
    constexpr int n1 = 26;
    constexpr int n2 = 12;

    int letters_heights[n1];
    read_numbers(letters_heights, n1);
    scanf("\n");

    char word[n2];
    fgets(word, sizeof(word), stdin);
    if (word[strlen(word) - 1] == '\n')
        word[strlen(word) - 1] = '\0';

    printf("%d\n", designer_pdf_viewer(letters_heights, word));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n_w: length of string word, no more than 10 letters
// T = O(10) = O(1)
// S = O(1) extra space
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
