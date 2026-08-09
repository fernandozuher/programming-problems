// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
int[] ranked = RemoveDuplicates(Reader.ReadLn<int, int[]>());
Reader.SkipInputLn();
int[] player = Reader.ReadLn<int, int[]>();
Writer.Println(ClimbingLeaderboard(ranked, player));

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
int[] RemoveDuplicates(int[] arr) => arr.Distinct().ToArray();

// n1: length of player, output
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
int[] ClimbingLeaderboard(int[] ranked, int[] player)
{
    int i = ranked.Length - 1;
    return player.Select(score =>
    {
        while (i >= 0 && score >= ranked[i])
            i--;
        return i + 2;
    }).ToArray();
}
