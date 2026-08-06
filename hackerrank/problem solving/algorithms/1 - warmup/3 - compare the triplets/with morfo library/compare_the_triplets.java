// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int[] tripletA = Reader.readLnInts();
    int[] tripletB = Reader.readLnInts();
    int[] result = computeTripletScores(tripletA, tripletB);
    IO.println(result[0] + " " + result[1]);
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
int[] computeTripletScores(int[] tripletA, int[] tripletB) {
    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < tripletA.length; i++)
        if (tripletA[i] > tripletB[i]) scoreA++;
        else if (tripletB[i] > tripletA[i]) scoreB++;

    return new int[]{scoreA, scoreB};
}
