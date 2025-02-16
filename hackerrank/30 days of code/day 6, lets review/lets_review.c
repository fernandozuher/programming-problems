// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true
// From C23 onwards

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    constexpr int maximum_length = 10001;
    char word[maximum_length];

    char word1[5001], word2[5001];
    for (int i = 0; i < n && scanf("%10000s", word) != EOF; ++i) {
        int size_word1 = 0, size_word2 = 0;

        for (int j = 0, is_word1_turn = true; word[j] != '\0'; ++j, is_word1_turn = !is_word1_turn)
            is_word1_turn ? (word1[size_word1++] = word[j]) : (word2[size_word2++] = word[j]);

        word1[size_word1] = word2[size_word2] = '\0';
        printf("%s %s\n", word1, word2);
    }

    return 0;
}
