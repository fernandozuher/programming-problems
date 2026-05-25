// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

Console.ReadLine();
int[] arr = ReadNumbers();
double[] ratios = PlusMinus(arr);
foreach (var ratio in ratios)
    Console.WriteLine(ratio.ToString("F6"));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// T: O(n)
// S: O(1) extra space
double[] PlusMinus(int[] arr)
{
    int positive = 0;
    int negative = 0;
    int zero = 0;

    foreach (int number in arr)
        if (number > 0)
            positive++;
        else if (number < 0)
            negative++;
        else
            zero++;

    double n = arr.Length;
    return [positive / n, negative / n, zero / n];
}
