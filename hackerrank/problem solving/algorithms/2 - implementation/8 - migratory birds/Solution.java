// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// From Java 21

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
        List<Integer> array = readIntArray(n);
        Collections.sort(array);
        System.out.print(findMostSpottedBird(array));
    }

        public static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }

        public static int findMostSpottedBird(final List<Integer> birdSightings) {
            int mostSpottedBird = birdSightings.getFirst();
            int countMostSpottedBird = 1;
            int tempCountMostSpottedBird = 1;

            for (int i = 1, n = birdSightings.size(); i < n; ++i)
                if (birdSightings.get(i) == birdSightings.get(i - 1))
                    ++tempCountMostSpottedBird;
                else if (tempCountMostSpottedBird > countMostSpottedBird) {
                    mostSpottedBird = birdSightings.get(i - 1);
                    countMostSpottedBird = tempCountMostSpottedBird;
                    tempCountMostSpottedBird = 1;
                }

            if (tempCountMostSpottedBird > countMostSpottedBird)
                mostSpottedBird = birdSightings.getLast();

            return mostSpottedBird;
        }
}
