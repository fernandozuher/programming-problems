// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int _ = _ReadANumber();
        List<int> cloudArray = _ReadAnArray();

        JumpingOnTheClouds obj = new JumpingOnTheClouds(cloudArray);
        int minimumNumberOfJumps = obj.GetMinimumNumberOfJumps();
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
}

    public class JumpingOnTheClouds
    {
        private List<int> _CloudArray;
        private int _MinimumNumberOfJumps;

        public JumpingOnTheClouds(List<int> cloudArray)
        {
            _CloudArray = cloudArray;
            _MinimumNumberOfJumps = 0;

            _CalculateMinimumNumberOfJumps();
        }

            private void _CalculateMinimumNumberOfJumps()
            {
                for (int i = 0, size = _CloudArray.Count - 1; i < size; )
                {
                    i = _GetIndexOfNextJump(i);
                    _MinimumNumberOfJumps++;
                }
            }

                private int _GetIndexOfNextJump(int index)
                {
                    if (_IsNextSecondIndexInsideRange(index + 2))
                        index += _IsNextSecondCloudCumulus(_CloudArray[index + 2]) ? 2 : 1;
                    else
                        index++;
                    return index;
                }

                    private bool _IsNextSecondIndexInsideRange(int index)
                    {
                        return index < _CloudArray.Count;
                    }

                    private bool _IsNextSecondCloudCumulus(int typeOfCloud)
                    {
                        return typeOfCloud == 0;
                    }

        public int GetMinimumNumberOfJumps()
        {
            return _MinimumNumberOfJumps;
        }
    }
