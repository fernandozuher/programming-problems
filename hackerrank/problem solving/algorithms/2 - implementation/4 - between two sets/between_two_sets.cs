// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

using System;

class Result
{
    /*
     * Complete the 'GetTotalX' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGERARRAY a
     *  2. INTEGERARRAY b
     */

    private List<int> _potentialFactors, _setA, _setB;
    private int _totalFactors;

    private void FindFactors()
    {
        FindNumbersDivisibleBySetA();
        FindFactorsOfSetB();
        CountFactors();
    }

        private void FindNumbersDivisibleBySetA()
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

        private void FindFactorsOfSetB()
        {
            foreach (int elementB in _setB)
                foreach (int i in Enumerable.Range(0, _potentialFactors.Count))
                    if (_potentialFactors[i] != 0 && elementB % _potentialFactors[i] != 0)
                        _potentialFactors[i] = 0;
        }

        private void CountFactors()
        {
            _totalFactors = _potentialFactors.Aggregate(0, (previousResult, item) => item != 0 ? ++previousResult : previousResult);
        }

    public Result(List<int> setA, List<int> setB)
    {
        _setA = setA;
        _setB = setB;
        _potentialFactors = new List<int>();
        _totalFactors = 0;

        FindFactors();

        PrintResult();
    }

        public void PrintResult()
        {
            Console.WriteLine(_totalFactors);
        }
}

class Solution
{
    private static List<int> readAsIntList()
    {
        List<int> numbers = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
        return numbers;
    }

    public static void Main()
    {
        readAsIntList();
        List<int> setA = readAsIntList();
        List<int> setB = readAsIntList();

        setA.Sort();
        setB.Sort();

        Result result = new Result(setA, setB);
    }
}