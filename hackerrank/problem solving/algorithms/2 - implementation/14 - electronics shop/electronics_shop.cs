// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

int budget = ReadNumbers()[0];
int[] keyboards = PreprocessInput(ReadNumbers());
int[] usbDrives = PreprocessInput(ReadNumbers());
Console.WriteLine(CalcMoneySpent(keyboards, usbDrives, budget));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array arr
// k: length after deduplication
// k <= n
// T: O(n + k log k) = O(n log n)
// S: O(k) = O(n) extra space
int[] PreprocessInput(int[] arr) => arr.Distinct().OrderBy(x => x).ToArray();

// n1: length of array keyboards
// n2: length of array usbDrives
// T: O(n1 + n2)
// S: O(1) extra space
int CalcMoneySpent(int[] keyboards, int[] usbDrives, int budget)
{
    if (keyboards[0] >= budget || usbDrives[0] >= budget)
        return -1;

    int maxSpent = -1;
    for (int idxK = 0, idxUD = usbDrives.Length - 1; idxK < keyboards.Length && idxUD >= 0;)
    {
        if (keyboards[idxK] >= budget)
            break;

        int currentSum = keyboards[idxK] + usbDrives[idxUD];
        if (currentSum == budget)
            return budget;

        if (currentSum > budget)
            idxUD--;
        else
        {
            maxSpent = Math.Max(maxSpent, currentSum);
            idxK++;
        }
    }

    return maxSpent;
}
