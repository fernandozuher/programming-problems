// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

public class Solution {
    private static Scanner scanner;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        final int arraySize = scanner.nextInt();
        final MinimumDistances obj = new MinimumDistances(scanner, arraySize);
        System.out.println(obj.getMinimumDistance());
    }
}

    class MinimumDistances {
        private static Scanner scanner;
        private static int NO_INDEX = -1;
        private List<Integer> elements;
        private int minimumDistance;

        public MinimumDistances(Scanner scanner, int size) {
            this.scanner = scanner;
            this.elements = Arrays.asList(new Integer[size]);
            this.minimumDistance = Integer.MAX_VALUE;
            this.findMinimumDistanceWhileReadElements();
        }

            private void findMinimumDistanceWhileReadElements() {
                Map<Integer, ArrayList<Integer>> firstIndexesOfElements = new HashMap<Integer, ArrayList<Integer>>();

                for (int i = 0; i < this.elements.size() && this.scanner.hasNext(); i++) {
                    this.elements.set(i, this.scanner.nextInt());
                    final int element = this.elements.get(i);

                    if (firstIndexesOfElements.containsKey(element)) {
                        int firstIndex = firstIndexesOfElements.get(element).get(0), secondIndex = firstIndexesOfElements.get(element).get(1);

                        if (secondIndex == NO_INDEX) {
                            secondIndex = i;
                            firstIndexesOfElements.get(element).set(1, secondIndex);
                            final int minimumDistanceOfCurrentElement = secondIndex - firstIndex;
                            this.minimumDistance = Math.min(this.minimumDistance, minimumDistanceOfCurrentElement);
                        }
                    } else
                        firstIndexesOfElements.put(element, new ArrayList<Integer>(List.of(i, NO_INDEX)));
                }

                this.minimumDistance = minimumDistanceOrNoIndex();
            }

                private int minimumDistanceOrNoIndex() {
                    return this.minimumDistance != Integer.MAX_VALUE ? this.minimumDistance : NO_INDEX;
                }

        public int getMinimumDistance() {
            return this.minimumDistance;
        }
    }
