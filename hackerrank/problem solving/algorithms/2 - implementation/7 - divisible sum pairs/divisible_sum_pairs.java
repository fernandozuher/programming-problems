// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Solution {
    void main() {
        int k = readNumbers()[1];
        int[] numbers = readNumbers();
        IO.println(divisibleSumPairs(numbers, k));
    }

    private static int[] readNumbers() {
        return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int divisibleSumPairs(int[] numbers, int k) {
        int[] frequency = initRemainderFrequency(numbers, k);
        return countPairsWithRemainder0(frequency) + countComplementaryRemainderPairs(frequency)
                + countPairsWithRemainderKHalf(frequency);
    }

    private static int[] initRemainderFrequency(int[] numbers, int k) {
        int[] frequency = new int[k];
        for (int x : numbers)
            frequency[x % k]++;
        return frequency;
    }

    private static int countPairsWithRemainder0(int[] frequency) {
        return pairCount(frequency[0]);
    }

    private static int pairCount(int n) {
        return n * (n - 1) / 2;
    }

    private static int countComplementaryRemainderPairs(int[] frequency) {
        int k = frequency.length;
        return IntStream.range(1, (k + 1) / 2).reduce(0, (acc, i) -> acc + frequency[i] * frequency[k - i]);
    }

    private static int countPairsWithRemainderKHalf(int[] frequency) {
        int k = frequency.length;
        return k % 2 == 0 ? pairCount(frequency[k / 2]) : 0;
    }
}
