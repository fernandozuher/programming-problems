// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

using System;

class Solution
{
    public static void Main()
    {
        ReadLineAsListInt();
        string steps = ReadLineAsString();
        
        Result result = new Result(steps);
    }

        private static List<int> ReadLineAsListInt()
        {
            List<int> inputLine = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
            return inputLine;
        }

        private static string ReadLineAsString()
        {
            string inputLine = Console.ReadLine();
            return inputLine;
        }
}

    class Result
    {
        private string _steps;
        private int _traversedValleys;

        public Result(string steps)
        {
            _steps = steps;
            _traversedValleys = 0;

            _CountingValleys();
            PrintResult();
        }

            private void _CountingValleys()
            {
                int currentAltitude = 0;

                foreach (char step in _steps)
                {
                    bool wasTravessingAValley = currentAltitude < 0;
                    currentAltitude += step == 'D' ? -1 : 1;
                    
                    if (_IsInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        _traversedValleys++;
                }
            }

                private bool _IsInSeaLevelFromValley(bool wasTravessingAValley, int currentAltitude)
                {
                    return wasTravessingAValley && currentAltitude == 0;
                }

            public void PrintResult()
            {
                Console.WriteLine(_traversedValleys);
            }
    }
