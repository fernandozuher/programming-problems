// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        int unused = int.Parse(ReadLine()!);
        List<int> array = ReadIntArray();
        array.Sort();
        Console.WriteLine(FindMostSpottedBird(array));
    }

        static List<int> ReadIntArray()
        {
            return ReadLine()!.Split().Select(int.Parse).ToList();
        }

        static int FindMostSpottedBird(List<int> birdSightings)
        {
            int mostSpottedBird = birdSightings.First();
            int countMostSpottedBird = 1;
            int tempCountMostSpottedBird = 1;

            for (int i = 1; i < birdSightings.Count; ++i)
            {
                if (birdSightings[i] == birdSightings[i - 1])
                    ++tempCountMostSpottedBird;
                else if (tempCountMostSpottedBird > countMostSpottedBird)
                {
                    mostSpottedBird = birdSightings[i - 1];
                    countMostSpottedBird = tempCountMostSpottedBird;
                    tempCountMostSpottedBird = 1;
                }
            }

            if (tempCountMostSpottedBird > countMostSpottedBird)
                mostSpottedBird = birdSightings.Last();

            return mostSpottedBird;
        }
}