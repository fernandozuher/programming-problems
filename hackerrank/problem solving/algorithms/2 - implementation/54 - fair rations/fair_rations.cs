// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// From C# 8.0

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
            int loaves = nLoavesOfEachPerson.First();

            foreach (int x in nLoavesOfEachPerson.Skip(1))
            {
                if (IsOdd(loaves))
                {
                    loaves = x + 1;
                    minLoavesToSatisfyRules += 2;
                }
                else
                    loaves = x;
            }

            return IsOdd(loaves) ? -1 : minLoavesToSatisfyRules;
        }

            static bool IsOdd(int n)
            {
                return n % 2 == 1;
            }
}
