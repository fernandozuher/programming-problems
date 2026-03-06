// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

Console.ReadLine();
int[] ranked = RemoveDuplicates(ReadNumbers());
Console.ReadLine();
int[] player = ReadNumbers();
Array.ForEach(ClimbingLeaderboard(ranked, player), Console.WriteLine);

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
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
