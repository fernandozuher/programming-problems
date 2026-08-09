// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
for (int i = 0; i < n; i++)
{
    Reader.SkipInput();
    int threshold = Reader.Read<int>();
    int[] arrivalTimes = Reader.ReadLn<int, int[]>();
    Console.WriteLine(AngryProfessor(arrivalTimes, threshold) ? "YES" : "NO");
}

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
bool AngryProfessor(int[] arrivalTimes, int threshold)
{
    int onTime = arrivalTimes.Count(t => t <= 0);
    return onTime < threshold;
}
