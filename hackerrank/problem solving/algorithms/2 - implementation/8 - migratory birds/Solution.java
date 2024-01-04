// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray();
        Collections.sort(array);

        var obj = new MigratoryBirds(array);
        System.out.println(obj.mostSpottedBird());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class MigratoryBirds {
        private List<Integer> birdSightings;
        private int nMostSpottedBird;

        public MigratoryBirds(final List<Integer> birdSightings) {
            this.birdSightings = birdSightings;
            findMostSpottedBird();
        }

            private void findMostSpottedBird() {
                nMostSpottedBird = birdSightings.get(0);
                int countNMostSpottedBird = 1;
                int tempCountMostSpottedBird = 1;
                int n = birdSightings.size();

                for (int i = 1; i < n; ++i)

                    if (birdSightings.get(i) == birdSightings.get(i - 1))
                        ++tempCountMostSpottedBird;

                    else if (tempCountMostSpottedBird > countNMostSpottedBird) {
                        nMostSpottedBird = birdSightings.get(i - 1);
                        countNMostSpottedBird = tempCountMostSpottedBird;
                        tempCountMostSpottedBird = 1;
                    }

                if (tempCountMostSpottedBird > countNMostSpottedBird)
                    nMostSpottedBird = birdSightings.get(n - 1);
            }

        public int mostSpottedBird() {
            return nMostSpottedBird;
        }
    }
