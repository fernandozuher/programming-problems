// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

using static System.Console;
using System.Numerics;

namespace ProgrammingProblem
{
class Solution
{
    static void Main()
    {
        List<int> array = ReadIntArray();
        int attendees = array.First(), topics = array.Last();
        List<BigInteger> binaries = ReadBinaries(attendees);
        var obj = new ACM_ICPC_TEAM(binaries);
        obj.FindMaximumSubjectsAndTeamsThatKnowThem();
        WriteLine("{0}\n{1}", obj.MaximumSubjectsKnownByTeams, obj.TeamsThatKnowMaximumSubjects);
    }

        static List<int> ReadIntArray()
        {
            return ReadLine().Split().Select(int.Parse).ToList();
        }

        static List<BigInteger> ReadBinaries(int n)
        {
            return new List<BigInteger>(new BigInteger[n])
                .Select(_ => ReadLine().Aggregate(new BigInteger(), (b, c) => b * 2 + c - '0'))
                .ToList();
        }
}

    class ACM_ICPC_TEAM
    {
        private List<BigInteger> _binaries;
        private int _maximumSubjectsKnownByTeams;
        private int _teamsThatKnowMaximumSubjects;

        public ACM_ICPC_TEAM(List<BigInteger> binaries)
        {
            _binaries = binaries;
            _maximumSubjectsKnownByTeams = 0;
            _teamsThatKnowMaximumSubjects = 0;
        }

        public void FindMaximumSubjectsAndTeamsThatKnowThem()
        {
            int i = 0;
            foreach (var previous in _binaries.SkipLast(1))
                foreach (var current in _binaries.Skip(++i))
                    _updateMaximumSubjectsAndTeamsThatKnowThem(_countSubjectsKnownBy2Teams(previous, current));
        }

            private int _countSubjectsKnownBy2Teams(BigInteger binary1, BigInteger binary2)
            {
                return (int)BigInteger.PopCount(binary1 | binary2);
            }

            private void _updateMaximumSubjectsAndTeamsThatKnowThem(int subjectsKnownBy2Teams)
            {
                if (subjectsKnownBy2Teams > _maximumSubjectsKnownByTeams)
                {
                    _maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                    _teamsThatKnowMaximumSubjects = 1;
                }
                else if (subjectsKnownBy2Teams == _maximumSubjectsKnownByTeams)
                    ++_teamsThatKnowMaximumSubjects;
            }

        public int MaximumSubjectsKnownByTeams
        {
            get { return _maximumSubjectsKnownByTeams; }
        }

        public int TeamsThatKnowMaximumSubjects
        {
            get { return _teamsThatKnowMaximumSubjects; }
        }
    }
}