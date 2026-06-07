// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true
// Java 25

void main() {
    var arr = readNumbers();
    int n = arr[0];
    int nQueries = arr[1];
    IO.println(arrayManipulation(n, nQueries));
}

int[] readNumbers() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// T: O(n + nQueries)
// S: O(n) extra space
long arrayManipulation(int n, int nQueries) {
    int[] arr = populateArr(n, nQueries);
    return maxSequentialSum(arr);
}

int[] populateArr(int n, int nQueries) {
    var res = new int[n + 2]; // +2 = 1-indexed array + range-end

    for (int i = 0; i < nQueries; i++) {
        var arr = readNumbers();
        int b = arr[0];
        int e = arr[1];
        int summand = arr[2];
        res[b] += summand;
        res[e + 1] -= summand;
    }

    return res;
}

long maxSequentialSum(int[] arr) {
    long sum = 0, max = 0;

    for (int x : arr) {
        sum += x;
        max = Math.max(max, sum);
    }

    return max;
}
