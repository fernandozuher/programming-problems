// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

int t = ReadNums()[1];
int[] widths = ReadNums();
for (int i = 0; i < t; i++)
    Console.WriteLine(minWidthInSegment(widths, ReadNums()));

int[] ReadNums() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of widths
// T: O(n)
// S: O(1) extra space
int minWidthInSegment(int[] widths, int[] segment)
{
    int start = segment[0], finish = segment[1];
    int nElements = finish - start + 1;
    return widths.Skip(start).Take(nElements).Min();
}
