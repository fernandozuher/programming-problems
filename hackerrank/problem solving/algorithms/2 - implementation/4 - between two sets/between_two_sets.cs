// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    public static void Main()
    {
        readIntArray();
        List<int> setA = readIntArray();
        List<int> setB = readIntArray();

        setA.Sort();
        setB.Sort();

        var result = new Result(setA, setB);
        Console.WriteLine(result.TotalFactors());
    }

        private static List<int> readIntArray()
        {
            return Console.ReadLine().Split().Select(int.Parse).ToList();
        }
}

    class Result
    {
        private List<int> _potentialFactors, _setA, _setB;
        private int _totalFactors;

        public Result(List<int> setA, List<int> setB)
        {
            _setA = setA;
            _setB = setB;
            _potentialFactors = new List<int>();
            _totalFactors = 0;

            _findFactors();
        }

            private void _findFactors()
            {
                _findNumbersDivisibleBySetA();
                _findFactorsOfSetB();
                _countFactors();
            }

                private void _findNumbersDivisibleBySetA()
                {
                    for (int potentialFactor = _setA.Last(); potentialFactor <= _setB.First(); potentialFactor += _setA.Last())
                    {
                        bool isARealPotentialFactor = true;

                        foreach (int elementA in _setA)
                            if (potentialFactor % elementA != 0)
                            {
                                isARealPotentialFactor = false;
                                break;
                            }

                        if (isARealPotentialFactor)
                            _potentialFactors.Add(potentialFactor);
                    }
                }

                private void _findFactorsOfSetB()
                {
                    foreach (int elementB in _setB)
                        foreach (int i in Enumerable.Range(0, _potentialFactors.Count))
                            if (_potentialFactors[i] != 0 && elementB % _potentialFactors[i] != 0)
                                _potentialFactors[i] = 0;
                }

                private void _countFactors()
                {
                    _totalFactors = _potentialFactors.Aggregate(0, (sum, item) => item != 0 ? ++sum : sum);
                }

            public int TotalFactors()
            {
                return _totalFactors;
            }
    }
