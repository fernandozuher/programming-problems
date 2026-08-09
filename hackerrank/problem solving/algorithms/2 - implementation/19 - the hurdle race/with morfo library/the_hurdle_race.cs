// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInput();
int maxJump = Reader.Read<int>();
int[] hurdles = Reader.ReadLn<int, int[]>();
Console.WriteLine(HurdleRace(hurdles, maxJump));

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int HurdleRace(int[] hurdles, int maxJump) => Math.Max(0, hurdles.Max() - maxJump);
