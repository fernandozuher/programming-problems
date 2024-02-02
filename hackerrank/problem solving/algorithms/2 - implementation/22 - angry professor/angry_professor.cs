// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<bool> cancelledClasses = new List<bool>(new bool[n]);

        for (int i = 0; i < n; ++i) {
            List<int> line = _readIntArray();
            int nStudentsArrivalTime = line.First();
            int cancellationThreshold = line.Last();
            List<int> studentsArrivalTime = _readIntArray();

            var obj = new AngryProfessor(studentsArrivalTime, cancellationThreshold);
            cancelledClasses[i] = obj.CancelledClass;
        }

        foreach (bool cancelled in cancelledClasses)
            Console.WriteLine(cancelled ? "YES" : "NO");
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class AngryProfessor
    {
        private List<int> _studentsArrivalTime;
        private int _cancellationThreshold;
        private bool _cancelledClass;

        public AngryProfessor(List<int> studentsArrivalTime, int cancellationThreshold)
        {
            _studentsArrivalTime = studentsArrivalTime;
            _cancellationThreshold = cancellationThreshold;
            _cancelledClass = false;
            _checkIfClassIsCancelled();
        }

            private void _checkIfClassIsCancelled()
            {
                _cancelledClass = _countEarlyArrivalTime() < _cancellationThreshold;
            }

                private int _countEarlyArrivalTime()
                {
                    int earlyArrivalTimeCount = 0;

                    foreach (int arrivalTime in _studentsArrivalTime)
                        if (arrivalTime <= 0)
                            ++earlyArrivalTimeCount;

                    return earlyArrivalTimeCount;
                }

        public bool CancelledClass
        {
            get { return _cancelledClass; }
        }
    }
