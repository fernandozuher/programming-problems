// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

using Morfo.IO;

var (n, page) = Reader.Read<int, int>();
Console.WriteLine(PageCount(n, page));

// T: O(1)
// S: O(1) extra space
int PageCount(int n, int page)
{
    int fromFront = page / 2;
    int fromBack = n / 2 - fromFront;
    return Math.Min(fromFront, fromBack);
}
