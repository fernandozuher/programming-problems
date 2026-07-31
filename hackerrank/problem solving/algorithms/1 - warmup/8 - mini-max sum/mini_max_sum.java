// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// Java 25

void main() {
    int[] arr = readNums();
    long[] minMaxSum = calcMinMaxSum(arr);
    IO.println(minMaxSum[0] + " " + minMaxSum[1]);
}

int[] readNums() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long[] calcMinMaxSum(int[] arr) {
    long total, minValue, maxValue;
    total = minValue = maxValue = arr[0];

    for (int i = 1; i < arr.length; i++) {
        total += arr[i];
        minValue = Math.min(minValue, arr[i]);
        maxValue = Math.max(maxValue, arr[i]);
    }

    return new long[]{total - maxValue, total - minValue};
}
