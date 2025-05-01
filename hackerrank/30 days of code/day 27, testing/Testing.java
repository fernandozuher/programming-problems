// https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true

import java.util.*;

class Solution {
    public static void main(String[] args) {
        try {
            testWithEmptyArray();
            testWithUniqueValues();
            testWithExactlyTwoDifferentMinimums();
            System.out.println("OK");
        } catch (Exception e) {
            System.out.println("A test case failed.");
        }
    }

    private static void testWithEmptyArray() {
        int[] numbers = TestDataEmptyArray.array();
        if (numbers.length > 0)
            throw new AssertionError("The array should be empty in this test case.");
        try {
            minimumIndexOfSmallestElement(numbers);
        } catch (IllegalArgumentException e) {
            return;
        }
        throw new AssertionError();
    }

    private static int minimumIndexOfSmallestElement(int[] numbers) {
        if (numbers.length == 0)
            throw new IllegalArgumentException("Cannot get the minimum value index from an empty sequence.");

        int minIndex = 0;
        int minValue = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] < minValue) {
                minValue = numbers[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    private static void testWithUniqueValues() {
        int[] numbers = TestDataUniqueValues.array();
        assertSize(numbers);
        assertArrayUnique(numbers);
        verifyResult(numbers, TestDataUniqueValues.expectedResult());
    }

    private static void assertSize(int[] numbers) {
        if (numbers.length < 2)
            throw new AssertionError("The container should have at least two unique elements.");
    }

    private static void assertArrayUnique(int[] numbers) {
        Set<Integer> uniqueNumbers = new HashSet<>();
        for (int num : numbers) {
            if (!uniqueNumbers.add(num)) {
                throw new AssertionError("Array elements are not unique.");
            }
        }
    }

    private static void verifyResult(int[] numbers, int expectResult) {
        try {
            int result = minimumIndexOfSmallestElement(numbers);
            if (result != expectResult)
                throw new AssertionError("Result does not match expected result.");
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            throw new AssertionError();
        }
    }

    private static void testWithExactlyTwoDifferentMinimums() {
        int[] numbers = TestDataExactlyTwoDifferentMinimums.array();
        assertSize(numbers);
        assertTwoOccurrencesOfMinimum(numbers);
        verifyResult(numbers, TestDataExactlyTwoDifferentMinimums.expectedResult());
    }

    private static void assertTwoOccurrencesOfMinimum(int[] numbers) {
        int min = Arrays.stream(numbers).min().getAsInt();
        int count = Math.toIntExact(Arrays.stream(numbers).filter(n -> n == min).count());
        if (count != 2)
            throw new AssertionError("There should be exactly two occurrences of the minimum value.");
    }
}

class TestDataEmptyArray {
    public static int[] array() {
        return new int[0];
    }
}

class TestDataUniqueValues {
    public static int[] array() {
        return new int[]{2, 1};
    }

    public static int expectedResult() {
        return 1;
    }
}

class TestDataExactlyTwoDifferentMinimums {
    public static int[] array() {
        return new int[]{1, 2, 1};
    }

    public static int expectedResult() {
        return 0;
    }
}
