// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

int days = int.Parse(Console.ReadLine()!);
Console.WriteLine(ViralAdvertising(days));

// n = days = length of the iteration
// T = O(n)
// S = O(1)
int ViralAdvertising(int days)
{
    int shared = 5;
    return Enumerable.Range(0, days).Sum(_ =>
    {
        int liked = shared / 2;
        shared = liked * 3;
        return liked;
    });
}
