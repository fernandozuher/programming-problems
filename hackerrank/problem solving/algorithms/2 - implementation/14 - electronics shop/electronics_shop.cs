// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

int budget = ReadNumbers()[0];
int[] keyboards = PreProcessInput(ReadNumbers());
int[] usbDrives = PreProcessInput(ReadNumbers());
Console.WriteLine(CalculateMoneySpent(keyboards, usbDrives, budget));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int[] PreProcessInput(int[] arr)
{
    return arr.Distinct().OrderBy(x => x).ToArray();
}

// n: length of array keyboards
// m: length of array usbDrives
// T: O(n + m)
// S: O(1) extra space
int CalculateMoneySpent(int[] keyboards, int[] usbDrives, int budget)
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
