// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
Console.WriteLine(DiagonalDifference(n));

// T: O(n^2)
// S: O(n) extra space
int DiagonalDifference(int n)
{
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++)
    {
        int[] arr = Reader.ReadLn<int, int[]>();
        primarySum += arr[i];
        secondarySum += arr[n - i - 1];
    }

    return Math.Abs(primarySum - secondarySum);
}
