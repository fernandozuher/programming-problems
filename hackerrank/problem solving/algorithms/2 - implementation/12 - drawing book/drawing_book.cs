// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int page = int.Parse(Console.ReadLine());
        Console.WriteLine(PageCount(n, page));
    }

    private static int PageCount(int n, int page)
    {
        int fromFront = page / 2;
        int fromBack = n / 2 - fromFront;
        return Math.Min(fromFront, fromBack);
    }
}
