// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

int[] tripletA = ReadNumbers();
int[] tripletB = ReadNumbers();
var (scoreA, scoreB) = CompareTriplets(tripletA, tripletB);
Console.WriteLine("{0} {1}", scoreA, scoreB);

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of a and b = 3
// T: O(3) = O(1)
// S: O(1) extra space
(int, int) CompareTriplets(int[] tripletA, int[] tripletB)
{
    int scoreA = 0, scoreB = 0;

    foreach (var (ta, tb) in tripletA.Zip(tripletB))
        if (ta > tb)
            scoreA++;
        else if (tb > ta)
            scoreB++;

    return (scoreA, scoreB);
}
