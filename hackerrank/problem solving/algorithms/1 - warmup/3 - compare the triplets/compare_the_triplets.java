// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// Java 25

void main() {
    int[] tripletA = readNums();
    int[] tripletB = readNums();
    int[] result = compareTriplets(tripletA, tripletB);
    IO.println(result[0] + " " + result[1]);
}

int[] readNums() {
    return Arrays.stream(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
int[] compareTriplets(int[] tripletA, int[] tripletB) {
    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < tripletA.length; i++)
        if (tripletA[i] > tripletB[i]) scoreA++;
        else if (tripletB[i] > tripletA[i]) scoreB++;

    return new int[]{scoreA, scoreB};
}
