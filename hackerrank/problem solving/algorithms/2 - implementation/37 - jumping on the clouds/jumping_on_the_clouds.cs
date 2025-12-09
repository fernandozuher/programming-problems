// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(MinimumNumberOfJumps(ReadNumbers()));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int MinimumNumberOfJumps(int[] clouds)
{
    int jumps = 0;
    for (int i = 0, n = clouds.Length - 1; i < n; i += NextJump(i, clouds))
        jumps++;
    return jumps;
}

int NextJump(int index, int[] clouds)
{
    bool isNextSecondCloudCumulus = false;
    if (index + 2 < clouds.Length)
        isNextSecondCloudCumulus = clouds[index + 2] == 0;
    return isNextSecondCloudCumulus ? 2 : 1;
}
