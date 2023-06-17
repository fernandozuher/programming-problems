// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

public class MinimumDistances {
    private static Scanner scanner;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        final int arraySize = scanner.nextInt();
        final int minimumDistance = findMinimumDistanceWhileReadElements(arraySize);
        System.out.println(minimumDistance);
    }

    private static int findMinimumDistanceWhileReadElements(int size) {
        int minimumDistance = Integer.MAX_VALUE;
        Map<Integer, ArrayList<Integer>> elements = new HashMap<Integer, ArrayList<Integer>>();

        // twoElementsSize = 2 -> Only the first 2 indexes of a repeated element matter
        // because they have the minimum distance of it
        for (int i = 0, element, twoElementsSize = 2; i < size && scanner.hasNext(); ++i) {
            element = scanner.nextInt();

            if (elements.containsKey(element)) {
                if (elements.get(element).size() < twoElementsSize) {
                    elements.get(element).add(i);
                    final int minimumDistanceOfCurrentElement = elements.get(element).get(1) - elements.get(element).get(0);
                    minimumDistance = Math.min(minimumDistance, minimumDistanceOfCurrentElement);
                }
            } else
                elements.put(element, new ArrayList<Integer>(List.of(i)));
        }

        return minimumDistance != Integer.MAX_VALUE ? minimumDistance : -1;
    }
}
