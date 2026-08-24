// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
for (int i = 0; i < n; i++)
{
    var (a, b) = Reader.Read<int, int>();
    Console.WriteLine(Squares(a, b));
}

// T: O(1)
// S: O(1) extra space
int Squares(int startNum, int endNum)
{
    int maxSquare = (int)Math.Floor(Math.Sqrt(endNum));
    int minSquare = (int)Math.Ceiling(Math.Sqrt(startNum));
    return maxSquare - minSquare + 1;
}
