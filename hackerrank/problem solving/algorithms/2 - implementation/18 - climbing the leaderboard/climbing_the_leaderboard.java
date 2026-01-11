// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
// Java 25

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

// n: length of array player|playerRanks
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
int[] climbingLeaderboard(int[] ranked, int[] player) {
    int[] playerRanks = new int[player.length];
    int seeker = ranked.length - 1;

    for (int writer = 0; writer < player.length; writer++) {
        while (seeker >= 0 && player[writer] >= ranked[seeker]) seeker--;
        playerRanks[writer] = seeker + 2;
    }

    return playerRanks;
}
