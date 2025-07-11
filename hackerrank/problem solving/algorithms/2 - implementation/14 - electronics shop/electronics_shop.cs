// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int budget = ReadNumbers()[0];
        int[] keyboards = ReadNumbers().Distinct().ToArray();
        int[] usbDrives = ReadNumbers().Distinct().ToArray();
        Array.Sort(keyboards);
        Array.Sort(usbDrives);
        Console.WriteLine(CalculateMoneySpent(keyboards, usbDrives, budget));
    }

    private static int[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
    }

    private static int CalculateMoneySpent(int[] keyboards, int[] usbDrives, int budget)
    {
        int maxSpent = -1, i = 0, j = usbDrives.Length - 1;

        while (i < keyboards.Length && j >= 0)
        {
            if (keyboards[i] >= budget)
                break;

            int sum = keyboards[i] + usbDrives[j];
            if (sum > budget)
                j--;
            else if (sum == budget)
                return budget;
            else
            {
                if (sum > maxSpent)
                    maxSpent = sum;
                i++;
            }
        }

        return maxSpent;
    }
}
