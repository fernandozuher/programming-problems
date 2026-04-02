// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// Java 25

void main() {
    int beautifulDifference = readNumbers()[1];
    var arr = readNumbers();
    IO.println(findBeautifulTriplets(arr, beautifulDifference));
}

int[] readNumbers() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
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
