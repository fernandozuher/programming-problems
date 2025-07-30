// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <string.h>

void read_numbers(int numbers[], int n);
int designer_pdf_viewer(const int letters_heights[], const char *word);

int main()
{
    constexpr int n1 = 26;
    constexpr int n2 = 12;

    int letters_heights[n1];
    char word[n2];
    read_numbers(letters_heights, n1);
    scanf("\n");
    fgets(word, sizeof(word), stdin);

    printf("%d\n", designer_pdf_viewer(letters_heights, word));

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int designer_pdf_viewer(const int letters_heights[], const char *word)
{
    int max_height = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++) {
        int index = word[i] - 'a';
        if (max_height < letters_heights[index])
            max_height = letters_heights[index];
    }

    return max_height * n;
}
