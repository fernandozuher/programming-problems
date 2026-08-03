// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

int maxJump = ReadNums()[1];
int[] hurdles = ReadNums();
Console.WriteLine(HurdleRace(hurdles, maxJump));

int[] ReadNums() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int HurdleRace(int[] hurdles, int maxJump) => Math.Max(0, hurdles.Max() - maxJump);
