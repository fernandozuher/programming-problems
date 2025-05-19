// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

public class Solution
{
    private static void Main()
    {
        int[] tripletA = ReadInput();
        int[] tripletB = ReadInput();
        var (scoreA, scoreB) = CompareTriplets(tripletA, tripletB);
        Console.WriteLine("{0} {1}", scoreA, scoreB);
    }

    private static int[] ReadInput()
    {
        return Console.ReadLine().Split().Select(int.Parse).ToArray();
    }

    private static (int, int) CompareTriplets(int[] tripletA, int[] tripletB)
    {
        int scoreA = 0, scoreB = 0;

        foreach (var (ta, tb) in tripletA.Zip(tripletB))
            if (ta > tb)
                ++scoreA;
            else if (tb > ta)
                ++scoreB;

        return (scoreA, scoreB);
    }
}
