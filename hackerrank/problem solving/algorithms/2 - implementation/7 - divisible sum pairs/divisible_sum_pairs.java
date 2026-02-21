// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true
// Java 25

void main() {
    int k = readNumbers()[1];
    int[] numbers = readNumbers();
    IO.println(divisibleSumPairs(numbers, k));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
int divisibleSumPairs(int[] numbers, int k) {
    int[] frequency = initRemainderFrequency(numbers, k);
    return countPairsWithRemainder0(frequency) + countComplementaryRemainderPairs(frequency) +
            countPairsWithRemainderKHalf(frequency);
}

int[] initRemainderFrequency(int[] numbers, int k) {
    int[] frequency = new int[k];
    for (int x : numbers)
        frequency[x % k]++;
    return frequency;
}

int countPairsWithRemainder0(int[] frequency) {
    return pairCount(frequency[0]);
}

int pairCount(int n) {
    return n * (n - 1) / 2;
}

int countComplementaryRemainderPairs(int[] frequency) {
    int n = frequency.length;
    return IntStream.range(1, (n + 1) / 2)
            .map(i -> frequency[i] * frequency[n - i])
            .sum();
}

int countPairsWithRemainderKHalf(int[] frequency) {
    int n = frequency.length;
    return n % 2 == 0 ? pairCount(frequency[n / 2]) : 0;
}
