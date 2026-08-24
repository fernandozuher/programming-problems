// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// C23

#include <stdlib.h>
#include "morfo/collections.h"
#include "morfo/io.h"

void climbing_leaderboard(const int *ranked, int n, const int *player, int n2, int *player_ranks);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *ranked = morfo_readln(int, &n);
    int rn = (int) morfo_unique(ranked, n);

    morfo_skip_input_ln();
    size_t n2;
    int *player = morfo_readln(int, &n2);

    int *player_ranks = malloc(n2 * sizeof(int));
    climbing_leaderboard(ranked, rn, player, (int)n2, player_ranks);
    morfo_println(player_ranks, n2);

    free(ranked);
    free(player);
    free(player_ranks);
    return 0;
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
