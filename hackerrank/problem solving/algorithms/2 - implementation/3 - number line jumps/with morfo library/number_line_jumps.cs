// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

using Morfo.IO;

(int, int, int, int) initialState = ReadInput();
Console.WriteLine(Kangaroo(initialState) ? "YES" : "NO");

(int, int, int, int) ReadInput() => Reader.Read<int, int, int, int>();

// T: O(1)
// S: O(1) extra space
bool Kangaroo((int, int, int, int) initialState)
{
    var (x1, v1, x2, v2) = initialState;

    if (v1 == v2)
        return x1 == x2;

    int distanceDiff = x2 - x1;
    int velocityDiff = v1 - v2;
    return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff == 0;
}
