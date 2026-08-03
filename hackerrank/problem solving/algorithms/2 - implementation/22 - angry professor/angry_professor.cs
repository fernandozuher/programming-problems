// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

int n = ReadNums()[0];
for (int i = 0; i < n; i++)
{
    int threshold = ReadNums()[1];
    int[] arrivalTimes = ReadNums();
    Console.WriteLine(AngryProfessor(arrivalTimes, threshold) ? "YES" : "NO");
}

int[] ReadNums() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
bool AngryProfessor(int[] arrivalTimes, int threshold)
{
    int onTime = arrivalTimes.Count(t => t <= 0);
    return onTime < threshold;
}
