// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

using System;

public class JumpingOnTheCloud
{
    public static void Main()
    {
        int _ = _ReadANumber();
        List<int> cloudArray = _ReadAnArray();
        int minimumNumberOfJumps = _CalculateMinimumNumberOfJumps(cloudArray);
        Console.WriteLine(minimumNumberOfJumps);
    }

    private static int _ReadANumber()
    {
        int number = int.Parse(Console.ReadLine());
        return number;
    }

    private static List<int> _ReadAnArray()
    {
        List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
        return array;
    }

    private static int _CalculateMinimumNumberOfJumps(List<int> array)
    {
        int jumps = 0;

        for (int i = 0, size = array.Count - 1; i < size; )
        {
            i = _GetIndexOfNextJump(i, array);
            jumps++;
        }

        return jumps;
    }

        private static int _GetIndexOfNextJump(int index, List<int> array)
        {
            if (_IsNextSecondIndexInsideRange(index + 2, array.Count))
                index += _IsNextSecondCloudCumulus(array[index + 2]) ? 2 : 1;
            else
                index++;
            return index;
        }

            private static bool _IsNextSecondIndexInsideRange(int index, int size)
            {
                return index < size;
            }

            private static bool _IsNextSecondCloudCumulus(int typeOfCloud)
            {
                return typeOfCloud == 0;
            }
}
