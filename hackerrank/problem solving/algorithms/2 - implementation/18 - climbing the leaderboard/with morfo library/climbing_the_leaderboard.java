// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;
import morfo.io.Writer;

void main() {
    Reader.skipInputLn();
    int[] ranked = removeDuplicates(Reader.readLnInts());
    Reader.skipInputLn();
    int[] player = Reader.readLnInts();
    Writer.println(climbingLeaderboard(ranked, player));
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
int[] removeDuplicates(int[] arr) {
    return Arrays.stream(arr).distinct().toArray();
}

// n1: length of player, playerRanks
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
int[] climbingLeaderboard(int[] ranked, int[] player) {
    int[] playerRanks = new int[player.length];
    int seeker = ranked.length - 1;

    for (int writer = 0; writer < player.length; writer++) {
        while (seeker >= 0 && player[writer] >= ranked[seeker]) seeker--;
        playerRanks[writer] = seeker + 2;
    }

    return playerRanks;
}
