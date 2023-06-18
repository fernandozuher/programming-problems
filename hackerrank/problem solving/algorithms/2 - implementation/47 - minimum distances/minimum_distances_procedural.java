// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

public class MinimumDistances {
    private static Scanner scanner;
    private static int NO_INDEX = -1;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        final int arraySize = scanner.nextInt();
        System.out.println(findMinimumDistanceWhileReadElements(arraySize));
    }

        private static int findMinimumDistanceWhileReadElements(int size) {
            int minimumDistance = Integer.MAX_VALUE;
            Map<Integer, ArrayList<Integer>> firstIndexesOfElements = new HashMap<Integer, ArrayList<Integer>>();

            for (int i = 0, element; i < size && scanner.hasNext(); i++) {
                element = scanner.nextInt();

                if (firstIndexesOfElements.containsKey(element)) {
                    int firstIndex = firstIndexesOfElements.get(element).get(0), secondIndex = firstIndexesOfElements.get(element).get(1);

                    if (secondIndex == NO_INDEX) {
                        secondIndex = i;
                        firstIndexesOfElements.get(element).set(1, secondIndex);
                        final int minimumDistanceOfCurrentElement = secondIndex - firstIndex;
                        minimumDistance = Math.min(minimumDistance, minimumDistanceOfCurrentElement);
                    }
                } else
                    firstIndexesOfElements.put(element, new ArrayList<Integer>(List.of(i, NO_INDEX)));
            }

            return minimumDistanceOrNoIndex(minimumDistance);
        }

            private static int minimumDistanceOrNoIndex(int minimumDistance) {
                return minimumDistance != Integer.MAX_VALUE ? minimumDistance : NO_INDEX;
            }
}
