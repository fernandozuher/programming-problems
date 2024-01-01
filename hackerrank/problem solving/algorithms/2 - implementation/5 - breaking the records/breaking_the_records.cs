// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        readIntArray();
        List<int> array = readIntArray();
        var records = new BreakingBestAndWorstRecords(array);

        Console.WriteLine("{0} {1}", records.MostPointsRecords(), records.LeastPointsRecords());
    }

        private static List<int> readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class BreakingBestAndWorstRecords
    {
        private List<int> _scores;
        private int _breakingMostPointsRecords, _breakingLeastPointsRecords;

        public BreakingBestAndWorstRecords(List<int> array)
        {
            _scores = array;
            _breakingMostPointsRecords = _breakingLeastPointsRecords = 0;
            _breakingRecords();
        }

            private void _breakingRecords()
            {
                int mostPoints = _scores.First();
                int leastPoints = _scores.First();

                foreach (int score in _scores)
                    if (score > mostPoints)
                    {
                        mostPoints = score;
                        ++_breakingMostPointsRecords;
                    }
                    else if (score < leastPoints)
                    {
                        leastPoints = score;
                        ++_breakingLeastPointsRecords;
                    }
            }

        public int MostPointsRecords()
        {
            return _breakingMostPointsRecords;
        }

        public int LeastPointsRecords()
        {
            return _breakingLeastPointsRecords;
        }
    }
