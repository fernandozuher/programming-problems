// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, int n);
int remove_duplicates(int *arr, int n);
void climbing_leaderboard(const int *ranked, int n, const int *player, int n2, int *player_ranks);

int main()
{
    int n;
    scanf("%d", &n);
    int ranked[n];
    read_numbers(ranked, n);
    n = remove_duplicates(ranked, n);

    int n2;
    scanf("%d", &n2);
    int player[n2];
    read_numbers(player, n2);

    int player_ranks[n2];
    climbing_leaderboard(ranked, n, player, n2, player_ranks);
    for (int i = 0; i < n2; ++i)
        printf("%d\n", player_ranks[i]);

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(1) extra space
int remove_duplicates(int *arr, int n)
{
    int writer = 0;
    for (int seeker = 1; seeker < n; ++seeker) {
        if (arr[seeker] == arr[writer])
            continue;
        ++writer;
        arr[writer] = arr[seeker];
    }
    return writer + 1;
}

// n1: length of player, player_ranks
// n2: length of ranked
// T: O(n1 + n2)
// S: O(1) extra space
void climbing_leaderboard(const int *ranked, int n, const int *player, int n2, int *player_ranks)
{
    int seeker = n - 1;
    for (int writer = 0; writer < n2; ++writer) {
        while (seeker >= 0 && player[writer] >= ranked[seeker])
            --seeker;
        player_ranks[writer] = seeker + 2;
    }
}
