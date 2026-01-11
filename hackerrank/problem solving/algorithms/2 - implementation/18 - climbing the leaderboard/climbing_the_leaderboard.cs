// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

Console.ReadLine();
int[] ranked = RemoveDuplicates(ReadNumbers());
Console.ReadLine();
int[] player = ReadNumbers();
Array.ForEach(ClimbingLeaderboard(ranked, player), Console.WriteLine);

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int[] RemoveDuplicates(int[] arr)
{
    return arr.Distinct().ToArray();
}

// n: length of array player and returned output array
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
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
