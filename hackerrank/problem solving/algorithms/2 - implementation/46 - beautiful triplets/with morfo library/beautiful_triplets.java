// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    Reader.skipInput();
    int beautifulDifference = Reader.read(Integer::parseInt);
    int[] arr = Reader.readLnInts();
    IO.println(findBeautifulTriplets(arr, beautifulDifference));
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
int findBeautifulTriplets(int[] arr, int beautifulDifference) {
    var values = Arrays.stream(arr).boxed().collect(Collectors.toSet());
    int doubleBD = 2 * beautifulDifference;
    return (int) Arrays.stream(arr)
            .filter(x -> values.contains(x + beautifulDifference) && values.contains(x + doubleBD))
            .count();
}
