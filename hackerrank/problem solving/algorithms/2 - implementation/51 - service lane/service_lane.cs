// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

int t = ReadNumbers()[1];
int[] widths = ReadNumbers();
for (int i = 0; i < t; i++)
    Console.WriteLine(minWidthInSegment(widths, ReadNumbers()));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array widths
// T: O(n)
// S: O(1) extra space
int minWidthInSegment(int[] widths, int[] segment)
{
    int nElements = segment[1] - segment[0] + 1;
    return widths.Skip(segment[0]).Take(nElements).Min();
}
