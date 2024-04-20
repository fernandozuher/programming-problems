// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int attendees = scan.nextInt();
        int topics = scan.nextInt();
        scan.nextLine();

        List<BitSet> binaries = readBinaries(attendees);

        var obj = new ACM_ICPC_TEAM(binaries);
        obj.findMaximumSubjectsAndTeamsThatKnowThem();
        System.out.println(obj.maxSubjectsKnownByTeams() + "\n" + obj.nTeamsThatKnowMaximumSubjects());
    }

        public static List<BitSet> readBinaries(final int n) {
            return Arrays.asList(new BitSet[n])
                   .stream()
                   .map(x -> toBitSet(scan.nextLine()))
                   .collect(toList());
        }

            public static BitSet toBitSet(final String binaryString) {
                int n = binaryString.length();
                var binary = new BitSet(n);
                for (int i = 0; i < n; ++i)
                    if (binaryString.charAt(i) == '1')
                        binary.set(i);
                return binary;
            }
}

    class ACM_ICPC_TEAM {
        private List<BitSet> binaries;
        private int maxSubjectsKnownByTeams;
        private int teamsThatKnowMaximumSubjects;

        public ACM_ICPC_TEAM(final List<BitSet> binaries) {
            this.binaries = binaries;
            maxSubjectsKnownByTeams = 0;
            teamsThatKnowMaximumSubjects = 0;
        }

        public void findMaximumSubjectsAndTeamsThatKnowThem() {
            int i = 0;
            for (var previous : binaries.subList(0, binaries.size() - 1))
                for (var current : binaries.subList(++i, binaries.size()))
                    updateMaximumSubjectsAndTeamsThatKnowThem(countSubjectsKnownBy2Teams(previous, current));
        }

            private int countSubjectsKnownBy2Teams(BitSet binary1, BitSet binary2) {
                var bin = (BitSet)binary1.clone();
                bin.or(binary2);
                return bin.cardinality();
            }

            private void updateMaximumSubjectsAndTeamsThatKnowThem(final int subjectsKnownBy2Teams) {
                if (subjectsKnownBy2Teams > maxSubjectsKnownByTeams) {
                    maxSubjectsKnownByTeams = subjectsKnownBy2Teams;
                    teamsThatKnowMaximumSubjects = 1;
                } else if (subjectsKnownBy2Teams == maxSubjectsKnownByTeams)
                    ++teamsThatKnowMaximumSubjects;
            }

        public int maxSubjectsKnownByTeams() {
            return maxSubjectsKnownByTeams;
        }

        public int nTeamsThatKnowMaximumSubjects() {
            return teamsThatKnowMaximumSubjects;
        }
    }
