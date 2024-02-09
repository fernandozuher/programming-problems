// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String args[]) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray();

        var obj = new SequenceEquation(array);
        obj.permutatedArray().forEach(System.out::println);
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class SequenceEquation {
        private List<Integer> array;
        private List<Integer> elementsPositionsArray;
        private List<Integer> permutArray;

        public SequenceEquation(final List<Integer> array) {
            this.array = array;
            elementsPositionsArray = Arrays.asList(new Integer[array.size()]);
            permutArray = Arrays.asList(new Integer[array.size()]);
            generateElementsPositionsArray();
            generatePermutatedArray();
        }

            private void generateElementsPositionsArray() {
                int i = 0;
                for (var x : array)
                    elementsPositionsArray.set(x - 1, i++);
            }

            private void generatePermutatedArray() {
                int i = 0;
                for (var x : elementsPositionsArray)
                    permutArray.set(i++, elementsPositionsArray.get(x) + 1);
            }

        public List<Integer> permutatedArray() {
            return permutArray;
        }
    }
