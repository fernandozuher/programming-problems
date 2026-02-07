// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// Java 25

void main() {
    int beautifulDifference = readNumbers().get(1);
    List<Integer> arr = readNumbers();
    IO.println(findBeautifulTriplets(arr, beautifulDifference));
}

List<Integer> readNumbers() {
    return Stream.of(IO.readln().split(" ")).map(Integer::parseInt).toList();
}

// n: length of array arr
// T: O(n)
// S: O(n) extra space
int findBeautifulTriplets(List<Integer> arr, int beautifulDifference) {
    var values = new HashSet<>(arr);
    int doubleBD = 2 * beautifulDifference;
    return (int) arr.stream()
            .filter(x -> values.contains(x + beautifulDifference) && values.contains(x + doubleBD))
            .count();
}
