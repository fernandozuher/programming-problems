// https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true
// Java 22

import java.util.*;

class Solution {
    public static void main(String[] args) {
        HashMap<String, TestCase> testCases = generateTestCases();
        testCases.forEach((_, testCase) -> minimumIndexTest(testCase));
        uniqueValuesTest(testCases.get("uniqueValues").numbers);
        duplicateMinimumValueTest(testCases.get("duplicateMinimumValue").numbers);
        System.out.println("OK");
    }

    private record TestCase(List<Integer> numbers, Integer expectedResult) {
    }

    private static HashMap<String, TestCase> generateTestCases() {
        HashMap<String, TestCase> cases = new HashMap<>();
        cases.put("emptyNumbers", new TestCase(List.of(), null));
        cases.put("uniqueValues", new TestCase(List.of(2, 1), 1));
        cases.put("duplicateMinimumValue", new TestCase(List.of(1, 2, 1), 0));
        return cases;
    }

    private static void minimumIndexTest(TestCase test) {
        assert Objects.equals(findIndexOfMinimum(test.numbers), test.expectedResult);
    }

    private static Integer findIndexOfMinimum(List<Integer> numbers) {
        if (numbers.isEmpty())
            return null;
        return numbers.indexOf(Collections.min(numbers));
    }

    private static void uniqueValuesTest(List<Integer> numbers) {
        Set<Integer> uniqueNumbers = new HashSet<>();
        for (int num : numbers) {
            assert uniqueNumbers.add(num) : "Elements are not unique.";
        }
    }

    private static void duplicateMinimumValueTest(List<Integer> numbers) {
        int min = Collections.min(numbers);
        long count = numbers.stream().filter(x -> x == min).count();
        assert count == 2 : "There should be exactly two occurrences of the minimum value.";
    }
}
