// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

int beautifulDifference = ReadNumbers()[1];
int[] arr = ReadNumbers();
Console.WriteLine(FindBeautifulTriplets(arr, beautifulDifference));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array arr
// T: O(n)
// S: O(n) extra space
int FindBeautifulTriplets(int[] arr, int beautifulDifference)
{
    var values = new HashSet<int>(arr);
    int doubleBD = 2 * beautifulDifference;
    return arr.Count(x => values.Contains(x + beautifulDifference) && values.Contains(x + doubleBD));
}
