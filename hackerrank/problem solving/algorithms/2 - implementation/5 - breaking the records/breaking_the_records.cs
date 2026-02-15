// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

Console.ReadLine();
var (mostRecordBreaks, leastRecordBreaks) = BreakingRecords(ReadNumbers());
Console.WriteLine($"{mostRecordBreaks} {leastRecordBreaks}");

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array scores
// T: O(n)
// S: O(1) extra space
(int, int) BreakingRecords(int[] scores)
{
    int mostPoints = scores[0], leastPoints = scores[0];
    int mostRecordBreaks = 0, leastRecordBreaks = 0;

    foreach (int score in scores)
        if (score > mostPoints)
        {
            mostPoints = score;
            mostRecordBreaks++;
        }
        else if (score < leastPoints)
        {
            leastPoints = score;
            leastRecordBreaks++;
        }

    return (mostRecordBreaks, leastRecordBreaks);
}
