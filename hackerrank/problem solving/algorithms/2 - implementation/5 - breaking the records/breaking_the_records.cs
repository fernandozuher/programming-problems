// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

Console.ReadLine();
var (mostRecordBreaks, leastRecordBreaks) = BreakingRecords(ReadNumbers());
Console.WriteLine($"{mostRecordBreaks} {leastRecordBreaks}");

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

(int, int) BreakingRecords(int[] scores)
{
    int mostPoints = scores[0], leastPoints = scores[0];
    int mostRecordBreaks = 0, leastRecordBreaks = 0;

    foreach (int score in scores.Skip(1))
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
