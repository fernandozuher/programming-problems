// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
// Java 25

void main() {
    IO.readln();
    int[] records = breakingRecords(readNumbers());
    IO.println(records[0] + " " + records[1]);
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

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
