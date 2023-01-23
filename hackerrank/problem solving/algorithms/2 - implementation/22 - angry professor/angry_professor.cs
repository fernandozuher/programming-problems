// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

using System;


class Solution
{
    public static void Main()
    {
        List<int> inputLine = ReadLineAsListInt();
        int nTestCases = inputLine.First();
        List<bool> results = new List<bool>(new bool[nTestCases]);

        for (int i = 0, n = results.Count; i < n; i++)
        {
            AngryProfessor angryProfessor = new AngryProfessor();
            results[i] = angryProfessor.GetCancelledClass();
        }

        foreach (bool result in results)
            Console.WriteLine(result ? "YES" : "NO");
    }

        public static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }
}

    class AngryProfessor
    {
        private int _cancellationThreshold;
        private List<int> _studentsArrivalTime;
        private bool _cancelledClass;

        public AngryProfessor()
        {
            List<int> inputLine = Solution.ReadLineAsListInt();
            _cancellationThreshold = inputLine.Last();
            _studentsArrivalTime = Solution.ReadLineAsListInt();

            _AngryProfessor();
        }

            private void _AngryProfessor()
            {
                _cancelledClass = _CountEarlyArrivalTime() < _cancellationThreshold;
            }

                private int _CountEarlyArrivalTime()
                {
                    int earlyArrivalTimeCount = 0;

                    foreach (int studentArrivalTime in _studentsArrivalTime)
                        if (studentArrivalTime <= 0)
                            earlyArrivalTimeCount++;

                    return earlyArrivalTimeCount;
                }

        public bool GetCancelledClass()
        {
            return _cancelledClass;
        }
    }
