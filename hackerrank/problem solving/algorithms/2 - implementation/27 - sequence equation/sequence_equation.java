// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] arr = readNumbers();
    for (int x : sequenceEquation(arr))
        IO.println(x);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of array arr/output
// T: O(n)
// S: O(n) extra space
int[] sequenceEquation(int[] arr) {
    int[] valuesToIndex = new int[arr.length];
    int i = 0;
    for (int val : arr) {
        valuesToIndex[val - 1] = i++;
    }
    return Arrays.stream(valuesToIndex).map(val -> valuesToIndex[val] + 1).toArray();
}
