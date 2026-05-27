// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// Java 25

void main() {
    int[] arr = readNumbers();
    long[] minMaxSum = calcMinMaxSum(arr);
    IO.println(minMaxSum[0] + " " + minMaxSum[1]);
}

int[] readNumbers() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long[] calcMinMaxSum(int[] arr) {
    long sum, min, max;
    sum = min = max = arr[0];

    for (int i = 1; i < arr.length; i++) {
        sum += arr[i];
        min = Math.min(min, arr[i]);
        max = Math.max(max, arr[i]);
    }

    return new long[]{sum - max, sum - min};
}
