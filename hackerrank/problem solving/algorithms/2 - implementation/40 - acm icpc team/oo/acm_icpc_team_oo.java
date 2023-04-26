// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int ATTENDEES = _readANumber();
        final int _TOPICS = _readANumber();
        final List<String> BINARY_STRINGS = _readBinaryStrings(ATTENDEES);

        final ACM_ICPC_TEAM OBJ = new ACM_ICPC_TEAM(BINARY_STRINGS);
        System.out.println(OBJ.getMaximumSubjectsKnownByTeams() + "\n" + OBJ.getTeamsThatKnowMaximumSubjects());
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
}

    class ACM_ICPC_TEAM {
        private List<String> _binaryStrings;
        private int _maximumSubjectsKnownByTeams;
        private int _teamsThatKnowMaximumSubjects;

        public ACM_ICPC_TEAM(List<String> binaryStrings) {
            _binaryStrings = binaryStrings;
            _maximumSubjectsKnownByTeams = 0;
            _teamsThatKnowMaximumSubjects = 0;

            _findMaximumSubjectsAndTeamsThatKnowThem();
        }

            private void _findMaximumSubjectsAndTeamsThatKnowThem() {
                for (int i = 0, size1 = _binaryStrings.size() - 1; i < size1; i++) {
                    for (int j = i + 1, size2 = size1 + 1; j < size2; j++) {
                        final int SUBJECTS_KNOWN_BY_2_TEAMS = _countSubjectsKnownBy2Teams(_binaryStrings.get(i), _binaryStrings.get(j));
                        _updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS);
                    }
                }
            }

                private int _countSubjectsKnownBy2Teams(String binaryString1, String binaryString2) {
                    int subjectsKnownBy2Teams = 0;

                    for (int i = 0, size = binaryString1.length(); i < size; i++)
                        if (binaryString1.charAt(i) == '1' || binaryString2.charAt(i) == '1')
                            subjectsKnownBy2Teams++;

                    return subjectsKnownBy2Teams;
                }

                private void _updateMaximumSubjectsAndTeamsThatKnowThem(int subjectsKnownBy2Teams) {
                    if (subjectsKnownBy2Teams > _maximumSubjectsKnownByTeams) {
                        _maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                        _teamsThatKnowMaximumSubjects = 1;
                    }
                    else if (subjectsKnownBy2Teams == _maximumSubjectsKnownByTeams)
                        _teamsThatKnowMaximumSubjects++;
                }

        public int getMaximumSubjectsKnownByTeams() {
            return _maximumSubjectsKnownByTeams;
        }

        public int getTeamsThatKnowMaximumSubjects() {
            return _teamsThatKnowMaximumSubjects;
        }
    }
