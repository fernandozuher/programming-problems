// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

int *read_numbers(int n);
int remove_duplicates(int numbers[], int n);
int *climbing_leaderboard(const int ranked[], int n, const int player[], int n2);

int main()
{
    int n;
    scanf("%d", &n);
    auto ranked = read_numbers(n);
    n = remove_duplicates(ranked, n);
    ranked = realloc(ranked, n * sizeof(int));

    int n2;
    scanf("%d", &n2);
    int *player = read_numbers(n2);

    int *player_ranks = climbing_leaderboard(ranked, n, player, n2);
    for (int i = 0; i < n2; ++i)
        printf("%d\n", player_ranks[i]);

    free(ranked);
    free(player);
    free(player_ranks);

    return 0;
}

int *read_numbers(int n)
{
    auto numbers = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
    return numbers;
}

int remove_duplicates(int numbers[], int n)
{
    int j = 0;
    for (int i = 1; i < n; ++i)
        if (numbers[i] != numbers[j])
            numbers[++j] = numbers[i];
    return j + 1;
}

int *climbing_leaderboard(const int ranked[], int n, const int player[], int n2)
{
    auto player_ranks = (int *) malloc(n2 * sizeof(int));
    int i = n - 1;

    for (int j = 0; j < n2; ++j) {
        while (i >= 0 && player[j] >= ranked[i])
            --i;
        player_ranks[j] = i + 2;
    }

    return player_ranks;
}
