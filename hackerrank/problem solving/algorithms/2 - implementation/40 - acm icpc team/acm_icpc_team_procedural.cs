// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

using System;

public class ACM_ICPC_TEAM
{
    public static void Main()
    {
        List<int> array = _ReadAnIntArray();
        int attendees = array.First();
        int _topics = array.Last();
        List<string> binaryStrings = _ReadBinaryStrings(attendees);

        List<int> output = _FindMaximumSubjectsAndTeamsThatKnowThem(binaryStrings);
        _PrintArray(output);
    }

        private static List<int> _ReadAnIntArray()
        {
            List<int> array = Console.ReadLine().Split().Select(int.Parse).ToList();
            return array;
        }

        private static List<string> _ReadBinaryStrings(int nStrings)
        {
            List<string> binaryStrings = new List<string>(new string[nStrings]);
            binaryStrings = binaryStrings.Select(element => Console.ReadLine()).ToList();
            return binaryStrings;
        }

        private static List<int> _FindMaximumSubjectsAndTeamsThatKnowThem(List<string> binaryStrings)
        {
            int maximumSubjectsKnownByTeams = 0;
            int teamsThatKnowMaximumSubjects = 0;

            for (int i = 0, size1 = binaryStrings.Count - 1; i < size1; i++)
            {
                for (int j = i + 1, size2 = size1 + 1; j < size2; j++)
                {
                    int subjectsKnownBy2Teams = _CountSubjectsKnownBy2Teams(binaryStrings[i], binaryStrings[j]);
                    _UpdateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams, ref maximumSubjectsKnownByTeams, ref teamsThatKnowMaximumSubjects);
                }
            }

            List<int> output = new List<int>() {maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects};
            return output;
        }

            private static int _CountSubjectsKnownBy2Teams(string binaryString1, string binaryString2)
            {
                int subjectsKnownBy2Teams = 0;

                for (int i = 0, size = binaryString1.Length; i < size; i++)
                    if (binaryString1[i] == '1' || binaryString2[i] == '1')
                        subjectsKnownBy2Teams++;

                return subjectsKnownBy2Teams;
            }

            private static void _UpdateMaximumSubjectsAndTeamsThatKnowThem(int subjectsKnownBy2Teams, ref int maximumSubjectsKnownByTeams, ref int teamsThatKnowMaximumSubjects)
            {
                if (subjectsKnownBy2Teams > maximumSubjectsKnownByTeams)
                {
                    maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                    teamsThatKnowMaximumSubjects = 1;
                }
                else if (subjectsKnownBy2Teams == maximumSubjectsKnownByTeams)
                    teamsThatKnowMaximumSubjects += 1;
            }

        private static void _PrintArray(List<int> array)
        {
            array.ForEach(Console.WriteLine);
        }
}
