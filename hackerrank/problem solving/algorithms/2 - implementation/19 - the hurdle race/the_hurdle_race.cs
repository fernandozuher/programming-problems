// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        List<int> array = _readIntArray();
        int n = array.First(), maximumHeightCanJump = array.Last();
        List<int> hurdlesHeights = _readIntArray();

        var obj = new HurdleRace(hurdlesHeights, maximumHeightCanJump);
        Console.WriteLine(obj.Doses);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class HurdleRace
    {
        private List<int> _hurdlesHeights;
        private int _maximumHeightCanJump;
        private int _doses;

        public HurdleRace(List<int> hurdlesHeights, int maximumHeightCanJump)
        {
            _hurdlesHeights = hurdlesHeights;
            _maximumHeightCanJump = maximumHeightCanJump;
            _doses = 0;
            _hurdleRace();
        }

            private void _hurdleRace()
            {
                int highestHurdle = _hurdlesHeights.Max();
                _doses = highestHurdle > _maximumHeightCanJump ? highestHurdle - _maximumHeightCanJump : 0;
            }

        public int Doses
        {
            get { return _doses; }
        }
    }
