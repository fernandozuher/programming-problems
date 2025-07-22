// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        List<int> ranked = RemoveDuplicates(ReadNumbers());
        Console.ReadLine();
        List<int> player = ReadNumbers();
        ClimbingLeaderboard(ranked, player).ForEach(Console.WriteLine);
    }

    private static List<int> ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToList();
    }

    private static List<int> RemoveDuplicates(List<int> numbers)
    {
        return numbers.Distinct().ToList();
    }

    private static List<int> ClimbingLeaderboard(List<int> ranked, List<int> player)
    {
        List<int> playerRanks = new List<int>(new int[player.Count]);
        int i = ranked.Count - 1;

        for (int j = 0; j < player.Count; j++)
        {
            while (i >= 0 && player[j] >= ranked[i])
                i--;
            playerRanks[j] = i + 2;
        }

        return playerRanks;
    }
}
