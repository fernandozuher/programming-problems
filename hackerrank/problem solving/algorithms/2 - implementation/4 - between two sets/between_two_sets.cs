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

    public Result(List<int> a, List<int> b)
    {
        _setA = a;
        _setB = b;
        _potentialFactors = new List<int>();
        _totalFactors = 0;
        FindFactors();
    }

    public int GetTotalX()
    {
        return _totalFactors;
    }
}

class Solution
{
    private static void readInput(ref List<int> a, ref List<int> b)
    {
        int[] arraySizes = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int n1 = arraySizes[0];
        int n2 = arraySizes[1];

        a = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
        b = Console.ReadLine().Split().ToList().Select(int.Parse).ToList();
    }

    public static void Main()
    {
        List<int> a = new List<int>(), b = new List<int>();
        readInput(ref a, ref b);

        Result result = new Result(a, b);
        int total = result.GetTotalX();
        Console.WriteLine(total);
    }
}
