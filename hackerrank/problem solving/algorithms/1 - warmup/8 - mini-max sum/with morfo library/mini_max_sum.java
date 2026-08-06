// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// Java 25

import morfo.collections.ReduceMany;
import morfo.io.Reader;

void main() {
    long[] arr = Reader.readLnLongs();
    long[] minMaxSum = calcMinMaxSum(arr);
    IO.println(minMaxSum[0] + " " + minMaxSum[1]);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
long[] calcMinMaxSum(long[] arr) {
    var r = ReduceMany.of(
            Arrays.stream(arr).boxed(),
            Long::sum, 0L,
            Math::min, arr[0],
            Math::max, arr[0]
    );

    return new long[]{r.a() - r.c(), r.a() - r.b()};
}
