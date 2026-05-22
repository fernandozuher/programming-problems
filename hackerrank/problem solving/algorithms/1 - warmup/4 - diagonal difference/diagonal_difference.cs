// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

int n = int.Parse(Console.ReadLine()!);
Console.WriteLine(DiagonalDifference(n));

// T: O(n^2)
// S: O(n) extra space
int DiagonalDifference(int n)
{
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++)
    {
        int[] arr = ReadNumbers();
        primarySum += arr[i];
        secondarySum += arr[n - i - 1];
    }

    return Math.Abs(primarySum - secondarySum);
}

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();
