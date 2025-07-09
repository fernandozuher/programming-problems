// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        Console.ReadLine();
        string steps = Console.ReadLine()!;
        Console.WriteLine(CountingValleys(steps));
    }

    private static int CountingValleys(string steps)
    {
        int valleys = 0;
        int currentAltitude = 0;

        foreach (char step in steps)
        {
            bool wasBelowSeaLevel = currentAltitude < 0;
            currentAltitude += step == 'D' ? -1 : 1;
            bool isInSeaLevelFromValley = wasBelowSeaLevel && currentAltitude == 0;
            if (isInSeaLevelFromValley)
                valleys++;
        }

        return valleys;
    }
}
