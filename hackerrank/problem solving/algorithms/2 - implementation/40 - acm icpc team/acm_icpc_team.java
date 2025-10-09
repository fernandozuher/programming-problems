// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int attendees = scan.nextInt();
        scan.nextLine();
        List<BitSet> binaries = readBinaries(scan, attendees);
        acmTeam(binaries).forEach(IO::println);
    }

    private static List<BitSet> readBinaries(Scanner scan, int n) {
        return IntStream.range(0, n).mapToObj(_ -> toBitSet(scan.nextLine())).toList();
    }

    private static BitSet toBitSet(String str) {
        int n = str.length();
        var binary = new BitSet(n);
        for (int i = 0; i < n; i++)
            if (str.charAt(i) == '1') binary.set(i);
        return binary;
    }

    private static List<Integer> acmTeam(List<BitSet> binaries) {
        int maxSubjects = 0;
        int teamsWithMax = 0;
        int i = 0;

        for (var b1 : binaries.subList(0, binaries.size() - 1))
            for (var b2 : binaries.subList(i++, binaries.size())) {
                int knownSubjects = countSubjectsKnownBy2Teams(b1, b2);

                if (knownSubjects > maxSubjects) {
                    maxSubjects = knownSubjects;
                    teamsWithMax = 1;
                } else if (knownSubjects == maxSubjects) teamsWithMax++;
            }

        return List.of(maxSubjects, teamsWithMax);
    }

    private static int countSubjectsKnownBy2Teams(BitSet a, BitSet b) {
        var bin = (BitSet) a.clone();
        bin.or(b);
        return bin.cardinality();
    }
}
