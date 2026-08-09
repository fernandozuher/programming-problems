// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

using Morfo.IO;

int t = Reader.ReadLn<int, int[]>()[1];
int[] widths = Reader.ReadLn<int, int[]>();
for (int i = 0; i < t; i++)
    Console.WriteLine(minWidthInSegment(widths, Reader.ReadLn<int, int[]>()));

// n: length of widths
// T: O(n)
// S: O(1) extra space
int minWidthInSegment(int[] widths, int[] segment)
{
    int start = segment[0], finish = segment[1];
    int nElements = finish - start + 1;
    return widths.Skip(start).Take(nElements).Min();
}
