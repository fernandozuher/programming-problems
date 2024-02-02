// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        List<Boolean> cancelledClasses = Arrays.asList(new Boolean[n]);

        for (int i = 0; i < n; ++i) {
            int nStudentsArrivalTime = scan.nextInt();
            int cancellationThreshold = scan.nextInt();
            scan.nextLine();
            List<Integer> studentsArrivalTime = readIntArray();

            var obj = new AngryProfessor(studentsArrivalTime, cancellationThreshold);
            cancelledClasses.set(i, obj.cancelledClass());
        }

        for (boolean cancelled : cancelledClasses)
            System.out.println(cancelled ? "YES" : "NO");
    }

        public static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
    }

    class AngryProfessor {
        private List<Integer> studentsArrivalTime;
        private int cancellationThreshold;
        private boolean cancelled;

        public AngryProfessor(final List<Integer> studentsArrivalTime, final int cancellationThreshold) {
            this.studentsArrivalTime = studentsArrivalTime;
            this.cancellationThreshold = cancellationThreshold;
            cancelled = false;

            checkIfClassIsCancelled();
        }

            private void checkIfClassIsCancelled() {
                cancelled = countEarlyArrivalTime() < cancellationThreshold;
            }

                private int countEarlyArrivalTime() {
                    int earlyArrivalTimeCount = 0;

                    for (int arrivalTime : studentsArrivalTime)
                        if (arrivalTime <= 0)
                            ++earlyArrivalTimeCount;

                    return earlyArrivalTimeCount;
                }

        public boolean cancelledClass() {
            return cancelled;
        }
    }
