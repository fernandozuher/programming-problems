// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
int[] arr = Reader.ReadLn<int>();
double[] ratios = PlusMinus(arr);
printRatios(ratios);

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
    return new double[] { positive / n, negative / n, zero / n };
}

void printRatios(double[] ratios) => Array.ForEach(ratios, ratio => Console.WriteLine(ratio.ToString("F6")));
