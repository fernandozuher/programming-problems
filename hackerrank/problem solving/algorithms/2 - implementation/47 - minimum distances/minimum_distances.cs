// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

public class Solution
{
    private static void Main()
    {
        Console.ReadLine();
        int[] arr = ReadNumbers();
        Console.WriteLine(MinDistance(arr));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int MinDistance(int[] arr)
    {
        var lastSeen = new Dictionary<int, int>();
        int minDist = -1;

        for (int i = 0; i < arr.Length; i++)
        {
            int x = arr[i];
            if (lastSeen.ContainsKey(x))
            {
                int dist = i - lastSeen[x];
                if (minDist == -1 || dist < minDist)
                {
                    minDist = dist;
                    if (minDist == 1)
                        return 1;
                }
            }
            lastSeen[x] = i;
        }

        return minDist;
    }
}
