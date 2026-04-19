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

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
int divisibleSumPairs(int[] numbers, int k) {
    int[] freq = initRemainderFrequency(numbers, k);
    return countPairsWithRemainder0(freq) + countComplementaryRemainderPairs(freq) +
            countPairsWithRemainderKHalf(freq);
}

int[] initRemainderFrequency(int[] numbers, int k) {
    int[] freq = new int[k];
    for (int x : numbers)
        freq[x % k]++;
    return freq;
}

int countPairsWithRemainder0(int[] freq) {
    return pairCount(freq[0]);
}

int pairCount(int n) {
    return n * (n - 1) / 2;
}

int countComplementaryRemainderPairs(int[] freq) {
    int n = freq.length;
    return IntStream.range(1, (n + 1) / 2)
            .map(i -> freq[i] * freq[n - i])
            .sum();
}

int countPairsWithRemainderKHalf(int[] freq) {
    int n = freq.length;
    return n % 2 == 0 ? pairCount(freq[n / 2]) : 0;
}
