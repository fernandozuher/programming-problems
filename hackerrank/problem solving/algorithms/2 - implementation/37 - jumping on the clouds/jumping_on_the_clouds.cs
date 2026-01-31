// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

Console.ReadLine();
Console.WriteLine(MinJumps(ReadNumbers()));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
int MinJumps(int[] clouds)
{
    int jumps = 0;
    for (int i = 0, n = clouds.Length - 1; i < n; i += Skip(i, clouds), jumps++);
    return jumps;
}

int Skip(int idx, int[] clouds) => IsNextSecondCloudCumulus(idx, clouds) ? 2 : 1;

bool IsNextSecondCloudCumulus(int idx, int[] clouds) => idx + 2 < clouds.Length && clouds[idx + 2] == 0;
