// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

using static System.Console;
using System.Linq;

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        List<int> nLoavesOfEachPerson = ReadLine().Split().Select(int.Parse).ToList();
        if (FindMinLoavesToSatisfyRules(nLoavesOfEachPerson) is var minLoaves && minLoaves == -1)
            WriteLine("NO");
        else
            WriteLine(minLoaves);
    }

        static int FindMinLoavesToSatisfyRules(List<int> nLoavesOfEachPerson)
        {
            int minLoavesToSatisfyRules = 0;

            foreach (int i in Enumerable.Range(0, nLoavesOfEachPerson.Count - 1))
                if (IsOdd(nLoavesOfEachPerson[i]))
                {
                    ++nLoavesOfEachPerson[i + 1];
                    minLoavesToSatisfyRules += 2;
                }

            return IsOdd(nLoavesOfEachPerson.Last()) ? -1 : minLoavesToSatisfyRules;
        }

            static bool IsOdd(int n)
            {
                return n % 2 == 1;
            }
}
