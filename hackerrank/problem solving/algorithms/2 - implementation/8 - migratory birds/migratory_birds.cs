// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

Console.ReadLine();
int[] birdCounts = ReadNumbers();
Console.WriteLine(FindMostSpottedBird(birdCounts));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int FindMostSpottedBird(int[] birdCounts)
{
    return birdCounts.GroupBy(bird => bird)
                .OrderByDescending(group => group.Count())
                .ThenBy(group => group.Key)
                .First()
                .Key;
}
