// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

using System;

public class FairRations
{
    public static void Main()
    {
        int nSubjects = int.Parse(Console.ReadLine());
        List<int> nLoavesOfEachPerson = Console.ReadLine().Split().Select(int.Parse).ToList();
        Console.WriteLine(_findMinLoavesToSatisfyRules(nLoavesOfEachPerson));
    }

        private static string _findMinLoavesToSatisfyRules(List<int> nLoavesOfEachPerson)
        {
            int minLoavesToSatisfyRules = 0;

            for (int i = 0, size = nLoavesOfEachPerson.Count - 1; i < size; i++)
                if (nLoavesOfEachPerson[i] % 2 == 1)
                {
                    nLoavesOfEachPerson[i]++;
                    nLoavesOfEachPerson[i + 1]++;
                    minLoavesToSatisfyRules += 2;
                }

            return nLoavesOfEachPerson.Last() % 2 == 1 ? "NO" : minLoavesToSatisfyRules.ToString();
        }
}
