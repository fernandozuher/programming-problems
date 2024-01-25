// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

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

        var obj = new PickingNumbers(array);
        System.out.println(obj.subarrayBiggestSize());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class PickingNumbers {
        private List<Integer> numbers;
        private int subarrayBiggestLength;

        public PickingNumbers(final List<Integer> numbers) {
            this.numbers = numbers;
            subarrayBiggestLength = 1;
            pickingNumbers();
        }

            private void pickingNumbers() {
                int firstReferenceNumberIndex = 0;
                int secondReferenceNumberIndex = 0;
                int subarrayCurrentSize = 1;

                for (int i = 1, n = numbers.size(); i < n; ++i) {
                    final int difference = numbers.get(i) - numbers.get(firstReferenceNumberIndex);

                    switch (difference) {
                    case 0:
                        ++subarrayCurrentSize;
                        break;

                    case 1:
                        ++subarrayCurrentSize;
                        if (numbers.get(secondReferenceNumberIndex) != numbers.get(i))
                            secondReferenceNumberIndex = i;
                        break;

                    default:
                        subarrayBiggestLength = updateSubarrayBiggestSize(subarrayCurrentSize);

                        List<Integer> update = updateFirstReferenceNumberIndexAndSubarrayCurrentSize(i, secondReferenceNumberIndex);

                        firstReferenceNumberIndex = update.get(0);
                        secondReferenceNumberIndex = i;
                        subarrayCurrentSize = update.get(1);
                    }
                }

                subarrayBiggestLength = updateSubarrayBiggestSize(subarrayCurrentSize);
            }

                int updateSubarrayBiggestSize(final int subarrayCurrentSize) {
                    return Math.max(subarrayCurrentSize, subarrayBiggestLength);
                }

                List<Integer> updateFirstReferenceNumberIndexAndSubarrayCurrentSize(final int i, final int secondReferenceNumberIndex) {
                    int firstReferenceNumberIndex, subarrayCurrentSize;

                    if (numbers.get(i) - numbers.get(secondReferenceNumberIndex) == 1) {
                        firstReferenceNumberIndex = secondReferenceNumberIndex;
                        subarrayCurrentSize = i - secondReferenceNumberIndex + 1;
                    } else {
                        firstReferenceNumberIndex = i;
                        subarrayCurrentSize = 1;
                    }

                    return List.of(firstReferenceNumberIndex, subarrayCurrentSize);
                }

        public int subarrayBiggestSize() {
            return subarrayBiggestLength;
        }
    }
