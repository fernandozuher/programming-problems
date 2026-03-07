// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

int maxJump = ReadNumbers()[1];
int[] hurdles = ReadNumbers();
Console.WriteLine(HurdleRace(hurdles, maxJump));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int HurdleRace(int[] hurdles, int maxJump) => Math.Max(0, hurdles.Max() - maxJump);
