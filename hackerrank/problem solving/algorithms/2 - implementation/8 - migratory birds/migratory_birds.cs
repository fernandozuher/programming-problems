// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<int> array = _readIntArray();
        array.Sort();
        MigratoryBirds obj = new MigratoryBirds(array);
        Console.WriteLine(obj.MostSpottedBird);
    }

        private static List<int> _readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    public class MigratoryBirds
    {
        private List<int> _birdSightings;
        private int _mostSpottedBird;

        public MigratoryBirds(List<int> birdSightings)
        {
            _birdSightings = birdSightings;
            _findMostSpottedBird();
        }

            private void _findMostSpottedBird()
            {
                _mostSpottedBird = _birdSightings.First();
                int countNMostSpottedBird = 1;
                int tempCountMostSpottedBird = 1;

                for (int i = 1; i < _birdSightings.Count; ++i)

                    if (_birdSightings[i] == _birdSightings[i - 1])
                        ++tempCountMostSpottedBird;

                    else if (tempCountMostSpottedBird > countNMostSpottedBird) {
                        _mostSpottedBird = _birdSightings[i - 1];
                        countNMostSpottedBird = tempCountMostSpottedBird;
                        tempCountMostSpottedBird = 1;
                    }

                if (tempCountMostSpottedBird > countNMostSpottedBird)
                    _mostSpottedBird = _birdSightings.Last();
            }

        public int MostSpottedBird
        {
            get { return _mostSpottedBird; }
        }
    }
