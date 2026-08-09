// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    Reader.skipInputLn();
    int[] records = breakingRecords(Reader.readLnInts());
    IO.println(records[0] + " " + records[1]);
}

// n: length of scores
// T: O(n)
// S: O(1) extra space
int[] breakingRecords(int[] scores) {
    int mostPoints = scores[0], leastPoints = scores[0];
    int mostRecordBreaks = 0, leastRecordBreaks = 0;

    for (int score : scores)
        if (score > mostPoints) {
            mostPoints = score;
            mostRecordBreaks++;
        } else if (score < leastPoints) {
            leastPoints = score;
            leastRecordBreaks++;
        }

    return new int[]{mostRecordBreaks, leastRecordBreaks};
}
