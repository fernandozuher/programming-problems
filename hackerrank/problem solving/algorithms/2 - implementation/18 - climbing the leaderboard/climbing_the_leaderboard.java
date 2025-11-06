// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.Stream;

void main() {
    IO.readln();
    int[] ranked = removeDuplicates(readNumbers());
    IO.readln();
    int[] player = readNumbers();
    for (var x : climbingLeaderboard(ranked, player))
        IO.println(x);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int[] removeDuplicates(int[] arr) {
    return Arrays.stream(arr).distinct().toArray();
}

int[] climbingLeaderboard(int[] ranked, int[] player) {
    int[] playerRanks = new int[player.length];
    int i = ranked.length - 1;

    for (int j = 0; j < player.length; j++) {
        while (i >= 0 && player[j] >= ranked[i]) i--;
        playerRanks[j] = i + 2;
    }

    return playerRanks;
}
