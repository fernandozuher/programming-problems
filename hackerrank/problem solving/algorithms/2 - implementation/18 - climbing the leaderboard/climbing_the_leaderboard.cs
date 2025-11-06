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

int[] ClimbingLeaderboard(int[] ranked, int[] player)
{
    int[] playerRanks = new int[player.Length];
    int i = ranked.Length - 1;

    for (int j = 0; j < player.Length; j++)
    {
        while (i >= 0 && player[j] >= ranked[i])
            i--;
        playerRanks[j] = i + 2;
    }

    return playerRanks;
}
