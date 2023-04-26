// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public class ACM_ICPC_TEAM {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int ATTENDEES = _readANumber();
        final int _TOPICS = _readANumber();
        final List<String> BINARY_STRINGS = _readBinaryStrings(ATTENDEES);

        final List<Integer> OUTPUT = _findMaximumSubjectsAndTeamsThatKnowThem(BINARY_STRINGS);
        _printArray(OUTPUT);
    }

        private static int _readANumber() {
            final int NUMBER = _scanner.nextInt();
            return NUMBER;
        }

        private static List<String> _readBinaryStrings(int nStrings) {
            List<String> binaryStrings = Arrays.asList(new String[nStrings]);
            binaryStrings = binaryStrings.stream().map(element -> _scanner.next()).collect(Collectors.toList());
            return binaryStrings;
        }

        private static List<Integer> _findMaximumSubjectsAndTeamsThatKnowThem(List<String> binaryStrings) {
            int maximumSubjectsKnownByTeams = 0;
            int teamsThatKnowMaximumSubjects = 0;

            for (int i = 0, size1 = binaryStrings.size() - 1; i < size1; i++) {
                for (int j = i + 1, size2 = size1 + 1; j < size2; j++) {
                    final int SUBJECTS_KNOWN_BY_2_TEAMS = _countSubjectsKnownBy2Teams(binaryStrings.get(i), binaryStrings.get(j));
                    final List<Integer> UPDATED_VARIABLES = _updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects);
                    maximumSubjectsKnownByTeams = UPDATED_VARIABLES.get(0);
                    teamsThatKnowMaximumSubjects = UPDATED_VARIABLES.get(1);
                }
            }

            final List<Integer> OUTPUT = Arrays.asList(maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects);
            return OUTPUT;
        }

            private static int _countSubjectsKnownBy2Teams(String binaryString1, String binaryString2) {
                int subjectsKnownBy2Teams = 0;

                for (int i = 0, size = binaryString1.length(); i < size; i++)
                    if (binaryString1.charAt(i) == '1' || binaryString2.charAt(i) == '1')
                        subjectsKnownBy2Teams++;

                return subjectsKnownBy2Teams;
            }

            private static List<Integer> _updateMaximumSubjectsAndTeamsThatKnowThem(int subjectsKnownBy2Teams, int maximumSubjectsKnownByTeams, int teamsThatKnowMaximumSubjects) {
                if (subjectsKnownBy2Teams > maximumSubjectsKnownByTeams) {
                    maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                    teamsThatKnowMaximumSubjects = 1;
                } else if (subjectsKnownBy2Teams == maximumSubjectsKnownByTeams)
                    teamsThatKnowMaximumSubjects++;

                return Arrays.asList(maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects);
            }

        private static void _printArray(List<Integer> array) {
            array.forEach(System.out::println);
        }
}
