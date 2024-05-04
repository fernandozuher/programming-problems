// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.lang.Math;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;
    private static final int NO_INDEX = -1;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        System.out.println(findMinimumDistanceWhileReadElements(n));
    }

        public static int findMinimumDistanceWhileReadElements(int size) {
            int minimumDistance = Integer.MAX_VALUE;
            var firstIndexesOfElements = new HashMap<Integer, ArrayList<Integer>>();

            for (int i = 0, element; i < size && scan.hasNext(); ++i) {
                element = scan.nextInt();

                if (firstIndexesOfElements.containsKey(element)) {
                    int firstIndex = firstIndexesOfElements.get(element).get(0);
                    int secondIndex = firstIndexesOfElements.get(element).get(1);

                    if (secondIndex == NO_INDEX) {
                        secondIndex = i;
                        firstIndexesOfElements.get(element).set(1, secondIndex);
                        int minimumDistanceOfCurrentElement = secondIndex - firstIndex;
                        minimumDistance = Math.min(minimumDistance, minimumDistanceOfCurrentElement);
                    }
                } else
                    firstIndexesOfElements.put(element, new ArrayList<>(List.of(i, NO_INDEX)));
            }

            return minimumDistance != Integer.MAX_VALUE ? minimumDistance : NO_INDEX;
        }
}
