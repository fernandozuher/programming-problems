// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = ReadNumbers()[0];
        Enumerable.Range(0, n).Select(_ =>
        {
            var line = ReadNumbers();
            int prisoners = line[0], sweets = line[1], startChair = line[2];
            return SaveThePrisoner(prisoners, sweets, startChair);
        })
        .ToList().ForEach(Console.WriteLine);
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split(' ').Select(int.Parse).ToArray();
    }

    private static int SaveThePrisoner(int prisoners, int sweets, int startChair)
    {
        return ((startChair - 1 + sweets - 1) % prisoners) + 1;
    }
}
