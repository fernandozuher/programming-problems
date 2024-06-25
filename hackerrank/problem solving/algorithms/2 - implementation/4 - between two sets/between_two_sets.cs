// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

using static System.Console;

class Solution
{
    static void Main()
    {
        ReadIntArray();
        List<int> setA = ReadIntArray();
        List<int> setB = ReadIntArray();

        setA.Sort();
        setB.Sort();
        
        var obj = new BetweenTwoSets(setA, setB);
        obj.FindFactors();
        WriteLine(obj.TotalFactors);
    }

    static List<int> ReadIntArray()
    {
        return ReadLine()!.Split().Select(int.Parse).ToList();
    }
}

    class BetweenTwoSets(List<int> setA, List<int> setB)
    {
        private readonly List<int> _potentialFactors = [];
        public int TotalFactors { get; private set; }

        public void FindFactors()
        {
            _findNumbersDivisibleBySetA();
            _findFactorsOfSetB();
            _countFactors();
        }

            private void _findNumbersDivisibleBySetA()
            {
                for (int potentialFactor = setA.Last(); potentialFactor <= setB.First(); potentialFactor += setA.Last())
                {
                    bool isARealPotentialFactor = true;

                    foreach (int x in setA)
                        if (potentialFactor % x != 0)
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
                foreach (int x in setB)
                foreach (int i in Enumerable.Range(0, _potentialFactors.Count))
                    if (_potentialFactors[i] != 0 && x % _potentialFactors[i] != 0)
                        _potentialFactors[i] = 0;
            }

            private void _countFactors()
            {
                TotalFactors = _potentialFactors.Count(x => x != 0);
            }
    }