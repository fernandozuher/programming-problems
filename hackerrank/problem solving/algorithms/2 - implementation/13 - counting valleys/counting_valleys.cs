// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string steps = Console.ReadLine();
        var obj = new CountValleys(steps);
        Console.WriteLine(obj.TraversedValleys);
    }
}

    public class CountValleys
    {
        private string _steps;
        private int _traversedValleys;

        public CountValleys(string steps)
        {
            _steps = steps;
            _traversedValleys = 0;
            _countingValleys();
        }

            private void _countingValleys()
            {
                int currentAltitude = 0;
                foreach (char step in _steps)
                {
                    bool wasTravessingAValley = currentAltitude < 0;
                    currentAltitude += step == 'D' ? -1 : 1;

                    if (_isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        ++_traversedValleys;
                }
            }

                private bool _isInSeaLevelFromValley(bool wasTravessingAValley, int currentAltitude)
                {
                    return wasTravessingAValley && currentAltitude == 0;
                }

        public int TraversedValleys
        {
            get { return _traversedValleys; }
        }
    }
