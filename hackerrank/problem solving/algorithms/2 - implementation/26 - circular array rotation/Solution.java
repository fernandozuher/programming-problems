// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
        int rotationCount = scan.nextInt();
        int nQueries = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readLine();
        List<Integer> queries = readLines(nQueries);

        var obj = new CircularArrayRotation(array, rotationCount);
        printArrayAccordingToIndexFromAnotherArray(obj.rotatedArray(), queries);
    }

        private static List<Integer> readLine() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }

        private static List<Integer> readLines(final int n) {
            return Arrays.asList(new Integer[n])
                   .stream()
                   .map(x -> scan.nextInt())
                   .collect(toList());
        }

        private static void printArrayAccordingToIndexFromAnotherArray(final List<Integer> array1, final List<Integer> array2) {
            array2.forEach(i -> System.out.println(array1.get(i)));
        }
}

    class CircularArrayRotation {
        private List<Integer> array;
        private int rotationCount;

        public CircularArrayRotation(final List<Integer> array, final int rotationCount) {
            this.array = array;
            this.rotationCount = rotationCount;
            reduceRotations();
            rotateArray();
        }

            private void reduceRotations() {
                if (array.size() > 1)
                    rotationCount = rotationCount >= array.size() ? rotationCount % array.size() : rotationCount;
                else
                    rotationCount = 0;
            }

            private void rotateArray() {
                List<Integer> firstPartNewArray = array.subList(array.size() - rotationCount, array.size());
                List<Integer> secondPartNewArray = array.subList(0, array.size() - rotationCount);
                array = Stream.concat(firstPartNewArray.stream(), secondPartNewArray.stream()).collect(toList());
            }

        public List<Integer> rotatedArray() {
            return array;
        }
    }
