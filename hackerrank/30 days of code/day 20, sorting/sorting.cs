// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

using static System.Console;

public static class Solution
{
    public static void Main()
    {
        List<int> numbers = ReadInput();
        int nSwaps = BubbleSort(numbers);
        WriteLine("Array is sorted in {0} swaps.", nSwaps);
        WriteLine("First Element: {0}", numbers[0]);
        WriteLine("Last Element: {0}", numbers[^1]);
    }

    private static List<int> ReadInput()
    {
        ReadLine(); // Skip size of list
        return ReadLine().Split().Select(int.Parse).ToList();
    }

    private static int BubbleSort(List<int> l)
    {
        int totalSwaps = 0;
        for (int end = l.Count; end > 0;)
        {
            var (nSwaps, newEnd) = SortSlice(l, end);
            totalSwaps += nSwaps;
            end = newEnd;
        }
        return totalSwaps;
    }

    private static (int, int) SortSlice(List<int> l, int end)
    {
        int nSwaps = 0, newEnd = 0;
        --end; // Decrease end to avoid out of range error
        for (int i = 0; i < end; i++)
        {
            if (l[i] > l[i + 1])
            {
                (l[i], l[i + 1]) = (l[i + 1], l[i]);
                ++nSwaps;
                newEnd = i + 1;
            }
        }
        return (nSwaps, newEnd);
    }
}
