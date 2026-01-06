// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

int n = int.Parse(Console.ReadLine()!);
int page = int.Parse(Console.ReadLine()!);
Console.WriteLine(PageCount(n, page));

// T: O(1)
// S: O(1)
int PageCount(int n, int page)
{
    int fromFront = page / 2;
    int fromBack = n / 2 - fromFront;
    return Math.Min(fromFront, fromBack);
}
