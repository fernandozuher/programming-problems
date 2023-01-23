// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {
    private static Scanner _input;

    public static void main(String[] args) throws IOException {
        _input = new Scanner(System.in);
        final int nTestCases = readOneInt();
        final List<Boolean> results = Arrays.asList(new Boolean[nTestCases]);

        for (int i = 0, n = results.size(); i < n; i++) {
            final AngryProfessor angryProfessor = new AngryProfessor();
            results.set(i, angryProfessor.getCancelledClass());
        }

        for (boolean result : results)
            System.out.println(result ? "YES" : "NO");
    }

        public static int readOneInt() {
            final int number = _input.nextInt();
            return number;
        }
}

    class AngryProfessor {
        private int _nStudentsArrivalTime;
        private int _cancellationThreshold;
        private boolean _cancelledClass;

        public AngryProfessor() {
            _nStudentsArrivalTime = Solution.readOneInt();
            _cancellationThreshold = Solution.readOneInt();

            _angryProfessor();
        }

            private void _angryProfessor() {
                _cancelledClass = _countEarlyArrivalTime() < _cancellationThreshold;
            }

                private int _countEarlyArrivalTime() {
                    int earlyArrivalTimeCount = 0;

                    for (int i = 0, studentArrivalTime; i < _nStudentsArrivalTime; i++) {
                        studentArrivalTime = Solution.readOneInt();

                        if (studentArrivalTime <= 0)
                            earlyArrivalTimeCount++;
                    }

                    return earlyArrivalTimeCount;
                }

        public boolean getCancelledClass() {
            return _cancelledClass;
        }
    }
