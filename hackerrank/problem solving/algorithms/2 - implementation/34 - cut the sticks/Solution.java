// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        List<Integer> array = readIntArray(n);
        Collections.sort(array);

        var obj = new CutTheSticks(array);
        printArray(obj.remainingSticksArray());
    }

        public static List<Integer> readIntArray(final int n) {
            return Arrays.asList(new Integer[n]).stream().map(x -> scan.nextInt()).collect(toList());
        }

        public static void printArray(final List<Integer> array) {
            array.forEach(System.out::println);
        }
}

    class CutTheSticks {
        private List<Integer> sticksLengthArray;
        private List<Integer> remainingSticksLengthArray;

        public CutTheSticks(final List<Integer> array) {
            sticksLengthArray = array;
            remainingSticksLengthArray = new ArrayList<Integer>() {{add(array.size());}};
            cutTheSticks();
        }

            private void cutTheSticks() {
                for (int i = 0, n = sticksLengthArray.size(); i < n;) {
                    int shortestStickLength = sticksLengthArray.get(i);

                    i = findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, n);
                    int currentIterationN = n - i;
                    if (i == n)
                        break;

                    remainingSticksLengthArray.add(currentIterationN);
                    decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, n, shortestStickLength);
                }
            }

                private int findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(int index, final int n) {
                    int shortestStickLength = sticksLengthArray.get(index);
                    while (index < n && sticksLengthArray.get(index) == shortestStickLength)
                        ++index;
                    return index;
                }

                private void decreaseSticksLengthsHigherThanCurrentShortestStickLength(final int index, final int n, final int shortestStickLength) {
                    for (int i = index; i < n; ++i)
                        sticksLengthArray.set(i, sticksLengthArray.get(i) - shortestStickLength);
                }

        public List<Integer> remainingSticksArray() {
            return remainingSticksLengthArray;
        }
    }
