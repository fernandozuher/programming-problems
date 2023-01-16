// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        List<int> inputLine = ReadLineAsListInt();
        int maximumHeightCanJump = inputLine.Last();

        List<int> hurdlesHeights = ReadLineAsListInt();

        Result result = new Result(hurdlesHeights, maximumHeightCanJump);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }
}

    class Result
    {
        private List<int> _hurdlesHeights;
        private int _maximumHeightCanJump;
        private int _doses;

        public Result(List<int> hurdlesHeights, int maximumHeightCanJump)
        {
            _hurdlesHeights = hurdlesHeights;
            _maximumHeightCanJump = maximumHeightCanJump;
            _doses = 0;

            _HurdleRace();
            PrintResult();
        }

            private void _HurdleRace()
            {
                int highestHurdle = _hurdlesHeights.Max();
                _doses = highestHurdle > _maximumHeightCanJump ? highestHurdle - _maximumHeightCanJump : 0;
            }

            public void PrintResult()
            {
                Console.WriteLine(_doses);
            }
    }
