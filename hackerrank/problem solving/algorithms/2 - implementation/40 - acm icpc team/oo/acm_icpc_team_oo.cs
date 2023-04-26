// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        List<int> array = _ReadAnIntArray();
        int attendees = array.First();
        int _topics = array.Last();
        List<string> binaryStrings = _ReadBinaryStrings(attendees);

        ACM_ICPC_TEAM obj = new ACM_ICPC_TEAM(binaryStrings);
        Console.WriteLine("{0}\n{1}",obj.GetMaximumSubjectsKnownByTeams(), obj.GetTeamsThatKnowMaximumSubjects());
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
}

    public class ACM_ICPC_TEAM
    {
        private List<string> _BinaryStrings;
        private int _MaximumSubjectsKnownByTeams;
        private int _TeamsThatKnowMaximumSubjects;

        public ACM_ICPC_TEAM(List<string> binaryStrings)
        {
            _BinaryStrings = binaryStrings;
            _MaximumSubjectsKnownByTeams = 0;
            _TeamsThatKnowMaximumSubjects = 0;

            _FindMaximumSubjectsAndTeamsThatKnowThem();
        }

            private void _FindMaximumSubjectsAndTeamsThatKnowThem()
            {
                for (int i = 0, size1 = _BinaryStrings.Count - 1; i < size1; i++)
                {
                    for (int j = i + 1, size2 = size1 + 1; j < size2; j++)
                    {
                        int subjectsKnownBy2Teams = _CountSubjectsKnownBy2Teams(_BinaryStrings[i], _BinaryStrings[j]);
                        _UpdateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams);
                    }
                }
            }

                private int _CountSubjectsKnownBy2Teams(string binaryString1, string binaryString2)
                {
                    int subjectsKnownBy2Teams = 0;

                    for (int i = 0, size = binaryString1.Length; i < size; i++)
                        if (binaryString1[i] == '1' || binaryString2[i] == '1')
                            subjectsKnownBy2Teams++;

                    return subjectsKnownBy2Teams;
                }

                private void _UpdateMaximumSubjectsAndTeamsThatKnowThem(int subjectsKnownBy2Teams)
                {
                    if (subjectsKnownBy2Teams > _MaximumSubjectsKnownByTeams)
                    {
                        _MaximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                        _TeamsThatKnowMaximumSubjects = 1;
                    }
                    else if (subjectsKnownBy2Teams == _MaximumSubjectsKnownByTeams)
                        _TeamsThatKnowMaximumSubjects += 1;
                }

        public int GetMaximumSubjectsKnownByTeams()
        {
            return _MaximumSubjectsKnownByTeams;
        }

        public int GetTeamsThatKnowMaximumSubjects()
        {
            return _TeamsThatKnowMaximumSubjects;
        }
    }
